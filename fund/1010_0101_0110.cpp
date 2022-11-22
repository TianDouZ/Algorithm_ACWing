#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n=10;
    unsigned int x=-n;  //转换成无符号数 x=-10

    for(int i=31;i>=0;i--) cout<<(x>>i&1);
    cout<<endl;

    return 0;
}