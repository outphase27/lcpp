//
//  501.cpp
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
//501
int main(int argc, const char * argv[]){
    int count = 0;
    cin >> count;
    while(count--){
        int a[100][100];
        int m=0,n=0;
        cin >> m >> n;
        int sum=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
                if(i==0||j==0||i==m-1||j==n-1)
                    sum+=a[i][j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
