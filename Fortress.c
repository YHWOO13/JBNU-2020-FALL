/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Sep. 27 2020
 Title: Fortress
 Original: 1st Sem. Lecture: Basic Programming, Prof �輺��
           School of Computer Science and Engineering, College of Engineering, Chung-Ang University */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//21:��, 22:�� 5:|

int me(int x, int y, int arr[][102]) {
	int i, j = 0;
	arr[30 - y][x] = 77;
	arr[30 - y][x + 1] = 92;
	arr[30 - y][x + 2] = 92;
	for (i = 30 - y - 1; i > 30 - y - 3; i--)
	{
		for (j = x; j < x + 3; j++)
			arr[i][j] = 92;
	}
	arr[30 - y -3][x +3] = 79;
}
int enemy(int a, int b, int arr[][102]) {
	int i, j = 0;
	arr[30 - b][a] = 69;
	arr[30 - b][a - 1] = 92;
	arr[30 - b][a - 2] = 92;
	for (i = 30 - b - 1; i > 30 - b - 3; i--)
	{
		for (j = a; j > a - 3; j--)
			arr[i][j] = 92;
	}
	arr[30 - b - 3][a - 3] = 79;
}
int boundary(int y, int x, int arr[][102])
{
	int i, j = 0;
	//y��
	for (i = 0; i < y-1; i++)
	{
		arr[i][1] = 5;
	}
	//x��
	for (i = 2; i < x; i++)
	{
		arr[29][i] = 95;
	}
}
/*
int power(int x)
{
	if (1 <= x & x <= 10) x = 1;
	else if (11 <= x & x <= 20) x = 2;
	else if (21 <= x & x <= 30) x = 3;
	else if (31 <= x & x <= 30) x = 4;
	else if (41 < x & x < 50) x = 5;
	else if (51 <= x & x <= 60) x = 6;
	else if (61 <= x & x <= 70) x = 7;
	else if (71 <= x & x <= 80)x = 8;
	else if (81 <= x & x <= 90)x = 9;
	else if (91 <= x & x <= 99)x = 10;
	else printf("=============out of range.=============\n");
}

int angle(int x)
{
	if (x = 0) x = 0;
	else if (1 <= x & x <= 15) x = 1;
	else if (16 <= x & x <= 30) x = 2;
	else if (31 <= x & x <= 45) x = 3;
	else if (46 <= x & x <= 60) x = 4;
	else if (61 <= x & x <= 75) x = 5;
	else if (76 <= x & x <= 89) x = 6;
	else if (x = 90)x = 0;
	else printf("=============out of range.=============\n");
}*/
int trajectory(int x, int y, int power, double angle, int gravity, int arr[][102])
{
	int i= 0;
	double increasement_x;
	increasement_x = sin(3.141592 * (angle / 180));
	double increasement_y;
	increasement_y = cos(3.141592 * (angle / 180));

	while(x>100 | y>30)
	{
		arr[y + power * (int)increasement_y][x + power* (int)increasement_x] = 79;
	}
}

int start_point(int height, int length, int arr[][102])
{
	srand(time(NULL));
	int i, j, k = 0;
	int me_x, me_y = 0;
	me_x = (rand() % 30) + 1;
	me_y =1+ (rand() % 20) + 1;

	int enemy_x, enemy_y = 0;
	enemy_x = 40 + (rand() % 30) + 1;
	enemy_y =1+ (rand() % 20) + 1;

	me(me_x, me_y, arr);
	enemy(enemy_y, enemy_x, arr);
}
int print_pitch(int height, int length, int arr[][102])
{
	int i, j, k = 0;
	boundary(height, length, arr);
	
	for (i = 0; i < height ; i++)
	{
		for (j = 0; j < length; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < 101; i++)
	{
		printf(" ");
	}
	printf("%d", 100);
}

void clean_pitch(int height, int length, int arr[][102]) {
	int i = 0, j = 0;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < length; j++)
		{
			arr[i][j]=' ';
		}
	}
}

int main() 
{
	srand(time(NULL));
	int x =0, y=0, a=0, b=0, p=0;
	int wind = 0, answer = 1, gravity = 3;
	int i, k, j = 0;
	int pitch_length = 102;
	int pitch_height = 31;
	int arr[31][102] = { 0, };
	x = 1+ (rand() % 30) + 1;
	y = (rand() % 20) + 1;
	a = 40 + (rand() % 30) + 1;
	b = (rand() % 20) + 1;
	
	printf("1. Start Game. \n");
	printf("2. End Game. \n");
	printf("The power of wind: <<, <, >>, > \n");
	
	//printf("Your answer: ");
	//scanf_s("%d", &answer);
	
	if (answer == 1)
	{
		//start_point(pitch_height, pitch_length, arr);
		clean_pitch(pitch_height, pitch_length, arr);
		me(x, y, arr);
		enemy(a, b, arr);
		print_pitch(pitch_height, pitch_length, arr);
		printf("\n");

		while (1)
		{
			printf("intensity of power(1-99): ");
			if (p > 99 | p<1)
			{
				print("out of range. \n");
			}
			scanf_s("%d", &p);
			printf("angle(0~90��): ");
			if (a > 90 | a<0)
			{
				print("out of range. \n");
			}
			else scanf_s("%d", &a);
			trajectory(x + 3, 30 - y - 3, p, a, gravity, arr);
			print_pitch(pitch_height, pitch_length, arr);
			printf("\n");
		}

	}
	else
	{

	}

	return 0;
}