#include <iostream>
#include <algorithm>

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
    int st,ed;
    scanf("%d%d",&st,&ed);
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        range[i]={l,r};
    }
    
    sort(range,range+n);
    
    int res=0;
    bool success=false; //防止找到最后r还是小于ed的
    for(int i=0;i<n;i++) { //用双指针循环一遍
        int j=i,r=-2e9;  //r表示当前最大值
        while(j<n&&range[j].l<=st) {  //遍历所有左端点在st左边所有区间中右端点的最大值
            r=max(r,range[j].r);
            j++;
        }
        
        if(r<st) {
            res=-1;
            break;
        }
        
        res++;
        if(r>=ed) {  
            success=true; //防止找到最后r还是小于ed的
            break;
        }
        
        st=r;
        
        //j跳出是第一个不满足条件的点，且for循环i会++，为保证下次循环从j开始没有遗漏，将i置为j-1
        i=j-1;  
    }
    
    if(!success) res=-1;
    printf("%d\n",res);
    
    return 0;
}