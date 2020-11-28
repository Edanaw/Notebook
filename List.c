#include "List.h"


int main()
{
    LinkList L;
    ElemType inser_ele;
    LNode *find_node;
    ElemType del_ele;
    int pos;

    // Intial linklist
    printf("Initial Linklist, please input five numbers: \n");
    CreateListHead_H(L, 5);
    PrintList(L);

    // Insert Element
    printf("please input insert element and pos(seperate them with commas): \n");
    scanf("%d, %d", &inser_ele, &pos);
    InsertElem(L, pos, inser_ele);

    return 0;
}