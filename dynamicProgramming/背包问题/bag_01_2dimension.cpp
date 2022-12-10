/*
    二维表示
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n,m;  //n表示物品个数，m表示背包容量
int v[N],w[N];  //v表示体积，w表示价值
int f[N][N];  //表示所有的状态

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    
    //初始化，枚举所有状态
    //f[0][0~m]=0;  定义成全局变量了，默认就是0，从前0个物品里面选体积不超过0~m的最大值都是0
    
    for(int i=1;i<=n;i++) {//枚举个数
        for(int j=0;j<=m;j++) {//枚举体积
            f[i][j]=f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    
    cout<<f[n][m]<<endl;
    
    return 0;
}