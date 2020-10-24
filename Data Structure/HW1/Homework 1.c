/* Author: Yoonhyuck WOO / JBNU_Industrial Information system Engineering
 Date; Oct. 19 2020
 Title: Student Array*/
#include <stdio.h>

struct student {

	char name[20];
	int year;
	char dept[30];
	int age;
	struct sudent* next;
};

int main()
{
	int noofdata;
	int i = 0;

	FILE* fp;

	struct student data[100];

	fp = fopen("studentdata.txt", "r");

	fscanf(fp, "%s %d %s %d", data[0].name, &data[0].year, data[0].dept, &data[0].age);

	fclose(fp);

	printf("%s, %d, %s, %d\n", data[0].name, data[0].year, data[0].dept, data[0].age);


}
