/*
    状态 O(n^2)
    转移 O(1)×3

    时间复杂度 O(n^2)

    当属性是最大值/最小值时，状态划分可以重复，如果属性是数量，状态划分不可以重复
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n,m;
char a[N],b[N];  //a和b表示两个字符串
int f[N][N];  //状态

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s%s",a+1,b+1);  
    //因为状态表示中有i-1,所以下标最好从1开始，故最初读入字符串时直接读入a+1和b+1的位置
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    }
    
    printf("%d\n",f[n][m]);
    
    return 0; 
    
}