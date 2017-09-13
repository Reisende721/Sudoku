/*********************************************************************************
�������� Visual Studio 2017 ������
Github��ַ: https://github.com/Reisende721/Sudoku
������ʱ�䣺 2017/9/13
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

void Generator::sudoku()                                // ���ֵ 8! * 36 = 1451520
{
	
	if (num != 0)
	{
		int list[N] = { 7, 1, 2, 3, 4, 5, 6, 8, 9 };    // ��һ�еĳ�ʼֵ
		do
		{
			if (num <= 0)
			{
				break;
			}
			memcpy(map[0], list, N * sizeof(int));
			map_generate();
			map_dig2();                                 // �����ڶ�
			row_array();								// ����������
		} while (next_permutation(list + 1, list + N)); // �Ե�һ�г��˵�һ�������⣬��������ȫ����, 8!
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

void Generator::row_array() // �������У��ɲ��� 36 �ֱ���
{
	int i, j;
	// order ˵������ʾ 4-6 �е�����������ϴ���
	int order[6][3] = { { 4, 5, 6 },
						{ 4, 6, 5 },
						{ 5, 4, 6 },
						{ 5, 6, 4 },
						{ 6, 4, 5 },
						{ 6, 5, 4 } };
	int temp[N][N] = { 0 };
	for (i = 0; i < N; ++i)
	{
		memcpy(temp[i], map[i], N * sizeof(int));
	}
	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < 6; ++j)
		{
			row_exchange(temp, order[0], -3); // 1 - 3
			row_exchange(temp, order[i], 0);  // 4 - 6
			row_exchange(temp, order[j], 3);  // 7 - 9
			print();
		}
	}
}

void Generator::row_exchange(int t[N][N], int list[3], int k)
{
	int i;
	int temp[3][9] = { 0 };
	for (i = 0; i < n; ++i)
	{
		memcpy(temp[i], t[list[i] - 1 + k], N * sizeof(int));
	}
	for (i = 0; i < n; ++i)
	{
		memcpy(map[i + n + k], temp[i], N * sizeof(int));
	}
}

//********************************����Ϊ�����޸ĵĴ����********************
//bool Generator::map_dig()
//{
//	int i, row, col, rr, cc, r_cnt;
//	int lose[N][N + 1] = { 0 };
//	int count = 0, cnt;
//	bool flag = true;
//	const int min_cnt = 30, max_cnt = 65;
//	cnt = rand() % 35 + 30;
//	for (i = 0; i < N; ++i)
//	{
//		memset(state[i], false, N * sizeof(bool));
//	}
//	for (i = 0; i < N; ++i)
//	{
//		rr = i / 3 * n;
//		r_cnt = rand() % (cnt / 9) + 2;
//		for (row = rr; row < rr + 3 && r_cnt > 0; ++row)
//		{
//			cc = i % 3 * n;
//			for (col = cc; col < cc + 3 && r_cnt > 0; ++col)
//			{
//				if (state[row][col] == false)
//				{
//					if (rand() % (r_cnt + 10))
//					{
//						if (check(lose[i], row, col))
//						{
//							lose[i][++lose[i][0]] = map[row][col];
//							map[row][col] = 0;
//							count++;
//							r_cnt--;
//						}
//						state[row][col] = true;
//					}
//				}
//				if (count == cnt)
//				{
//					break;
//				}
//			}
//			if (count == cnt)
//			{
//				break;
//			}
//			else if (0 <= r_cnt && r_cnt < 2 && row == rr + 2)
//			{
//				if (judge_fill())
//				{
//					row = rr - 1;
//				}
//				else
//				{
//					flag = false;
//				}
//			}
//
//		}
//		if (count == cnt)
//		{
//			break;
//		}
//		else if (count < cnt && i == N - 1)
//		{
//			if (count < min_cnt)
//			{
//				if (judge_fill())
//				{
//					i = -1;
//				}
//				else
//				{
//					flag = false;
//				}
//			}
//		}
//	}
//	return flag;
//}

//bool Generator::judge_fill()
//{
//	int i, j;
//	bool flag = true;
//	for (i = 0; i < N; ++i)
//	{
//		for (j = 0; j < N; ++j)
//		{
//			flag *= state[i][j];
//		}
//	}
//	return !flag;
//}

//bool Generator::check(int lose[], int x, int y)
//{
//	return 1;
//	int i = x / 3 * n, j = y % 3 * n, k;
//	if (lose[0] == 0) // ����С�Ź����Ψһ�Ŀ�
//	{
//		return (true & map[x][y]);
//	}
//	for (k = 0; k < N; ++k) // ��������Ψһ�Ŀգ������Ƿ����ظ�
//	{
//		if (map[x][y] > 0 && (map[x][k] == 0 || map[k][y] == 0))
//		{
//			k = -1;
//			break;
//		}
//		if (map[x][y] < 0 && ((map[x][k] == -map[x][y] && k != y) ||(map[k][y] == -map[x][y] && k != x)))
//		{
//			return false;
//		}
//	}
//	if (map[x][y] > 0 && k == -1)
//	{
//		return true;
//	}
//	return check(lose, x, y, map[x][y]);
//}

//bool Generator::check(int lose[], int x, int y, const int m)
//{
//	int i, j, ii = x / 3 * n, jj = y % 3 * n;
//	for (i = ii; i <  ii + n; ++i)
//	{
//		for (j = jj; j < jj + n; ++j)
//		{
//			if (map[i][j] == 0 && state[i][j] == false)
//			{
//				map[i][j] = -m;
//				if (check(lose, i, j))
//				{
//					return false;
//				}
//				else
//				{
//					state[i][j] = true;
//					map[i][j] = 0;
//				}
//			}
//		}
//	}
//	return true;
//}
//********************************����Ϊ�����޸ĵĴ����********************

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

void Generator::map_dig2()
{
	int count = rand() % 20 + 30;
	int i, j, k;
	int m;
	int lose[N] = { 0 };     // ��¼ÿ��С�Ź�������ڶ�����Ŀ
	while (count > 0)        // �����81�������ڶ�
	{
		m = rand() % 81;
		i = m / N;
		j = m % N;
		if (map[i][j] != 0)
		{
			map[i][j] = 0;
			count--;
			lose[i / 3 * n + j / 3]++;
		}
	}
	for (k = 0; k < N; ++k)  // ����δ������2�������ϵ�С����
	{
		while (lose[k] < 2)
		{
			int ii = k / 3 * n;
			int jj = k % 3 * n;
			for (i = ii; i < ii + n; ++i)
			{
				for (j = jj; j < jj + n; ++j)
				{
					if (map[i][j] != 0)
					{
						map[i][j] = 0;
						lose[k]++;
					}
				}
			}
		}
	}
}