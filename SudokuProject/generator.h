/*********************************************************************************
编译器： Visual Studio 2017 社区版
Github地址: https://github.com/Reisende721/Sudoku
最后更新时间： 2017/9/11
PS：仅分享学习
*********************************************************************************/

#pragma once
class Generator
{
	public:
		Generator();
		Generator(int);
		~Generator();
		void sudoku();
	private:
		int num;						// 数独个数
		int map[9][9];					// 数独
		void map_generate();            // 生成 2-9 行
		void row_exchange();            // 大行排列
		void print();					// 数独打印
		void row_print(int [], int);    // 小行打印
};
