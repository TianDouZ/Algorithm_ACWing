#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=510,INF=0x3f3f3f3f;

int n,m;
int g[N][N];  //稠密图用邻接矩阵存
int dist[N];
int st[N];

/*
    与dijkstra很想，但是prim里面的集合指的是当前的生成树，即当前已经在连通块内的点的集合；
    具体过程为：
        1.先把dist[t]全部置为正无穷
        2.for(int i=0;i<n;i++) {//迭代n次
            t <-- 找到集合外距离集合最近的点
            
            结果累加: res+=dist[t];  //一定要先加再更新

            用t更新其它点到集合的距离:dist[j]=min(dist[j],g[t][j]);
            
            st[t]=true;

        }
*/

int prim() {
    memset(dist,0x3f,sizeof dist);
    
    int res=0;
    for(int i=0;i<n;i++) {
        int t=-1;
        for(int j=1;j<=n;j++) {
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t=j;
        }
        
        //如果不是第一个点，并且dist是正无穷，说明当前的点是不连通的，不存在最小生成树，直接return即可
        if(i&&dist[t]==INF) return INF;
        
        //只要不是第一个点，dist[t]表示的就是当前的点距离集合的最短距离，是一条树边，加到res里面
        if(i) res+=dist[t]; 
        
        /*
            用t更新其它点到集合的距离,不能先更新先更新会导致存在负的自环时，g[t][t]会把dist[j]变得更小,
            但是自环不应该加入最小生成树，更新后再加res就不行了，所以要先加在更新。
        */
        for(int j=1;j<=n;j++) dist[j]=min(dist[j],g[t][j]);  //g[t][j]是t加入集合后点j到集合的距离
        
        st[t]=true;
    }
    
    return res;
}

int main() {
    scanf("%d%d",&n,&m);
    
    memset(g,0x3f,sizeof g);
    
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    
    int t=prim();
    
    if(t==INF) puts("impossible");  //不连通不存在生成树
    else printf("%d\n",t);
    
    return 0;
}