#include"LinkList.h"

void LinkList_test()
{
    LinkList::LinkList<int> mylist; //链表实例化
	int select = 1; //保存功能选择开关
	int pos = 0; //保存数据位置
	int leng = 0; //保存链表长度
	int data = 0; //保存输入数据（可自定义修改类型）
	while (select != 0)
	{
		cout << "        单循环链表测试程序        " << endl;
		cout << "**********************************" << endl;
		cout << "*  [1]头插数据     [2]尾插数据   *" << endl;
		cout << "*  [3]头部删除     [4]尾部删除   *" << endl;
		cout << "*  [5]按位插入     [6]按值插入   *" << endl;
		cout << "*  [7]逆置链表     [8]自动排序   *" << endl;
		cout << "*  [9]按值删除     [10]按位删除  *" << endl;
		cout << "**********************************" << endl;
		cout << "目前缓存链表为：";
		mylist.ShowList();
		leng = mylist.length();
		cout << "目前链表长度为：" << leng << "\n" << endl;
		cout << "功能选择（标*为待开发项）>>>>";
		switch (cin >> select, select)
		{
		case 1:
			cout << "请输入头部插入的数据(-1结束)>>>>";
			while (cin >> data, data != -1)
			{
				mylist.PushFront(data);
			}
			break;
		case 2:
			cout << "请输入尾部插入的数据(-1结束)>>>>";
			while (cin >> data, data != -1)
			{
				mylist.PushBack(data);
			}
			break;
		case 3:
			mylist.PopFront();
			break;
		case 4:
			mylist.PopBack();
			break;
		case 5:
			cout << "请输入要插入的数据>>>>";
			cin >> data;
			cout << "请输入要插入的位置>>>>";
			cin >> pos;
			mylist.InsertPos(data, pos);
			break;
		case 6:
			cout << "请输入要插入的值>>>>";
			cin >> data;
			mylist.InsertVal(data);
			break;
		case 7:
			mylist.Reverse();
			break;
		case 8:
			mylist.Sort();
			break;
		case 9:
			cout << "请输入要删除的值>>>>";
			cin >> data;
			if (!mylist.PopVal(data))
				cout << "删除失败";
			break;
		case 10:
			cout << "请输入要删除的位置>>>>";
			cin >> pos;
			if (!mylist.PopPos(pos))
				cout << "删除失败";
			break;
		default:
			cout << "选择错误！" << endl;
			break;
		}
		system("cls");
	}
}