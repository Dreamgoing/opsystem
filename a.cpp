#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
using namespace std;
#define PERM S_IRUSR|S_IWUSR

int main()
{
    key_t shmid;
    int *p_addr, *c_addr;
    pid_t pid;

    if( (shmid = shmget(IPC_PRIVATE, 100, PERM)) == -1 )   { //(1)申请一个共享内存
        cout<<"error"<<endl;
        return 0;
    }
    pid = fork();
    if(pid > 0) {
        cout<<"the father :"<<endl;
        p_addr = (int *)shmat(shmid, 0, 0);//在主进程中获得次共享内存的地址
        memset(p_addr, 0, 100);
        for(int i = 1;i<100;i++){
            p_addr[i] = p_addr[i-1]+1;
        }

        //wait();
        exit(0);
    }
    else if (pid == 0){
        sleep(1);
        cout<<"the son :"<<endl;
        c_addr = (int *) shmat(shmid, 0, 0);//在子进程中获取此共享内存的地址
        for(int i = 0;i<100;i++){
            cout<<c_addr[i]<<" ";
        }
        exit(0);
    }
}
