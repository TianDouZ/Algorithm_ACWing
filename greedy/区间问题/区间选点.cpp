#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;

int n;
struct Range {  //用结构体表示每一个区间
    int l,r;
    bool operator< (const Range &W)const {
        return r<W.r;
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
     
    int res=0,ed=-2e9;  
    //res表示当前选的点的数量，ed表示上一个选的点的下标
    //初始ed没有选，初始化为负无穷
    for(int i=0;i<n;i++) {
        if(range[i].l>ed) {
            res++;
            ed=range[i].r;
        }
    }
    
    printf("%d\n",res);
    
    return 0;
     
}