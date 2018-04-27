//
//  603.cpp
//  ncpp
//
//  Created by zhaoshen liu on 27/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
using namespace std;
//603
int main(int argc, const char * argv[]){
    int m=0,n=0;
    cin >> m >> n;
    int A[30][30] = {0};
    for(int i=1;i<m+1;++i){
        for(int j=1;j<n+1;++j){
            cin >> A[i][j];
        }
    }
    for(int i=1;i<m+1;++i){
        for(int j=1;j<n+1;++j){
            if( (A[i][j]>=A[i+1][j]) && (A[i][j]>=A[i-1][j]) && (A[i][j]>=A[i][j+1]) && (A[i][j]>=A[i][j-1]) )
                cout << i-1 << ' ' << j-1 << endl;
        }
    }
    return 0;
}
