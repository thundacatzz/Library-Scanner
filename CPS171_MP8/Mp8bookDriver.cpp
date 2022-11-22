#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "book.h"
using namespace std;

// These are the prototpyes for the functions in this file and the declaration for the input file stream.
ifstream bookData;
void OpenOutputFile();
void OpenInputFile();
void OpenInputFile2();
void BinarySearch(Book books[], int left, int right, long tempISBN);

int main()
{
	OpenInputFile();
	OpenOutputFile();

	Book books[10];

	cout << "Testing the book class by Logan Skura" << endl << endl;
	
	// This loop performs the functions to get and print the data from the input file for each book in the array.
	for (int i = 0; i <= 9; i++)
	{
		int j = (i + 1);
		books[i].GetData(bookData);
		books[i].Print(j);
	}
	
	// This block closes the first input file and then opens the second input file that will search for ISBNs amongst the data already entered into the array.
	bookData.close();
	OpenInputFile2();
	cout << "Customer book search begins here:" << endl;
	
	// This block establishes the bounds of the array for the binary search function and then runs the binary serach function for the ISBNs until it's out of lines.
	int left = 0;
	int right = 9;
	while (!bookData.eof())
	{
		long tempISBN = 0;
		bookData >> tempISBN;
		bookData.ignore(1, '\n');
		BinarySearch(books, left, right, tempISBN);
	}
	return 0;
}

// This function conducts a binary search through the data available, and if it doesn't find an ISBN, calls the ISBNNotFound function.
void BinarySearch(Book books[], int left, int right, long tempISBN)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (books[mid].ISBN == tempISBN)
		{
			int j = (mid + 1);
			books[mid].Print(j);
			return;
		}

		else if (books[mid].ISBN > tempISBN)
		{
			return BinarySearch(books, left, mid - 1, tempISBN);
		}

		else if (books[mid].ISBN < tempISBN)
		{
			return BinarySearch(books, mid + 1, right, tempISBN);
		}
	}
	books->ISBNNotFound(tempISBN);
	return;
}

// This function opens the input file.
void OpenInputFile()
{
	bookData.open("mp7bookarray.txt");
	if (bookData.fail())
	{
		cout << "Failed to open input file";
		return;
	}
}

// This function opens the second input file.
void OpenInputFile2()
{
	bookData.open("mp8bookISBN.txt");
	if (bookData.fail())
	{
		cout << "Failed to open input file";
		return;
	}
}