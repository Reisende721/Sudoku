/*********************************************************************************
�������� Visual Studio 2017 ������
Github��ַ: https://github.com/Reisende721/Sudoku
������ʱ�䣺 2017/9/11
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
		void row_exchange();            // ��������
		void print();					// ������ӡ
		void row_print(int [], int);    // С�д�ӡ
};
