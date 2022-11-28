#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

/*
    步骤:
        迭代n次（实际意义是不超过n条边）
        for(int i=0;i<n;i++) {
            memcpy(backup,dist,sizeof dist);  //求不超过条边每次循环前先把dist备份一下,backup里面存的是上一次迭代的结果，防止串联
            for 所有边a,b,w
                dist[b]=min(dist[b],backup[a]+w);  //用上一次迭代的结果来更新当前的距离
        }
*/

const int N=510, M=10010;

int n,m,k;
int dist[N],backup[N];

struct Edge{
    int a,b,w;
}edges[M];

void bellman_ford() {
    
    //初始化
    memset(dist,0x3f,sizeof dist);  
    dist[1]=0;
    
    for(int i=0;i<k;i++) {//迭代k次，最多经过4条边
    
        memcpy(backup,dist,sizeof dist);  //每次循环前先把dist备份一下,backup里面存的是上一次迭代的结果
        //以dist指向的地址为起点，将连续的sizeof个字节数据，复制到以backup指向的地址为起点的内存中。
        /*
        在内层循环当中要保证当前遍历到的边的终点被更新至最短距离（如果可以）之后就停止将该点作为接下来遍历的边的始点更新其终点的最短距离
        
        每次迭代，是从当前状态每个节点距离d[i] = min(d[i],last[j] + g[j][i])试图添加“一条”路径，来得到k步以内的最短距离，每次迭代只向前迈一步。
        第k次迭代，是从第k-1步的状态，转移向k步状态。
        而串联指的是，在第k次迭代中途，d[]中部分数据已经发生了迭代，得到的结果是k条边的最短路径，
        在后续中再次对其判断迭代后，得到了k+1条边时才能得到的距离，在一次迭代中添加了多条边。
        
        对于获得最短路径的最终状态来说，串联没有影响。
        而对于有边数限制的最短路来说，串联会导致得到的结果是不符合要求的，超过边数限制的最短路。
        */
        for(int j=0;j<m;j++) {
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);  //用上一次迭代的结果来更新当前的距离
        }
    }

}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=0;i<m;i++) {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    
    bellman_ford();
    
    if(dist[n]>0x3f3f3f3f/2) puts("impossible");
    //前一个节点的正无穷会更新后一个节点的正无穷，如果是负权边，最后一个节点可能到不了0x3f3f3f3f，但是也是一个很大的
    else printf("%d\n",dist[n]);
    
    return 0;
}