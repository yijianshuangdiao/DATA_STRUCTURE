#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include<iostream>
#include<cassert>

using namespace std;

namespace SeqStack
{
    template<typename ElemType>class SeqStack
    {
    private:
        ElemType *base; //栈指针
        int capacity;   //容量
        int top;        //栈顶
        int capacity_inic; //扩容量
    public:
        SeqStack();
        ~SeqStack();
        bool SeqStackInic(); //扩容
        void ShowStack() const; //打印数据
        bool IsEmpty(); //判空
        bool IsFull();  //判满
        int length() const;                //求长度
        bool Push(const ElemType data);    //入栈
        bool Pop();                        //出栈
        ElemType GetTop();                 //获取栈顶元素
        bool ClearStack(); //清空
    };
}

template <typename ElemType>
SeqStack::SeqStack<ElemType>::SeqStack() : capacity(8),top(0),capacity_inic(3)
{
    base = (ElemType *)malloc(sizeof(ElemType) * capacity);
    assert(base != nullptr);
}
    
template<typename ElemType>
SeqStack::SeqStack<ElemType>::~SeqStack()
{
    ClearStack(); //清空数据
    free(base);
    this->base = NULL;
	this->capacity = this->top = 0;
}

template <typename ElemType>
bool SeqStack::SeqStack<ElemType>::SeqStackInic() //栈扩容
{
    ElemType *newbase = (ElemType *)realloc(this->base, sizeof(ElemType) * (this->capacity + capacity_inic));
    assert(newbase != nullptr);
    this->base = newbase;
    this->capacity = capacity + capacity_inic;
    return true;
}

template<typename ElemType>
bool SeqStack::SeqStack<ElemType>::IsEmpty() //判空
{
    return this->top == 0;
}

template<typename ElemType>
bool SeqStack::SeqStack<ElemType>::IsFull() //判满
{
    return this->top == this->capacity;
}

template <typename ElemType>
int SeqStack::SeqStack<ElemType>::length() const //求长度
{
    return this->top;
}

template<typename ElemType>
bool SeqStack::SeqStack<ElemType>::Push(const ElemType data) //入栈
{
    if(this->IsFull() && !this->SeqStackInic())
        return false;
    this->base[this->top++] = data;
    return true;
}

template<typename ElemType>
bool SeqStack::SeqStack<ElemType>::Pop() //出栈
{
    if(this->IsEmpty())
        return false;
    this->top--;
    return true;
}

template<typename ElemType>
bool SeqStack::SeqStack<ElemType>::ClearStack() //清空数据
{
    if(this->IsEmpty())
        return false;
    while(this->top!=0)
    {
        this->top--;
    }
    return true;
}

template <typename ElemType>
void SeqStack::SeqStack<ElemType>::ShowStack() const //打印
{
    for (auto i = this->length(); i > 0; i--)
    {
        std::cout << this->base[i-1] << std::endl;
    }
}

template <typename ElemType>
ElemType SeqStack::SeqStack<ElemType>::GetTop() //获取栈顶元素
{
    if(this->IsEmpty())
        return false;
    return this->base[this->top - 1];
}

#endif