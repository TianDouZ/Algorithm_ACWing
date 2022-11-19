#include <iostream> 

using namespace std;

const int N=100010;

int n,m;
int a[N],s[N];
/*
    前缀和：用来数组中计算一段数字的和
    公式: 
        预处理S[i]=S[i-1]+a[i]，S[0]=0;
        sum[l,r]=s[r]-s[l-1]
*/
int main() {
    //ios::sync_with_stdio(false); //可以提高cin的读取速度，但是不能用scanf了，但是优化之后还是妹有scanf快
    
    //数据规模>=1000000 scanf，否则cin

    scanf("%d%d",&n,&m); //读取数的数量多的时候比cin快一倍
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]; //前缀和的初始化
    
    while(m--) {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);  //区间和的计算
    }
    
    return 0;
}