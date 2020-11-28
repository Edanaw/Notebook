#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
typedef int ElemType,Status;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// initial -> head insrt
Status CreateListHead_H(LinkList L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s;
    L->next = NULL;
    int i;
    ElemType ele;
    for (i = 0; i < n; ++i) {
        scanf("%d", &ele);
        s = (LinkList)malloc(sizeof(LNode));
        s->data = ele;
        s->next = L->next;
        L->next = s;
    }
    return OK;
}

// intial -> rear insert
Status CreateListRear_H(LinkList L, int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;
    LNode *r = L;

    int i;
    ElemType ele;
    for (i = 0; i < n; ++i) {
        /* code */
        scanf("%d", &ele);
        s = (LinkList)malloc(sizeof(LNode));
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return OK;
}

// find by value
LNode *GetList_Elem(LinkList L, ElemType value)
{
    LNode *node = L->next;
    while (node != NULL && node->data != value) {
        /* code */
        node = node->next;
    }
    return node;
}

// find by index
LNode *GetList_Pos(LinkList L, int pos)
{
    if (pos == 0) {
        return L;
    } else if (pos < 0) {
        return NULL;
    }

    LNode *ndoe = L;

    int j = 0;
    while (node && j < pos) {
        /* code */
        node = node->next;
        ++j;
    }

    if (node == NULL) {
        printf("insert pos is out of range!\n");
        // fprintf("");
    }
    return Node;
}

// Insert (using function GetList_Pos)
Status InsertElem(LinkList L, int pos, ElemType ele)
{
    LNode *node;
    LNode *new_node = (LinkList)malloc(sizeof(LNode));

    new_node->data = ele;
    node = GetList_Pos(L, pos - 1);
    new_node->next = node->next;
    node->next = new_node;
    return OK;
}

// Delete (using function GetList_Pos)
Status DeleteElem(LinkList L, int pos, ElemType *ele)
{
    LNode *node;
    LNode *del_node = (LinkList)malloc(sizeof(LNode));
    node = GetList_Pos(L, pos - 1);
    del_node = node->next;
    *del_node = del_node->next;
    free(del_node);
    return OK;
}

// print 
void PrintList(LinkList L)
{
    LNode *node = L->next;
    printf("the element of linklist is: \n");
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n\n");
}

// Merge (not understand)
void MergeList(LinkList La, LinkList Lb, LinkList Lc)
{
    LNode *nodea = La->next;
    LNode *nodeb = Lb->next;

    LNode *nodec = (LinkList)malloc(sizeof(LNode));
    // ???
    Lc = nodec = La;

    while (nodea != NULL && nodeb != NULL) {
        if (nodea->data <= nodeb->data) {
            nodec->next = nodea;
            nodec = nodea;
            nodea = nodea->next;
        } else {
            nodec->next = nodeb;
            nodec = nodeb;
            nodeb = nodeb->next;
        }
    }

    nodec->next = nodea ? nodea : nodeb;
    free(nodec);
}

#endif  //!__LIST__H__