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
    bool sortright(vector<int> arr){
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])return false;
        }
        return true;
    }
public:
    void Solution(){
        vector<int> nums1=data.data_int_arr1[0];
        vector<int> nums2=data.data_int_arr1[1];

        vector<int> nums3;
        srand((int)time(0));
        for(int i=0;i<nums2.size();i++){
            nums3.push_back(rand()%10000000);
        }
        vector<int> res3;
        
        

        clock_t start, end;
        start = clock();
        vector<int> res2=guibingsort(nums2,0,nums2.size()-1);
        end = clock();
        double seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("归并排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;

/*
        start = clock();
        res2=maopaosort(nums2);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("冒泡排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;
*/
        res2=nums2;res3=nums3;
        start = clock();
        quicksort(0,res2.size()-1,res2);
        quicksort(0,res3.size()-1,res3);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("快速排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;
        if(!sortright(res3))cout<<"排序错误"<<endl;

        start = clock();
        res2=heapsort(nums2);
        res3=heapsort(nums3);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("堆排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;

        start = clock();
        res2=shellsort(nums2);
        res3=shellsort(nums3);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("希尔排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;

        start = clock();
        res2=insertsort(nums2);
        res3=insertsort(nums3);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("插入排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;

        start = clock();
        res2=bucketsort(nums2,100);
        res3=bucketsort(nums3,100);
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("桶排序 Use time is: %.3f ms\n", seconds*1000);
        if(!sortright(res2))cout<<"排序错误"<<endl;

        


        cout<<"----------------函数库-------------------"<<endl;
        res2=nums2;res3=nums3;
        start = clock();
        sort(res2.begin(),res2.end());
        sort(res3.begin(),res3.end());
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("函数库:快速排序 Use time is: %.3f ms\n", seconds*1000);

        res2=nums2;res3=nums3;
        start = clock();
        stable_sort(res2.begin(),res2.end());
        stable_sort(res3.begin(),res3.end());
        end = clock();
        seconds  =(double)(end - start)/CLOCKS_PER_SEC;
        printf("函数库:稳定排序 Use time is: %.3f ms\n", seconds*1000);

        
        
        



        
    };
    vector<int> guibingsort(vector<int>& nums,int left,int right){
        
        if(left==right){
            vector<int> res;
            res.push_back(nums[left]);
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
    
    //快速排序：左基数
    void quicksort(int l, int r, vector<int>& arr) {
		if (l >= r)return;
		int base = arr[l];//左边为基数
		int i = l, j = r;//双指针交换
		int tmp;
		while (i < j) {
			//注意这边先走的应该时远离基数的那一边
			while (arr[j] >= base && i < j)j--;
			while (arr[i] <= base && i < j)i++;
			if (i < j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}

		}
		//这时候 ij都同时指向小的那一边的最左边。与交换基数即可
		arr[l] = arr[i];
		arr[i] = base;
		//开始递归
		quicksort(l, i - 1, arr);
		quicksort(i + 1, r, arr);
	} 

    //桶排序
    vector<int> heapsort(vector<int> arr){
        int len=arr.size();
        //建立最大堆
        for(int i=len/2;i>=0;i--){
            heapify(arr,i,len);
        }

        //交换头尾，并且重新维护堆
        for(int i=len-1;i>0;i--){
            int tmp=arr[0];
            arr[0]=arr[i];arr[i]=tmp;
            len--;
            heapify(arr,0,len);
        }
        return arr;
    }
    //桶排序维护函数，维护根结点为i的堆
    void heapify(vector<int>& arr, int i,int len){
        int left=2*i+1;
        int right=2*i+2;
        int bigindex=i;
        if(left<len && arr[left]>arr[bigindex])bigindex=left;
        if(right<len && arr[right]>arr[bigindex])bigindex=right;
        if(bigindex!=i){
            int tmp=arr[i];
            arr[i]=arr[bigindex];arr[bigindex]=tmp;
            //这时bigindex指向的是被换下来的数字，
            //这个数字有可能很小，所以要继续往下比较。
            heapify(arr,bigindex,len);
        }
    }
    //希尔排序
    vector<int> shellsort(vector<int> arr){
        int gap=arr.size()/2;

        while(gap>0){
            for(int i=gap;i<arr.size();i++){
                //取arr[i]这个值，往前插，只不过间隔是gap
                //-gap就是前一个元素，+gap就是后一个元素
                int tmp=arr[i];
                int j=i-gap;
                while(j>=0 && arr[j]>tmp){
                    arr[j+gap]=arr[j];
                    j-=gap;
                }
                arr[j+gap]=tmp;
            }
            gap=gap/2;
        }

        return arr;
    }
    //插入排序
    vector<int> insertsort(vector<int> arr){
        for(int i=1;i<arr.size();i++){
            int tmp=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>tmp){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=tmp;
        }
        return arr;
    }
    //桶排序
    vector<int> bucketsort(vector<int> arr,int buckSize){
        if(arr.size()==0)return arr;
        int minval=arr[0];
        int maxval=arr[0];
        for(int val:arr){
            if(val<minval)minval=val;
            else if(val>maxval)maxval=val;
        }
        //准备多少个桶子
        int bucketCount=(maxval-minval)/buckSize+1;
        vector<vector<int>> buckets(bucketCount);

        //把所有数映射到桶中
        for(int e:arr){
            int index=(e-minval)/buckSize;
            buckets[index].push_back(e);
        }

        //对桶中元素进行排序，并安排回arr
        int arri=0;
        for(auto buck:buckets){
            if(buck.size()==0)continue;
            buck=insertsort(buck);
            for(int e:buck){
                arr[arri++]=e;
            }
        }

        return arr;
        
    }

};

int main(int argc, char const *argv[])
{
    
    mysort out;

    out.Solution();

   
    
    
    return 0;
}
