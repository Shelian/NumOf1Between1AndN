#ifndef __NUMOF1BETWEEN1ANDN_H__
#define __NUMOF1BETWEEN1ANDN_H__
#include<iostream>
using namespace std;


int PowerBase10(unsigned int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
		result *= 10;

	return result;
}


int NumberOf1(const char* strN)
{
	//返回的条件
	if (strN == NULL || *strN<'0' || *strN>'9' || *strN == '\0')
	{
		return 0;
	}

	int first = *strN - '0';
	unsigned int length = strlen(strN);

	if (length == 1 && first == 0)
		return 0;

	if (length == 1 && first > 0)
		return 1;

	//假设数strN是22345
	//numFirstDigit是数字10000~19999中的第一个位中的数目
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);

	//数strN为12345的情况
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;
	//乘上first表示分段分为几部分，length-1表示每一位为1，如果是1111就算4次，其他的随便取的情况
	//对于重复点，因为每次只算一个1，如11111他就需要算五次
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumOf1Between1AndN(int num)
{
	if (num < 0)
		return 0;

	char strN[50];
	//输入的数字转换成字符串
	sprintf(strN, "%d", num);

	return NumberOf1(strN);
}


void test2()
{
	cout<<NumOf1Between1AndN(2)<<endl;
}



#endif //__NUMOF1BETWEEN1ANDN_H__