//
//  202.cpp
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

// 202 角谷猜想
// 所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘3加1，如果是偶数，则除以2，得到的结果再按照上述规则重复处理，最终总能够得到1。如，假定初始整数为5，计算过程分别为16、8、4、2、1。
int myf(int i){
    if(i!=1) {
        if(i%2==0) {
            cout << i << '/'<< 2 << '=' << i/2 << endl;
            return myf(i/2);
        }
        else {
            cout << i << '*' << 3 << '+' << 1 << '=' << i*3+1 << endl;
            return myf(i*3+1);
        }
    }
    return 1;
}

int main(int argc, const char * argv[]){
    int num;
    cin >> num;
    while(myf(num)!=1); //这个的条件就实现了功能，很好
    cout<<"End";
    return 0;
}

