#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int ElemType,Status;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//初始化-头插法 
Status CreateList_H(LinkList &L,int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s;
	L->next = NULL;
	int i;
	ElemType ele;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&ele);
		s = (LNode*)malloc(sizeof(LNode));		
		s->data = ele;
		s->next = L->next;
		L->next = s;
	}
	return OK;
} 

//初始化-尾插法
Status CreateList_T(LinkList &L,int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *s;
	LNode *r = L;
	int i;
	ElemType ele;
	for(i = 0;i < n;i++)
	{
		scanf("%d",&ele);
		s = (LNode*)malloc(sizeof(LNode));		
		s->data = ele;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return OK;
} 

//按照值查找 
LNode * GetList_Elem(LinkList L,ElemType find_ele)
{
	LNode * node = L->next;
	while(node!=NULL && node->data != find_ele)
	{
		node = node->next;
	}
	return node;
}

//按照位置查找 
LNode * GetList_Pos(LinkList L,int pos)
{
	if(pos == 0)
	{
		return L;
	}
	if(pos < 1)
	{
		return NULL;
	}
	LNode * node = L;
	int j = 0;
	while(node && j < pos)
	{
		
		node =node->next;
		j++;
	}
	if(node == NULL)
	{
		printf("插入位置超出范围！");
		return NULL;	
	}
	return node;
}

//插入 
Status InserElem(LinkList &L,int pos,ElemType inser_ele)
{
	LNode * node;
	LNode * new_node = (LNode*)malloc(sizeof(LNode));
	new_node->data = inser_ele;
	node = GetList_Pos(L,pos-1);
	new_node->next = node->next;
	node->next = new_node;
	return OK;
}

//删除
Status DeleteElem(LinkList &L,int pos,ElemType * del_ele)
{
	LNode * node;
	LNode *del_node;
	node = GetList_Pos(L,pos-1);
	del_node = node->next;
	node->next = del_node->next;
	*del_ele = del_node->data; 
	free(del_node);
	return OK;
} 

//输出
void PrintList(LinkList L)
{
	LNode * node = L->next;
	printf("表中元素为:\n"); 
	while(node!= NULL)
	{
		printf("%d\t",node->data);
		node = node->next;
	} 
	printf("\n\n");
}

//合并
void MergeList(LinkList &LA, LinkList &LB, LinkList &LC)
{
	LNode * anode = LA->next;
	LNode * bnode = LB->next;
	LNode * cnode;
	LC = cnode = LA;
	while(anode!= NULL && bnode !=NULL)
	{
		if(anode->data <= bnode->data)
		{
			cnode->next = anode;
			cnode = anode;
			anode = anode->next;
		}
		else
		{
			cnode->next = bnode;
			cnode = bnode;
			bnode = bnode->next;
		}	
	}
	cnode->next = anode?anode:bnode;
	free(LB);
} 

int main()
{
	LinkList L;
	ElemType inser_ele;
	LNode * find_node;
	ElemType del_ele;
	int pos;
	
	printf("初始化链表L，请输入5个数字："); 
	CreateList_T(L,5);
	PrintList(L);
	
	printf("请输入要插入的元素以及插入的位置:(用逗号隔开，输入法为英文)");
	scanf("%d,%d",&inser_ele,&pos);
	InserElem(L,pos,inser_ele); 
	PrintList(L);
	
	printf("请输入要删除元素的位置：");
	scanf("%d",&pos);
	DeleteElem(L,pos,&del_ele); 
	printf("所删除的元素为：%d",del_ele);
	PrintList(L);
	
	printf("请输入要查找的元素的位置：");
	scanf("%d",&pos);
	find_node = GetList_Pos(L,pos);
	printf("所查找的元素为:%d\n",find_node->data); 
	
	
	printf("------接下来为单链表的合并---------\n");
	LinkList LA; 
	LinkList LB; 
	LinkList LC; 
	printf("初始化链表LA，请输入5个数字："); 
	CreateList_T(LA,5);
	printf("初始化链表LB，请输入5个数字："); 
	CreateList_T(LB,5);
	CreateList_T(LC,0);
	MergeList(LA,LB,LC);
	PrintList(LC);
	return 0;
}



// #include <stdio.h>
// #include <stdarg.h>


// double average(int num,...)
// {
//     /* 为num个参数初始化valist */
//     va_list valist;
//     double sum = 0.0;
//     int i;

//     /* 访问所有赋给valist 的参数*/
//     va_start(valist, sum);

//     for (int i = 0; i < num; i++)
//     {
//         sum += va_arg(valist, int);
//     }
    
//     va_end(valist);
//     return sum / num;
// }



// int main()
// {
//     // sprintf();
//     printf("average of 2,3,4,5 = %f\n", average(4, 2,3,4,5));



//     return 0;
// }