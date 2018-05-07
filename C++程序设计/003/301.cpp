//
//  301.cpp
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
//301 构造函数啊！
class A {
public:
    int val;
    A (int n=0) {val = n;}
    A & GetObj(){          // 使用引用的话，才能改变a中的val。 这个引用对于改变A十分重要
        return * this;
    }
};
int main()  {
    A a,b;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
    // cout << b.val << endl;
    return 0;
}
