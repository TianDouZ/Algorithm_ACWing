#include <cstring>
#include <iostream>
#include <algorithm> 

using namespace std;

/*
    Dijkstra步骤：O(n^2)
        1.初始化距离，dist[1]=0,其它初始化为0x3f；
        2.循环n次 
            for(int i=0;i<n;i++) {               n
                t=不在st中的，距起始点最近的点    n
                st[t]=true;
                遍历全部点，用t更新其它点。       n
            }
*/

const int N=510;

int n,m;
int g[N][N];  //邻接矩阵，稠密图用邻接矩阵存
int dist[N]; //表示每个点距离第一个点的当前最短路径
bool st[N]; //表示每个点的最短路是否已经确定

int dijkstra() {
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    for(int i=0;i<n;i++) {  //遍历n次
        int t=-1; //表示还没取的点
        for(int j=1;j<=n;j++) {  //遍历所有点
            //如果j的最短路没确定，并且这点没取过或者当前的距离不是最短的(不是下一个点)
            if(!st[j]&&(t==-1 || dist[t]>dist[j]))  t=j;  //找所有st=false的点中，dist最小的点
            if(t==n) break;  //这是一步优化，可有可无
        }
        
        st[t]=true;
        
        for(int j=1;j<=n;j++) { //用t更新一下每个点的距离
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    
    if(dist[n]==0x3f3f3f3f) return -1;  //dist[n]是正无穷，说明从起点不能到n这个点，return -1即可。
    return dist[n];
    
}

int main() {
    scanf("%d%d",&n,&m);
    
    memset(g,0x3f,sizeof g); //初始化
    
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);  //读入m条边
        g[a][b]=min(g[a][b],c); //有重边，在最短路算法中保留权重最小的边即可
    }
    
    int t=dijkstra();
    
    printf("%d\n",t);
    
    return 0;
}