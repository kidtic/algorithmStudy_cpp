//钢条切割问题
//假定我们知道某公司出售一段长度为i英寸的钢条的价格为p[i](i=1,2,3….)
//现在先给一段长度为n的钢条，问怎么切割，获得的收益最大 rn?

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>


using namespace std;

class steelbar_cut
{
private:
    /* data */
public:
    int solution(vector<int> pri,int n){
        pri.push_back(0);
        vector<int> r(n + 1, INT_MIN);
        r[0] = 0;
        for (int j = 1; j <= n; j++)
        {
            int q = INT_MIN;
            int size=pri.size();
            for (int i = 1; i <= min(j, size); i++)// i<=j      改为       i <= min(j,price.size)
                q = max(q, pri[i] + r[j - i]);
            r[j] = q;
        }
        return r[n];
    };

};


int main(int argc, char const *argv[])
{
    printf("hello world\n");
    steelbar_cut out;
    vector<int> pricetab{ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30,34,36,39,48,50,66,71,72,73,77,77,79 };
    for(int i=0;i<50;i++){
        int res=out.solution(pricetab,13525206+i);
        cout<<i<<":"<<res<<endl;
    }
    
    
    return 0;
}



