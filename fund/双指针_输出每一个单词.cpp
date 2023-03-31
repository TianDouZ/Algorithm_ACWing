/*
    输出每一个单词
*/
#include <iostream> 
#include <string.h>

using namespace std;

int main() {
    char str[1000];  //定义字符串数组
    
    fgets(str,1000,stdin);  //读入字符串 
    
    int n=strlen(str);  //n表示字符串长度，strlen()在#include <string.h>下
    
    /*
        sizeof计算的是该数组占用的空间大小；
        strlen计算的是字符串的长度并吧'\0'结尾符也算作一个单位但是null并不计算
    */
    
    for(int i=0;i<n;i++) {
        int j=i;
        while(j<n&&str[j]!=' ') j++;
        
        //这道问题的具体逻辑
        for(int k=i;k<j;k++) cout<<str[k];
        
        cout<<endl;
        
        i=j;
    }
    
    return 0;
}