/*
    方法一：和全排列一样的思路 O（n*n!）
*/
#include <iostream>

using namespace std;

const int N=20;  //开二倍，因为对角线有2n-1条

int n;
char g[N][N];  //用char来记方案
bool col[N],dg[N],udg[N]; //同一列、正对角线、反对角线

void dfs(int u) {
    
    if(u==n) {
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    
    for(int i=0;i<n;i++) {
        if(!col[i] && !dg[u+i] && !udg[n-u+i]) {  //第i列没有，正对角线、反对角线上都没有
        
            g[u][i]='Q'; 
            col[i]=dg[u+i]=udg[n-u+i]=true; //标记一下都有了
            
            dfs(u+1);
            
            //恢复现场,上下完全对称
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.'; 
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            g[i][j]='.';   //先把每一块都设置成空地
        }
    }
    
    dfs(0);
    
    return 0;
}

/*
    方法二：O（2^(n^2)）
        挨个格子遍历，数形遍历
                   o
                放  不放
              o          o
           放  不放   放  不放
*/
#include <iostream>

using namespace std;

const int N=20;  //开二倍，因为对角线有2n-1条

int n;
char g[N][N];  //用char来记方案
bool row[N],col[N],dg[N],udg[N]; //同一行、列、正对角线、反对角线

void dfs(int x,int y,int s) {  //搜索坐标是(x,y)的格子，当前有s个皇后
    if(y==n) y=0,x++;  //从左到右依次遍历，遍历到最后一列换行，y重置为0
    
    if(x==n) {//遍历到最后一行
        if(s==n) { //当前n个皇后全摆完了，输出
            for(int i=0;i<n;i++) puts(g[i]);
            puts("");
        }
        return;
    }
    
    //不放皇后
    dfs(x,y+1,s);
    
    //放皇后
    if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[x-y+n]) {//同一行同一列两条对角线上都没有皇后
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
        
        dfs(x,y+1,s+1);
        
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false; //恢复现场
        g[x][y]='.';
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            g[i][j]='.'; 
        }
    }
    
    dfs(0,0,0);
    
    return 0;
}