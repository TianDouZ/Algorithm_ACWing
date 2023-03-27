/*
    时间复杂度O(n) 2n个状态，计算每个状态要算它的儿子，即边的数量n-1
*/
#include <cstring> //有memset
#include <iostream>
#include <algorithm>

using namespace std;

const int N=6010;

int n;
int happy[N];
int h[N],e[N],ne[N],idx;  //邻接表存图
int f[N][2];  //所有状态
bool has_father[N];

void add(int a,int b) {
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u) {
    f[u][1]=happy[u];  //选择u就要加上u的快乐值
    //枚举u的所有儿子
    for(int i=h[u];i!=-1;i=ne[i]) {
        int j=e[i];  //j表示u的每个儿子
        dfs(j);
        
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&happy[i]);
    
    memset(h,-1,sizeof h);  //把所有的表头初始化成-1
    
    //求根节点-----没有父节点的点
    for(int i=0;i<n-1;i++) {   //读入n-1条边
        int a,b;
        scanf("%d%d",&a,&b); //表示b是a的父节点
        has_father[a]=true;
        add(b,a);
    }
    //求根节点
    int root=1;
    while(has_father[root]) root++;
    
    dfs(root);
    
    printf("%d\n",max(f[root][0],f[root][1]));
    
    return 0;
}
