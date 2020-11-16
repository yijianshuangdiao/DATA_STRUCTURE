/*
 * filename:LinkList.h
 * description:单向循环链表
 */
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include<iostream>
#include<cassert>

using namespace std;

namespace LinkList
{
    template<typename ElemType>class ListNode //带模板的结点类
    {
    public:
        ElemType data;            //结点数据域
        ListNode<ElemType> *next; //结点指针域
    };

    template <typename ElemType>
    class LinkList :public ListNode<ElemType>
    {
    private:
        ListNode<ElemType> *Head; //头指针
    public:
        LinkList();  //构造函数
        ~LinkList(); //析构函数
        void ShowList() const; //打印链表
        int length() const;    //求链表长度
        bool PushFront(const ElemType date); //头插数据
        bool PushBack(const ElemType date);  //尾插数据
        bool PopFront() const; //链表头删数据
        bool PopBack() const;  //链表尾删数据
        bool InsertVal(const ElemType key);                //按值插入
        bool InsertPos(const ElemType key, const int pos); //按位插入
        bool Reverse() const;                              //逆置链表
        bool Sort() const;                                 //链表排序
        bool PopVal(const ElemType key);                   //按值删除(递归删除)
        bool PopPos(const int pos);                        //按位删除

        virtual void ClearLinkList() const; //重置链表为空
    };
}

template <typename ElemType>
LinkList::LinkList<ElemType>::LinkList() //构造一个空线性表
{
	Head = new ListNode<ElemType>; //产生头结点
    assert(Head != nullptr);       //存储分配失败退出
    Head->next = Head;             //链表单循环特性
}

template<typename ElemType>
LinkList::LinkList<ElemType>::~LinkList() //摧毁线性表
{
	ClearLinkList(); //置为空表
    delete Head;   //释放头结点
}

template<typename ElemType>
void LinkList::LinkList<ElemType>::ClearLinkList()const //清除链表
{
	ListNode<ElemType>* p;
	while (Head->next != Head)
	{
        p = Head->next;
        Head->next = p->next;
        free(p);
	}
}

template<typename ElemType>
void LinkList::LinkList<ElemType>::ShowList()const //打印链表
{
    ListNode<ElemType> *p = Head;
    while (p->next!=Head)
    {
        std::cout << p->next->data << "-->";
        p = p->next;
    }
    std::cout << "Nul." << std::endl;
}

template<typename ElemType>
int LinkList::LinkList<ElemType>::length()const //求链表长度
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
bool LinkList::LinkList<ElemType>::PushFront(const ElemType data) //头插数据
{
    ListNode<ElemType> *s = new ListNode<ElemType>;
    assert(s != nullptr);
    s->data = data;
    s->next = Head->next;
    Head->next = s;
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::PushBack(const ElemType data) //尾插数据
{
    ListNode<ElemType> *p = Head->next;
    ListNode<ElemType> *s = new ListNode<ElemType>;
    assert(s != nullptr);
    s->data = data;
    while (p->next!=Head)
    {
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::PopFront() const //头删数据
{
    if(Head->next==Head)
        return false;
    ListNode<ElemType> *p = Head->next;
    Head->next = p->next;
    free(p);
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::PopBack() const //尾删数据
{
    if(Head->next==Head)
        return false;
    ListNode<ElemType> *p = Head->next;
    ListNode<ElemType> *q = Head;
    while (p->next!=Head)
    {
        q = q->next;
        p = q->next;
    }
    q->next = p->next;
    free(p);
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::InsertVal(const ElemType key) //按值插入
{
    ListNode<ElemType> *s = new ListNode<ElemType>;
    ListNode<ElemType> *p = Head;
    s->data = key;
    while (p->next!=Head && p->next->data<s->data)
    {
        p = p->next;
    }
    s->next = p->next;
    p->next = s;
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::InsertPos(const ElemType key, const int pos) //按位插入
{
    if (pos<0 || pos>this->length())
		return false;
    ListNode<ElemType>* s = new ListNode<ElemType>;
    ListNode<ElemType> *p = Head;
    s->data = key;
	for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
    s->next = p->next;
    p->next = s;
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::Reverse() const //逆置链表
{
    if(this->length()==0 || this->length()==1)
        return false;
    ListNode<ElemType> *q, *p = Head->next;
    q = p->next;
    p->next = Head;
    while (q!=Head)
    {
        p = q;
        q = p->next;
        p->next = Head->next;
        Head->next = p;
    }
    return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::Sort() const //链表排序
{
    if (this->length() == 0 || this->length() == 1)
		return false;
	ListNode<ElemType>* r, * q, * p = Head->next;
	q = p->next;
	p->next = Head;
	while (q != Head)
	{
		r = Head;
		p = q;
		q = p->next;
		while (r->next != Head && p->data > r->next->data)
		{
			r = r->next;
		}
		p->next = r->next;
		r->next = p;
	}
	return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::PopVal(const ElemType key) //按值删除（递归删除）
{
    if(this->length()==0)
        return false;
    ListNode<ElemType> *q, *p = Head;
    while (p->next != Head && p->next->data != key)
	{
		p = p->next;
	}
	if (p->next == Head)
	{
		return false;
	}
	else
	{
        q = p->next;
        p->next = q->next;
        free(q);
		if (this->PopVal(key))
			return true;
	}
	return true;
}

template <typename ElemType>
bool LinkList::LinkList<ElemType>::PopPos(const int pos) //按位删除
{
    if (pos<0 || pos>this->length() - 1)
		return false;
    ListNode<ElemType> *q, *p = Head;
    for (int i = 0; i < pos; i++)
	{
		p = p->next;
	}
    q = p->next;
    p->next = q->next;
    free(q);
	return true;
}

#endif