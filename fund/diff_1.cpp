#include <iostream>

using namespace std;

const int N=100010;

int n,m;
int a[N],b[N];

//插入函数，把[l,r]区间的数都+c
void insert(int l,int r, int c) {
    b[l] += c;
    b[r+1] -= c;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++) insert(i,i,a[i]) ;  //构造差分数组
    
    while(m--) {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    
    for(int i=1;i<=n;i++) b[i]+=b[i-1];  
    //对差分数组求前缀和就是原数组，此处对b数组求前缀和把b再变成原数组
    
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    
    return 0;
}