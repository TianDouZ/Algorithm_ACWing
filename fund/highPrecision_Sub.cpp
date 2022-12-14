#include <iostream>
#include <vector>

using namespace std;

const int N=1e6+10;  //+10是为了防止边界问题

//判断是否有A>=B 
bool cmp(vector<int> &A,vector<int> &B) {
    if(A.size()!=B.size()) return A.size()>B.size();
    
    //若位数相同，模仿人工比大小，从高位开始比
    for(int i=A.size()-1;i>=0;i--) {
        if(A[i]!=B[i]) return A[i]>B[i];
    }
    return true;  //比到这说明都相等
}

//C=A-B
vector<int> sub(vector<int> &A,vector<int> &B) { //加引用&是为了提高效率，不加&要把原来的数组copy一遍
    vector<int> C;
    
    for(int i=0,t=0;i<A.size();i++) { //t是进位，保证A>=B,，所以A.size()>=B.size()
       t=A[i]-t;
       if(i<B.size())  t-=B[i]; //判断B有没有这一位，有才需要-B[i]
        C.push_back((t+10)%10);  //当前这一位
        if(t<0) t=1;
        else t=0;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();  //去除做完减法的先导0（逆序）
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
    
    
    if(cmp(A,B)) {
        auto C=sub(A,B);
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]); //从高位输出，因为是倒序，所以高位在后面
    } else {
        auto C=sub(B,A);
        printf("-");
        for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]); //从高位输出，因为是倒序，所以高位在后面
    }
    
    return 0;
}