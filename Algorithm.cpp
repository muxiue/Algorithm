// Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

#if __WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

const int width = 5;
const int height = 4;
int input[4][5] = { {1, 2, 3, 4, 5},
{2,3,4,8,13},
{3,4,6,9,14},
{4,5,7,10,16} };

void search1()
{
	

	int flag[4][5] = { 0 };

	int i = 0, j = 0;
	int find = 0;
	cin >> find;
	while (true)
	{
		flag[i][j] = 1;

		if (input[i][j] == find)
		{
			cout << i << "," << j << endl;
			break;
		}

		if (input[i][j] < find)
		{
			if (j < width - 1 && flag[i][j + 1] == 0)
			{
				j++;
				continue;
			}
			else if (i < height - 1 && flag[i + 1][j] == 0)
			{
				i++;
				continue;
			}
		}

		if (input[i][j] > find)
		{
			if (j > 0 && flag[i][j - 1] == 0)
			{
				j--;
				continue;
			}
			if (i < height - 1 && flag[i + 1][j] == 0)
			{
				i++;
				continue;
			}
		}

		// if all is set to 1
	}
}

void search2()
{
	

	int i = 0, j = width - 1;
	int find = 0;
	cin >> find;

	while (i <= height - 1 && j >= 0)
	{
		if (input[i][j] == find)
		{
			break;
		}

		if (input[i][j] < find) {
			i++;
			continue;
		}
		if (input[i][j] > find) {
			j--;
			continue;
		}
	}

	if (i > height - 1 || j < 0)
	{
		cout << "didn't find the number" << endl;
	}
	else
	{
		cout << i << "," << j << endl;
	}
}

void search3(int startPoint, int w, int h, int number, bool inifound)
{
	if (startPoint > height - 1 || w < 0)
	{
		return;
	}

	int i = startPoint, j = w;

	bool found = false;
	while (i <= h && j >= 0)
	{
		if (input[i][j] == number)
		{
			cout << i << "," << j << endl;
			found = true;

			search3(i, j-1, i, number, true);
			search3(i + 1, j, height-1, number, true);
			break;
		}

		if (input[i][j] < number) {
			i++;
			continue;
		}
		if (input[i][j] > number) {
			j--;
			continue;
		}
	}

	if (found == false && inifound == false)
	{
		cout << "didn't find the number" << endl;
	}
}

void search3_start()
{
	int find;
	cin >> find;
	search3(0, width - 1, height - 1, find, false);
}

void printFormat()
{
	int a = 1;
	int b = -1;
	printf("%d, %d", a, b);
	printf("\n");
	printf("%x, %x", a, b);
}

void GetUtf8(unsigned short uni)
{
	unsigned char utf_8[4];

	//if (uni && 0xFFFF)
}

// http://www.runoob.com/cprogramming/c-100-examples.html
void constructInteger()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int m = 1; m <= 4; m++)
			{
				if (i != j && j != m && i != m)
				{
					printf("%d%d%d\n", i, j, m);
				}
			}
		}
	}
}

// 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
void findNumber()
{
	int  i, j, m, n, x;
	for (i = 1; i < 168 / 2 + 1; i++)
	{
		if (168 % i == 0)
		{
			j = 168 / i;
			if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
			{
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n * n - 100;
				printf("%d + 100 = %d * %d\n", x, n, n);
				printf("%d + 268 = %d * %d\n", x, m, m);
			}
		}
	}
}

void findNumber2()
{
	for (int m = 0; ; m++)
	{
		if ((m + 1)*(m + 1) - m * m > 168)
			break;

		int square = m * m;
		int number = square - 100;
		int n = number + 268;
		int i = m+1;
		int square2 = i * i;
		while (square2 <= n)
		{
			if (square2 == n)
				break;
			i++;
			square2 = i * i;
		}
		if (square2 == n)
		{
			printf("Found %d \n", number);
		}
	}
}

// %[flag][width][.precision]type
void printUsage()
{
	int a1 = 20, a2 = 345, a3 = 700, a4 = 22;
	int b1 = 56720, b2 = 9999, b3 = 20098, b4 = 2;
	int c1 = 233, c2 = 205, c3 = 1, c4 = 6666;
	int d1 = 34, d2 = 0, d3 = 23, d4 = 23006783;
	printf("%-9d %-9d %-9d %-9d\n", a1, a2, a3, a4);
	printf("%-9d %-9d %-9d %-9d\n", b1, b2, b3, b4);
	printf("%9d %9d %9d %9d\n", c1, c2, c3, c4);
	printf("%9d %9d %9d %9d\n", d1, d2, d3, d4);
}

