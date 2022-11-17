/*
    整数二分:需要判断边界条件
    步骤:
    先把mid=1+r+1 写出来，再check之后看r更新成mid还是l更新成mid
    如果是l更新成mid，mid=l+r+1 >>2
*/
//模板
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

//例：https://www.acwing.com/problem/content/description/791/
#include <iostream>

using namespace std;

const int N=100010;

int n,m;
int q[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    
    while(m--) {
        int x;
        scanf("%d",&x);
        
        int l=0,r=n-1;
        while(l<r) {  //找左边界
            int mid= l+r >> 1;
            if(q[mid]>=x) r=mid;
            else l=mid+1;
        }
        
        if(q[l]!=x) cout<<"-1 -1"<<endl;
        else {
            cout<<l<<' '; //输出l与输出r相同，因为l==r才会退出循环
            
            int l=0,r=n-1;
            while(l<r) {
                int mid=l+r+1 >>1;
                if(q[mid]<=x) l=mid;
                else r=mid-1;
            }
            
            cout<<l<<endl;
        }
    }
    
    return 0;
    
}



/*
    浮点数二分：
        不用判断边界
*/

//模板
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    //1e-x,x比题目中要求的有效位数多2一般精度就不会有问题
    //比如要求六位小数就1e-8
    //用while可以和整数二分对上
    while (r - l > eps)  //for(int i=0;i<100;i++)也可以
    // 浮点数二分不用精度表示直接循环一百次也可以，相当于精度是用整个长度除以2的100次方，精度很高
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}

//例：求x的平方根
#include <iostream> 
using namespace std;

int main() { //输入一个数求它的平方根
    double x;
    cin>>x;
    
    double l=0,r=x;
    //while(r-l>1e-8)  //1e-x,x比题目中要求的有效位数多2一般精度就不会有问题
    //比如要求六位小数就1e-8
    //用while可以和整数二分对上
    for(int i=0;i<100;i++)  //浮点数二分不用精度表示直接循环一百次也可以，相当于精度是用整个长度除以2的100次方，精度很高
    {
        double mid=(l+r)/2;
        if(mid*mid>=x) r=mid;
        else l=mid;
    }
    
    printf("%1f\n",l);
    
    return 0;
}