#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <linux/sem.h>
#include <stdio.h>
#include <errno.h>
#include <bits/ipc.h>

#include "sem.h"

#define MAX_RESOURCE    10



int main(void)
{
    key_t key_info = 36;


    int semid;

    printf("key is %d\n", key_info);

    if ((semid = semget(key_info, 1, IPC_CREAT | IPC_EXCL | 0666)) < 0)
    {
        if (errno == EEXIST)
        {
            semid = semget(key_info, 1, 0666);
        }
        else
        {
            perror("semget");
            exit(-1);
        }
    }
    else
    {
        init_sem(semid, 0, 1);
    }

    while (1) 
	{
		//p
		printf("p\n");
		sem_p (semid, 0);
		//进入临界区
		sleep(4);
		//V
		printf("v\n");
		sem_v (semid, 0);
		sleep(3);
	}
	exit(0);
}
