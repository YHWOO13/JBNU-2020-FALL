/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Sep. 27. 2020 - Nov. 3. 2020
 Title: Fortress
 Original: 1st Sem. Lecture: Basic Programming, Prof �����
           School of Computer Science and Engineering, College of Engineering, Chung-Ang University */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<Windows.h>

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

int P1_trajectory(int x, int y, int a, int b, int power, double angle, int gravity, float wind, int arr[][102])
{
	int i= 0, success = 1, fail = 0;
	double increasement_x;
	increasement_x = cos(angle * (3.141592 / 180));
	double increasement_y;
	increasement_y = sin(angle * (3.141592 / 180));
	x = x + 3, y = y - 3;
	while((0 < x && x < 100) && (0 < y && y < 30))
	{
		y = y - (int) ((int)(power) * increasement_y)+gravity;
		x = x + (int) ((int)(power) * increasement_x) + wind;
		gravity=gravity+1;
		if ((0 < x && x < 100) && (0 < y && y < 30))
		{
			arr[y][x] = 79;
			if ((30 - b - 4 <= y && y <= 30 - b+1) && (a - 4 <= x && x <= a+1))
			{
				printf("             =================================Success================================= \n");
				return 1;
			}
		}
		else
		{
			printf("             =================================Fail================================= \n");
			return 0;
		}
	}
}
int P2_trajectory(int x, int y, int a, int b, int power, double angle, int gravity, float wind, int arr[][102])
{
	int i = 0;
	double increasement_x;
	increasement_x = cos(angle * (3.141592 / 180));
	double increasement_y;
	increasement_y = sin(angle * (3.141592 / 180));
	x = x - 3, y = y - 3;
	while ((0 < x && x < 100) && (0 < y && y < 30))
	{
		y = y - (int)((int)(power)*increasement_y) + gravity;
		x = x - (int)((int)(power)*increasement_x) - wind;
		gravity = gravity + 1;
		if ((0 < x && x < 100) && (0 < y && y < 30))
		{
			arr[y][x] = 79;
			if ((30 - b - 4 <= y && y <= 30 - b +1) && (a - 4 <= x && x <= a+1))
			{
				printf("             =================================Success================================= \n");
				return 1;
			}
		}
		else
		{
			printf("             =================================Fail================================= \n");
			return 0;
		}
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
	printf("\n");
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

void direction_wind(float wind)
{
	if (wind == 2)
	{
		printf("The power of wind: >> \n");
	}
	else if (wind == 1)
	{
		printf("The power of wind: > \n");
	}
	else if (wind == 0)
	{
		printf("The power of wind: �� \n");
	}
	else if (wind == -1)
	{
		printf("The power of wind: < \n");
	}
	else if (wind == -2)
	{
		printf("The power of wind: << \n");
	}
}

int main(void) 
{
	srand(time(NULL));
	int x = 0, y = 0, t = 0, f=0, ang = 0, a = 0, b = 0, po = 0;
	int answer = 1, gravity = 2;
	float wind;
	int p1_score=0, p2_score = 0;
	int pitch_length = 102;
	int pitch_height = 31;
	int arr[31][102] = { 0, };
	x = (rand() % 30) + 2;
	y = (rand() % 20);
	a = (rand() % 30) + 41;
	b = (rand() % 20);
	wind = rand() % 4 - 2;
	printf("1. Start Game. \n");
	printf("2. End Game. \n");
	
	printf("Your answer: ");
	scanf_s("%d", &answer);
	system("cls");
	
	while (1)
	{
		if (answer == 1)
		{
			clean_pitch(pitch_height, pitch_length, arr);
			me(x, y, arr);
			enemy(a, b, arr);
			print_pitch(pitch_height, pitch_length, arr);
			printf("\n");

			while (1)
			{
				printf("P1. intensity of power(1-99): ");
				scanf_s("%d", &po);
				while (po > 99 || po < 1)
				{
					printf("out of range. \n");
					printf("P1. intensity of power(1-99): ");
					scanf_s("%d", &po);
				}
				printf("angle(0~90��): ");
				scanf_s("%d", &ang);
				while (ang > 90 || ang < 0)
				{
					printf("out of range. \n");
					printf("angle(0~90��): ");
					scanf_s("%d", &ang);
				}

				clean_pitch(pitch_height, pitch_length, arr);
				me(x, y, arr);
				enemy(a, b, arr);
				system("cls");
				direction_wind(wind);

				if ((P1_trajectory(x + 3, 30 - y - 3, a, b, po, ang, gravity, wind, arr)) == 1)
				{
					p1_score++;
					printf("P1 socre: %d, P2 score:%d \n", p1_score, p2_score);
				}
				else {
					printf("P1 socre: %d, P2 score:%d \n", p1_score, p2_score);
				}
				print_pitch(pitch_height, pitch_length, arr);

				printf("P2. intensity of power(1-99): ");
				scanf_s("%d", &po);
				while (po > 99 || po < 1)
				{
					printf("out of range. \n");
					printf("P2. intensity of power(1-99): ");
					scanf_s("%d", &po);
				}
				printf("angle(0~90��): ");
				scanf_s("%d", &ang);
				while (ang > 90 || ang < 0)
				{
					printf("out of range. \n");
					printf("angle(0~90��): ");
					scanf_s("%d", &ang);
				}

				clean_pitch(pitch_height, pitch_length, arr);
				me(x, y, arr);
				enemy(a, b, arr);
				printf("\n");
				system("cls");
				direction_wind(wind);

				if ((P2_trajectory(a - 3, 30 - b - 3, x, y, po, ang, gravity, wind, arr)) == 1)
				{
					p2_score++;
					printf("P1 socre: %d, P2 score:%d \n", p1_score, p2_score);
				}
				else {
					printf("P1 socre: %d, P2 score:%d \n", p1_score, p2_score);
				}
				print_pitch(pitch_height, pitch_length, arr);
			}
		}
		else if (answer == 2) break;
		else 
		{
			printf("Out of order.\n");
			printf("1. Start Game. \n");
			printf("2. End Game. \n");

			printf("Your answer: ");
			scanf_s("%d", &answer);
			system("cls");
		}
	}
	return 0;
}