 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 typedef pair<int,int> PII; //first存区间的左端点，second存区间的右端点
 
 const int N=100010;
 
 int n;
 vector<PII> segs;
 
 void merge(vector<PII> &segs) {
    vector<PII> res;
    
    sort(segs.begin(),segs.end());  //pair优先以左端点排序，再以右端点排序
    
    int st=-2e9,ed=-2e9;  //确定边界，应为负无穷到正无穷，但是本题数据范围为-1e9~1e9;
    for(auto seg:segs) {
        if(ed<seg.first) { //当前区间于维护区间无交集
            if(st!=-2e9) res.push_back({st,ed});  //st!=-2e9说明不是边界，放答案里
            st=seg.first,ed=seg.second; //是边界，把当前区间设为维护的区间
        } 
        else ed = max(ed,seg.second);   //当前区间于维护区间有交集,ed取较大值
    }
    
    //把最后的区间加入答案中，此处判断是为了防止输入的数组是空数组
    if(st!=-2e9) res.push_back({st,ed});
    
    segs=res;
 }
 
 int main() {
    cin>>n;
    
    for(int i=0;i<n;i++) {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    
    merge(segs);
    
    cout<<segs.size()<<endl;
     
    return 0;
 }