#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include<iostream>
#include<cassert>

using namespace std;

namespace LinkStack
{
    template<typename ElemType>class ListNode //带模板的结点类
    {
    public:
        ElemType data;            //结点数据域
        ListNode<ElemType> *next; //结点指针域
    };

    template <typename ElemType>
    class LinkStack :public ListNode<ElemType>
    {
    private:
        ListNode<ElemType> *Head; //头指针
    public:
        LinkStack();  //构造函数
        ~LinkStack(); //析构函数
        void ShowStack() const;     //打印数据
        int length() const;         //求长度
        bool Push(const ElemType date);  //入栈
        bool Pop() const;                //出栈
        ElemType GetTop() const;         //获取栈顶元素

        virtual void ClearLinkStack() const; //清空数据
    };
}

template <typename ElemType>
LinkStack::LinkStack<ElemType>::LinkStack() //构造一个空栈
{
	Head = new ListNode<ElemType>; //产生头结点
    assert(Head != nullptr);       //存储分配失败退出
    Head->next = Head;             //链表单循环特性
}

template<typename ElemType>
LinkStack::LinkStack<ElemType>::~LinkStack() //摧毁栈
{
	ClearLinkStack(); //置为空栈
    delete Head;   //释放头结点
}

template<typename ElemType>
void LinkStack::LinkStack<ElemType>::ClearLinkStack()const //清除栈
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
void LinkStack::LinkStack<ElemType>::ShowStack()const //打印数据
{
    ListNode<ElemType> *p = Head;
    while (p->next!=Head)
    {
        std::cout << p->next->data << std::endl;
        p = p->next;
    }
}

template<typename ElemType>
int LinkStack::LinkStack<ElemType>::length()const //求栈长度
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
bool LinkStack::LinkStack<ElemType>::Push(const ElemType data) //入栈
{
    ListNode<ElemType> *s = new ListNode<ElemType>;
    assert(s != nullptr);
    s->data = data;
    s->next = Head->next;
    Head->next = s;
    return true;
}

template <typename ElemType>
bool LinkStack::LinkStack<ElemType>::Pop() const //出栈
{
    if(Head->next==Head)
        return false;
    ListNode<ElemType> *p = Head->next;
    Head->next = p->next;
    free(p);
    return true;
}

template <typename ElemType>
ElemType LinkStack::LinkStack<ElemType>::GetTop() const //获取栈顶元素
{
    if(this->length()==0)
        return false;
    return Head->next->data;
}


#endif