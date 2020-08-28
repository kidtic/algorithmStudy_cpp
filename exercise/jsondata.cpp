#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fs("data/test.json",ios::binary);
    Json::Value json_root;
    Json::Reader reader;
    if(!reader.parse(fs,json_root)){
        cout << "open error" << endl;
		fs.close();
    }
    //cout<<json_root.toStyledString()<<endl;

    int  argnum = json_root["argnum"].asInt();
    for(int i=0;i<json_root["argnum"].asInt();i++){
        string argtype=json_root["arg"][i]["type"].asString();
        if(argtype=="int"){
            int res=json_root["arg"][i]["data"].asInt();
            cout<<res<<endl;
        }
        else if(argtype=="vector<string>")
        {
            vector<string> res;
            for(int j=0;j<(int)json_root["arg"][i]["data"].size();j++){
                res.push_back(json_root["arg"][i]["data"][j].asString());
                cout<<res.back()<<" ";
            }
            cout<<endl;

        }
    
        
    }

    return 0;
    

}