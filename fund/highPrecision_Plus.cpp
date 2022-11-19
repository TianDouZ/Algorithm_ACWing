#include <iostream>
#include <vector>

using namespace std;

const int N=1e6+10;  //+10是为了防止边界问题

//C=A+B
vector<int> add(vector<int> &A,vector<int> &B) { //加引用&是为了提高效率，不加&要把原来的数组copy一遍
    vector<int> C;
    
    int t=0; //进位
    for(int i=0;i<A.size()||i<B.size();i++) {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);  //当前这一位
        t/=10;   //进位
    }
    
    if(t) C.push_back(1); //判断最高位是否有进位，如果有进1
    return C;
}

int main() {
    string a,b;
    vector<int> A,B;
    
    cin>>a>>b;  //a=123456;
    //倒序，把低位放在前面，高位进位在数组后面添加新的比较方便
    for(int i=a.size()-1;i>=0;i--)  A.push_back(a[i]-'0');  //a[i]是char类型的数字，变成数字要减去0；
    //A=[6,5,4,3,2,1]
    for(int i=b.size()-1;i>=0;i--)  B.push_back(b[i]-'0');
    
    auto C= add(A,B);
    
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]); //从高位输出，因为是倒序，所以高位在后面
    return 0;
}