//
//  601.cpp
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
//601
int main(int argc, const char * argv[]){
    int num=0;
    double level;
    cin >> num >> level;
    int count = 0;
    int numl[51] = {0};
    double level_List[51] = {0};
    
    while(num--){
        int num1 = 0;
        double num2 = 0;
        cin >> num1 >> num2;
        if(num2 > level) {
            numl[count]=num1;
            level_List[count]=num2;
            count ++;
        }
    }
    if(count == 0 )
        cout << "None.";
    else {
        for(int i=0;i<=count;++i){
            for(int j=0;j<count-i;++j)
                if(level_List[j]<level_List[j+1]){
                    double tem = numl[j];
                    numl[j] = numl[j+1];
                    numl[j+1] = tem;
                    tem = level_List[j];
                    level_List[j] = level_List[j+1];
                    level_List[j+1] = tem;
                }
        }
        for(int i=0;i<count;++i){
            cout << setw(3) << setfill('0') << numl[i] << " " << setiosflags(ios::fixed) << setprecision(1) << level_List[i] << endl;
        }
    }
    return 0;
}

