#include <iostream>
#include <algorithm>

using namespace std;

const int N=310;

int n;
int s[N];  //前缀和
int f[N][N]; //状态

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    
    //处理前缀和
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    
    //按照长度从小到大枚举所有状态
    for(int len=2;len<=n;len++) {  
    //区间长度可以从2开始枚举，如果区间长度是1则只有一堆，合并代价为0，f是全局数组，默认都是0
        for(int i=1;i+len-1<=n;i++) {  //枚举起点
            int l=i,r=i+len-1;
            f[l][r]=1e8;  //先将f[l][r]初始化为比较大的数再比较取min
            for(int k=l;k<r;k++) {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    
    printf("%d\n",f[1][n]);
    
    return 0;
    
}