void bubble()
{ 
	int a[] = { 4, 5, 1, 7, 1 , 6, 9, 5, 8, 6, 13, 10 };
	int n = 12;
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void mergeSort()
{
	int a[] = { 4, 5, 1, 7, 1 , 6, 9, 5, 8, 6, 13, 10, 12 };
	int n = 13;
	int temp;
	int b[13] = { 0 };

	for (int i = 1; i < n; i = i * 2)
	{
		for (int j = 0; j < n; j = j + i + i)
		{
			int arrayIndex1 = j;
			int arrayIndex2 = j + i;
			int index = j;

			if (j + i >= n)
			{
				while (arrayIndex1 < j + i && arrayIndex1 < n)
				{
					b[index] = a[arrayIndex1];
					arrayIndex1++;
					index++;
				}
				break;
			}

			
			while(true)
			{
				if (arrayIndex1 < j+ i && (a[arrayIndex1] <= a[arrayIndex2] || arrayIndex2 >= j+i+i || arrayIndex2 >= n))
				{
					b[index] = a[arrayIndex1];
					arrayIndex1++;
				}
				else if ((arrayIndex2 < j + i + i && arrayIndex2 < n) && (a[arrayIndex1] > a[arrayIndex2] || arrayIndex1 >= j+i))
				{
					b[index] = a[arrayIndex2];
					arrayIndex2++;
				}
				else
				{
					break;
				}

				index++;
			}
		}

		for (int j = 0; j < n; j++)
			a[j] = b[j];
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
}

void Merge(int sourceArr[], int tempArr[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (sourceArr[i] > sourceArr[j])
			tempArr[k++] = sourceArr[j++];
		else
			tempArr[k++] = sourceArr[i++];
	}
	while (i != midIndex + 1)
		tempArr[k++] = sourceArr[i++];
	while (j != endIndex + 1)
		tempArr[k++] = sourceArr[j++];
	for (i = startIndex; i <= endIndex; i++)
		sourceArr[i] = tempArr[i];
}

//内部使用递归
void RecursiveMergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//避免溢出int
		RecursiveMergeSort(sourceArr, tempArr, startIndex, midIndex);
		RecursiveMergeSort(sourceArr, tempArr, midIndex + 1, endIndex);
		Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
	}
}

void callRecursiveMergeSort()
{
	int a[] = { 4, 5, 1, 7, 1 , 6, 9, 5, 8, 6, 13, 10, 12 };
	int n = 13;
	int b[13];

	RecursiveMergeSort(a, b, 0, n - 1);

	for(int i = 0;i < n; i++)
		printf("%d ", a[i]);
}

void usageOfSizeof()
{
	int arr[] = { 99, 15, 100, 888, 252 };
	int len = sizeof(arr);
	printf("%d", len);
}

void pointer()
{
	const char *str = "Hello World!";
	str = "I love C!";  //正确
	printf("%s", str);
	//str[3] = 'P';  //错误
}

void d2PointerArray()
{
	int a[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
	int *q[4] = {&a[0][0], &a[0][1], &a[0][2], &a[0][3]};
	int *o[4] = { a[0], a[1], a[2] }; //指针数组
	int(*p)[4] = a; // [] priority > * 二维数组指针

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%2d", *(*(p + i) + j));
		}
		printf("\n");
	}
}

void functionPointer()
{
	void(*p)() = d2PointerArray;
	(*p)();
}

void structUsage()
{
	struct {
		char *name;  //姓名
		int num;  //学号
		int age;  //年龄
		char group;  //所在小组
		float score;  //成绩
	} stu1;
	//给结构体成员赋值
	stu1.name = new char[sizeof(char) * 20]{ "Tom" };
	stu1.num = 12;
	stu1.age = 18;
	stu1.group = 'A';
	stu1.score = 136.5;
	//读取结构体成员的值
	printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.score);
	delete[] stu1.name;
}

void random()
{
	srand((unsigned)time(NULL)); // time could only change based on seconds
	int a = rand();
	printf("%d\n", a);
}

