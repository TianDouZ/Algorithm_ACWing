#include <iostream>

using namespace std;

const int N=1000010;

int n,k;
int a[N],q[N]; //a存的是原来的值，q存的是单调队列

int main() {
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    
    int hh=0,tt=-1; //定义队头、队尾
    //队列里面存的是下标
    for(int i=0;i<n;i++) {
        //判断队头是否已经滑出窗口
        if(hh<=tt&&i-k+1>q[hh]) hh++;  //写if就行，因为窗口每次只移动一位，最多只有一个数不在窗口内
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);
        
    }
    puts("");
    
    hh=0,tt=-1; //定义队头、队尾
    //队列里面存的是下标
    for(int i=0;i<n;i++) {
        //判断队头是否已经滑出窗口
        if(hh<=tt&&i-k+1>q[hh]) hh++;  //写if就行，因为窗口每次只移动一位，最多只有一个数不在窗口内
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        
        q[++tt]=i;
        if(i>=k-1) printf("%d ",a[q[hh]]);
        
    }
    puts("");
    
    return 0;
}