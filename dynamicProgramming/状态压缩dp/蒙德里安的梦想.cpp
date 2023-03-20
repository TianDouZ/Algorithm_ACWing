#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>  //存储所有做法状态

using namespace std;

typedef long long LL;

const int N=12,M=1<<N;   //M=2^N  N多开一列因为最后棋盘会多处理一列
int n,m;
LL f[N][M];
vector<int> state[M];   
//vector存的是所有合法状态，对遂于每个状态而言是一个数组，所有能转移到它的合法状态有哪些，预处理一下
bool st[M];  //判断当前列是否能用1x2的小方格填满，即当前列所有连续空着的小方格是否均为偶数


int main() {
    //预处理
    while(cin>>n>>m,n||m) {
        //预处理st数组
        for(int i=0;i<(1<<n);i++) {  //枚举每一种状态
            int cnt=0;  //0的个数
            bool is_vaild=true;   //is_vaild表示是否合法，最开始定义为true
            for(int j=0;j<n;j++) {  //每一列n个数
                if(i>>j&1) {  //如果当前位是1
                    if(cnt&1) {
                        is_vaild=false;  //不合法
                        break;
                    }
                    cnt=0;  //清空cnt
                } else cnt++;
            }
            if(cnt&1) is_vaild=false;   //判断最后一段0，如果最后一段0是奇数个也违法
            st[i]=is_vaild;
        }
        
        //枚举所有合法状态
        for(int i=0;i<1<<n;i++) {
            state[i].clear();
            //枚举所有方案
            for(int j=0;j<1<<n;j++) {
                if((i&j)==0 && st[i|j]) state[i].push_back(j);
            }
        }
        
        memset(f,0,sizeof f); //初始化，清空所有状态
        f[0][0]=1;  //表示空棋盘有一种方案 f[0][其它]均为0
        for(int i=1;i<=m;i++) {  //每一列共m列
            for(int j=0;j<1<<n;j++) {  //枚举每一种状态
                for(auto k:state[j]) {  //枚举每一种合法状态
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;  //f[m][0]表示前m-1列已经摆好，且第m-1列延伸到第m列的状态为0
    }
    
    return 0;
}