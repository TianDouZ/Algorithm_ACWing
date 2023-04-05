#include <iostream>
#include <algorithm>
#include <queue>  //每次求最小的两个点用优先级队列

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    
    priority_queue<int,vector<int>,greater<int>> heap;  // 小根堆要加上greater这个参数
    while(n--) {
        int x;
        scanf("%d",&x);
        heap.push(x);
    }
    
    int res=0;
    while(heap.size()>1) {
        int a=heap.top(); heap.pop();
        int b=heap.top(); heap.pop();
        
        res+=a+b;
        heap.push(a+b);
    }
    
    printf("%d\n",res);
    return 0;
}