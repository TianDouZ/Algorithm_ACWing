/*
    二进制优化  -->  把s分组，转换成用0-1背包解决问题
    O(m*n*logs)
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N=12010,M=2010;   //物品个数最多是1000*1og2000

int n,m;
int v[N],w[N];
int f[M];  //0-1背包可以用一维优化，直接写一维了

int main() {
    cin>>n>>m;
    
    int cnt=0;// 存储新的物品的组数
    for(int i=1;i<=n;i++) {
        int a,b,s;  //第i个物品的体积、价值、数量
        cin>>a>>b>>s;
        int k=1;
        
        //分组
        while(k<=s) {
            cnt++;  //组数+1
            v[cnt]=a*k;  //该组物品的体积
            w[cnt]=b*k;  //该组物品的价值
            s-=k;  //待分组数量减少
            k*=2;  //下一组个数增加
        }
        if(s>0) {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }
    
    n=cnt;   //把n更新成cnt
    
    //0-1背包
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=v[i];j--) {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    
    cout<<f[m]<<endl;
    
    return 0;
}