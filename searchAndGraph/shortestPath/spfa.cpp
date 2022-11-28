#include <cstring>
#include <iostream>
#include <algorithm> 
#include <queue>

using namespace std;

const int N=150010;

int n,m;
int h[N],w[N],e[N],ne[N],idx;  //邻接表存稀疏图,w[N]存的是权重
int dist[N]; //表示每个点距离第一个点的当前最短路径
bool st[N]; //存当前的点是否在队列当中，防止队列中存重复点

void add(int a,int b,int c) {
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa() {
    //初始化
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    queue<int> q;  //建立一个队列存待更新其他点的点
    q.push(1);
    
    while(q.size()) {
        int t=q.front();
        q.pop();
        
        st[t]=false;
        
        for(int i=h[t];i!=-1;i=ne[i]) {
            int j=e[i];
            if(dist[j]>dist[t]+w[i]) {
                dist[j]=dist[t]+w[i];
                if(!st[j]) {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    
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
    
    int t=spfa();
    
    if(t==0x3f3f3f3f) puts("impossible");
    else printf("%d\n",t);
    
    return 0;
}