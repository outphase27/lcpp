//
//  503.cpp
//  ncpp
//
//  Created by zhaoshen liu on 26/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;
int max_W = 1000;  // 最多单词数量
int max_Wl = 40;   // 最大单词长度
int max_Char = 80; // 一行最多的字符数

//503
int main(int argc, const char * argv[]){
    char w[max_W][max_Wl];
    int wl[max_W];
    int n;
    cin >> n;
    // 输入所有的单词
    for (int i=0;i<n;++i){
        cin >> w[i];
        wl[i] = strlen(w[i]);
    }
    // 输出第一个单词
    int l = wl[0];
    cout << w[0];
    for (int i=1;i<n;i++) {
        if (l+1+wl[i]<=max_Char){
            l = l + 1 + wl[i];
            cout << ' ' << w[i];
        }
        else{
            cout << endl;
            l = wl[i];
            cout << w[i];
        }
    }
    cout << endl;
    return 0;
}


