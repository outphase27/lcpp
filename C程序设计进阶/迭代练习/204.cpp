//
//  204.cpp
//  ncpp
//
//  Created by zhaoshen liu on 21/4/18.
//  Copyright © 2018 zhaoshen liu. All rights reserved.
//

// 204 括号匹配问题
//


int i=0;  // 下标啊
char str[101] = {0};
int l = 0;    // 0 前面没有左括号；
int r = 0;    // 计数器

void myf(){
    char c = str[i];
    i++;
    
    if(c=='\0'){
        if(l!=0)
            ;
    }
    
    if(c!='\0'){
        if(c=='('){
            l ++;
        }                             //   加一个左括号
        else if(l==0) {               //   到现在没出现左括号
            if(c==')')
                cout << '?';
            else
                cout << ' ';
        }
        else if(c==')') {             // 当前是右 之前有
            l --;
            if(l==0){                 // 之前没有多余的'('
                while(r--)            //r清零；
                    cout<<' ';
            }
            else
                
                
                }
        myf();
    }
}



int main(int argc, const char * argv[]){
    while (cin.getline(str,101)){
        i = 0; //循环里清0
        myf();
        cout << endl;
    }
    
    
    return 0;
}
