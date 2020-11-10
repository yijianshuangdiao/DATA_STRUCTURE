#include"DCList.h"

int main()
{
    DCList<int> mylist;
    int select = 1;
    int leng = 0; //保存链表长度
    int date = 0; //保存输入数据（可自定义修改类型）
    while (select!=0)
    {
        cout << "        双循环链表测试程序        " << endl;
        cout << "**********************************" << endl;
        cout << "*  [1]头插数据     [2]尾插数据   *" << endl;
        cout << "*  [3]头部删除     [4]尾部删除   *" << endl;
        cout << "*  [5*]按位插入    [6*]按值插入  *" << endl;
        cout << "*  [7*]逆置链表    [8*]自动排序  *" << endl;
        cout << "*  [9*]按值删除    [10*]按位删除 *" << endl;
        cout << "**********************************" << endl;
        cout << "目前缓存链表为：";
        mylist.ShowList();
        leng = mylist.length();
        cout << "目前链表长度为：" << leng <<"\n"<< endl;
        cout << "功能选择（标*为待开发项）>>>>";
        switch (cin >> select,select)
        {
        case 1:
            cout << "请输入头部插入的数据(-1结束)>>>>";
            while(cin >> date,date!=-1)
            {
                mylist.PushFront(date);
            }
            break;
        case 2:
            cout << "请输入尾部插入的数据(-1结束)>>>>";
            while(cin >> date,date!=-1)
            {
                mylist.PushBack(date);
            }
            break;
        case 3:
            mylist.PopFront();
            break;
        case 4:
            mylist.PopBack();
            break;
        case 5:
            break;
        default:
            cout << "选择错误！" << endl;
            break;
        }
        system("cls");
    }
    
    

}