#include"LinkStack.h"

void LinkStack_test()
{
    LinkStack::LinkStack<int> mylinkstack; //栈实例化
	int select = 1; //保存功能选择开关
	int leng = 0; //保存长度
	int data = 0; //保存输入数据（可自定义修改类型）
	while (select != 0)
	{
		cout << "         顺序栈测试程序           " << endl;
		cout << "*********************************" << endl;
		cout << "*    [1]入栈        [2]出栈     *" << endl;
		cout << "*    [3]打印        [4]清空     *" << endl;
		cout << "*********************************" << endl;
        cout << "目前缓存栈为：" << endl;
        mylinkstack.ShowStack();
		cout << "目前缓存栈栈顶元素为：" << mylinkstack.GetTop() << endl;
		leng = mylinkstack.length();
		cout << "目前栈长度为：" << leng << "\n" << endl;
		cout << "功能选择（标*为待开发项）>>>>";
		switch (cin >> select, select)
		{
		case 1:
			cout << "请输入入栈数据(-1结束)>>>>";
			while (cin >> data, data != -1)
			{
				mylinkstack.Push(data);
			}
			break;
		case 2:
			mylinkstack.Pop();
			break;
		case 3:
			mylinkstack.ShowStack();
			break;
		case 4:
			mylinkstack.ClearLinkStack();
            break;
        default:
			cout << "选择错误！" << endl;
			break;
		}
		//system("cls");
	}
}