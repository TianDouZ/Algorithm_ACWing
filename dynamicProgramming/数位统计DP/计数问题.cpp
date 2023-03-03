/*

    001~abc-1, 999

    abc
        1. num[i] < x, 0
        2. num[i] == x, 0~efg
        3. num[i] > x, 0~999

    
    时间复杂度：
        10x2x8x10=O(1600) 
        枚举每个数字x两个区间每个算一次x每次枚举每一位x循环每个数字

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//辅助函数，vector中从获得num的l位到r位的数
int get(vector<int> num,int l,int r) {
    int res=0;
    for(int i=l;i>=r;i--) res=res*10+num[i];
    return res;
}


//辅助函数，求后面粉部分，10^i
int power10(int x) {
    int res=1;
    while(x--) res*=10;
    return res;
}

int count(int n,int x) {
    //count函数返回的是1到n中x出现得次数，如果n=0直接输出0即可
    if(!n) return 0;
    
    //将n每一位上的数字抠出来
    vector<int> num;
    while(n) {
        num.push_back(n%10);
        n/=10;
    }
    
    n=num.size();
    
    int res=0;
    //从最高位开始枚举
    for(int i=n-1-!x;i>=0;i--) {  //当x在最高位且x=0时，因为0不能在最高位，从第二位开始枚举即可，所以i从n-1-!x开始枚举
        //如果i=n-1,则num[i]表示的是最高位，求最高位出现的次数时不包含（1）情况，只有（2）
        if(i<n-1) {
            res+=get(num,n-1,i+1)*power10(i);
            //如果x是0，在（1）情况下，前一部分要从001开始取，少了000，所以少了1*power10(i)
            if(!x) res-=power10(i);
        }
        
        if(num[i]==x) res+=get(num,i-1,0)+1;
        else if(num[i]>x) res+=power10(i);
    }
    
    return res;
}

int main() {
    int a,b;
    while(cin>>a>>b,a||b) {
        if(a>b) swap(a,b);
        for(int i=0;i<10;i++) cout<<count(b,i)-count(a-1,i)<<' ';
        cout<<endl;
    }
    return 0;
}