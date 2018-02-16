#include "stdafx.h"

using namespace std;

template<class T> void SortOperator(vector<T> vectorToSort)
{
	T temp;

	for (int i = 0; i < (int)vectorToSort.size(); i++)
		for (int j = i + 1; j < (int)vectorToSort.size(); j++)
			if (vectorToSort[i] > vectorToSort[j])
			{
				temp = vectorToSort[i];
				vectorToSort[i] = vectorToSort[j];
				vectorToSort[j] = temp;
			}

	cout << "Sort by operator[]:" << endl;
	ShowVector(vectorToSort);
}
template<class T> void ShowVector(vector<T> vectorToShow)
{
	for (int i = 0; i < (int)vectorToShow.size(); i++)
		cout << i << ".:\t " << vectorToShow[i] << endl;
}
void SortAt(vector<int> vectorToSort);
void SortIterator(vector<int> vectorToSort);
void ReadFromTextFile();
void InsetNumberInVector();
void DeleteEvenNumbers(vector<int> vectorWithEven);
void InsertOneAfterThree(vector<int> vectorWithThree);
void FillRandom(double* arrayR, int size);

void main()
{
	vector<int> mainVector /*= { 4,53,3,17,6,2,6,9,345,97,234 }*/;
	vector <double> vector5, vector10, vector25, vector50, vector100;
	double randomArray[100];
	
	for (int i = 0; i < 500; i++)
	{
		srand(time(0));
		mainVector.push_back(rand());
	}
	
	//ShowVector(mainVector);

	//clock_t timeStart = clock();
	//SortOperator(mainVector);
	//clock_t timeEnd = clock();
	//cout << "время выполнения: " << timeEnd - timeStart;

	//clock_t timeStart = clock();
	//SortAt(mainVector);
	//clock_t timeEnd = clock();
	//cout << "время выполнения: " << timeEnd - timeStart;
	
	//clock_t timeStart = clock();
	//SortIterator(mainVector);
	//clock_t timeEnd = clock();
	//cout << "время выполнения: " << timeEnd - timeStart;

	//ReadFromTextFile();
	//InsetNumberInVector();
	
	/*FillRandom(randomArray, 5);
	vector5.assign(randomArray, &randomArray[5]);
	ShowVector(vector5);
	SortOperator(vector5);
	
	FillRandom(randomArray, 10);
	vector10.assign(randomArray, &randomArray[10]);
	ShowVector(vector10);
	SortOperator(vector10);

	FillRandom(randomArray, 25);
	vector25.assign(randomArray, &randomArray[25]);
	ShowVector(vector25);
	SortOperator(vector25);

	FillRandom(randomArray, 50);
	vector50.assign(randomArray, &randomArray[50]);
	ShowVector(vector50);
	SortOperator(vector50);

	FillRandom(randomArray, 100);
	vector100.assign(randomArray, &randomArray[100]);
	ShowVector(vector100);
	SortOperator(vector100);*/

	_getch();
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

void ReadFromTextFile()
{
	ifstream iFile;
	const int rows(3), len(7);
	char arrayToWrite[rows][len];
	vector <char> vectorToInsert;

	iFile.open("FileToRead.txt");
	if (!iFile)
		cout << "ERROR! FILE NOT FOUND" << endl;

	for (int i = 0; i < rows; i++)
		iFile.getline(arrayToWrite[i], len);
	
	iFile.close();

	for (int i = 0; i < rows; i++)
		cout << arrayToWrite[i] << endl;
		
	vectorToInsert.insert(vectorToInsert.begin(), arrayToWrite[0], arrayToWrite[0] + sizeof(arrayToWrite) - 1);
	//vectorToInsert.assign(arrayToWrite, &arrayToWrite[3]);
	
	cout << "vector: \n";
	for (int i = 0; i < vectorToInsert.size(); i++)
		cout << vectorToInsert[i];	
}

void InsetNumberInVector()
{
	vector<int> vectorToInsert;
	int inputFromConsol = 1;
	bool checkToExit = true;
	
	cout << "Enter number in vector.(For end - insert 0.)\n";	
	
	while (true)
	{
		cin >> inputFromConsol;
		if (inputFromConsol == 0)
			break;

		vectorToInsert.insert(vectorToInsert.end(), inputFromConsol);
	}

	cout << "Origin vector: \n";
	ShowVector(vectorToInsert);
		
	if (vectorToInsert.back() == 1)
		DeleteEvenNumbers(vectorToInsert);

	if (vectorToInsert.back() == 2)
		InsertOneAfterThree(vectorToInsert);
}

void DeleteEvenNumbers(vector<int> vectorWithEven)
{
	int sizeOfVector;

	sizeOfVector = vectorWithEven.size();
	for (int i = 0; i < sizeOfVector; i++)
	{
		if (vectorWithEven[i] % 2 == 0)
		{
			vectorWithEven.erase(vectorWithEven.begin() + i);
			sizeOfVector = vectorWithEven.size();
			--i;
		}
	}

	cout << "\nVector without even numbers: \n";
	ShowVector(vectorWithEven);
}

void InsertOneAfterThree(vector<int> vectorWithThree)
{
	int sizeOfVector;
	
	sizeOfVector = vectorWithThree.size();
	for (int i = 0; i < sizeOfVector; i++)
	{
		if (vectorWithThree[i] % 3 == 0)
		{
			vectorWithThree.insert(vectorWithThree.begin() + (i + 1), 3, 1);
			sizeOfVector = vectorWithThree.size();
		}
	}

	cout << "\nVector with 3 '1' after '3': \n";
	ShowVector(vectorWithThree);
}

void FillRandom(double* arrayR, int size)
{
	srand(time(0));

	for (int i = 0 ; i < size; i++)
		arrayR[i] = 0.0001 * ((rand() % 20000) - 10000);
}