/*
    三维实现：
        三重循环，复杂度高，最坏时间复杂度是O(n*v^2);
        f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n,m;
int v[N],w[N];
int f[N][N];

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    //枚举所有状态
    for(int i=1;i<=n;i++) {  //枚举物品O(n)
        for(int j=0;j<=m;j++) {  //枚举体积O(v)
            for(int k=0;k*v[i]<=j;k++) {  //枚举第i个物品的个数k，限制条件是k个i物品的体积不能超过背包容量
                //最坏v[i]=1,j=v,循环v次，O(v)
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
            }
        }
    }
    
    cout<<f[n][m]<<endl;
    
    return 0;
}