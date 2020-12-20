#ifndef _VECTOR_ADVANCED_H_
#define _VECTOR_ADVANCED_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <functional>		//bind2nd

using namespace std;


/********************************exp3-6**********************************/
void print(const int& temp)
{
	cout << temp << endl;
}

void vertor_find()
{
	const int ARRAY_SIZE = 8;
	int IntArray[ARRAY_SIZE] = { 1, 2, 3, 4, 4, 5, 6, 7 };
	vector<int> myvt;
	//int* location_index = NULL;
	vector<int>::iterator location_index;
	for (int i = 0; i < 8; i++)
		myvt.push_back(IntArray[i]);

	for_each(myvt.begin(), myvt.end(), print);

	location_index = find(myvt.begin(), myvt.end(), 2);	                        //find
	cout << "数字2的下标是 :" << (location_index - myvt.begin()) << endl;		//迭代器可以加减
	location_index = find_if(myvt.begin(), myvt.end(), bind2nd(greater<int>(), 5));
	cout << "第一个大于5的数字的下标是 :" << (location_index - myvt.begin()) << endl;
}


/***********************************exp3-7************************************/
class student {
public:
	student(const string &a, double b) :name(a), score(b)
	{}
	string name;
	double score;
	bool operator<(const student& m) const
	{
		return score < m.score;		//效果与 this->score < m.score;一样
	}
};

bool name_sort_less(const student& m, const student& n)
{
	return m.name < n.name;
}
bool name_sort_greater(const student& m, const student& n)
{
	return m.name > n.name;
}
bool score_sort(const student& m, const student& n)
{
	return m.score > n.score;
}
void print_score(student& S)
{
	cout << S.name << "        " << S.score << endl;
}
void Original(vector<student>& V)
{
	student st1("Tom", 74);
	V.push_back(st1);
	st1.name = "Jimy";
	st1.score = 56;
	V.push_back(st1);
	st1.name = "Mary";
	st1.score = 92;
	V.push_back(st1);
	st1.name = "Jessy";
	st1.score = 85;
	V.push_back(st1);
	st1.name = "Jone";
	st1.score = 56;
	V.push_back(st1);
	st1.name = "Bush";
	st1.score = 52;
	V.push_back(st1);
	st1.name = "Winter";
	st1.score = 77;
	V.push_back(st1);
	st1.name = "Ander";
	st1.score = 63;
	V.push_back(st1);
	st1.name = "Lily";
	st1.score = 76;
	V.push_back(st1);
	st1.name = "Maryia";
	st1.score = 89;
	V.push_back(st1);
}

void vector_sort()
{
	vector<student> vect;
	Original(vect);
	cout << "----Before sorted.-----" << endl;
	for_each(vect.begin(), vect.end(), print_score);

	sort(vect.begin(), vect.end());
	cout << "----After sorted by score.-----" << endl;
	for_each(vect.begin(), vect.end(), print_score);

	sort(vect.begin(), vect.end(), name_sort_less);
	cout << "----After sorted by name less.-----" << endl;
	for_each(vect.begin(), vect.end(), print_score);

	sort(vect.begin(), vect.end(), score_sort);
	cout << "----After sorted by score greater.-----" << endl;
	for_each(vect.begin(), vect.end(), print_score);

	sort(vect.begin(), vect.end(), name_sort_greater);
	cout << "----After sorted by name greater.-----" << endl;
	for_each(vect.begin(), vect.end(), print_score);
}

#endif