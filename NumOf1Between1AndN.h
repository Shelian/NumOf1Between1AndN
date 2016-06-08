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
	//���ص�����
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

	//������strN��22345
	//numFirstDigit������10000~19999�еĵ�һ��λ�е���Ŀ
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);

	//��strNΪ12345�����
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;
	//����first��ʾ�ֶη�Ϊ�����֣�length-1��ʾÿһλΪ1�������1111����4�Σ����������ȡ�����
	//�����ظ��㣬��Ϊÿ��ֻ��һ��1����11111������Ҫ�����
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumOf1Between1AndN(int num)
{
	if (num < 0)
		return 0;

	char strN[50];
	//���������ת�����ַ���
	sprintf(strN, "%d", num);

	return NumberOf1(strN);
}


void test2()
{
	cout<<NumOf1Between1AndN(2)<<endl;
}



#endif //__NUMOF1BETWEEN1ANDN_H__