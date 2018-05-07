
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;
/*
 描述
 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
 
 红司令部，City 1，City 2，……，City n，蓝司令部
 
 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
 
 双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
 
 武士在刚降生的时候有一个生命值。
 
 在每个整点，双方的司令部中各有一个武士降生。
 
 红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
 
 蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
 
 制造武士需要生命元。
 
 制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
 
 如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
 
 给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
 
 一共有两种事件，其对应的输出样例如下：
 
 1) 武士降生
 
 输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
 
 表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
 
 2) 司令部停止制造武士
 
 输出样例： 010 red headquarter stops making warriors
 
 表示在10点整，红方司令部停止制造武士
 
 输出事件时：
 
 首先按时间顺序输出；
 
 同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。
 
 输入
 第一行是一个整数，代表测试数据组数。
 
 每组测试数据共两行。
 
 第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
 
 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
 
 输出
 对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
 
 对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
 
 接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
 
 */
//304 备战哈

int timer = 0;



class dragon {
    int number;
    static int HP;
    static int Attack;
    friend class HQ;
public:
    static int show_HP() {
        return HP;
    }
    static void setHP (int hp){
        HP = hp;
    }
};

class wolf {
    int number;
    static int HP;
    static int Attack;
    friend class HQ;
public:
    int show_HP() {
        return HP;
    }
    static void setHP (int hp){
        HP = hp;
    }
};
class lion {
    int number;
    static int HP;
    static int Attack;
    friend class HQ;
public:
    int show_HP() {
        return HP;
    }
    static void setHP (int hp){
        HP = hp;
    }
};
class ninja {
    int number;
    static int HP;
    static int Attack;
    friend class HQ;
public:
    int show_HP() {
        return HP;
    }
    static void setHP (int hp){
        HP = hp;
    }
};

class iceman {
    int number;
    static int HP;
    static int Attack;
    friend class HQ;
public:
    static int show_HP() {
        return HP;
    }
    static void setHP (int hp){
        HP = hp;
    }
};

class HQ{
    int num;
    int wolf_num;
    int dragon_num;
    int lion_num;
    int iceman_num;
    int ninja_num;
    int produce_order;
public:
    char name[10];
    char order[10];
    bool stopinfo;
    int total_HP;
    bool able_produce;
    HQ(int a1):num(0), wolf_num(0),dragon_num(0),lion_num(0),iceman_num(0),ninja_num(0),produce_order(0),total_HP(a1){}
    void sname(){
        for(int i=0;name[i]!='\0';i++)
            cout << name[i];
    }
    bool check(){
        if(total_HP >= iceman:: HP || total_HP >= lion :: HP || total_HP >= wolf:: HP || total_HP >= ninja:: HP || total_HP >= dragon:: HP)
            able_produce = true;
        else
            able_produce = false;
        return able_produce;
    }
    //  输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
    void produce(){
        if(check()==true){
            num ++;
            int produce_finished = false;
            // cout << order << endl;
            // cout << produce_order << endl;
            while (produce_finished == false) {        // 保证至少要生产出东西；
                switch (order[produce_order]) {
                    case 'd':
                        if(total_HP >= dragon::HP) {
                            dragon_num++;
                            cout<<setw(3)<<setfill('0')<< timer <<' '<< name <<" dragon "<< num <<" born with strength " << dragon::HP<<','<<dragon_num<< " dragon in the "<<name<< " headquarter"<< endl;
                            total_HP -= dragon:: HP;
                            produce_finished = true;
                        }
                        break;
                    case 'i':
                        if(total_HP >= iceman::HP) {
                            iceman_num++;
                            cout<<setw(3)<<setfill('0')<< timer <<' '<< name <<" iceman "<< num <<" born with strength " << iceman::HP<<','<<iceman_num<< " iceman in the "<<name<< " headquarter"<< endl;
                            total_HP -= iceman:: HP;
                            produce_finished = true;
                        }
                        break;
                    case 'w':
                        if(total_HP>=wolf::HP){
                            wolf_num++;
                            cout<<setw(3)<<setfill('0')<< timer <<' '<< name <<" wolf "<< num <<" born with strength " << wolf::HP<<','<<wolf_num<< " wolf in the "<<name<< " headquarter"<< endl;
                            total_HP -= wolf:: HP;
                            produce_finished = true;
                        }
                        break;
                    case 'l':
                        if(total_HP>=lion::HP){
                            lion_num++;
                            cout<<setw(3)<<setfill('0')<< timer <<' '<< name <<" lion "<< num <<" born with strength " << lion::HP<<','<<lion_num<< " lion in the "<<name<< " headquarter"<< endl;
                            total_HP -= lion::HP;
                            produce_finished = true;
                        }
                        break;
                    case 'n':
                        if(total_HP>ninja::HP){
                            dragon_num++;
                            cout<<setw(3)<<setfill('0')<< timer <<' '<< name <<" ninja "<< num <<" born with strength " << ninja::HP<<','<<ninja_num<< " ninja in the "<<name<< " headquarter"<< endl;
                            total_HP -= ninja::HP;
                            produce_finished = true;
                        }
                        break;
                }
                produce_order ++;       // 生产下一个目标
                produce_order %= 5;
            }
        } else if(stopinfo == false){
            // 输出样例： 010 red headquarter stops making warriors
            cout << setw(3) << setfill('0')<< timer <<' ' << name <<" headquarter stops making warriors" << endl;
            stopinfo = true;
        }
    }
};
// 所有静态成员变量 都要在外面单独声明
int dragon :: HP;
int ninja :: HP;
int iceman :: HP;
int lion :: HP;
int wolf :: HP;
int main()  {
    // 输入测试组数
    int testNum;
    cin >> testNum;
    while(testNum--){
        int total_HP;
        // 第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
        cin >> total_HP;
        HQ hq1(total_HP);
        hq1.name[0] = 'r'; hq1.name[1] = 'e';hq1.name[2]='d';
        hq1.order[0]='i';hq1.order[1]='l';hq1.order[2]='w';hq1.order[3]='n';hq1.order[4]='d';//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
        HQ hq2(total_HP);
        hq2.name[0] = 'b';hq2.name[1] = 'l';hq2.name[2] = 'u';hq2.name[3]='e';
        hq2.order[0]='l';hq2.order[1]='d';hq2.order[2]='n';hq2.order[3]='i';hq2.order[4]='w';//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
        // 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
        int dH,nH,iH,lH,wH;
        cin >> dH;
        cin >> nH;
        cin >> iH;
        cin >> lH;
        cin >> wH;
        dragon:: setHP(dH);
        iceman:: setHP(iH);
        ninja:: setHP(nH);
        wolf::setHP(wH);
        lion::setHP(lH);
        
        // cout << dragon :: show_HP() << endl;
        // cout << hq1.total_HP << endl;
        
        while(hq1.check()||hq2.check()||!hq1.stopinfo||!hq2.stopinfo){
            hq1.produce();
            hq2.produce();
            timer ++;
        }
        
        // hq1.produce();
        // hq2.produce();
        // cout << hq1.name << endl;
        // cout << hq2.name << endl;
        // cout << hq2.name << endl;
    }
    return 0;
}
