//路径规划，在矩形二维障碍物地图内做路径规划
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include "input.h"
#include <queue>
#include <time.h>
#include <unistd.h>


using namespace std;

class pathplanning
{
public:
    /* data */
    arginput data;
    pathplanning(){
        data.read("data/pathplanning.json");
    };
public:
    void Solution(){
        outmap(data.data_int_arr2[0],0);
        vector<vector<int>> res=solutionbfs(data.data_int_arr2[0],data.data_int_arr1[0]);
        outmap(res,0);

        
    };
    void outmap(vector<vector<int>> map,int flag){
        if(flag==0){
            cout<<"out:\n--------------------------------------------------------------"<<endl;
            for(auto eline:map){
                for(auto e:eline){
                    if(e==0) cout<<"  ";
                    else if(e==1) cout<<"# ";
                    else if(e==11) cout<<"o ";
                }
                cout<<endl;
            }
            cout<<"--------------------------------------------------------------\n\n"<<endl;
        }
        else if(flag==1){
            cout<<"out:\n--------------------------------------------------------------"<<endl;
            for(auto eline:map){
                for(auto e:eline){
                cout<<e<<" ";
                }
                cout<<endl;
            }
            cout<<"--------------------------------------------------------------\n\n"<<endl;
        }
        
    };
    vector<vector<int>> solutionbfs(vector<vector<int>> map,vector<int> s2e){
        //实现
        int starti=s2e[0];
        int startj=s2e[1];
        int endi=s2e[2];
        int endj=s2e[3];
        vector<vector<int>> dif={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};

        vector<vector<int>> vis=vector<vector<int>>(map.size(),vector<int>(map[0].size(),0));
        queue<int> cashex;
        queue<int> cashey;
        cashex.push(starti);cashey.push(startj);
        vis[starti][startj]=9;
        while(!cashex.empty()){
            int nodex=cashex.front(),nodey=cashey.front();
            if(nodex==endi&&nodey==endj){
                cout<<"find end"<<endl;
                break;
            }
            for(int i=0;i<8;i++){
                int nx=nodex+dif[i][0],ny=nodey+dif[i][1];
                if(nx<0||nx>=vis.size()||ny<0||ny>=vis[0].size())continue;
                if(map[nx][ny]==1)continue;
                if(vis[nx][ny]>0)continue;
                vis[nx][ny]=i+1;
                cashex.push(nx);cashey.push(ny);
            }
            cashex.pop();cashey.pop();
            //outmap(vis);
            //usleep(100000);

        }
        printf("hello world\n");
        //返回
        int pi=endi,pj=endj;
        while(vis[pi][pj]!=9){
            map[pi][pj]=11;
            int vv=vis[pi][pj];
            pi=pi-dif[vv-1][0];
            pj=pj-dif[vv-1][1];
        }


        return map;

    };

};


int main(int argc, char const *argv[])
{
    
    pathplanning out;

    out.Solution();
    
    
    return 0;
}