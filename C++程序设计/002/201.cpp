//
//  201.cpp
//  ncpp
//
//  Created by zhaoshen liu on 4/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
//201

class student {
    char tem;
    char name[100];
    unsigned age;
    char id[100];
    unsigned grade[4];
public:
    void setname() {
        cin.getline(name,100,',');
    }
    void setage(){
        cin >> age;
        cin >> tem;
    }
    void setid(){
        cin.getline(id,100,',');
    }
    void ig(){
        cin >> grade[0];
        cin >> tem;
        cin >> grade[1];
        cin >> tem;
        cin >> grade[2];
        cin >> tem;
        cin >> grade[3];
    }
    void on(){
        cout << name;
    }
    void oa(){
        cout << age;
    }
    void oi(){
        cout << id;
    }
    void og(){
        cout << (grade[0]+grade[1]+grade[2]+grade[3])/4;
    }
} student1;


int main() {
    student1.setname();
    student1.setage();
    student1.setid();
    student1.ig();
    student1.on();
    cout << ',';
    student1.oa();
    cout << ',';
    student1.oi();
    cout << ',';
    student1.og();
    return 0;
}
