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