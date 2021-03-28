/*
 * filename:LinkList.h
 * description:顺序表
 */
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

const int MAXSIZE = 100; //定义顺序表最大容量为100

#include<iostream>
#include<cassert>

namespace SeqList
{
    template<typename ElemType>class SeqList{
    public:
        SeqList();                      //建立空的顺序表
        SeqList(ElemType a[], int n);   //以数组a[]为初始数据建立一个长度为n的顺序表
        ~SeqList();                     //析构函数
        int Length();                   //返回顺序表的表长
        ElemType Get(int i);            //按位查找,返回第i个元素的值
        int Locate(ElemType x);         //按值查找
        void Insert(int i, ElemType x); //插入操作
        ElemType Delete(int i);         //删除操作
        void PrintList();               //遍历操作
    private:
        ElemType data[MAXSIZE];         //存放数据元素的数组
        int lenght;                     //记录顺序表长度

    public:
        void DelDup(SeqList<ElemType> &L);               //重复元素删除
        bool DelValue(SeqList<ElemType> &L, ElemType x); //删除指定元素
        int DelValue(SeqList<ElemType> &L, ElemType s, ElemType t); //删除顺序表中s到t(s<t)之间的元素

    };
} // namespace SeqList

template<typename ElemType>
SeqList::SeqList<ElemType>::SeqList(){
    lenght = 0;
}

template<typename ElemType>
SeqList::SeqList<ElemType>::SeqList(ElemType a[],int n){
    if(n>MAXSIZE)
        throw "参数异常";
    for (int i = 0; i < n; i++)
    {
        data[i] = a[i];
        lenght++;
    }
}

template <typename ElemType>
int SeqList::SeqList<ElemType>::Length(){
    return lenght;
}

template<typename ElemType>
SeqList::SeqList<ElemType>::~SeqList(){
    
}

template <typename ElemType>
ElemType SeqList::SeqList<ElemType>::Delete(int i){
    if(i<0||i>lenght)
        throw "参数错误";
    for (int j = i - 1; j < lenght; j++)
    {
        data[j] = data[j + 1];  
    }
    lenght--;
    return data[i - 1];
}

template<typename ElemType>
ElemType SeqList::SeqList<ElemType>::Get(int i){
    if(i<0||i>lenght-1)
        throw "参数错误";
    return data[i - 1];
}

template<typename ElemType>
int SeqList::SeqList<ElemType>::Locate(ElemType x){
    for (int i = 0; i < lenght;i++)
    {
        if(data[i]==x)
            return i+1;
    }
    if(data[lenght-1]!=x)
        throw "无匹配数据";
}

template<typename ElemType>
void SeqList::SeqList<ElemType>::Insert(int i,ElemType x){
    if(i<0||i>lenght)
        throw "参数异常";
    for (int j = lenght; j >= i;j--)
    {
        data[j] = data[j - 1];
    }
    data[i-1] = x;
    lenght++;
}

template<typename ElemType>
void SeqList::SeqList<ElemType>::PrintList(){
    for (int i = 0; i < lenght;i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename ElemType>
void SeqList::SeqList<ElemType>::DelDup(SeqList<ElemType> &L){
    
}

template<typename ElemType>
bool SeqList::SeqList<ElemType>::DelValue(SeqList<ElemType> &L, ElemType x){
    int j = 0;
    for (int i = 0; i < L.lenght;i++)
    {
        if(data[i]!=x)
        {
            data[j] = data[i];
            j++;
        }
    }
    if(j==L.lenght)
        return false;
    L.lenght = j;
    return true;
}

template<typename ElemType>
int SeqList::SeqList<ElemType>::DelValue(SeqList<ElemType> &L, ElemType s, ElemType t){
    if(s>=t)
        return false;
    int j0 = -1; //假定-1位置即边界位置0
    int j1 = -1; //假定-1位置即边界位置1
    for (int i = 0; i < L.lenght;++i)
    {
        if(data[i]>s && data[i]<t){
            j0 = i;
            while(data[i]>s && data[i]<t){
                i++;
            }
            j1 = i;
            break;
        }
    }
    if(j0==-1){
        printf("顺序表中无目标元素\n");
    }
    else if(j1==-1){
        L.lenght == j0;
    }
    else{
        int k = j1 - j0; //待删除的元素个数
        for (int z = 0; z < L.lenght - j1;++j0,++j1){
            data[j0] = data[j1];
        }
        L.lenght -= k;
    }
    return true;
}

#endif