//
//  404.cpp
//  ncpp
//
//  Created by zhaoshen liu on 13/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include<cstdio>
#include<cstring>
using namespace std;

class bigInt{
    int digit[200];            // 存放数字
    bool flag;                 // 存放正负符号
    unsigned long len;        // 存放数字的长度
public:
    bigInt(){        // 无参数构造函数
        memset(digit,0,sizeof(digit));
        flag = true;
        len = 0;
    }
    bigInt(const char str[]); // 有参数的时候的构造函数
    bool operator<(const bigInt & operand2);
    bool operator>(const bigInt & operand2);
    bool operator==(const bigInt & operand2);
    bigInt operator+(const bigInt & operand2);
    bigInt operator-(const bigInt & operand2);
    bigInt operator*(const bigInt & operand2);
    bigInt operator/(const bigInt & operand2);
    void printBigInt();
};

bigInt:: bigInt(const char str[]){
    flag = true;
    len = strlen(str);
    for(int i =0;i<len;++i){
        digit[i] = str[len-i-1]-'0';  //这样就把数字取了出来并且将低位的数字放入前面；
    }
}

bool bigInt:: operator<(const bigInt & operand2){
    if(len<operand2.len)
        return true;
    else if(len == operand2.len){
        for(int i=len-1;i>=0;--i) {
            if( digit[i] < operand2.digit[i])
                return true;
            if(operand2.digit[i] < digit[i])
                return false;
        }
        return false;
    }
    else
        return false;
}


bool bigInt:: operator>(const bigInt & operand2){
    if(len>operand2.len)
        return true;
    else if(len == operand2.len){
        for(int i=len-1;i>=0;--i) {
            if( digit[i] > operand2.digit[i])
                return true;
            if(operand2.digit[i] > digit[i])
                return false;
        }
        return false;
    }
    else
        return false;
}

bool bigInt:: operator == (const bigInt & operand2){
    if (len!= operand2.len)
        return false;
    else{
        for(unsigned long i=0;i<len;++i){
            if(digit[i]!=operand2.digit[i])
                return false;
        }
        return true;
    }
}


bigInt bigInt::operator+(const bigInt & operand2){
    bigInt result;
    int carry =0;
    for(unsigned long i=0;i<len||i<operand2.len;i++){
        result.digit[result.len++] = (carry + digit[i] + operand2.digit[i])%10;
        carry = (carry + digit[i] + operand2.digit[i])/10;

    }
    if(carry!=0)
        result.digit[result.len++]=carry;
    return result;
}


bigInt bigInt::operator-(const bigInt & operand2){
    
    bigInt result;
    bigInt minuend; // 被减数
    bigInt subtrahend;
    if(*this<operand2){
        result.flag = false;
        minuend = operand2;
        subtrahend = *this;
    }
    else{
        minuend=*this;
        subtrahend = operand2;
    }
    for (int i=0;i<minuend.len||i<subtrahend.len;++i){
        if(minuend.digit[i]<subtrahend.digit[i]){
            minuend.digit[++i]--;  //
            minuend.digit[i] += 10;
        }
        result.digit[result.len++] = minuend.digit[i] - subtrahend.digit[i];
    }
    while(result.len-1>=1&&result.digit[len-1]==0){
        result.len -- ;
    }
    
    return result;
}


bigInt bigInt::operator*(const bigInt & operand2){
    bigInt result;
    result.len = len+operand2.len;
    for(unsigned long i=0;i<len;++i){
        for(unsigned long j=0;j<operand2.len;++j){
            result.digit[i+j]+= digit[i]*operand2.digit[j];//关键算法，需要自己手动模拟一下
            result.digit[i+j+1]+= result.digit[i+j]/10;
            result.digit[i+j]=result.digit[i+j]%10;//简单来说就是a[i]*b[j]保存在c[i+j]上
        }
    }
    if(result.digit[result.len -1]==0)
        result.len--;
    return result;
}


bigInt bigInt::operator/(const bigInt & operand2){
    bigInt quotient;
    bigInt remainder;
    if(*this < operand2){
        quotient.len = 1;
        quotient.digit[0] = 0;
    }
    else{
        quotient.len = this->len-operand2.len +1;                // 商的位数最多为位数差+1；
        remainder.len = operand2.len -1;                         // 很奇怪这里，余数的位数应该是除数的位数 这里把余数长度作被除数长度-1
        for(unsigned long i= quotient.len -1 ; i>0;--i){
            remainder.digit[i] = this->digit[i+quotient.len];     //说的是从大给余数赋初值
        }
    }
    for(unsigned long i=quotient.len-1;i>0;--i){
        remainder.len++;
        for(unsigned long j=remainder.len-1;j>0;--j){
            remainder.digit[j] = remainder.digit[j-1];
        }
        remainder.digit[0] = digit[i];  // 不用指针啊
        if(remainder<operand2)
            quotient.digit[i]=0;
        else{
            int cnt=0;
            while(remainder>operand2||remainder == operand2){
                remainder =remainder - operand2;
                cnt ++;
            }
            quotient.digit[i] =cnt;
        }
    }
    if(quotient.digit[quotient.len-1]==0)
        quotient.len --;
    
    return quotient;
}

void bigInt::printBigInt(){
    if(flag==false)
        printf("-");
    for(int i=len-1;i>=0;--i)
        printf("%d",digit[i]);
    printf("\n");
}



int main(){
    char str1[1000];
    char op;
    char str2[1000];
    gets(str1);        //gets能吃掉回车
    op=getchar();
    getchar();//吞掉回车符
    gets(str2);
    
    bigInt a (str1);
    bigInt b (str2);
    bigInt result;
    switch (op){
        case '+': result = a+b;break;
        case '-': result = a-b;break;
        case '*': result = a*b;break;
        case '/': result = a/b;break;
        default: break;
    }
    
    result.printBigInt();
    
    return 0;
    
}

