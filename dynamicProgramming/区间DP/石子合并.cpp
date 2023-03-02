/*
    石子合并：
    状态 O(N^2)
    转移 枚举k O(n)
    时间复杂度 O(N^3)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=310;

int n;
int s[N];  //前缀和
int f[N][N]; //状态

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    
    //处理前缀和
    for(int i=1;i<=n;i++) s[i]+=s[i-1];

    /*
        区间dp：
            先循环区间长度
            再循环区间左端点
            最后循环决策
    */
    
    //按照长度从小到大枚举所有状态
    for(int len=2;len<=n;len++) {  
    //区间长度可以从2开始枚举，如果区间长度是1则只有一堆，合并代价为0，f是全局数组，默认都是0
        for(int i=1;i+len-1<=n;i++) {  //枚举起点
            int l=i,r=i+len-1;
            f[l][r]=1e8;  //先将f[l][r]初始化为比较大的数再比较取min
            for(int k=l;k<r;k++) {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    
    printf("%d\n",f[1][n]);
    
    return 0;
    
}


/*
    编辑距离：多次套最短编辑距离DP
    
    询问次数:10^3个x10^3=10^6
    编辑距离：O(n^3)
    时间复杂度 O(n^8)   10^8

    C++ 10^7~10^8/s
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N=15,M=1010;

int n,m;
int f[N][N];
char str[M][N];  //存放字符串，M个字符串每个字符串不超过N个字符

int edit_distance(char a[],char b[]) {
    int la=strlen(a+1),lb=strlen(b+1);  //求两个字符串的长度
    
    for(int i=0;i<=lb;i++) f[0][i]=i;
    for(int i=0;i<=la;i++) f[i][0]=i;
    
    
    for(int i=1;i<=la;i++) {
        for(int j=1;j<=lb;j++) {
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            f[i][j]=min(f[i][j],f[i-1][j-1]+(a[i]!=b[j]));
        }
    }
    
    return f[la][lb];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]+1);  //编辑距离，下标从1开始存
    
    while(m--) {
        char s[N];
        int limit;
        scanf("%s%d",s+1,&limit);
        
        int res=0;
        for(int i=0;i<n;i++) {
            if(edit_distance(str[i],s)<=limit) res++;
        }
        printf("%d\n",res);
    }
    
    return 0;
}