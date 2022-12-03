#include <iostream>
#include <algorithm>

using namespace std;

const int N=200010,INF = 0x3f3f3f3f;  //N开的是边数

int n,m;
int p[N]; //并查集里面的p，p[x]里面存的是x的父亲，如果p[x]的父亲就是他自己，那说明他是祖宗

struct Edge {
    int a,b,w;
    
    //重载小于号，方便按照权重排序
    bool operator< (const Edge &W)const {
        return w<W.w;
    }
}edges[N];

int find(int x) {
    if(p[x]!=x) p[x]=find(p[x]);  //如果x的祖宗节点不是p[x],就找到p[x]的祖宗赋值给p[x];
    return p[x];
}

int kruskal() {
    sort(edges,edges+m);  //排序所有边
    //初始化并查集
    for(int i=1;i<=n;i++) p[i]=i;
    
    int res=0,cnt=0;  //res存的是最小生成树中所有的树边之和，cnt存的是当前加了多少条边；
    //从小到大枚举所有边
    for(int i=0;i<m;i++) {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        
        a=find(a),b=find(b);  //把a的祖宗节点赋值给a，b的祖宗节点赋值给b
        
        if(a!=b) { //如果两个祖宗节点不联通
            p[a]=b;  //合并两个并查集
            res+=w;
            cnt++;
        }
    }
    
    if(cnt<n-1) return INF;
    return res;
}

int main() {
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++) {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }

    int t=kruskal();
    
    if(t==INF) puts("impossible");
    else printf("%d\n",t);
    
    return 0;
}
