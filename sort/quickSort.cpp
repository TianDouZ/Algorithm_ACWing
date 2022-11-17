//https://www.acwing.com/problem/content/description/787/
#include <iostream>

using namespace std;

const int N=1e6+10;

int n;
int q[N];

void quick_sort(int q[],int l,int r) {
    if(l>=r) return; //边界，只有一个数或没有数直接return 

    int x=q[(l+r)/2],i=l-1,j=r+1; //l r分别指向边界左右两次，这样每次都先把l r往中间移动一位
    //注意数据量多的时候，分界点x应随机取或取中间点，否则会超时
    while (i<j)
    {
        do i++;while(q[i]<x);
        do j--;while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }

    quick_sort(q,l,j);
    quick_sort(q,j+1,r);

    /*
        边界问题：
                quick_sort(q,l,j);
                quick_sort(q,j+1,r);   用j分界，分界点x不能取右边界即q[r];

                quick_sort(q,l,i-1);
                quick_sort(q,i,r);   用i分界，分界点x不能取左边界即q[l];
                
                否则会陷入死循环，例q=[1,2]。
    */
    
}

int main() {
    scanf("%d",&n); //输入数据多用scanf
    for(int i=0;i<n;i++) scanf("%d",&q[i]);

    quick_sort(q,0,n-1);

    for(int i=0;i<n;i++) printf("%d ",q[i]);

    return 0;
}