#include <iostream>

using namespace std;

const int N=100010;

int m;
int e[N],l[N],r[N],idx;

/*
//用结构体建立也可以，但是会导致代码变长
struct Node{
    int e,l,r;
}nodes[N];
    
*/

//初始化
void init() {
    //0表示左端点，1表示右端点
    r[0]=1,l[1]=0;  //0号点的右边是1号点，1号点的左边是0号点
    idx=2;  //0和1已经被占用了，idx初始化为2
}

//在下标是k的点右边，插入x
void add(int k,int x) {
    e[idx]=x;
    r[idx]=r[k];
    l[idx]=k; 
    l[r[k]]=idx;
    r[k]=idx++;
}

//在下 标是k的点左边插入x可以类比上面写一个，也可以直接调用add(l[k],x); 

//删除第k个点
void remove(int k) {
    r[l[k]]=r[k];
    l[r[k]]=l[k];
    
    /*
    //用结构体写这句话
    nodes[nodes[k].l].r=nodes[k].r;
    */ 
}

int main() {
    int m;
    cin>>m;
    
    init();
    
    while(m--) {
        int k,x;
        string op;
        
        cin>>op;
        if(op=="L") {
            cin>>x;
            add(0,x);
        }else if(op=="R") {
            cin>>x;
            add(l[1],x);
        }else if(op=="D") {
            cin>>k;
            remove(k+1);
        }else if(op=="IL"){
            cin>>k>>x;
            add(l[k+1],x);
        }else {
            cin>>k>>x;
            add(k+1,x);
        }
    }
    
    for(int i=r[0];i!=1;i=r[i]) cout<<e[i]<<' ';
    cout<<endl;
    
    return 0;
}


