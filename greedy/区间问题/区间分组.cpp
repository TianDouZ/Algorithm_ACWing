#include <iostream>
#include <algorithm>
#include <queue>  //处理小根堆

using namespace std;

const int N=100010;

int n;
struct Range{
    int l,r;
    bool operator< (const Range &W)const {
        return l<W.l;
    }
}range[N];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    
    sort(range,range+n);
    
    priority_queue<int,vector<int>,greater<int>> heap;  //定义小根堆
    for(int i=0;i<n;i++) {
        auto r=range[i];
        if(heap.empty() || heap.top() >=r.l)  heap.push(r.r); //新建一个组
        else {  //更新最新的右端点
            int t=heap.top();
            heap.pop();
            heap.push(r.r);
        }
    }
    
    printf("%d\n",heap.size());
    
    return 0;
    
}