/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Oct. 19 2020
 Title: Student Array*/
#include<stdio.h>

int main(void)
{
	int i = 0;
	struct student
	{
		int no;
		char name[20];
		int year;
		char department[30];
		int age;
	};

	FILE* fp;
	fopen_s(&fp, "studentdata.txt", "r");

	struct student stu[24];

	for (i = 0; i < 24; i++)
	{
		fscanf_s(fp, "%d %s %d %s %d", &stu[i].no, stu[i].name, sizeof(stu[i].name), &stu[i].year, stu[i].department, sizeof(stu[i].department), &stu[i].age);

		printf("no.%2d Std.ID: %d Name: %s, Year: %d, Department: %s, Age: %d",
			i + 1, stu[i].no, &stu[i].name, stu[i].year, stu[i].department, stu[i].age);
		printf("\n");
	}
	fclose(fp);
	return 0;
}