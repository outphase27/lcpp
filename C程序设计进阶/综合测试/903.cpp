//
//  903.cpp
//  ncpp
//
//  Created by zhaoshen liu on 30/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
//903 运算符判定
int main() {
    int a=0,b=0,c=0;
    char tem;
    cin >> a >> tem >> b >> tem >> c;
    if(c==a+b)
        cout << '+';
    else if(c==a-b)
        cout << '-';
    else if(c==a*b)
        cout << '*';
    else if(c==a/b)
        cout << '/';
    else if(c==a%b)
        cout << '%';
    else
        cout << "error" ;
    return 0;
}
