/*
    模板：
        作者：yxc
        链接：https://www.acwing.com/blog/content/277/
        来源：AcWing
        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
        vector<int> alls; // 存储所有待离散化的值
        sort(alls.begin(), alls.end()); // 将所有值排序
        alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

        // 二分求出x对应的离散化的值
        int find(int x) // 找到第一个大于等于x的位置
        {
            int l = 0, r = alls.size() - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (alls[mid] >= x) r = mid;
                else l = mid + 1;
            }
            return r + 1; // 映射到1, 2, ...n，求前缀和，所以映射到1开始的自然数好作，不用考虑边界问题
            //return r是映射到从0开始的自然数
        }


//自己写unique:基本的实现思路——双指针
vector<int>::iterator unique(vector<int> &a) {
    int j=0; 
    for(int i=0;i<a.size();i++) {
        if(!i | a[i]!=a[i-1]) a[j++]=a[i];
    }
    //a[0]~a[j-1]存放的就是所有a中不重复的元素
    
    return a.begin()+j;
}

//例：
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;  //用pair来存每对操作数

const int N = 300010;  //N=n+2*m;
int n,m;
int a[N],s[N]; //a存的是离散化之后的数，s存的是前缀和

vector<int> alls;  //存的是所有要离散化的值
vector<PII> add,query;  
//所有加上一个数的操作和求和操作分别放在两个pair组成的vector里面

//求x离散化的结果
int find(int x) {
    int l=0,r=alls.size()-1;
    while(l<r) {
        int mid=(l+r) >> 1;
        if(alls[mid]>=x) { //要找的是>=x的最小的数
            r=mid;
        } else {
            l=mid+1;
        }
    }
    return r+1; //将x映射到从1开始的自然数
    //return r是映射到从0开始的自然数，因为这道题求得是前缀和，所以映射到1开始的自然数好作，不用考虑边界问题
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});  //把{x,c}加入加的操作数组里面去
        
        alls.push_back(x); //把x加入待离散化的数组里面
    }
    
    for(int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r;
        query.push_back({l,r}); //把{l,r}加入求和操作数组里面去
        
        alls.push_back(l); //把l加入待离散化的数组里面
        alls.push_back(r); //把r加入待离散化的数组里面
    }
    
    //去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    //处理插入
    for(auto item:add)  {
        int x=find(item.first);
        a[x]+=item.second;
    }
    
    //预处理前缀和 映射到1,2,...,alls.size();
    for(int i=1;i<=alls.size();i++) s[i]=s[i-1]+a[i];
    
    //处理询问
    for(auto item:query) {
        int l=find(item.first),r=find(item.second);
        
        cout<<s[r]-s[l-1]<<endl;  
    }
    
    
    return 0;
}