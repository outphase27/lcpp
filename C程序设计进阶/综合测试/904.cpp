//  904.cpp
//  ncpp
//
//  Created by zhaoshen liu on 30/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//  这题的思路是有问题的，有时间的话要重新处理一下

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
//904 寻找极大点
int main() {
    int num =0;
    int x[100]={0};
    int y[100]={0};
    cin >> num;
    for (int i=0;i<num;++i){
        cin >> x[i] >> y[i];
    }
    // 把边界画出来，有问题就是点会不会重叠，先当不重叠去解决
    int rx =0,ry=0;
    for(int i=0;i<num;++i){
        if(x[i]>rx&&y[i]>ry){
            rx = x[i];
            ry = y[i];
        }
    }
    // cout << rx << ' ' << ry << endl;
    // 把外面的点都找出来
    // 这里第一次交说wrong answer怀疑就是重复的点的问题，因此在这里加一个去掉重复的模块
    // 所有的点都有可能重复
    /*
     int count =0;
     for (int i=0;i<num;++i){
     if(x[i]==rx&&y[i]==ry)
     count ++;
     }
     */
    // cout << count << endl;
    int sx[100] = {0};
    int sy[100] = {0};
    int k=0;
    for (int i=0;i<num;++i){
        if( x[i]>rx||y[i]>ry||(x[i]==rx&&y[i]==ry)){
            sx[k] = x[i];
            sy[k] = y[i];
            k++;
        }
    }
    for(int i=0;i<k-1;i++){
        for(int j=1;i+j<k;j++){
            if(sx[i]==sx[i+j]&&sy[i]==sy[i+j]){
                sx[i] = 0;
                sx[i+j] = 0;
                sy [i] = 0;
                sy[i+j] = 0;
            }
        }
    }
    
    // for(int i=0;i<k;++i)
    // cout << sx[i] << ' ' << sy[i] << endl;
    // 来拍一波顺序 按照x大小
    for(int i=0;i<k-1;++i){
        for(int j=0;j<k-1-i;++j){
            if(sx[j]>sx[j+1]){
                int tem = sx[j+1];
                sx[j+1] = sx[j];
                sx[j] = tem;
                tem = sy[j+1];
                sy[j+1] = sy[j];
                sy[j] = tem;
            }
        }
    }
    //for(int i=0;i<k;++i)
    // cout << sx[i] << ' ' << sy[i] << endl;
    // 找第一个点
    int count = 0;
    for(;(sx[count]==0&&sy[count]==0);++count){
    }
    // cout << count << endl;
    // 变成题目要求的格式
    cout << '(' << sx[count] << ',' << sy[count] << ')';
    for(int i=count+1;i<k;++i)
        cout << ',' <<'(' << sx[i] << ',' << sy[i] << ')';
    return 0;
}

