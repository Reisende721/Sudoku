/*********************************************************************************
�������� Visual Studio 2017 ������
Github��ַ: https://github.com/Reisende721/Sudoku
������ʱ�䣺 2017/9/13
PS��������ѧϰ
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
		int num;						// ��������
		int map[9][9];					// ����
		void map_generate();            // ���� 2-9 ��
		void row_array();               // ��������
		//bool map_dig();
		void map_dig2();
		//bool check(int[], int, int);
		//bool check(int[], int, int, const int);
		//bool judge_fill();
		void print();					// ������ӡ
		void row_exchange(int [9][9], int[], int);   // С�н���
};
