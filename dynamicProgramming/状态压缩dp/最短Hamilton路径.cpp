#include <cstring>  //memset在里面
#include <iostream>
#include <algorithm>

using namespace std;

const int N=20,M=1<<N;

int n;
int w[N][N];  //存路径的长度
int f[M][N];  //存dp的状态

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>w[i][j];
        }
    }
    
    //初始化
    memset(f,0x3f,sizeof f);  //全部初始化为正无穷
    f[1][0]=0;  //从0走到0的路径长度是0，只有第0个点的状态是1其余位都是0。
    for(int i=0;i<1<<n;i++) {  
        for(int j=0;j<n;j++) { //枚举i、j所有状态
            
            //如果从0走到j，那么i里面一定要包含走过j的状态，即i的第j位为1
            if(i>>j & 1) {
                for(int k=0;k<n;k++) {  //枚举转移的状态，枚举从哪个点转移到j
                    //如果从第k个点转移到第j个点，那么i除去第j个点之后的状态中必然含有k
                    //即使 (i-(1<<j)) >>k & 1 为1
                    if((i-(1<<j)) >> k & 1)  f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
                }
            }
            
        }
    }
    cout<<f[(1<<n)-1][n-1]<<endl;  //(1<<n)-1 表示n位均为1
    
    return 0;
}