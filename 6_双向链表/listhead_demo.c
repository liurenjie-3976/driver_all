#include <stdio.h>
#include <stdlib.h>

struct my_list_node
{
    int data;
    struct my_list_node *next;
    struct my_list_node *prev;
};

// 初始化链表节点

void init_list_node(struct my_list_node *node, int data)
{

    node->data = data;
    node->next = NULL;
    node->prev = NULL;
}

// 在链表尾部插入节点
void list_add_tail(struct my_list_node *head, struct my_list_node *new_node)
{
    struct my_list_node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new_node;
    new_node->prev = tail;
}

// 删除特定数值的节点
void list_remove_by_value(struct my_list_node *head, int target_value) {
    struct my_list_node *current = head->next;
    while (current != NULL) {
        if (current->data == target_value) {
            struct my_list_node *to_remove = current;
            current = current->next;
            list_remove(to_remove);
        } else {
            current = current->next;
        }
    }
}

// 删除节点
void list_remove(struct my_list_node *node)
{
    if (node->prev != NULL)
    {
        if(node->prev->next==NULL){
            exit(1);
        }
        node->prev->next = node->next;
        // 这边是非空的情况下的数据，所以这是一个正常的情况。
    }
    if (node->next != NULL)
    {
        if(node->next->prev==NULL){
            exit(1);
        }
        node->next->prev = node->prev;
    }
    free(node);
}

// 修改节点的数据
void list_modify(struct my_list_node *node, int new_data)
{
    node->data = new_data;
}

// 查找节点
struct my_list_node *list_find(struct my_list_node *head, int target_data)
{
    struct my_list_node *current = head->next;
    while (current != NULL)
    {
        if (current->data == target_data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// 遍历链表并打印节点数据
void list_print(struct my_list_node *head)
{
    struct my_list_node *current = head->next;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 在链表头部插入节点
void list_add_head(struct my_list_node *head, struct my_list_node *new_node)
{
    new_node->next = head->next;
    new_node->prev = head;
    if (head->next != NULL)
    {
        head->next->prev = new_node;
    }
    head->next = new_node;
}

int main()
{
    struct my_list_node head;
    init_list_node(&head, 0);

    struct my_list_node node1, node2, node3;
    init_list_node(&node1, 10);
    init_list_node(&node2, 20);
    init_list_node(&node3, 30);

    list_add_tail(&head, &node1);
    list_add_tail(&head, &node2);
    list_add_tail(&head, &node3);

    printf("Original list contents: ");
    list_print(&head);

    struct my_list_node *found_node = list_find(&head, 20);

    if (found_node)
    {
        list_modify(found_node, 25);

        printf("List after modification: ");

        list_print(&head);
    }

    struct my_list_node new_node;
    init_list_node(&new_node, 5);
    list_add_head(&head, &new_node);
    printf("List after adding at head: ");
    list_print(&head);

    // list_remove_by_value(&head, 25);

    // list_remove(&new_node);
    printf("List after removing node 2: ");
    list_print(&head);

    return 0;
}
