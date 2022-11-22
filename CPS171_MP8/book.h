#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// This header file contains the declarations for my Book class.
class Book
{
public:
	string author;
	string title;
	long ISBN;
	Book();
	void Print(int&) const;
	void GetData(ifstream& bookData);
	long GetISBN() const;
	void ISBNNotFound(long& tempISBN);
};

