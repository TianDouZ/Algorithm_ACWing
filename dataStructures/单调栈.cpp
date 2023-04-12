/*
    时间复杂度：
        O(n) 每个元素最多只会进栈、出栈一次
*/
#include <iostream>

using namespace std;

const int N=100010;

int n;
int stk[N],tt;

int main() {
    
    //ios::sync_with_stdio(false);  //这段语句可以来打消iostream的输入 输出缓存，可以节省许多时间
    //cin.tie(0);   用cout和cin加上这句就快了

    scanf("%d",&n);  //scanf printf比cin cout快很多
    
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        while(tt&&stk[tt]>=x) tt--;  
        if(tt) printf("%d ",stk[tt]);
        else printf("-1 ");
        
        stk[++tt]=x;
    }
    
    return 0;
}