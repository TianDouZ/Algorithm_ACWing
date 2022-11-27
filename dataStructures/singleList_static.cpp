#include <iostream>

using namespace std;

const int N=100010;


//head表示头节点的下标
//e[i]表示节点i的值
//ne[i]表示节点i的next指针是多少，即节点i的下一个点的下标是什么
//idx存储当前用到了哪个点，相当于一个指针，从第一个值开始指，每加入一个点时，idx++
//idx指的是当前可以用的最新的点的下标
int head,e[N],ne[N],idx;

//初始化
void init() {
    head=-1;  //-1代表空节点
    idx=0;
}

//将x插到头节点
void add_to_head(int x) {
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

//将x插入下标是k的点的后面
void add(int k,int x) {
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}

//将下标是k的点后面的点删掉
void remove(int k) {
    ne[k]=ne[ne[k]];
}

int main() {
    int m;
    cin>>m;
    
    init();
    
    while(m--) {
        int k,x;
        char op;
        
        cin>>op;
        if(op=='H') {
            cin>>x;
            add_to_head(x);
        }else if(op=='D') {
            cin>>k;
            if(!k) head=ne[head];  //删除头节点
            else remove(k-1);
        }else {
            cin>>k>>x;
            add(k-1,x);
        }
    }
    
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
    cout<<endl;
    
    return 0;
}
