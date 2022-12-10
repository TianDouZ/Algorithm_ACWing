/*
    三维实现：
        三重循环，暴力实现，和完全背包一样，加一个k<=s[i]的限制，复杂度高，最坏时间复杂度是O(n*v^2);
        f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+w[i]*k);
        O(m*n*s)
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int N=110;

int n,m;
int v[N],w[N],s[N];
int f[N][N];

int main() {
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];
    
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++) {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    
    cout<<f[n][m]<<endl;
    
    return 0;
}