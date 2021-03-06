// 01_locks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

#define IMP 30

int GetBits(int a, int i)
{
	return (a >> i) & 1;
}
void SetBits(int &c, int i, int v)
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}
}
void Flip(int &c, int i)
{
	c ^= (1 << i);
}
void Reverse(int &c, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int t1 = GetBits(c, i);
		int t2 = GetBits(c, size - 1 - i);
		SetBits(c, i, t2);
		SetBits(c, size - 1 - i, t1);
	}
}



void Read(int &a, int &b,int &n)
{
	string str1, str2;
	cin >> str1 >> str2;
	n = str1.size();
	for (int i = 0; i < n; i++)
	{
		SetBits(a, i, str1[n - 1 - i] - '0');
		SetBits(b, i, str2[n - 1 - i] - '0');
	}
	
}

int fun(int locks,int keys,int b,int size)
{
	int i = size - 2;
	while (i >= 0 && GetBits(locks, i) == GetBits(b, i))
	{
		i--;
	}
	if (i >= 0)
	{
		if (i == 0)
			return IMP;
		//fun()
		for (; i > 0; i--)
		{
			if (GetBits(locks, i) != GetBits(b, i))
			{
				SetBits(keys, i - 1, 1);
				Flip(locks, i);
				Flip(locks, i - 1);
				if (i - 2 >= 0)
					Flip(locks, i - 2);
			}
		}
		if (GetBits(locks, i) == GetBits(b, i))
		{
			int count = 0;
			for (int j = 0; j < size; j++)
			{
				if (GetBits(keys, j))
					count++;
			}
			return count;
		}
		else
			return IMP;
	}
	else
		return 0;

}
int Press(int a, int b, int size)
{
	if (size == 1)
	{
		return a == b ? 0 : 1;
	}
	if (GetBits(a, size - 1) == GetBits(b, size - 1))
	{
		Reverse(a, size);
		Reverse(b, size);
	}
	int min = size;//最少要按的次数设为size，当无法完成时min设为IMP 30
	int locks=a; //当前锁的状态
	//int results = 0;
	int keys = 0;//按下去的锁的位置
	
	if (GetBits(a,size-1)!=GetBits(b,size-1))
	{
		//将该情况转换为开始相同的情况
		//fun()
		int m1, m2;
		int keys1 = 0;
		//第一种情况 按下第一个锁
		SetBits(keys1, size - 1, 1);
		Flip(locks, size - 1);
		Flip(locks, size - 2);
		m1 = fun(locks, keys1, b, size);
		
		locks = a;
		int keys2 = 0;
		SetBits(keys2, size - 2, 1);
		Flip(locks, size - 1);
		Flip(locks, size - 2);
		if(size-3>=0)
			Flip(locks, size - 3);
		m2 = fun(locks, keys2, b, size);
		min = m1 < m2 ? m1 : m2;
	}
	else
	{
		min = fun(locks, keys, b, size);
	}
	return min;
}
int main()
{
	int a, b,size;
	memset(&a, 0, sizeof(int));
	memset(&b, 0, sizeof(int));
	Read(a, b,size);


	int times = Press(a, b, size);
	if (times == IMP)
		cout << "impossible" << endl;
	else
		cout << times << endl;
 	return 0;
}
