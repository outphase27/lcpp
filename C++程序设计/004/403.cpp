//
//  403.cpp
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

// 403 减法语句的重载
class Array2{
private:
    int row,column;
    int *ptr;
public:
    Array2()
    {
        ptr = NULL;
    }
    Array2(int row, int column):row(row),column(column) // 构造函数
    {
        ptr = new int[row*column];
    }
    Array2(Array2& a):row(a.row),column(a.column)       // 复制构造函数
    {
        ptr = new int[row * column];
        memcpy(ptr,a.ptr,sizeof(int)*row*column);
    }
    Array2& operator = (const Array2 &a)                // = 的重载
    {
        if (ptr) delete[] ptr;
        row = a.row;
        column = a.column;
        ptr = new int[row*column];
        memcpy(ptr,a.ptr,sizeof(int)*row*column);
        return *this;
    }
    ~Array2()
    {
        if(ptr) delete [] ptr;
    }
    int* operator[] (int i)                            // 一个是指针 第二个自己能解决
    {
        return ptr + i*column;
    }
    int& operator()(int a, int b)                       // 运算符一定要贴着operator
    {
        return ptr[a*column+b];
    }
    /*
     int& operator() (int i, int j)
     {
     return ptr[i*column + j];
     }
     */
    
    
    
};


int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

