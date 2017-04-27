// WInstruments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

typedef int T;

// WList

// > Typedef
// WList
// Value
struct WData1
{
	int a;
};

struct WList
{
	WData1 wData;		// Value

	struct WList * ptr;	// Pointer
};

// > Function
// WList
// init
struct WList * init(int a) // а- значение первого узла
{
	struct WList * lst;

	// выделение памяти под корень списка
	lst = new WList;

	lst->wData.a = a;
	lst->ptr = NULL; // это последний узел списка


	return(lst);
}

// add
struct WList * addelem(WList *lst, int number)
{
	struct WList *temp, *p;
	temp = new WList;

	p = lst->ptr; // сохранение указателя на следующий узел
	lst->ptr = temp; // предыдущий узел указывает на создаваемый

	temp->wData.a = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент


	return(temp);
}

//
// Main routine
//

int main()
{
	// Test 2x vector OP

	int n = 10;
	int m = 10;

	vector<vector<T> > a(n, vector<T>(m, 1)); // два размера

	for (int k = 0; k < n; k++)
	{
		for (int kk = 0; kk < m; kk++)
		{
			// set
			a[k][kk] = 100 * k + kk;

			// test check
			cout << "a[" << k << ", " << kk << "] = " << a[k][kk] << "\n";
		}
	}
	

	// Test WList
	struct WList * pLst_1 = init(15);
	cout << "pLst_1->wData.a = " << pLst_1->wData.a << "\n";

	pLst_1->wData.a = 20;
	cout << "pLst_1->wData.a = " << pLst_1->wData.a << "\n";

	struct WList * pLst_2 = addelem(pLst_1, 25);
	cout << "pLst_2->wData.a = " << pLst_2->wData.a << "\n";

	// Wait, press key
	getchar();

    return 0;
}

