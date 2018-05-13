//
//  402.cpp
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
using namespace std;

// 401 减法语句的重载

class MyInt  {
    int nVal;
public:
    MyInt(int n) { nVal = n; }
    int ReturnVal() { return nVal; }
    // 在此处补充你的代码
    MyInt & operator - (int a) {
        nVal -= a;
        return *this;
    }
};
int main ()  {
    MyInt objInt(10);
    objInt-2-1-3;
    cout << objInt.ReturnVal();
    cout <<",";
    objInt-2-1;
    cout << objInt.ReturnVal();
    return 0;
}
