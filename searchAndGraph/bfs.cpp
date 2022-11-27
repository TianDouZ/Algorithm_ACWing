/*
    BFS带路径输出
*/

#include <cstring>
#include <iostream>
#include <algorithm>
//#include <queue> 也可以直接手写队列

using namespace std;

typedef pair<int,int> PII;

const int N =110;

int n,m;
int g[N][N]; //存的是地图
int d[N][N]; //存的是每一个点到起点的距离
PII q[N*N],Prev[N][N];  //Prev记录前一个点是哪个点，q用来模拟队列

int bfs() {
    int hh=0,tt=0;  //队头hh，队尾tt。
    q[0]={0,0};
    
    memset(d,-1,sizeof d); //把所有点的距离初始化为-1，表示所有的点都没有走过
    d[0][0]=0;  //表示这个点已经走过了
    
    int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};  //代表往四个方向走
    
    while(hh<=tt) { //队列不为空
        auto t=q[hh++];  //取出队头
        
        for(int i=0;i<4;i++) { 
            
            int x=t.first+dx[i], y=t.second+dy[i];  //走完之后的x,y
            if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0 && d[x][y]==-1) { //在范围内，为0且没有走过
                d[x][y]=d[t.first][t.second]+1;  //比原来的数多加1（下一层）
                Prev[x][y]=t;  //(x,y)的前一个点是t，即(x,y)是从t这个点过来的
                q[++tt]={x,y}; //把之后的(x,y)加入队列
                
            }
        }
    }
    int x=n-1,y=m-1; //输出路径，从后往前倒
    while(x||y) {
        cout<<x<<' '<<y<<endl;
        auto t=Prev[x][y];
        x=t.first,y=t.second;
    }
    return d[n-1][m-1];
}

int main() {
    cin>>n>>m;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
        }
    }
    
    cout<<bfs()<<endl;
    
    return 0;
}