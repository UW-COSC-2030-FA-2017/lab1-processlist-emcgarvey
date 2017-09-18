#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	string file = "";
	cout << "Enter a file name: ";
	cin >> file;
	ifstream inFile(file);
	if (!inFile)
	{
		cout << "File not found" << endl;
		return 0;
	}
	double current = NULL;
	double first = NULL;
	double second = NULL;
	double beforelast = NULL;
	double last = NULL;
	int counter = 0;
	while (inFile>>current && !inFile.fail()) // this file i/o operation is equivalent to checking .fail()
	{ 
		counter++;
		if (counter == 1) //stores the current character as 'first' on the first iteration
		{
			first = current;
		}
		if (counter == 2) //stores the current character as 'second' on the second iteration
		{
			second = current;
		}
		if (counter > 1) //updates the number before last as it iterates through the file
		{
			beforelast = last;
		}
		last = current;
		// counts the number of times through the loop
	}
	inFile.close();
	cout << "Number of numbers: " << counter << endl;
	cout << "First two: " << first << ", " << second << endl;
	cout << "Last two: " << beforelast << ", " << last << endl;
}

