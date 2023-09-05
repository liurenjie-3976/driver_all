#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

#include "data_global.h"

typedef struct msg_pack
{
    char msg_type;
    char text[27];
}link_datatype;


typedef struct _node_
{
    link_datatype data;
    struct _node_ *next;


}linknode,*linklist;

extern linklist CreateEmptyLinklist();
extern int EmptyLinklist(linklist L);
extern linklist GetLinknode(linklist L, int i);
extern int InsertLinknode(link_datatype x);

#endif