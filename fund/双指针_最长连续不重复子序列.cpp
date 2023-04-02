/*
    O(n) 两个指针最多各走n次，O(2n)
*/
#include <iostream>

using namespace std;

const int N=100010;

int n;
int a[N],s[N];  //a[N]原来的数,s[N]当前j到i每个数出现的次数

int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    
    int res=0;
    for(int i=0,j=0;i<n;i++) {
        s[a[i]]++;
        while(s[a[i]]>1) {
            s[a[j]]--;
            j++;
        }
        
        res=max(res,i-j+1);
    }
    
    cout<<res<<endl;
    
    return 0;
}