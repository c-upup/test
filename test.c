#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define boom_num 10
void boom(char arr[ROWS][COLS],int row,int col)//����
{
	int i = 0;
	int x, y = 0;
	for (i = 0; i <boom_num; i++)//�����10����
	{
		again:
		srand((unsigned int)time(NULL));
		x = rand()%row+1;
		y = rand() %col+1;//�����������arr[x][y],0<=x,y<=9
		if (arr[x][y] =='0')
			arr[x][y] = '*';//���ס�*��
		else
			goto again;
	}
}
void display(char arr[ROWS][COLS],int row,int col)//��ӡ
{
	int i, j;
	int m = 0;
	printf("  ");
	for(m=1;m<=col;m++)
		printf("%d ",m);
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
void init_arr(char arr[ROWS][COLS],int rows,int cols,char set)//��ʼ��
{
	int i, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}
void find(char arr[ROWS][COLS],char arr1[ROWS][COLS],int row,int col)
{
	int count = 0;//��¼��Χ�׵ĸ���
	int x, y = 0;
	while (1)
	{
	again:
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//����������ڣ�1-9��1-9����
		{
			if (arr[x][y] == '*')
			{
				printf("�����ˣ���Ϸ����");
				break;
			}
			else
			{
				count = get_count(arr, x, y);
				arr1[x][y] = count + '0';
			}
		}
		else
		{
			printf("��������������");
			goto again;
		}
		display(arr1, ROW, COL);
		win(arr1, ROW, COL);
	}
}
int win(char arr1[ROWS][COLS], int row, int col)
{
	int num = 0;
	int i, j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (arr1[i][j] == '#')
				num++;
		}
	}
	if (num == boom_num)
		printf("��ʤ");
}
int get_count(char arr[ROWS][COLS], int x, int y)
{
	int i, j = 0;
	int num = 0;
	for (i = x-1; i <= x+1; i++)
	{
		for (j = y-1; j <= y+1; j++)
		{
			if (arr[i][j] == '*')//�жϸ������Ƿ�����
				num++;
		}
	}
	return num;
}
int main()
{
	char arr[ROWS][COLS] = {0};
	char arr1[ROWS][COLS] = { 0 };
	init_arr(arr,ROWS,COLS,'0');//��ʼ��
	init_arr(arr1, ROWS, COLS,'#');
	boom(arr,ROW,COL);//����
	display(arr, ROW, COL);
	display(arr1,ROW,COL);//��ӡ��ʼ��ҳ��
	find(arr, arr1, ROW, COL);//����
	return 0;
}