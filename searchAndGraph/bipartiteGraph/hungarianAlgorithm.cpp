#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int  N=510,M=100010;

int n1,n2,m;
int h[N],e[M],ne[M],idx; 
int match[N];  //记录右边的点对应的点
bool st[N];  //记录搜过没有，保证不要重复搜索点

void add(int a,int b) {
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x) {
    for(int i=h[x];i!=-1;i=ne[i]) {
        int j=e[i];
        if(!st[j]) {
            st[j]=true;
            if(match[j]==0 || find(match[j])) {  //妹子没找到，或者给妹子的现男友找到下一任了
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d",&n1,&n2,&m);
    
    memset(h,-1,sizeof h);
    
    while(m--) {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int res=0;
    for(int i=1;i<=n1;i++) {  //遍历左边的点
        memset(st,false,sizeof st);
        if(find(i)) res++;
    }
    
    printf("%d\n",res);
    
    return 0;
}