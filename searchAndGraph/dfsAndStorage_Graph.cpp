#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010,M=N*2;

int n;
int h[N],e[M],ne[M],idx; 
//h[N]是每个单链表的头节点,e[M]是每个节点的值（顶点）,ne[M]是每个节点的next指针指向哪（边）,idx是e和ne用到哪了; 
/*
    节点的下标指节点在数组中的位置索引，数组之间的关系就是通过下标来建立连接，下标用idx来记录。idx范围从0开始，如果idx==-1表示空。

    e[i]的值是编号，是下标为i节点的编号。
    ne[i]的值是下标，是下标为i的节点的next节点的下标。
    
    h[i]存储的是下标，是编号为i的节点的next节点的下标，比如编号为1的节点的下一个节点是4，那么我输出e[h[1]]就是4。
*/
bool st[N];  //记录哪些值被遍历过

int ans=N;  //全局的答案存的就是最小的最大值


void add(int a,int b) {  //插入一条边（头插）：在a所对应的邻接表里插入一个节点b
    e[idx]=b;
    ne[idx]=h[a]; //新加入的b的next指向原来的h[a];
    h[a]=idx++;
    //e记录当前点的值(地址->值),ne下一点的地址(地址->地址)，h记录指向的第一个点的地址(值->地址)
}

//返回的是以u为根的子树中点的数量
int dfs(int u) {  //u表示当前在遍历的点
    st[u]=true;  //标记一下这个点已经被搜索过了
    
    int sum=1,res=0;  //res存的是把这个块删掉后每个连通块的点数量的最大值
    for(int i=h[u];i!=-1;i=ne[i]) {
        int j=e[i];
        if(!st[j]) {
            int s = dfs(j);  //没搜索过就搜索j
            res = max(res,s);
            sum+=s;
        }
    }
    
    res=max(res,n-sum);  //上面剩下的那一坨
    
    ans=min(ans,res);
    
    return sum;
}


int main() {
    cin>>n;
    memset(h,-1,sizeof h); //把所有的头全初始化成-1
    
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        add(a,b), add(b,a);
    }
    
    dfs(1);
    
    cout<<ans<<endl;
    
    return 0;
}