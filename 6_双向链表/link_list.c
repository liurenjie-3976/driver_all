/*
从 zigbee采集到的数据存放的链表
*/

#include "link_list.h"
#include "data_global.h"

linklist envlinkHead,envlinkTail;

linklist  CreateEmptyLinklist(){
    linklist h;
    h=(linklist)malloc(sizeof(linknode));
    envlinkTail=h;
    h->next=NULL;
    return h;
}