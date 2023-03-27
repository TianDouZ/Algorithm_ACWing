/*
    记忆化搜索优缺点：
        优点：代码复杂度低，思路简单
        缺点：时间复杂度比循环高一些，且递归层数多可能会爆栈
*/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=310;

int n,m;
int h[N][N];  //表示每个点的高度
int f[N][N];  //表示dp的状态

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int dp(int x,int y) {
    int &v=f[x][y];  //C++特性，这么写表示所有写v的地方等价于f[x][y]
    
    //判断一下v算过没有，算过了直接返回v即可
    if(v!=-1) return v;
    
    v=1; //初始化v=1，因为v最差可以走当前的格子，v最小为1
    for(int i=0;i<4;i++) {
        int a=x+dx[i],b=y+dy[i];
        if(a>=1&&a<=n&&b>=1&&b<=m&&h[a][b]<h[x][y]) 
            v=max(v,dp(a,b)+1);
    }
    
    return v;
}

int main() {
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d",&h[i][j]);
        }
    }
    
    memset(f,-1,sizeof f); //全部初始化为-1表示所有的状态都没有算过
    
    int res=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            res=max(res,dp(i,j)); 
            //dp(i,j)表示求出(i,j)开始的状态并返回，f(i,j)并没有求出来
        }
    }
    
    printf("%d\n",res);
    
    return 0;
}