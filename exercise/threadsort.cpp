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

#include <sys/types.h>
#include <sys/stat.h>
#include <thread>
#include "threadpool.h"

using namespace std;

vector<int> nums;
ThreadPool thp;

class task:public BasicTask{
public:
    int id;
    task(int id,vector<int>::iterator lit,vector<int>::iterator rit){
        this->id=id;
        this->lit=lit;
        this->rit=rit;
    }
    vector<int>::iterator lit;
    vector<int>::iterator rit;
    void run(){
        if(lit>=rit)return;
        
        if((rit-lit)<id/8){
            sort(lit,rit+1);
            return;
        }
        
        
        int tmp=*lit;
        auto l=lit,r=rit;
        while(l<r){
            while(l<r && *r>=tmp)r--;
            while(l<r && *l<=tmp)l++;
            if(l<r){
                int ctmp=*l;
                *l=*r;
                *r=ctmp;
            }
        }
        *lit=*l;
        *l=tmp;
        //分
        if(lit<l-1){
            BasicTask* lefttask=new task(id,lit,l-1);
            thp.addTask(lefttask);
        }
        

        if(l+1<rit){
            BasicTask* righttask=new task(id,l+1,rit);
            thp.addTask(righttask);
        }
        
        
        
    }

};

class mythreadsort
{
public:
    /* data */
    arginput data;
    mythreadsort(){
        data.read("data/sort.json");
        cout<<"finish data load"<<endl;
    };
    bool sortright(vector<int> arr){
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])return false;
        }
        return true;
    }
public:
    void Solution(){
        int len=data.data_int_arr1[1].size();
        for(int i=0;i<len*10;i++){
            nums.push_back(i);
        }
        random_shuffle(nums.begin(),nums.end());
        

        clock_t start, end;
        start = clock();
        
        BasicTask* sorttask=new task(nums.size(),nums.begin(),--nums.end());
        thp.addTask(sorttask);
        thp.start();
        //等待任务为空
        thp.taskwaitEmpty();//阻塞
        //sleep(1);
        thp.stop();

        end = clock();
        double seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("多线程快速排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(nums))cout<<"排序错误"<<endl;
        
        /*for(int e:nums){
            cout<<e<<" ";
        }
        cout<<endl;*/
        
    }

};

int main(){
    
    mythreadsort out;

    out.Solution();
  
    
   
}