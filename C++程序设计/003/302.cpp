//
//  302.cpp
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
//302 复制构造函数啊！

class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    // 在此处补充你的代码
    Sample(Sample & c){
        v = 10;
    }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}
