#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;

int n,m;
int h[N],e[N],ne[N],idx;
int q[N],d[N];  //d存的是入度

void add(int a,int b) {
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool topsort() {
    int hh=0,tt=-1;  //注意这里tt要初始化成-1，如果没有入度为0的点就不用放到队列里
    
    for(int i=1;i<=n;i++) {
        if(!d[i]) {  //如果i的入度是0吗，加到队列中
            q[++tt]=i;  
        }
    }
    
    while(hh<=tt) {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]) {
            int j=e[i]; //找到出边
            d[j]--;
            if(d[j]==0) q[++tt]=j;
        }
    }
    
    return tt==n-1;  
    //tt==n-1,说明n个点均入队了，说明其是有向无环图，存在拓扑序，出队的顺序就是拓扑序（最后数组模拟的队列里面的次序就是拓扑序）
}

int main() {
    cin>>n>>m;
    
    memset(h,-1,sizeof h);
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    
    if(topsort()) {
        for(int i=0;i<n;i++) printf("%d ",q[i]);
    }
    else puts("-1");
    
    return 0;
}