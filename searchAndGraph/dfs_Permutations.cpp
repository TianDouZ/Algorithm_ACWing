#include <iostream>

using namespace std;

const int N=10;

int n;
int path[N];  
//对应的就是状态，用来存方案，往下搜的过程会把path里面的数填满，搜到叶子节点就填满了
bool st[N];  
//用来记录哪些数字被用过，bool数组是true则表示该数字被用过了

void dfs(int u) {
    if(u==n) {
        for(int i=0;i<n;i++) printf("%d ",path[i]);  
        //遍历到第n个位置，说明此时数字已经被填满了，可以直接输出，从第0个位置输出
        puts("");  //输出空行
        
        return;
    }
    /*
        到叶子结点说明一次DFS到头了，这道题用u判断是不是叶子节点；
        u=0 -> 第一层，一个数都没填进去
        u=1 -> 第二层，填了一个数
        u=2 -> 第三层，填了两个数
        ...
        u=n -> 最后一层，到叶子节点，全填满了
    */
    for(int i=1;i<=n;i++) {  //u<n说明没遍历完，把1开始的数放进去
        if(!st[i]) {  //找个没被用过的数放上去

            /*
                进入递归之前修改状态->递归->递归后马上把状态改回来
            */

            //把这个没用过的数放在u上，记录一下这个数被用过了
            path[u]=i; 
            st[i]=true;
            
            //深搜下一个位置
            dfs(u+1);
            
            //恢复现场
            //path[u]=0;  //path[u]不恢复也行，因为path[u]会被覆盖
            st[i]=false; //st[i]恢复成原来的样子

        }
    }
}

int main() {
    cin>>n;
    
    dfs(0);
    
    return 0;
}


/*
    Leetcode46全排列_核心代码
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permute(vector<int>& nums) {
        path=vector<int>(nums.size()); //初始化path的长度
        st=vector<bool>(nums.size());

        dfs(nums,0);

        return ans;
    }

    void dfs(vector<int>& nums,int u) {
        if(u==nums.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(st[i]==false) {
                path[u]=nums[i];
                st[i]=true;

                dfs(nums,u+1);

                st[i]=false;
                path[u]=0;  //有没有都行，因为path[u]会被覆盖
            }
        }
    }
};