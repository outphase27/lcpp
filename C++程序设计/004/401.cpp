//
//  401.cpp
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

// 401 赋值语句的重载

class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    void operator = (const char* s)
    {
        string str = s;
        int pos = str.find("+", 0);
        string strReal = str.substr(0, pos);//分离出代表实部的字符串
        r = atof(strReal.c_str());//atof库函数能将const char*指针指向的内容转换成float
        string strImaginary = str.substr(pos+1, str.length()-pos-2);//分离出虚部代表的字符串
        i = atof(strImaginary.c_str());
    }
    
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
