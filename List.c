#include "List.h"

/* 
    C语言中必须使用二级指针的两种典型情况？
    (1) 需要传递一级指针的数组的时候
    (2) 需要对传入的一级指针做修改的时候

    note: 一级指针变量的传入需要 + &
    c++的做法可以在函数参数中直接使用引用变量
*/ 



int main()
{
    LinkList L = NULL;
    ElemType inser_ele;
    LNode *find_node;
    ElemType del_ele;
    int pos;

    // Intial linklist
    // printf("Initial Linklist, please input five numbers: \n");
    // CreateListHead_H(&L, 5);
    // PrintList(&L);
    // MemoryFree(&L);

    printf("Initial Linklist, please input five numbers: \n");
    CreateListRear_H(&L, 5);
    PrintList(&L);
    MemoryFree(&L);

    // Insert Element
    // printf("please input insert element and pos(seperate them with commas): \n");
    // scanf("%d, %d", &inser_ele, &pos);
    // InsertElem(L, pos, inser_ele);

    // int b = 10;
    // int *a = &b;
    // int **c = &a;

    // *a = 11;
    // printf("c: %d\n", *(*c));


    return 0;
}