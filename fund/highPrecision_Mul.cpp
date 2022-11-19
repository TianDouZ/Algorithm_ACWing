#include <iostream>
#include <vector>

using namespace std;



vector<int> mul(vector<int> &A,int b) {
    vector<int> C;
    
    int t=0;//进位
    for(int i=0;i<A.size() ||t ;i++) {
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10; //和加法类似
    }
    
    return C;
}

int main() {
    string a;
    int b;
    
    cin>>a>>b;
    
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    
    
    if(b==0) { //判断一下一个为0则结果直接为0
        cout<<'0';
    } else {
        auto C=mul(A,b);
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    }
        

    return 0;
} 