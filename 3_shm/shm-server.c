/* shm_server.c : the time server using shared memory, a bizarre application  */
#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SEG_SIZE ((size_t)100) /*size of segment*/

/**
 * 1、创建我们所要的key
 * 2、用这个key来进行创建一个共享内存空间
 * 3、把这个共享的内存空间，加载到我们的进程当中
 * 4、把这个共享内存空间，从我们的进程当中分离出去
**/
#define	TIME_MEM_KEY	99	/* like a filename      */


int main()
{
    int n;
    long now;
    key_t key_info;

    if ((key_info = ftok("hello.c", 12) < 0))
    {
        perror("ftok info");
        exit(-1);
    }

    /*创建一个分享内存空间*/
    printf("seg_id:%d\n", key_info);

    key_info=25;

    int seg_id = shmget(key_info, SEG_SIZE, IPC_CREAT | 0777);
    

    /* attach to it and get a pointer to where it attaches */
    char *mem_ptr = shmat(seg_id, NULL, 0);
    printf("The time, direct from memory: ..%d \n", mem_ptr);

    /* run for a minute */

    for (n = 0; n < 60; n++)
    {
        time(&now); /* get the time */
        // 这边是把time的时间转换为我们能够看的时间。
        strcpy(mem_ptr, ctime(&now)); /* copy to shared memory */
        printf("The time, direct from memory: ..%s", mem_ptr);
        sleep(1);
    }
    shmctl(seg_id, IPC_RMID, NULL);
}