#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void display(char a[3][3])//显示函数
{
	int i = 0;
	printf(" %d %d %d\n",1,2,3);
	for (i = 0; i < 3; i++)
	{
		printf("%d%c|%c|%c\n",i+1, a[i][0], a[i][1], a[i][2]);
		if (i < 2)
		{
			printf(" ———\n");
		}
	}
}
void player_move(char arr1[3][3])//玩家下棋
{
	int x=0;
	int y = 0;
	while (1)
	{
		printf("玩家输入：");
		scanf("%d%d", &x, &y);//输入棋子坐标
		if (x >=1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (arr1[x-1][y-1] != '*' && arr1[x-1][y-1] != '#')
			{
				arr1[x-1][y-1] = '*';//落子
				break;
			}
			else
				printf("该坐标已有棋子，请重新输入\n");
		}
		else
			printf("该坐标已超过棋盘范围，请重新输入\n");
	}
	display(arr1);//显示落子后的棋盘
}
void computer_move(char arr2[3][3])//电脑下棋
{
	int x, y;
	int z;
	while (1)
	{
		srand((unsigned int)time(NULL));
		x = rand() % 3+1;
		y = rand() % 3+1;//生成随机数:0-2
		z = 10 * x + y;
		if (arr2[x-1][y-1] != '*'&&arr2[x-1][y-1]!='#')//如果该坐标已经有棋子，将产生新坐标直到该坐标可以落子
			break;
	}
	printf("电脑输入：%02d\n",z);
	switch (z)//电脑落子
	{
	case 11:arr2[0][0] = '#';
		break;
	case 12:arr2[0][1] = '#';
		break;
	case 13:arr2[0][2] = '#';
		break;
	case 21:arr2[1][0] = '#';
		break;
	case 22:arr2[1][1] = '#';
		break;
	case 23:arr2[1][2] = '#';
		break;
	case 31:arr2[2][0] = '#';
		break;
	case 32:arr2[2][1] = '#';
		break;
	case 33:arr2[2][2] = '#';
		break;
	}display(arr2);//显示落子后的棋盘
}
int judge(char arr[3][3])//判断胜负
{
	if ((arr[0][0] == '*' && arr[1][0] == '*' && arr[2][0] == '*') || (arr[0][0] == '*' && arr[1][1] == '*' && arr[2][2] == '*') || (arr[0][0] == '*' && arr[0][1] == '*' && arr[0][2] == '*') || (arr[0][1] == '*' && arr[1][1] == '*' && arr[2][1] == '*') || (arr[0][2] == '*' && arr[1][2] == '*' && arr[2][2] == '*') || (arr[1][0] == '*' && arr[1][1] == '*' && arr[1][2] == '*') || (arr[2][0] == '*' && arr[1][1] == '*' && arr[0][2] == '*') || (arr[2][0] == '*' && arr[2][1] == '*' && arr[2][2] == '*'))
	//玩家获胜的条件
	{
		printf("玩家赢\n");
		return 1;
	}

	else
		if ((arr[0][0] == '#' && arr[1][0] == '#' && arr[2][0] == '#') || (arr[0][0] == '#' && arr[1][1] == '#' && arr[2][2] == '#') || (arr[0][0] == '#' && arr[0][1] == '#' && arr[0][2] == '#') || (arr[0][1] == '#' && arr[1][1] == '#' && arr[2][1] == '#') || (arr[0][2] == '#' && arr[1][2] == '#' && arr[2][2] == '#') || (arr[1][0] == '#' && arr[1][1] == '#' && arr[1][2] == '#') || (arr[2][0] == '#' && arr[1][1] == '#' && arr[0][2] == '#') || (arr[2][0] == '#' && arr[2][1] == '#' && arr[2][2] == '#'))
		//电脑获胜的条件
		{
			printf("电脑赢\n");
			return 1;
		}
		else
		{
			printf("继续\n");
		}
}
int main()
{
	int x=0;
	char arr[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
	display(arr);//显示初始化棋盘
	while (1)
	{
		player_move(arr);//玩家下棋
		x=judge(arr);//判断胜负
		if (x == 1)//玩家赢，结束游戏
			break;
		computer_move(arr);//电脑下棋
		x=judge(arr);//判断胜负
		if (x == 1)//电脑赢，结束游戏
			break;
	}
	return 0;
}
