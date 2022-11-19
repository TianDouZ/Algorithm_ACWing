#include <iostream>
#include <vector>
#include <algorithm>  //reverse

using namespace std;

//A/b,商是C，余数是r
vector<int> div(vector<int> &A,int b,int &r) {  //r是余数，引用传进来
    vector<int> C;  //商
    r=0;
    for(int i=A.size()-1;i>=0;i--) { //除法从最高位开始看
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    
    reverse(C.begin(),C.end());  //上面存放的是高位在前低位在后，与定义的大整数存储方式相反，reverse一下
    while(C.size()>1&&C.back()==0)  C.pop_back();   //去除前导0
    
    return C;
}

int main() {
    string a;
    int b;
    
    cin>>a>>b;
    
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    
    
    int r;//余数
    auto C=div(A,b,r);
    
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);  //输出商
    cout<<endl<<r<<endl;  //输出余数

    return 0;
} 