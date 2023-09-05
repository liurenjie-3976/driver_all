#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/stat.h>

int main()
{

    int segment_id, segment_size;
    char *shared_memory;
    struct shmid_ds shmbuffer;
    const int shared_segment_size = 0x6400;
    /*分配*/
    segment_id = shmget(IPC_PRIVATE, shared_segment_size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    /*將把这个得到的内存，加载到这个进程当中*/
    shared_memory = (char *)shmat(segment_id, 0, 0);
    printf("shared memory attached at address %p\n", shared_memory);
    /*
    **这是一个指向 struct shmid_ds 类型的结构体的指针，用于传递获取的共享内存段状态信息。
    **struct shmid_ds 结构体包含了关于共享内存段的多种信息，如权限、大小、附加的进程等。
    **shmctl: 这是一个用于控制共享内存的系统调用函数。
    **它的原型通常是 int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    **其中 shmid 是共享内存标识符，cmd 是控制命令，buf 是一个结构体指针，用于传递或接收信息。
    */
    shmctl(segment_id, IPC_STAT, &shmbuffer);

    segment_size = shmbuffer.shm_segsz;
    printf("segment size: %d\n", segment_size);
    sprintf(shared_memory, "12345678910\n");

    /*把共享内存从进程里面分离出去*/
    shmdt(shared_memory);

    /*绑定到共享内存块*/
    shared_memory = (char *)shmat(segment_id, (void *)0x500000, 0);
    printf("shared memory reattached at address %p\n", shared_memory);

    printf("%s\n", shared_memory);
    /*tuo li*/
    shmdt(shared_memory);
    /*释放内存*/
    shmctl(segment_id, IPC_RMID, 0);
    return;
}