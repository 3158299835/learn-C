#define _CRT_SECURE_NO_WARNINGS

#include "3ziqi_game.h"




int game(int a)
{

	//��������
	char Board[ROW][COL] = { 0 };

	//��ʼ������
	InitBoard(Board, ROW, COL);
	
	int Power = 1;//���������Ƿ�ѭ��
	int role = 0; // 0Ϊ����  1Ϊ���
	while (Power)
	{	
		switch (a)
		{
			case 0:
			{
				Power = 0;
				break;//�˳���Ϸ
			}
			case 1://��Ҷ�ս
			{
				role = 1;
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//���1����
				Player1_input(Board, ROW, COL);
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL,role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//���2����
				Player2_input(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 2://���Զ�ս
			{
				role = 0;
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//���1����
				Player1_input(Board, ROW, COL);
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//��������
				Easy_Computer_input(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}

			case 3:
			{
				role = 0;
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//���1����
				Player1_input(Board, ROW, COL);
				//��ӡ����
				DisplayBoard(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}


				//��������
				Hard_Computer_input(Board, ROW, COL);
				//��������
				if (Detprintf(Board, ROW, COL, role) == 0)
				{
					Power = 0;
					DisplayBoard(Board, ROW, COL);
					break;
				}
				break;
			}
		}
	}

}

//��Ϸ�˵�
void menu()
{
	printf("\n***************************************\n");
	printf("*****         1. ��Ҷ�ս         *****\n");
	printf("*****         2. �򵥵���         *****\n");
	printf("*****         3. ���ѵ���         *****\n");
	printf("*****         0. �뿪��Ϸ         *****\n");
	printf("***************************************\n");
}

//��ʼ������
void InitBoard(char Board[ROW][COL],int row,int col)//ע�����ִ�Сд
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		for (j = 0; j < COL; j++)
		{
			Board[i][j] = ' ';  //����ô����к��ж���ֵΪ�ո�
		}
	}
}

//��ӡ����---------------------------------------------------------------------
//   |   |   
//---|---|---
//   |   |
//---|---|---
//   |   |    
// 
//���������һ��
//   |   |   
//---|---|---
//
//��ôֻ��Ҫ�ٴ�ӡһ��|��---|---|---����
//�ٰ�---|����һ�Σ�����Ҫ�ٴ�ӡһ��|�Ϳ���ʵ�ֶ��е�����Ӧ
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for ( j = 0; j < col; j++) //��ӡһ��
		{
			//��ӡ��ʼ�����̵ĵ�i��j�е��ַ�
			printf(" %c ", Board[i][j]);
			//��ӡ | COL-1��
			if (j < row - 1)  //�ٴ�ӡһ�� |
			{
				printf("|");
			}
		}
		//����
		printf("\n");
		if (i < col - 1)//�ٴ�ӡһ��---|---|---
		{
			int k = 0;
			for (k = 0; k < col; k++)
			{
				printf("---");
				if (k < col - 1)//�ٴ�ӡһ�� |
				{
					printf("|");
				}
			}
		}
		printf("\n");//��ӡ��һ��
	}
}

//-----------------------------------------------------------------------------





//-----------------------------------------------------------------------------

//����

//����
//ֻ��������δ�����õ�����
//ע������е����������������겻һ����Ҫ-1.
//ע�ⲻҪ������������̷�Χ



//----------------------------------
//�������1
//�����������1-ROW 1-COL �����ӣ����ӷ���Ϊ*
void Player1_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("���1����>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '*';
			break;//����
		}
		else //���򲻷���Ҫ��
		{
			printf("\n���겻����Ҫ�����������롣\n���뷶ΧӦ��(1-%d 1-%d)\n�Ҳ�Ҫ���������ӵ����������\n\n", row, col);
		}
	}
}
//----------------------------------



//----------------------------------
//�������2
//�����������1-ROW 1-COL �����ӣ����ӷ���Ϊ#
void Player2_input(char Board[ROW][COL], int row, int col)
{
	while (1)
	{
		printf("���2����>:");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (Board[x - 1][y - 1] != '*' && Board[x - 1][y - 1] != '#' && 1 <= x && x <= row && 1 <= y && y <= col)

		{
			Board[x - 1][y - 1] = '#';
			break;//����
		}
		else //���򲻷���Ҫ��
		{
			printf("\n���겻����Ҫ�����������롣\n���뷶ΧӦ��(1-%d 1-%d)\n�Ҳ�Ҫ���������ӵ����������\n\n", row, col);
		}
	}
}
//----------------------------------



//----------------------------------
//��������(��)
//����Զ����ӣ����ӷ���Ϊ#
//�������- 
// srand <stdlib.h>
void Easy_Computer_input(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������\n");
	while (1)
	{
		//����һ�����ֵ���õ��������̷�Χ���������
		x = rand() % row;
		y = rand() % col;
		//���ȥ�������Ľ�ȥ���˳�ѭ����ע�������x��y����0-row-1�ķ�Χ �������������һ��-1
		if (Board[x][y] != '*' && Board[x][y] != '#' && 0 <= x && x <= row - 1 && 0 <= y && y <= col - 1)
		{
			Board[x][y] = '#';
			break;//����
		}
		continue;
	}
}

