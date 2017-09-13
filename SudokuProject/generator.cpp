/*********************************************************************************
�������� Visual Studio 2017 ������
Github��ַ: https://github.com/Reisende721/Sudoku
������ʱ�䣺 2017/9/11
PS��������ѧϰ
*********************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include "generator.h"

using namespace std;

const int N = 9;
const int n = (int)sqrt(N);

Generator::Generator()
{
}

Generator::Generator(int nn) : num(nn)
{
}

Generator::~Generator()
{
}

void Generator::sudoku()                                    // ���ֵ 8! * 36 = 1451520
{
	
	if (num != 0)
	{
		int list[N] = { 7, 1, 2, 3, 4, 5, 6, 8, 9 };        // ��һ�еĳ�ʼֵ
		memcpy(map[0], list, N * sizeof(int));
		do
		{
			map_generate();
			if (num <= 1000)								// �� n <= 1000 ʱѡ��˷���
			{
				print();
			}
			else
			{
				row_exchange();								// ����������
			}
		} while (next_permutation(map[0] + 1, map[0] + N)); // �Ե�һ�г��˵�һ�������⣬��������ȫ����, 8!
	}
}

void Generator::map_generate() // ���� 2-9 ��
{
	int i, j;
	for (i = 1; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (i < n)         // �� 2��3 ��Ϊ��һ�е�Ԫ������ 3 ����λ 
			{
				map[i][j] = map[i - 1][(N + j + n) % N];
			}
			else               // �� 4-9 ��Ϊ��һ�������У�3��Ϊһ���У����� 1 ����λ
			{
				map[i][j] = map[i - n][(j + 1) % N];
			}
		}
	}
}

void Generator::row_exchange() // �������У��ɲ��� 36 �ֱ���
{
	int i, j;
	// order ˵������ʾ 4-6 �е�����������ϴ���
	int order[6][3] = { { 4, 5, 6 },
						{ 4, 6, 5 },
						{ 5, 4, 6 },
						{ 5, 6, 4 },
						{ 6, 4, 5 },
						{ 6, 5, 4 } };
	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < 6; ++j)
		{
			if (num-- > 0)
			{
				row_print(order[0], -3); // 1 - 3
				row_print(order[i], 0);  // 4 - 6
				row_print(order[j], 3);  // 7 - 9
				if (num != 0)
				{
					putchar('\n');
				}
			}
			else
			{
				exit(0);
			}
		}
	}
}

void Generator::print()
{
	num--;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			putchar(map[i][j] + '0');
			if (j < N - 1)
			{
				putchar(' ');
			}
		}
		if ((i < N - 1) || (i == N - 1) && (num != 0))
		{
			putchar('\n');
		}
	}
	if (num == 0)
	{
		exit(0);
	}
	else
	{
		putchar('\n');
	}
}

void Generator::row_print(int list[3], int k)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			putchar(map[list[i] - 1 + k][j] + '0');
			putchar((j == N - 1) ? '\n' : ' ');
		}
	}
}