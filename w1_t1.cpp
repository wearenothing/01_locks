// w1_t1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

#define IMP 30

int Press(char* A1, char *A2, int size)
{
	int min = size;//最少要按的次数设为size，当无法完成时min设为IMP 30
	char keys[30],results[30];
	strcpy(keys, A1);
	for (int i = 0; i < size; i++)
	{
		results[i] = '0';
	}
	if (A1[0] != A2[0])
	{
		//fun()
	}
	else
	{
		results[0] = '0';
		int i = 1;
		while (A1[i] && A1[i] == A2[i])
		{
			results[i] = '0';
			i++;
		}
		if (A1[i])
		{
			if (i == size-1)
				return IMP;
			//fun()
		}
		else
			return 0;

	}
	return min;
}

int main()
{
	char A1[30];
	char A2[30];
	cin >> A1 >> A2;
	int size = strlen(A1);
	
	
	int times = Press(A1, A2, size);
	if (times == 30)
		cout << "impossible" << endl;
	else
		cout << times << endl;
    return 0;
}