//----------------------------------



//----------------------------------
// �߼���������
void Hard_Computer_input(char Board[ROW][COL], int row, int col)
{
	printf("��������\n");

	// ����Ƿ���������ʤ���߷�
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '#', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// ���û��������ʤ���߷�������Ƿ�����ֹ���ֻ�ʤ
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (Board[i][j] == ' ' && CheckWin(Board, i, j, '*', row, col))
			{
				Board[i][j] = '#';
				return;
			}

	// ���������������������㣬ѡ��һ����λ��������
	int x, y;
	do
	{
		x = rand() % row;
		y = rand() % col;
	} while (Board[x][y] != ' ');

	Board[x][y] = '#';
}

// �����������ڼ�����λ���Ƿ�ᵼ��������ʤ
int CheckWin(char Board[ROW][COL], int x, int y, char symbol, int row, int col)
{
	Board[x][y] = symbol; // ���������λ�÷�����

	// �����
	int count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && Board[x - i][y] == symbol) ++count;
		if (x + i < row && Board[x + i][y] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// �����
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (y - i >= 0 && Board[x][y - i] == symbol) ++count;
		if (y + i < col && Board[x][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// ���Խ���
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y - i >= 0 && Board[x - i][y - i] == symbol) ++count;
		if (x + i < row && y + i < col && Board[x + i][y + i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	// ��鷴��Խ���
	count = 1;
	for (int i = 1; i < 3; ++i)
	{
		if (x - i >= 0 && y + i < col && Board[x - i][y + i] == symbol) ++count;
		if (x + i < row && y - i >= 0 && Board[x + i][y - i] == symbol) ++count;
	}
	if (count >= 3) return 1;

	Board[x][y] = ' '; // ��������
	return 0;
}


//----------------------------------


//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
//�������⺯��
//�ж��У��У���ԽǺ��ҶԽ��Ƿ���������ͬ
//���������� *  #   P   C  �ֱ��ʾ ���1Ӯ����һ����Ӯ��ƽ�֣�����
//���ǵ�һ���뵽ð������ļ���
int Detection(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)  // һ��һ�м������������ͬ
	{
		for (j = 0; j < col - 2; j++)  // �������Ա����������Ƿ���ͬ��������ѭ�� 2 �� 1 = 2 & 2 = 3 ͬʱ���ʱ����������
		{
			if (Board[i][j] == Board[i][j + 1] && Board[i][j + 1] == Board[i][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// �м��
	for (i = 0; i < col; i++)  // һ��һ�м������������ͬ
	{
		for (j = 0; j < row - 2; j++)  // �������Ա����������Ƿ���ͬ��������ѭ�� 2 �� 1 = 2 & 2 = 3 ͬʱ���ʱ����������
		{
			if (Board[j][i] == Board[j + 1][i] && Board[j + 1][i] == Board[j + 2][i])
			{
				if (Board[j][i] == '*')
				{
					return '*';
				}
				else if (Board[j][i] == '#')
				{
					return '#';
				}
			}
		}
	}

	// �����Ͻǿ�ʼ�����½ǵĶԽ��߼��
	for (i = 0; i < row - 2; i++)  // �����е���ʼλ��
	{
		for (j = 0; j < col - 2; j++)  // �����е���ʼλ��
		{
			if (Board[i][j] == Board[i + 1][j + 1] && Board[i + 1][j + 1] == Board[i + 2][j + 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}

	// �����Ͻǿ�ʼ�����½ǵĶԽ��߼��
	for (i = 0; i < row - 2; i++)  // �����е���ʼλ��
	{
		for (j = col - 1; j >= 2; j--)  // �����е���ʼλ��
		{
			if (Board[i][j] == Board[i + 1][j - 1] && Board[i + 1][j - 1] == Board[i + 2][j - 2])
			{
				if (Board[i][j] == '*')
				{
					return '*';
				}
				else if (Board[i][j] == '#')
				{
					return '#';
				}
			}
		}
	}
	// �ж��Ƿ�Ϊƽ��
	for (i = 0; i < row ; i++)  // ����ÿһ��ÿһ���Ƿ񲻵���' '
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
			{
				return 'C';//��һ�����ǿո�ͷ��ؼ���
			}
		}

	}
	return 'P';//����Ϊƽ��
}
//-----------------------------------------------------------------------------




//-----------------------------------------------------------------------------
//��ⷵ��ֵ����ӡ����
int Detprintf(char Board[ROW][COL], int row, int col, int role)
{
	//���
	switch (Detection(Board, ROW, COL))
	{
	case '*':
	{
		if (role = 1)
		{
			printf("���1���ʤ��\n");
			return 0;
		}
		if (role = 0)
		{
			printf("��һ��ʤ��\n");
			return 0;
		}
	}
	case '#':
	{
		if (role == 1)
		{
			printf("���2���ʤ��\n");
			return 0;
		}
		if (role == 0)
		{
			printf("���Ի��ʤ��\n");
			return 0;
		}
	}
	case 'P':
	{
		printf("ƽ��\n");
		return 0;
	}
	case 'C':
	{
		return 1;
	}
	}
}
//-----------------------------------------------------------------------------