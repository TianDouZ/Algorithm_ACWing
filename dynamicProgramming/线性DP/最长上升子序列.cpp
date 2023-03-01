#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n;
int a[N],f[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++) {
        f[i]=1;  //只有a[i]一个数满足要求，即以a[i]结尾的上升子序列的长度为1
        for(int j=1;j<i;j++) {  //枚举a[i]前面的每一个数
            if(a[j]<a[i]) {
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,f[i]);
    printf("%d\n",res);
    
    return 0;
}

/*
    存储最长上升子序列
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010;

int n;
int a[N],f[N],g[N];  //g[N]用来存储每个转移是怎么做出来的

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++) {
        f[i]=1;  //只有a[i]一个数满足要求，即以a[i]结尾的上升子序列的长度为1
        g[i]=0; 
        for(int j=1;j<i;j++) {  //枚举a[i]前面的每一个数
            if(a[j]<a[i]) {
                if(f[i]<f[j]+1) {
                    f[i]=f[j]+1;
                    g[i]=j;  //类似于并查集
                }
            }
        }
    }
    
    int k=1;  //用来记录最优解的下标
    for(int i=1;i<=n;i++) {
        if(f[k]<f[i]) k=i;
    }
    printf("%d\n",f[k]);
    
    //根据g数组倒推最长上升子序列,逆序输出
    for(int i=0,len=f[k];i<len;i++) {
        printf("%d ",a[k]);
        k=g[k];
    }
    
    return 0;
}