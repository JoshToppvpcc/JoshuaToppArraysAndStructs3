// StructsAndArraysProjectJoshuaTopp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <iomanip>
#include <fstream>
using namespace std;
const int MaxRows = 20;
const int NCols = 8;
const string inFile = "RuunnersText.txt";
ifstream inFilie;

//Read the data off of the input file
// Preconditions - needs a place to send the names of the runners and they miles they ran, which are empty arrrays. 
// Post conditions - Return the number of rows (names) on the file and store the data into the arrays. 
int GetMilesRan(string runners[], double milesRan[][NCols], int MaxRows);

// Calc. Total miles and average miles ran per day for each runner
// Preconditions - recieves the number of miles ran each day for each runner. 
// Post conditions - The average miles per day of each runner is calculated and output in the right spot. 
void CalcAverage(double milesRan[][NCols], int rows);


//Clac toal miles of each runner in that week and display it. 
//Preconditions - Table of milesRan[i][j] has to be accessible so the numbers can be added and returned. 
// Post condition - The total miles of each runners' week is out put next to their average at the end of the table. 
void CalcToal(double milesRan[][NCols], int rows);


int main()
{
	ifstream inFile;
	inFile.open("RuunnersText.txt");
	string runners[MaxRows];
	double milesRan[MaxRows][NCols];
	double averages[MaxRows];
	double totals[MaxRows];

	double numRecords;
	numRecords = GetMilesRan(runners, milesRan, MaxRows);
	CalcAverage(milesRan, numRecords);

	for (int i = 0; i < numRecords; i++) {
		cout << runners[i] << " ";
		for (int j = 0; j < NCols - 1; j++) {
			cout << milesRan[i][j] << " ";
			//cout << CalcAverage(milesRan[i][j], MaxRows);
			//cout << CalcTotal(milesRan[i][j], MaxRows) << endl;
		}
	}


}
int GetMilesRan(string runners[], double milesRan[][NCols], int MaxRows) {
	ifstream  inFile;
	int rows = 0;
	inFile.open("RuunnersText.txt");
	inFile >> runners[rows];
	while (!inFile.eof() && !(rows >= MaxRows)) {
		for (int i = 0; i < NCols - 1; i++) {
			inFile >> milesRan[rows][i];
		}
		rows++;
		inFile >> runners[rows];
	}
	inFile.close();
	return rows;


}
void CalcAverage(double milesRan[][NCols], int rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 1; j++)
			sum += milesRan[i][j];
		milesRan[i][NCols - 1] = sum / (NCols - 1);

	}
}
void CalcTotal(double milesRan[][NCols], int rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < NCols - 1; j++)
			sum += milesRan[i][j];
	}
}