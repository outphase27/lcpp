//
//  003.cpp
//  ncpp
//
//  Created by zhaoshen liu on 13/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

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
