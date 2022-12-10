/*
    二维实现：
        不用枚举k
        f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]);
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
    for(int i=1;i<=n;i++) {  //枚举物品
        for(int j=0;j<=m;j++) {  //枚举体积
            f[i][j]=f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    }
    
    cout<<f[n][m]<<endl;
    
    return 0;
}