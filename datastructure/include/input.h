#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

class arginput
{
public:
    //data
    vector<int> data_int;
    vector<string> data_string;
    vector<vector<int>> data_int_arr1;
    vector<vector<vector<int>>> data_int_arr2;
    vector<vector<string>> data_string_arr1;
    vector<vector<vector<string>>> data_string_arr2;
    //data type
    vector<string> data_tpyes;
    //json
    Json::Value json_root;
    Json::Reader reader;

public:
    arginput(){};
    void  read(string json_path);

};

void arginput::read(string json_path){
    ifstream fs(json_path,ios::binary);
    if(!reader.parse(fs,json_root)){
        cout << "json data open error" << endl;
		fs.close();
    }

    int argnum = json_root["arg"].size();
    for(int i=0;i<argnum;i++){
        string argtype=json_root["arg"][i]["type"].asString();
        data_tpyes.push_back(argtype);
        //查看参数类型
        if(argtype=="int"){
            int res=json_root["arg"][i]["data"].asInt();
            data_int.push_back(res);
        }
        else if (argtype=="string")
        {
            string res=json_root["arg"][i]["data"].asString();
            data_string.push_back(res);
        }
        else if (argtype=="vector<int>")
        {
            vector<int> res;
            for(int j=0;j<(int)json_root["arg"][i]["data"].size();j++){
                res.push_back(json_root["arg"][i]["data"][j].asInt());
            }
            data_int_arr1.push_back(res);
        }
        else if(argtype=="vector<string>")
        {
            vector<string> res;
            for(int j=0;j<(int)json_root["arg"][i]["data"].size();j++){
                res.push_back(json_root["arg"][i]["data"][j].asString());
            }
            data_string_arr1.push_back(res);
        }
        else if(argtype=="vector<vector<int>>"){
            vector<vector<int>> res;
            for(int m=0;m<json_root["arg"][i]["data"].size();m++){
                vector<int> inin;
                for(int n=0;n<json_root["arg"][i]["data"][0].size();n++){
                    inin.push_back(json_root["arg"][i]["data"][m][n].asInt());
                }
                res.push_back(inin);
            }
            data_int_arr2.push_back(res);
        }
    
        
    }

}