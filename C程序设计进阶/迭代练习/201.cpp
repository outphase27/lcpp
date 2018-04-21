//
//  201.cpp
//  ncpp
//
//  Created by zhaoshen liu on 21/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;

// 201 单词翻转 空格不动
char str[501] = {0}; // 输入长度为500 保证最后有结束符；
int i=0;             // 当前处理的下标
int ff()
{
    char c = str[i];
    i++;
    if(c==' ')
        return 1;
    else if(c!=' '&&c!='\0'){
        ff();
        cout << c;
    }
    return 1;
}
int main(int argc, const char * argv[]){
    cin.getline(str,501);
    char tem;
    while(str[i]!='\0'){
        tem = ff();
        if( (tem==1&&str[i]!='\0')|| (str[i]=='\0'&&str[i-1]==' ') ){   //处理一下最后的那个空格 预防一下最后一位还是空格
            cout <<' ';
        }
    }
    return 0;

}
