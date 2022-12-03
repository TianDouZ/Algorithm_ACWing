#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010, M=200010;

int n,m;
int h[N],e[M],ne[M],idx;
int color[N];

void add(int a,int b) {
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

/*
    染色法：
        for循环遍历所有点
            if(i未被染色)
                dfs(i,1),深搜把i的连通块都染一遍
    
*/

bool dfs(int u,int c) {
    color[u]=c;  //记录一下当前点的颜色染成了c
    
    for(int i=h[u];i!=-1;i=ne[i]) {  //遍历这个点的所有邻点
        int j=e[i];
        if(!color[j]) {  //color没被染色
            if(!dfs(j,3-c)) return false;   //3-c可以把1改成2，把2改成1
        } 
        else if(color[j]==c) return false;   //color被染色了，且染色的颜色和u当前的颜色相同，那就说明矛盾了，return false。
    }
    
    return true;
}

int main() {
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h);
    
    while(m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b), add(b,a);
    }
    
    bool flag=true;  //记录染色过程中是否有矛盾发生
    for(int i=1;i<=n;i++) {  //遍历所有点
        if(!color[i]) {
            if(!dfs(i,1)) {
                flag=false;
                break;
            }
        }
    }
    
    if(flag) puts("Yes");
    else puts("No");
    
    return 0;
}