//
//  602.cpp
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
//602
int main(int argc, const char * argv[]){
    int n=0;
    cin >> n;
    cin.get();
    char A[1000][256]={0};
    for(int i=0;i<n;++i){
        cin.getline(A[i],256);
    }
    for(int i=0;i<n;++i){
        for(int j=0;A[i][j]!='\0';j++){
            if(A[i][j]=='A')
                A[i][j]='T';
            else if(A[i][j]=='G')
                A[i][j]='C';
            else if(A[i][j]=='T')
                A[i][j]='A';
            else if(A[i][j]=='C')
                A[i][j]='G';
        }
    }
    for(int i=0;i<n;++i){
        cout << A[i] << endl;
    }
    return 0;
}
