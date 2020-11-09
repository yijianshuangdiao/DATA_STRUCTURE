#ifndef _DCLIST_
#define _DCLIST_

#include<iostream>
#include<malloc.h>
#include<assert.h>
using namespace std; 

template<typename ElemType>class ListNode //带模板结点类
{
public:
	ElemType date; //结点数据类型
	ListNode<ElemType>* prio; //结点前驱指针
	ListNode<ElemType>* next; //结点后继指针
};

template<typename ElemType>class DCList :public ListNode<ElemType> //带模板并继承ListNode的链表类
{
public:
	ListNode<ElemType>* Head; //头结点
public:
	DCList(); //默认构造函数
	~DCList(); //析构函数
	void PushBack(const ElemType date); //尾插数据
    void PushFront(const ElemType date); //头插数据
	void PopBack() const; //链表尾删数据
	void PopFront() const; //链表头删数据
	void ShowList() const; //打印链表
	int length() const;	  //求链表长度

	void ClearDCList() const; //重置链表为空
};

template<typename ElemType>
DCList<ElemType>::DCList() //构造一个空线性表
{
	Head = new ListNode<ElemType>; //产生头结点
	assert(Head != nullptr); //存储分配失败退出
	Head->next = Head->prio = Head; //链表双循环特性
}

template<typename ElemType>
DCList<ElemType>::~DCList() //摧毁线性表
{
	ClearDCList(); //置为空表
	delete Head; //释放头结点
}

template<typename ElemType>
void DCList<ElemType>::ClearDCList()const //清除链表
{
	ListNode<ElemType>* p;
	while (Head->next != Head)
	{
		p = Head->next;
		p->next->prio = p->prio;
		p->prio->next = p->next;
		free(p);
	}
}

template<typename ElemType>
void DCList<ElemType>::PushBack(const ElemType date) //链表尾插数据
{
	ListNode<ElemType>* s = new ListNode<ElemType>;
	s->date = date;
	ListNode<ElemType>* p = Head;
	while (p->next != Head)
	{
		p = p->next;
	}
	s->next = p->next;
	s->prio = p;
	p->next->prio = s;
	p->next = s;
}

template<typename ElemType>
void DCList<ElemType>::ShowList()const //打印链表
{
	ListNode<ElemType>* p = Head->next;
	while (p != Head)
	{
		cout << p->date << "-->";
		p = p->next;
	}
	cout << "Nul." << endl;
}

template<typename ElemType>
int DCList<ElemType>::length()const //求链表长度
{
    ListNode<ElemType> *p = Head->next;
    int k = 0; //记录遍历次数
    while (p!=Head)
    {
        p = p->next;
        k++;
    }
    return k;
}

template<typename ElemType>
void DCList<ElemType>::PushFront(const ElemType date) //链表头插数据
{
    ListNode<ElemType>* s = new ListNode<ElemType>;
	s->date = date;
    ListNode<ElemType> *p = Head->next;
    if(p->next==Head)
	{
		PushBack(date);
	}
    s->next = p;
    s->prio = p->prio;
    p->prio->next = s;
	p->prio = s;
}

template<typename ElemType>
void DCList<ElemType>::PopBack()const //链表尾删数据
{
	ListNode<ElemType> *p = Head->next;
	if(p==Head)
	{
		cout << "链表已空" << endl;
		return;
	}
	while(p->next!=Head)
	{
		p = p->next;
	}
	p->prio->next = Head;
	p->next->prio = p->prio;
	free(p);
}

template<typename ElemType>
void DCList<ElemType>::PopFront()const //链表头删数据
{
	ListNode<ElemType> *p = Head->next;
	if(p==Head)
	{
		cout << "链表已空" << endl;
		return;
	}
	p->prio->next = p->next;
	p->next->prio = p->prio;
	free(p);
}

#endif