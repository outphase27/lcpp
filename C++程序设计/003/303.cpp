//
//  303.cpp
//  ncpp
//
//  Created by zhaoshen liu on 7/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
//303 封闭类构造函数啊！
class Base {
public:
    int k;
    Base(int n):k(n) { }
};
class Big  {
public:
    int v; Base b;
    // 在此处补充你的代码
    Big (int a1): v(a1),b(a1) {};
};
int main()  {
    Big a1(5);    Big a2 = a1;
    cout << a1.v << "," << a1.b.k << endl;
    cout << a2.v << "," << a2.b.k << endl;
    return 0;
}

