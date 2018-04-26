//
//  502.cpp
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
//502
int main(int argc, const char * argv[]){
    /*
     m=3 n=3
     00 01 10 02 11 20 12 21 22
     */
    int A[101][101]={0};
    int m=0,n=0;
    cin >> m >> n;
    for (int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin >> A[i][j];
        }
    }
    for (int s=0;s<m+n-1;++s){
        for(int i=0;i<=s;++i){
            int j=s-i;
            if(i<m&&j<n)
                cout << A[i][j]<<endl;
        }
    }
    return 0;
}
