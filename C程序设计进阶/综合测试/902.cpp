//
//  902.cpp
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
//902
int main() {
    char s[501] = {0};
    cin.getline(s,501);
    int sum[26]={0};
    for(int i=0;i<26;++i){
        sum[i]=0;
    }
    // a to z 出现次数
    for(int i=0;s[i]!='\0';++i){
        int d =0;
        d = s[i] - 'A';
        if (d>=0 && d<='Z'-'A'){
            sum[d] += 1;
        }
        else if (d>='a'-'A'&&d<='z'-'A') {
            sum[d-('a'-'A')]+=1;
        }
    }
    /*
     for(int i=0;i<26;i++){
     cout << sum[i] << endl;
     }
     */
    // 找出第二多数量是多少
    int max1=0;
    int max2=0;
    for(int i=0;i<26;++i){
        if (sum[i] > max1) {
            max2 = max1;
            max1 = sum[i];
        }
        else if (sum[i]>max2&&sum[i]!=max1){
            max2 = sum[i];
        }
    }
    // cout << max1 << endl;
    // cout << max2 << endl;
    //找出满足第二多的字母有哪些
    int max2l[26] = {0};
    for (int i = 0; i<26;++i)
        max2l[i] = -1000;
    int k = 0;
    for (int i=0;i<26;++i) {
        if (sum[i]==max2) {
            max2l[k] = i;
            k++;
        }
    }
    /*
     for (int i=0;max2l[i]!=-1000;++i)
     cout << max2l[i] << endl;
     */
    // max2l 应该是{0 3 4 5 -1000 -1000 -1000 -1000 -1000} -1000 能突破ascII的范围
    // 寻找第一个出现的次数第二多字母
    int id = -1;
    for(int i=0;s[i]!='\0';i++){
        if ( (s[i]>='A'&&s[i]<='Z') || (s[i]>='a'&&s[i]<='z') ) {
            int d = s[i] - 'A';
            // cout << "s[i] = "<< s[i] << endl;
            // cout << "d1= " << d - 'a' +'A' << endl;
            // cout << "dd = "<< 'a' - 'a' +'A' << endl;
            for(int j=0;max2l[j]!=-1000;j++){
                if( (d==max2l[j]) || ( d-('a'-'A')==max2l[j] ) ) {
                    id = j;
                    break;
                }
            }
        }
        
        if(id!=-1 )
            break;
    }
    cout << (char)('A'+max2l[id]) << '+' << (char)('a'+max2l[id]) << ':'<<max2;
    return 0;
}
