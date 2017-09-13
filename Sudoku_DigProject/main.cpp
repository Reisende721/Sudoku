/*********************************************************************************
编译器： Visual Studio 2017 社区版
Github地址: https://github.com/Reisende721/Sudoku 
最后更新时间： 2017/9/13
PS：仅分享学习
*********************************************************************************/

#include <iostream>
#include <cstring>
#include "generator.h"
#pragma warning(disable : 4996)

using namespace std;

int input_check(int argc, char *str[])
{
	if (argc != 3)
	{
		return -1;
	}
	else if ((argc == 3) && !strcmp("-c", str[1]))
	{
		int len = strlen(str[2]);
		if (len == 0)
		{
			return -1;
		}
		for (int i = 0; i < len; ++i)
		{
			if (str[2][i] < '0' || str[2][i] > '9')
			{
				return -1;								// 输入为非数字
			}
		}
		if (len != 1 && str[2][0] == '0')
		{
			return -1;									// 输入的数字>0，但首位为0
		}
		if (len > 8)
		{
			return -2;									// 输入超出范围
		}
		int num = 0;
		for (int i = 0; i < len; ++i) 
		{
			num = num * 10 + str[2][i] - '0';
		}
		if (num > 1451520)
		{
			return -2;									// 输入超出范围
		}
		return num;
	}
	return -1;
}

int main(int argc, char * argv[])
{
	int n;
	if ((n = input_check(argc, argv)) == -1)
	{
		cerr << "Input error! Please re-enter(e.g.:sudoku.exe -c [int]):" << endl;
	}
	else if (n == -2)
	{
		cerr << "0 <= [int] <= 1451520" << endl;
	}
	else
	{
		// 输出文件路径设置
		char filepath[500] = { '\0' };
		strcpy(filepath, _pgmptr);
		*(strrchr(filepath, '\\')) = '\0';
		strcat(filepath, "\\sudoku.txt");

		freopen(filepath, "w", stdout);
		Generator g(n);
		g.sudoku();
	}
	
	return 0;
}