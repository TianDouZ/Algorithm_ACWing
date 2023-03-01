/*
    方法一：从上往下dp，需要考虑边界问题，初始化的时候每一列的左右两侧也需要一同初始化成-INF才符合负数存在的情况。
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=510,INF=1e9;

int n;
int a[N][N];  //a存储三角形的每一个数字
int f[N][N];  //f存储状态,表示到达该数字的最大的数字和

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
           scanf("%d",&a[i][j]); 
        }
    }
    
    //初始化，把所有的状态初始化成负无穷
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i+1;j++) {//注意这里考虑边界 两边也要初始化一下
            f[i][j]=-INF;
        }
    }
    /*
    也可以用memset，但是头文件要加上cstring
    memset(f,-0x3f,sizeof f);
    */

   /*
    memset 是 cstring 里的函数，用于填充 char 型数组。对于数值型数组只能初始化为 0 或 -1。
    memset 是按字节填充
   */
    
    f[1][1]=a[1][1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            f[i][j]=max(f[i-1][j-1]+a[i][j],f[i-1][j]+a[i][j]);
         }
    }
    
    int res=-INF;
    for(int i=1;i<=n;i++) {
        res=max(res,f[n][i]);
    }
    
    printf("%d\n",res);
    return 0;
    
    
}


/*
    自下而上的dp，不需要考虑边界问题
    代码简化后
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=510;

int n;
//int w[N][N]；  //将w和f简化为一个数组即可
int f[N][N];  

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>f[i][j]; //直接读到f中
        }
    }
    
    //for(int i=1;i<=n;i++) f[n][i]=w[n][i];
    for(int i=n-1;i;i--) {
        for(int j=1;j<=i;j++) {
            //f[i][j]=max(f[i+1][j],f[i+1][j+1])+w[i][j];
            f[i][j]+=max(f[i+1][j],f[i+1][j+1]);
        }
    }
    
    cout<<f[1][1];
    
    return 0;
}