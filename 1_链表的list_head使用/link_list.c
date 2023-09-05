/*
从 zigbee采集到的数据存放的链表
*/

#include <stdio.h>

#include <string.h>
#include <stdlib.h>

#include "link_list.h"

linklist envlinkHead,envlinkTail;

linklist CreateEmptyLinklist()
{
	linklist h;
	h = (linklist)malloc (sizeof (linknode));
	envlinkTail = h;
	h->next = NULL;
	return h;
}

int EmptyLinklist (linklist h)
{
	return NULL == h->next;
}

linklist GetLinknode(linklist h)
{
	if (1 == EmptyLinklist (h))	
	{
		return NULL;
	}
	linklist p = h->next;
	h->next = p->next;
	if (p->next == NULL)
		envlinkTail = h;
	return p;
}

int InsertLinknode(link_datatype x)
{
	linklist q = (linklist)malloc (sizeof (linknode));
	if (NULL == q)
	{
		printf ("InsertLinknode Error\n");
		return -1;
	}
	envlinkTail->next = q;
	envlinkTail = q;
	q->data = x;
	q->next = NULL;

	return 0;
}

linklist CreateEmptyCacheList ()
{
	linklist h;
	h = (linklist) malloc (sizeof (linknode));
	h->next = NULL;
	return h;
}

linklist GetCacheNode (linklist h, linklist *t)
{
	if (1 == EmptyLinklist (h))
	{
		return NULL;
	}

	linklist p = h->next;
	h->next = p->next;
	if (p->next == NULL)
	{
		*t = h;
	}
	return p;
}


int InsertCacheNode (linklist *t, link_datatype x)
{
	linklist q = (linklist)malloc (sizeof (linknode));
	if (NULL == q)
	{
		printf ("InsertCacheNode Error\n");
		return -1;
	}
	(*t)->next = q;
	*t = q;
	q->data = x;
	q->next = NULL;

	return 0;
}