#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;  //int的数值范围是20亿

const int N=100010;

int n;
int t[N];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&t[i]);
    
    sort(t,t+n);
    
    ll res=0;
    for(int i=0;i<n;i++) res+=t[i]*(n-i-1);
    
    printf("%lld\n",res);
    
    return 0;
}