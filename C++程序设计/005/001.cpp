//
//  001.cpp
//  ncpp
//
//  Created by zhaoshen liu on 14/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

class MyString:public string {
public:
    MyString():string(){};       // 无参构造函数
    MyString(const char *st):string(st){};  // 有参构造函数
    MyString(const string &st):string(st){}; // 很像复制构造函数，但是参数是基类的对象，基类是可以被派生类赋值的。
    MyString operator()(int m, int n){       // 派生类的参数
        return substr(m,n);
    }
};
