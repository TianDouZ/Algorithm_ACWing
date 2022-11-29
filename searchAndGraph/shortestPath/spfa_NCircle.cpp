#include <cstring>
#include <iostream>
#include <algorithm> 
#include <queue>

using namespace std;

const int N=150010;

int n,m;
int h[N],w[N],e[N],ne[N],idx;  //邻接表存稀疏图,w[N]存的是权重
int dist[N],cnt[N]; //dist表示每个点距离第一个点的当前最短路径,cnt表示到x最短路径经历的边数
bool st[N]; //存当前的点是否在队列当中，防止队列中存重复点

void add(int a,int b,int c) {
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa() {
    //不需要初始化了，因为我们求的是有没有负环，不需要距离的绝对值
    //memset(dist,0x3f,sizeof dist);
    //dist[1]=0;
    
    queue<int> q;  //建立一个队列存待更新其他点的点
    //q.push(1);
    
    //判断负环需要把所有点都放到队列里面挨个找，因为负环可能从第一个点开始走不到
    for(int i=1;i<=n;i++) {
        st[i]=true;
        q.push(i);
    }
    
    while(q.size()) {
        int t=q.front();
        q.pop();
        
        st[t]=false;
        
        for(int i=h[t];i!=-1;i=ne[i]) {
            int j=e[i];
            if(dist[j]>dist[t]+w[i]) {
                dist[j]=dist[t]+w[i];
                cnt[j]=cnt[t]+1;
                
                if(cnt[j]>=n) return true;
                
                if(!st[j]) {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h); //初始化邻接表，把每个表头都初始化为-1
    
    while(m--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);  //读入m条边
        add(a,b,c);
    }
    
    if(spfa()) puts("Yes");
    else puts("No");
    
    return 0;
}