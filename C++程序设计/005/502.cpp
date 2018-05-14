//
//  502.cpp
//  ncpp
//
//  Created by zhaoshen liu on 15/5/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include<cstdio>
#include<cstring>
using namespace std;
const int warrior_num = 5;
const int weapon_num = 3;

/*
 红色 iceman,lion,wolf,ninja,dragon
 蓝色 lion,dragon,ninja,iceman,wolf
 */

//502

class Headquarter;
class warrior
{
private:
    Headquarter * pHeadquarter;    // 指向司令部的指针
    int kindNo;                    // 武士种类
    int weaponNum;                 // 武器的数量
    int weaponNo[2];               // 武器
    int no;                        // 武士编号
    double morale;                 // 士气
    int loyalty;                   // 忠诚度
public:
    static string names[warrior_num];
    static string weapons[weapon_num];
    static int initialLifeValue[warrior_num];
    warrior(Headquarter *p, int number, int kindNumber ); // 武士的构造函数
    void PrintResult(int nTime);
    void PrintInformation();
};

class Headquarter
{
private:
    int totalLifeValue;         // 总的生命元
    bool stopped;
    int totalWarriorNumber;
    int color;
    int curMakingSeqIdx;                     // 当前要制造的武士是制造序列中的第几个
    int warriorNum[warrior_num];             // 存放每种武士的数量
    warrior *pWarriors[1000];                // 指向武士
public:
    friend class warrior;                       // 武士是司令部的友元
    static int makingSeq[2][warrior_num];    // 制造武士的顺序
    void Init(int color_, int lv);
    ~Headquarter();                         // 析构函数
    int Produce(int nTime);
    string GetColor();                         // 返回的string
};

warrior::warrior(Headquarter * p,int no_,int kindNo_){
    no = no_;
    kindNo = kindNo_;
    pHeadquarter = p;
    
    if(kindNo!=3 && kindNo!=4 ){                            // dragon 0 ninja 1 iceman 2 lion 3 wolf 4   3 和 4没有武器 1 两把
        if(kindNo == 1)
            weaponNum = 2;
        else
            weaponNum = 1;
    }
    else
        weaponNum = 0;
    for(int i=0;i<weaponNum;i++){                           //武器编号是 武士编号%3
        weaponNo[i] = (no + i) %3;
    }
    if(kindNo == 0) morale = (double)p->totalLifeValue/initialLifeValue[0];  // 龙 司令部里有对应的信息
    else morale = 0;
    if(kindNo == 3 ) loyalty = p-> totalLifeValue;           // 狮子士气
    else loyalty = 0;
}

void warrior :: PrintResult(int nTime)
{
    string color = pHeadquarter->GetColor();
    printf("%03d %s %s %d born with strength %d,%d &s in %s headquarter\n",
           nTime,color.c_str(),names[kindNo].c_str(),no,initialLifeValue[kindNo],
           pHeadquarter->warriorNum[kindNo],names[kindNo].c_str(),color.c_str());
    // pHeadquarter->warriorNum[kindNo],names[kindNo].c_str(),color.c_str());
}

void warrior::PrintInformation()
{
    if(kindNo == 0) printf("It has a %s, and it's morale is %.2f\n",weapons[weaponNo[0]].c_str(),morale);       // dragon
    if(kindNo == 1) printf("It has a %s and %s\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str());   // ninja
    if(kindNo == 2) printf("It has a %s\n",weapons[weaponNo[0]].c_str());                                       // iceman
    if(kindNo == 3) printf("It's loyalty is %d\n",loyalty);                                                     // lion
}

void Headquarter::Init(int color_, int lv){
    color = color_;
    totalLifeValue = lv;
    totalWarriorNumber = 0;
    stopped = false;
    curMakingSeqIdx = 0;
    for(int i=0;i<warrior_num;i++)
        warriorNum[i] = 0;
}
Headquarter:: ~Headquarter(){
    for(int i=0;i<totalWarriorNumber;i++)
        delete pWarriors[i];
}
int Headquarter::Produce(int nTime)
{
    if(stopped)
        return 0;
    
    int searchingTimes = 0;
    while(warrior::initialLifeValue[makingSeq[color][curMakingSeqIdx]] > totalLifeValue && searchingTimes < warrior_num){
        curMakingSeqIdx = (curMakingSeqIdx + 1)/ warrior_num;
        searchingTimes++;
    }
    int kindNo = makingSeq[color][curMakingSeqIdx];
    if(warrior:: initialLifeValue[kindNo]>totalLifeValue){
        stopped = true;
        if (color ==0)
            printf("%03d red headquarter stops making warriors \n",nTime);
        else
            printf("%03d blue headquarter stops making warriors \n",nTime);
        return 0;
    }
    
    totalLifeValue -= warrior::initialLifeValue[kindNo];                              // 生命元扣除
    curMakingSeqIdx = (curMakingSeqIdx+1) % warrior_num;                              // 当前的序号
    pWarriors[totalWarriorNumber] = new warrior( this, totalWarriorNumber+1,kindNo);  // 生产武士 指过去
    warriorNum[kindNo]++;
    pWarriors[totalWarriorNumber]-> PrintResult(nTime);
    pWarriors[totalWarriorNumber]-> PrintInformation();
    totalWarriorNumber++;
    return 1;
    
}
string Headquarter::GetColor()
{
    if(color ==0)
        return "red";
    else
        return "blue";
}

string warrior:: names[warrior_num] = {"dragon","ninja","iceman","lion","wollf"};
string warrior:: weapons[weapon_num] = {"sword","bomb","arrow"};
int warrior ::initialLifeValue[warrior_num];
int Headquarter::makingSeq[2][5] ={{2,3,4,1,0},{3,0,1,2,4}};

int main()
{
    int times;   // 次数
    int totallife;
    Headquarter red, blue;
    scanf("%d",&times);
    int CaseNo = 1;
    while (times--){
        printf("Case:%d\n",CaseNo++);
        scanf("%d",&totallife);
        for(int i=0;i<warrior_num;i++){
            scanf("%d",& warrior::initialLifeValue[i]);
        }
        red.Init(0, totallife);
        blue.Init(1, totallife);
        int nTime = 0;
        while(true){
            int res1 = red.Produce(nTime);
            int res2 = blue.Produce(nTime);
            if(res1==0&&res2==0)
                break;
            nTime++;
        }
    }
    return 0;
}

