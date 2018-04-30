//
//  905.cpp
//  ncpp
//
//  Created by zhaoshen liu on 30/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
//905 走出迷宫
char map[101][101]={0};
int stepmap[101][101]={0};
int min_count= 0;
int n=0,m=0; // 边界外面是用得上的

void run(int u, int v, int i, int j){
    int stepvalue = stepmap[u][v];
    if(u==i && v==j)                   // 到达终点
    {
        min_count = stepvalue;
    }
    stepvalue++; // 下一步的stepvalue
    
    if (v< n-1 && map[u][v+1]!= '#' && stepmap[u][v+1] > stepvalue) { // 范围内没有走到过； 这一步是往右走
        stepmap[u][v+1] = stepvalue;
        run(u,v+1,i,j);
    }
    if (u > 0 && map[u-1][v]!= '#' && stepmap[u-1][v] > stepvalue) { // 范围内没有走到过； 这一步是往上走
        stepmap[u-1][v] = stepvalue;
        run(u-1,v,i,j);
    }
    if (v > 0 && map[u][v-1]!= '#' && stepmap[u][v-1] > stepvalue) { // 范围内没有走到过； 这一步是往右走
        stepmap[u][v-1] = stepvalue;
        run(u,v-1,i,j);
    }
    if (u < m-1 && map[u+1][v]!= '#' && stepmap[u+1][v] > stepvalue) { // 范围内没有走到过； 这一步是往右走
        stepmap[u+1][v] = stepvalue;
        run(u+1,v,i,j);
    }
}
int main() {
    // 输入地图 并找到S和T的坐标
    int sx=0,sy=0,tx=0,ty=0;
    cin >> m >> n;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin >> map[i][j];
            if(map[i][j]=='S'){
                sx = i;
                sy = j;
            }else if(map[i][j]=='T'){
                tx = i;
                ty = j;
            }
        }
    }
    // cout << sx << ' ' << sy << ' ' << tx << ' ' << ty << endl;
    // memset(stepmap,1,sizeof(stepmap)); // 按字节为单位赋值：16843309，其实就是赋值一个极大的数
    for(int i=0;i<101;++i){
        for(int j=0;j<101;++j)
            stepmap[i][j] = 10000;
    }
    stepmap[sx][sy]=0;
    run(sx,sy,tx,ty);
    cout << min_count;
    return 0;
}

