#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(char a[3][3])//��ʾ����
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%c|%c|%c\n", a[i][0], a[i][1], a[i][2]);
		if (i < 2)
		{
			printf("������\n");
		}
	}
}
void player_move(char arr1[3][3])//�������
{
	int x=0;
	int y = 0;
	while (1)
	{
		printf("������룺");
		scanf("%d%d", &x, &y);//������������
		if (x >= 0 && x < 3 && y >= 0 && y < 3)
		{
			if (arr1[x][y] != '*' && arr1[x][y] != '#')
			{
				arr1[x][y] = '*';//����
				break;
			}
			else
				printf("�������������ӣ�����������\n");
		}
		else
			printf("�������ѳ������̷�Χ������������\n");
	}
	display(arr1);//��ʾ���Ӻ������
}
void computer_move(char arr2[3][3])//��������
{
	int x, y;
	int z;
	while (1)
	{
		srand((unsigned int)time(NULL));
		x = rand() % 3;
		y = rand() % 3;//���������:0-2
		z = 10 * x + y;
		if (arr2[x][y] != '*'&&arr2[x][y]!='#')//����������Ѿ������ӣ�������������ֱ���������������
			break;
	}
	printf("�������룺%02d\n",z);
	switch (z)//��������
	{
	case 00:arr2[0][0] = '#';
		break;
	case 01:arr2[0][1] = '#';
		break;
	case 02:arr2[0][2] = '#';
		break;
	case 10:arr2[1][0] = '#';
		break;
	case 11:arr2[1][1] = '#';
		break;
	case 12:arr2[1][2] = '#';
		break;
	case 20:arr2[2][0] = '#';
		break;
	case 21:arr2[2][1] = '#';
		break;
	case 22:arr2[2][2] = '#';
		break;
	}display(arr2);//��ʾ���Ӻ������
}
int judge(char arr[3][3])//�ж�ʤ��
{
	if ((arr[0][0] == '*' && arr[1][0] == '*' && arr[2][0] == '*') || (arr[0][0] == '*' && arr[1][1] == '*' && arr[2][2] == '*') || (arr[0][0] == '*' && arr[0][1] == '*' && arr[0][2] == '*') || (arr[0][1] == '*' && arr[1][1] == '*' && arr[2][1] == '*') || (arr[0][2] == '*' && arr[1][2] == '*' && arr[2][2] == '*') || (arr[1][0] == '*' && arr[1][1] == '*' && arr[1][2] == '*') || (arr[2][0] == '*' && arr[1][1] == '*' && arr[0][2] == '*') || (arr[2][0] == '*' && arr[2][1] == '*' && arr[2][2] == '*'))
	//��һ�ʤ������
	{
		printf("���Ӯ\n");
		return 1;
	}

	else
		if ((arr[0][0] == '#' && arr[1][0] == '#' && arr[2][0] == '#') || (arr[0][0] == '#' && arr[1][1] == '#' && arr[2][2] == '#') || (arr[0][0] == '#' && arr[0][1] == '#' && arr[0][2] == '#') || (arr[0][1] == '#' && arr[1][1] == '#' && arr[2][1] == '#') || (arr[0][2] == '#' && arr[1][2] == '#' && arr[2][2] == '#') || (arr[1][0] == '#' && arr[1][1] == '#' && arr[1][2] == '#') || (arr[2][0] == '#' && arr[1][1] == '#' && arr[0][2] == '#') || (arr[2][0] == '#' && arr[2][1] == '#' && arr[2][2] == '#'))
		//���Ի�ʤ������
		{
			printf("����Ӯ\n");
			return 1;
		}
		else
		{
			printf("����\n");
		}
}
int main()
{
	int x=0;
	char arr[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	display(arr);//��ʾ��ʼ������
	while (1)
	{
		player_move(arr);//�������
		x=judge(arr);//�ж�ʤ��
		if (x == 1)//���Ӯ��������Ϸ
			break;
		computer_move(arr);//��������
		x=judge(arr);//�ж�ʤ��
		if (x == 1)//����Ӯ��������Ϸ
			break;
	}
	return 0;
}
