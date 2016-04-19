//
// Created by 王若璇 on 16/4/18.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
    int loopnum = 20;
    srand(time(0));
    while (loopnum--){
        char a = 'a'+rand()%26;
        cout<<a;
    }
    cout<<'\n';
    return 0;
}
