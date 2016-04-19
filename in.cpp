//
// Created by 王若璇 on 16/4/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    string s;
    ofstream f("res.txt",std::ios::out|std::ios::ate);
    if(!f){
        cout<<"can't open file "<<endl;
        exit(0);
    }
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),(int (*)(int))toupper);
    f<<s;
    return 0;
}
