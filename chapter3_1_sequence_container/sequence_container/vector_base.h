#ifndef _VECTOR_BASE_H_
#define _VECTOR_BASE_H_
#include <iostream>
#include <vector>
using namespace std;

struct ST {
	int id;
	double db;
};


/*********************exp3-4*************************/
void Origin(int num, vector<ST>& vt)
{
	int m = num;
	ST temp;
	for (int i = 0; i < m; i++)
	{
		temp.id = i + 1;
		temp.db = (i + 1) * 10;
		vt.push_back(temp);
	}
}
void Iter_for(vector<ST>& vt)
{
	ST temp;
	vector<ST>::iterator iter;
	for (iter = vt.begin(); iter != vt.end(); iter++)
	{
		temp = *iter;
		cout << "id:  " << temp.id << ",  db:  " << temp.db << endl;
	}
}

void at_for(vector<ST>& vt)
{
	ST temp;
	int i = 0;
	int m = vt.size();
	for (i = 0; i < m; i++)
	{
		temp = vt.at(i);
		cout << "id:  " << temp.id << ",  db:  " << temp.db << endl;
	}
}

void vector_base_test()
{
	ST tmp;
	vector<ST> myvt;
	Origin(5, myvt);

	int size = myvt.size();
	cout << "size: " << size << endl;
	cout << "Iterator output!" << endl;
	Iter_for(myvt);
	cout << "at() output!" << endl;
	at_for(myvt);

	myvt.resize(7);
	cout << "empty() usage:" << endl;
	while (!myvt.empty())
	{
		tmp = myvt.back();
		cout << "id " << tmp.id << ", db: " << tmp.db << endl;
		myvt.pop_back();
	}
}

/***************************exp3-5********************************/
#include <algorithm>
struct Student {
	int id;
	double score;
};

template <class T> void Original(T& myvt)
{
	Student temp;
	temp.id = 1;
	temp.score = 90;
	myvt.push_back(temp);
	temp.id = 2;
	temp.score = 95;
	myvt.push_back(temp);
	temp.id = 3;
	temp.score = 98;
	myvt.push_back(temp);
	temp.id = 4;
	temp.score = 97;
	myvt.push_back(temp);
	temp.id = 5;
	temp.score = 95;
	myvt.push_back(temp);
	temp.id = 6;
	temp.score = 90;
	myvt.push_back(temp);
}

void out(Student& stu)
{
	cout << "id: " << stu.id << " , score: " << stu.score << endl;
}

bool greater95(Student& stu)
{
	if (stu.score >= 95.0)
		return 1;
	else
		return 0;
}

//for_each  count_if
void vertor_algo_test()
{
	vector<Student> myvt;
	vector<Student>::iterator iter;
	int countV = 0;
	Original(myvt);
	for_each(myvt.begin(), myvt.end(), out);                  //for_eachÀ„∑®
	countV = count_if(myvt.begin(), myvt.end(), greater95);	   //
	cout << "The Number of the elements >95.0: " << countV << endl;    //

}


#endif