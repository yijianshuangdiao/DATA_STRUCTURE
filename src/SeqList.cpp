#include"SeqList.h"

void SeqList_test()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SeqList::SeqList<int> mylist(a, (sizeof(a) / sizeof(int))); //顺序表实例化
    mylist.PrintList();
    //std::cout << mylist.Length() << std::endl;
    //std::cout << mylist.Get(2) << std::endl;
    //mylist.Insert(11, 22);
    //mylist.PrintList();
    //std::cout << mylist.Locate(99) << std::endl;
    //mylist.Delete(8);
    //mylist.DelValue(mylist, 4);
    //std::cout << mylist.DelValue(mylist, 6, 7) << std::endl;
    mylist.DelValue(mylist, 7, 11);
    std::cout << mylist.Length() << std::endl;
    mylist.PrintList();
}