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


using namespace std;

class mysort
{
public:
    /* data */
    arginput data;
    mysort(){
        data.read("data/sort.json");
        cout<<"finish data load"<<endl;
    };
public:
    void Solution(){
        vector<int> nums1=data.data_int_arr1[0];
        vector<int> nums2=data.data_int_arr1[1];

        vector<int> res1=maopaosort(nums1);
        for(int e:res1){
            cout<<e<<" ";
        }
        cout<<endl;


        clock_t start, end;
        start = clock();
        vector<int> res2=guibingsort(nums2,0,nums2.size()-1);
        end = clock();
        double seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("归并排序 Use time is: %.8f ms\n", seconds*1000);

        start = clock();
        res2=maopaosort(nums2);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("冒泡排序 Use time is: %.8f ms\n", seconds*1000);

        



        
    };
    vector<int> guibingsort(vector<int>& nums,int left,int right){
        if(left>right||left<0||right>=nums.size()){
            vector<int> res;
            return res;
        }
        if(left==right){
            vector<int> res;
            res.push_back(nums[left]);
            return res;
        }
        if(right-left==1){
            vector<int> res;
            res.push_back(min(nums[left],nums[right]));
            res.push_back(max(nums[left],nums[right]));
            return res;
        }
        int mid=(left+right)/2;
        vector<int> a=guibingsort(nums,left,mid);
        vector<int> b=guibingsort(nums,mid+1,right);
        vector<int> res;
        int i=0,j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]<=b[j]){
                res.push_back(a[i]);
                i++;
            }
            else{
                res.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            res.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            res.push_back(b[j]);
            j++;
        }
        return res;
        
    }
    vector<int> maopaosort(vector<int>& nums){
        vector<int> res=nums;
        for(int i=0;i<res.size()-1;i++){
            for(int j=0;j<res.size()-1-i;j++){
                if(res[j]>res[j+1]){
                    int t=res[j+1];
                    res[j+1]=res[j];
                    res[j]=t;
                }
            }
        }
        return res;

    }

};

int main(int argc, char const *argv[])
{
    
    mysort out;

    out.Solution();
    
    
    return 0;
}
