#pragma warning(disable:4786)
#include <iostream>
#include <string>
#include <vector>

//#include "vector_base.h"
#include "vector_advanced.h"

void main()
{
	/*********************vector exp3-3************************/
	//push_back()  size()  capacity()  reserve()  resize()
	vector<string>myvt;
	myvt.reserve(4);
	cout << "The size is 4." << endl;
	myvt.push_back("1. Beijing City.");
	myvt.push_back("2. Tianjin City.");
	myvt.push_back("3. Shanghai City.");
	myvt.push_back("4. Chongqing City.");
	cout << "OK!" << endl;
	cout << "成功消除编译警告信息!" << endl;
	vector<string>::iterator it;
	for (it = myvt.begin(); it != myvt.end(); it++)
	{
		cout << *it << endl;
	}

	int m = myvt.size();		//size()
	int n = myvt.capacity();	//capacity()
	int m1 = myvt.max_size();
	cout << "vector:myvt, size is " << m << endl;
	cout << "vector:myvt, capacity is " << n << endl;
	cout << "vector:myvt, maxsize is " << m1 << endl;
	myvt.resize(10);
	cout << "resize: 10." << endl;
	int n1 = myvt.capacity();
	int n2 = myvt.size();
	cout << "vector:myvt, capacity is " << n1 << endl;
	cout << "vector:myvt, size is " << n2 << endl;
	for (it = myvt.begin(); it != myvt.end(); it++)
	{
		if (*it == "")
			cout << "******" << endl;
		cout << *it << endl;
	}

	/****************************exp3-4****************************/
	//empty()  pop_back()  at()  iterator
//	vector_base_test();

	/****************************exp3-5****************************/
	//for_each  count_if
//	vertor_algo_test();

	/****************************exp3-6****************************/
	vertor_find();
	
	/****************************exp3-7****************************/
	vector_sort();

	cin.get();
}