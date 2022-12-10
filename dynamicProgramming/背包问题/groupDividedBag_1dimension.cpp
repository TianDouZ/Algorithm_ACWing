/*
    直接写的一维的：
        f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=110;

int n,m;
int v[N][N],w[N][N],s[N];  //s[N]用来存每一组的物体个数
int f[N];   //分组背包也可以从二维优化成一维，直接写一维


//状态转移用的是上一层的就从大到小枚举体积，用的是本层的就从小到大枚举体积
int main() {
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        for(int j=0;j<s[i];j++) {
            cin>>v[i][j]>>w[i][j];
        }
    }
    
    for(int i=1;i<=n;i++) {  //从前往后枚举每一组
        for(int j=m;j>=0;j--) {  //从大到小枚举所有体积
            for(int k=0;k<s[i];k++) {  //枚举所有选择
                if(v[i][k]<=j)  f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
            
        }
    }
    
    cout<<f[m]<<endl;
    
    return 0;
}