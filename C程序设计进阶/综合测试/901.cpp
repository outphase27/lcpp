//
//  901.cpp
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

//901

int main() {
    int m=0,k=0;
    cin >> m >> k;
    int c1 =0,tem=0,m1=m;
    for(int i=1;i<=5;++i){
        tem = m1%(int)pow(10,i);
        // cout << tem << endl;
        c1+=(tem==3*pow(10,i-1));
        m1-=tem;
    }
    if(m%19==0&&c1==k){
        cout << "YES";
    }
    else
        cout << "NO";
    return 0;
}