void fileOperator()
{
	const int n = 1000;
	char str[n+1];
	FILE *fp;
	errno_t error = fopen_s(&fp, "file.txt", "r");
	if (fp == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}

	while (fgets(str, n, fp) != NULL)
	{
		printf("%s", str);
	}
	printf("\n");

	fclose(fp);

	/*
	while( (ch=fgetc(fp)) != EOF ){
        putchar(ch);
    }

	if(ferror(fp)){
		puts("读取出错");
	}else{
		puts("读取成功");
	}
	//ferror, feof

	// int fputc ( int ch, FILE *fp );
	// 注意，读取到的字符串会在末尾自动添加 '\0'，n 个字符也包括 '\0'。也就是说，实际只读取到了 n-1 个字符，如果希望读取 100 个字符，n 的值应该为 101。例如：
	// int fputs( char *str, FILE *fp );
	// size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );
	// size_t fwrite ( void * ptr, size_t size, size_t count, FILE *fp );

	*/

	const int number = 5;
	int a[number], b[number];
	int i, size = sizeof(int);
	FILE *fp1;
	fopen_s(&fp1, "file1.txt", "wb+");
	if (fp1 == NULL) {  //以二进制方式打开
		puts("Fail to open file!");
		exit(0);
	}

	//从键盘输入数据 并保存到数组a
	for (i = 0; i < number; i++) {
		scanf_s("%d", &a[i]);
	}
	//将数组a的内容写入到文件
	fwrite(a, size, number, fp1);
	//将文件中的位置指针重新定位到文件开头
	rewind(fp);
	//从文件读取内容并保存到数组b
	fread(b, size, number, fp1);
	//在屏幕上显示数组b的内容
	for (i = 0; i < number; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	fclose(fp);
	// 格式化读写函数
	// int fscanf ( FILE *fp, char * format, ... );
	// int fprintf(FILE *fp, char * format, ...);
	// fprintf(stdout, "Input two numbers: ");
	// fscanf(stdin, "%d %d", &a, &b);
	// void rewind ( FILE *fp );
	// int fseek ( FILE *fp, long offset, int origin );
}

#define N 3
struct stu {
	char name[10]; //姓名
	int num;  //学号
	int age;  //年龄
	float score;  //成绩
}boys[N], boy, *pboys;
/*
void fileInsert()
{
	FILE *fp;
	int i;
	pboys = boys;
	if ((fp = fopen("d:\\demo.txt", "wb+")) == NULL) {
		printf("Cannot open file, press any key to exit!\n");
		exit(1);
	}
	printf("Input data:\n");
	for (i = 0; i < N; i++, pboys++) {
		scanf("%s %d %d %f", pboys->name, &pboys->num, &pboys->age, &pboys->score);
	}
	fwrite(boys, sizeof(struct stu), N, fp);  //写入三条学生信息
	fseek(fp, sizeof(struct stu), SEEK_SET);  //移动位置指针
	fread(&boy, sizeof(struct stu), 1, fp);  //读取一条学生信息
	printf("%s  %d  %d %f\n", boy.name, boy.num, boy.age, boy.score);
	fclose(fp);
}
*/
//输入某年某月某日，判断这一天是这一年的第几天？
void calculateDay()
{
	int year, month, day;
	scanf_s("%d %d %d", &year, &month, &day);
	int days;
	int isRunnian = 0;
	switch (month)
	{
	case 1: days = 0; break;
	case 2: days = 31; break;
	case 3: days = 59; break;
	case 4: days = 90; break;
	case 5: days = 120; break;
	case 6: days = 151; break;
	case 7: days = 181; break;
	case 8: days = 212; break;
	case 9: days = 243; break;
	case 10: days = 273; break;
	case 11: days = 304; break;
	case 12: days = 334; break;
	default:printf("data error"); break;
	}

	days += day;

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		isRunnian = 1;
	}

	if (month > 2)
	{
		days += isRunnian;
	}

	printf("this is the %d day", days);
	
}


void printGraphic()
{
	char a = 176, b = 219;
	printf("%c%c%c%c%c\n", b, a, a, a, b);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", a, a, b, a, a);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", b, a, a, a, b);
}

void printMultiply()
{
	int i, j, result;
	printf("\n");
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			result = i * j;
			printf("%d*%d=%-3d", i, j, result); /*-3d表示左对齐，占3位*/
		}
		printf("\n"); /*每一行后换行*/
	}
}

//要求输出国际象棋棋盘
void printChessBoard()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				printf("%c%c", 219, 219);
			else printf("  ");
		}
		printf("\n");
	}
}

void printChessBoard2()
{
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			int w = i % 8;
			int h = j % 8;
			if ((w + h) % 2 == 0)
			{
				printf("c");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

//判断101到200之间的素数。

//将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。
void findOdd()
{
	int n, i;
	cin >> n;
	for (int i = 2; i < n; i++)
	{
		while (n%i == 0)
		{
			cout << i;
			n /= i;
			if (n != 1) cout << "*";
		}
	}
	cout << endl;
}

//最大公约数和最小公倍数
void findGongyueshu()
{
	int a, b, t, r;
	printf("请输入两个数字：\n");
	scanf_s("%d %d", &a, &b);
	if (a < b)
	{
		t = b; b = a; a = t;
	}
	r = a % b;
	int n = a * b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	printf("这两个数的最大公约数是%d，最小公倍数是%d\n", b, n / b);
}

int main()
{
	printChessBoard2();
	return 0;
}
