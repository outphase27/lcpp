
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include<cstdio>
#include<cstring>
using namespace std;

class BigInt{
    int d[1000];//用作存储大整数的每一位数
    bool flag;//用作正负号
    int len;//大整数的数位长度
public:
    BigInt(){
        memset(d,0,sizeof(d));
        flag=true;
        len=0;
    }//无参数时的构造函数
    BigInt(const char str[]);//有字符串参数的构造函数
    bool operator<(const BigInt & operand2);
    bool operator>(const BigInt & operand2);
    bool operator==(const BigInt & operand2);
    BigInt & operator=(const BigInt & operand);
    BigInt operator+(const BigInt & operand2);
    BigInt operator-(const BigInt & operand2);
    BigInt operator*(const BigInt & multiplier);
    BigInt operator/(const BigInt & divisor);
    void printBigInt();//打印大整数
};

BigInt::BigInt(const char str[]){
    flag=true;//由于输入的数据为正数，所以置为真
    len=strlen(str);//字符串长度即为数位长度
    for(int i=0;i<len;++i){
        d[i]=str[len-1-i]-'0';//逆着赋值，这样整数的低位存储在数组的低位
    }
}

bool BigInt::operator <(const BigInt & operand2){
    if(len<operand2.len)
        return true;//数的长度比后者小，则数小
    else if(len==operand2.len){
        for(int i=len-1;i>=0;--i){
            if(d[i]<operand2.d[i])
                return true;//从高位往低位比较，只要有一位小，则数小
            else if(d[i]>operand2.d[i])
                return false;
        }
        return false;//两数相等
    }else
        return false;//前面的数大
}

bool BigInt::operator >(const BigInt & operand2){
    if(len>operand2.len)
        return true;//数的长度比后者大，则数大
    else if(len==operand2.len){
        for(int i=len-1;i>=0;--i){
            if(d[i]>operand2.d[i])
                return true;//从高位往低位比较，只要有一位大，则数大
            else if(d[i]<operand2.d[i])
                return false;
        }
        return false;//两数相等
    }else
        return false;//前面的数小
}


int main(){
    return 0;
}
