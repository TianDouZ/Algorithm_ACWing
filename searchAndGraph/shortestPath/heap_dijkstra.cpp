#include <cstring>
#include <iostream>
#include <algorithm> 
#include <queue>

using namespace std;

/*
    堆优化的dijkstra算法： O(mlogm)
        把查找最近点的过程优化成堆（C++用priority_queue即可实现）。  这一步的时间复杂度为O(1)xn=O(n)
        插入元素的时间复杂度变为mlogm
*/

typedef pair<int,int> PII;  //堆里面存的是pair，维护距离需要知道节点编号

const int N=150010,M=150010;

int n,m;
int h[N],w[M],e[M],ne[M],idx;  //邻接表存稀疏图,w[N]存的是权重
int dist[N]; //表示每个点距离第一个点的当前最短路径
bool st[N]; //表示每个点的最短路是否已经确定

void add(int a,int b,int c) {
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra() {
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    priority_queue<PII,vector<PII>,greater<PII>> heap;  //小根堆
    heap.push({0,1});  //heap初始化，把距离为0的一号点放进去
    
    while(heap.size()) {  //priority_queue里面最多只有m个元素，因为我们只有m个边
        auto t=heap.top();  //拿出顶，就是最小的元素
        heap.pop();
        
        int ver=t.second,distance=t.first;   //ver表示编号，distance表示距离
        if(st[ver]) continue;  //如果ver已经确定过了，说明当前点是冗余备份，直接continue即可
        st[ver] = true;
        
        //用当前点来更新其它数据
        for(int i=h[ver];i!=-1;i=ne[i]) {
            int j=e[i];
            if(dist[j]>distance+w[i]) {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});  //更新之后把新的点放到priority_queue里面
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return -1;  //dist[n]是正无穷，说明从起点不能到n这个点，return -1即可。
    return dist[n];
    
}

int main() {
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h); //初始化邻接表，把每个表头都初始化为-1
    
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);  //读入m条边
        add(a,b,c);
    }
    
    int t=dijkstra();
    
    printf("%d\n",t);
    
    return 0;
}