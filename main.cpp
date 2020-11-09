#include"DCList.h"

int main()
{
    DCList<int> mylist;
    for (int i = 0; i < 5; i++)
    {
        mylist.PushBack(i);
    }
    mylist.ShowList();
    cout <<"此时链表长度为"<<mylist.length()<<"\n"<<endl; 

    for (int i = 0; i < 5; i++)
    {
        mylist.PushFront(i);
    }
    mylist.ShowList();
    cout <<"此时链表长度为"<<mylist.length()<<"\n"<<endl; 

    for (int i = 0; i < 12; i++)
    {
        mylist.PopBack();
        mylist.ShowList();
        if (mylist.length()==0)
        {
            cout <<"此时链表为空"<<"\n"<<endl; 
        }
        else
        {
            cout <<"此时链表长度为"<<mylist.length()<<"\n"<<endl; 
        }
    }
}