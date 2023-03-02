/*
    方法一：从背包问题的角度考虑
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010,mod=1e9+7;

int n;
int f[N];

int main() {
    cin>>n;
    
    //初始化，一个数都不选体积为0是1种选法，一个数都不选体积选为恰好是j的选法没有，所以除了f[0]=1其余都为0
    /*
        这里f[0]代表一个数都不选，此时总体积为0，这也是一种合法的方案，
        这里的一个数都不选，实际上是“别的数一个都不选，只选i自己”
        比如我们计算转移的状态f[i-1][j-si]中，如果恰好j-si=0,代表恰好s个i能够满足j的要求，此时是一种合法的方案。
    */
    f[0]=1; //可以看为f[1][0]=1
    
    for(int i=1;i<=n;i++) { //枚举物品
        for(int j=i;j<=n;j++) {  //枚举体积
            f[j]=(f[j]+f[j-i])%mod;
        }        
    }
    
    cout<<f[n]<<endl;
    
    return 0;
}


/*
    方法二：f[i][j]表示所有总和是i并且恰好表示成j个数的和的方案
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1010,mod=1e9+7;

int n;
int f[N][N];

int main() {
    cin>>n;
    
    f[0][0]=1; //组成的数是0用0个数来表示的方案为1
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {  //j个数最多表示成i
            f[i][j]=(f[i-1][j-1]+f[i-j][j])%mod;
        }
    }
    
    int res=0;
    for(int i=1;i<=n;i++) res=(res+f[n][i])%mod;
    
    cout<<res<<endl;
    return 0;
}

