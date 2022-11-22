#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        
        int res= 0;
        while(x) x-=lowbit(x),res++;  
        //当x不为0的时候，每次减去x的最后一位1，减了多少次就有多少个1
        
        cout<<res<<' ';
    }
    
    return 0;
}