#include "stdafx.h"

using namespace std;

void SortOperator(vector<int> whatToSort);
void SortAt(vector<int> vectorToSort);
void SortIterator(vector<int> vectorToSort);
void ShowVector(vector<int> vectorToShow);
void ReadFromTextFile();
//void TestFunc();

void main()
{
	vector<int> mainVector = { 4,53,3,17,6,2,6,9,345,97,234 };
	int timeStart, timeEnd;

	//ShowVector(mainVector);
	//SortOperator(mainVector);
	//SortAt(mainVector);
	//SortIterator(mainVector);
	ReadFromTextFile();

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

	cout << "Sort by aoperator[]:" << endl;
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

	cout << "Sort by at():" << endl;
	ShowVector(vectorToSort);
}

void SortIterator(vector<int> vectorToSort)
{
	vector<int>::iterator iterFirst, iterNext;
	int temp;

	iterFirst = vectorToSort.begin();

	while ((iterFirst+2) != vectorToSort.end())
	{
		iterNext = iterFirst + 1;
		do
		{
			if (*iterFirst > *iterNext)
			{
				temp = *iterFirst;
				*iterFirst = *iterNext;
				*iterNext = temp;
			}
			iterNext++;
		} while (iterNext != vectorToSort.end());
		
		iterFirst++;
	}

	cout << "Sort by Iterator:" << endl;
	ShowVector(vectorToSort);
}

void ShowVector(vector<int> vectorToShow)
{
	for (int i = 0; i < (int)vectorToShow.size(); i++)
		cout << i << ".:\t " << vectorToShow[i] << endl;
}

void ReadFromTextFile()
{
	ifstream iFile;
	char arrayToWrite[100];

	iFile.open("FileToRead.txt");
	if (!iFile)
		cout << "ERROR! FILE NOT FOUND" << endl;

	while (!iFile.eof())
	{
		iFile.getline(arrayToWrite, sizeof(arrayToWrite));		
	}
	iFile.close();

	for (int i = 0; i < 100; i++)
	{
		cout << arrayToWrite[i] << endl;
	}



}

//void TestFunc()
//{
//	long testArray[2000000];
//	for  (long i = 0; i < 2000000; i++)
//	{
//		testArray[i] = i;
//	}
//}