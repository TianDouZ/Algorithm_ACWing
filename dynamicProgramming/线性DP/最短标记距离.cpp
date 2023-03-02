/*
    最短区间距离：
    状态 O(N^2)
    转移 3xO(1)
    时间复杂度 O(N^2)
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n,m;
char a[N],b[N];
int f[N][N];

int main() {
    scanf("%d%s",&n,a+1);
    scanf("%d%s",&m,b+1);
    
    //初始化，将A的前0个字符变成B的i个，则i是多少就添加多少次
    for(int i=0;i<=m;i++) f[0][i]=i;
    
    //初始化，将A的前i个字符与B的前0个字符匹配，只能用删除操作，i是多少就删除多少次
    for(int i=0;i<=n;i++) f[i][0]=i;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
            if(a[i]==b[j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
            else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
        }
    }
    
    printf("%d\n",f[n][m]);
    return 0;
}