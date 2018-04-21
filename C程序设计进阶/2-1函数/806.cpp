//
//  806.cpp
//  lcpp
//
//  Created by zhaoshen liu on 11/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//


#include <iostream>
#include <iomanip>
using namespace std;
// 806
int main(int argc, const char * argv[]){
    int n=0,a[100];
    cin >> n;
    int j=0;
    for(int i=10;i<=n;++i){
        if(i%( (i/10) + (i%10) ) == 0){
            a[j] = i;
            ++j;
        }
    }
    for(int i=0;i<j;++i)
        cout << a[i]<<endl;
    return 0;
}
