#include "stdafx.h"

using namespace std;

void SortOperator(vector<int> whatToSort);
void SortAt(vector<int> vectorToSort);
void SortIterator(vector<int> vectorToSort);
void ShowVector(vector<int> vectorToShow);
//void TestFunc();

void main()
{
	vector<int> mainVector = { 4,53,3,17,6,2,6,9,345,97,234 };
	int timeStart, timeEnd;

	ShowVector(mainVector);
	//SortOperator(mainVector);
	SortAt(mainVector);
	SortIterator(mainVector);

	_getch();
}

void SortOperator(vector<int> vectorToSort)
{
	int temp;

	for (int i = 0; i < (int)vectorToSort.size(); i++)
		for (int j = i + 1; j < (int)vectorToSort.size(); j++)
			if (vectorToSort[i] > vectorToSort[j])
			{
				temp = vectorToSort[i];
				vectorToSort[i] = vectorToSort[j];
				vectorToSort[j] = temp;
			}

	ShowVector(vectorToSort);
}

void SortAt(vector<int> vectorToSort)
{
	int temp;

	for (int i = 0; i < (int)vectorToSort.size(); i++)
		for (int j = i + 1; j < (int)vectorToSort.size(); j++)
			if (vectorToSort.at(i) > vectorToSort.at(j))
			{
				temp = vectorToSort.at(i);
				vectorToSort.at(i) = vectorToSort.at(j);
				vectorToSort.at(j) = temp;
			}

	ShowVector(vectorToSort);
}

void SortIterator(vector<int> vectorToSort)
{
	vector<int>::iterator iter;
	int temp;

	iter = vectorToSort.begin();
	
	while ((iter+1) != vectorToSort.end())
	{
		if (*iter > *(iter + 1))
		{
			temp = *iter;
			*iter = *(iter + 1);
			*(iter + 1) = temp;
		}
		iter++;
	}
	ShowVector(vectorToSort);
}

void ShowVector(vector<int> vectorToShow)
{
	for (int i = 0; i < (int)vectorToShow.size(); i++)
		cout << i << ".:\t " << vectorToShow[i] << endl;
}

//void TestFunc()
//{
//	long testArray[2000000];
//	for  (long i = 0; i < 2000000; i++)
//	{
//		testArray[i] = i;
//	}
//}