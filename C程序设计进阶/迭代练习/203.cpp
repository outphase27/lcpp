//
//  203.cpp
//  ncpp
//
//  Created by zhaoshen liu on 21/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

//
//  203.cpp
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
// 203 排队问题
//
char str[101]={0};
int i=0;
int rn = 0;// 专门放右括号的位置
char boy;
void myf(){
    char c = str[i];
    int tem = i;
    i++;
    if(c==boy){
        myf();
        cout << tem << ' ' << rn << endl;
        myf();                                   // myf主要功能往后动 （ 动两下 ） 就不会动 最后多动的那一下没有效果
    }
    else if (c!=boy)
        rn =tem;
}
int main(int argc, const char * argv[]){
    cin.getline(str,101);
    boy=str[0];
    myf();
    return 0;
}
