//
// Created by 王若璇 on 16/4/18.
//
#include <iostream>
#include <cstdio>
#include "err.h"
using namespace std;
void showRes(int *a,int n){
    int pid = getpid();
    cout<<"pid == "<<pid<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
/*创建无名管道需要使用pipe(int _pipedes[2])函数，
这个函数的参数是一个含有两个元素的整型数组，如果执行成功，
这个整形数组将分别存储无名管道读端的文件描述符和写端的文件描述符，利用这两个读、写文件描述符
，我们可以像读写文件一样，操作无名管道的读写。如pipe( )函数调用失败将返回-1。*/
int main(){
    int fd[2];
    pid_t pid;
    if(pipe(fd)<0){
        cout<<"pipe error"<<endl;
    }
    if((pid=fork())<0){
        cout<<"fork error"<<endl;
    } else if(pid>0){ //   parent process
        close(fd[0]);
        for(int i = 0;i<100;i++){
            int *tmp = &i;
            write(fd[1],tmp,sizeof(int));
        }
    } else{
        close(fd[1]);
        sleep(1);
        for(int i= 0;i<100;i++){
            int *tmp;
            ssize_t res = read(fd[0], tmp, sizeof(int));
            cout<<*tmp<<" ";

        }
    }

    return 0;
}

