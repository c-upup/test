#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<stdlib.h>
#include <Windows.h>
IMAGE img;
IMAGE img1;
IMAGE img2;
IMAGE img3;
struct fire  //创建烟花弹结构体类型
	{
		int x, y;//初始坐标
		int max_x, max_y;//烟花最大高度
		IMAGE Img;//保存图片
	}fire;


void fire_boom(int x, int y)//烟花绽放
{
	int a = rand() % 3 + 1;
	loadimage(&img1, "烟花1.png", 200, 200);
	loadimage(&img2, "烟花2.png", 200, 200);
	loadimage(&img3, "烟花3.png", 200, 200);
	if (a == 1)
	{
		putimage(x - 100, y - 100, &img1, SRCINVERT);
		Sleep(1500);
		putimage(x - 100, y - 100, &img1, SRCINVERT);
	}
	else
		if (a == 2)
		{
			putimage(x - 100, y - 100, &img2, SRCINVERT);
			Sleep(1500);
			putimage(x - 100, y - 100, &img2, SRCINVERT);
		}
		else
		{
			putimage(x - 100, y - 100, &img3, SRCINVERT);
			Sleep(1500);
			putimage(x - 100, y - 100, &img3, SRCINVERT);
		}
}


void fire_up()//烟花弹上升
{
	fire.x= rand()%700+100;//烟花弹初始化x=100-800;y=100-400;
	fire.y = 600;
	fire.max_x = fire.x;
	fire.max_y = rand() % 300+100;
	
	while (1)
	{
		loadimage(&fire.Img, "烟花弹.png", 20, 60);
		putimage(fire.x, fire.y, &fire.Img, SRCINVERT);
		if (fire.y > fire.max_y)
		{
			fire.y -= 10;
		}
		else
		{
			fire_boom(fire.x, fire.y);
			break;
		}
		putimage(fire.x, fire.y, &fire.Img, SRCINVERT);
		Sleep(90);
	}
}
int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	initgraph(1000, 600);//初始化图形界面
	loadimage(&img, "2023.png", 1000, 600);
	putimage(0,0,&img,SRCINVERT);//背景图
	for(i=0;i<5;i++)
		fire_up();
	while (1);
	return 0;
}