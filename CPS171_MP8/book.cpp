#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "book.h"
using namespace std;

void OpenOutputFile();

ofstream outputFile;

// This is the constructor for the Book class.
Book::Book()
{
	author = "No name";
	title = "Unknown title";
	ISBN = 0;
}

// This is the Print function for the Book class. It outputs the book information to the console and the output file.
void Book::Print(int& j) const
{
	cout << "The information for book " << j << " is: " << endl;
	cout << left << setfill('.') << setw(20) << author << setw(50) << title << " " << GetISBN() << endl;
	cout << "Book " << j << " has ISBN: " << GetISBN() << endl << endl;
	
	
	outputFile << "The information for book " << j << " is: " << endl;
	outputFile << left << setfill('.') << setw(20) << author << setw(50) << title << " " << GetISBN() << endl;
	outputFile << "Book " << j << " has ISBN: " << GetISBN() << endl << endl;
}

// This function is called when an ISBN is searched for that doesn't exist within the "library." It informs the user that the ISBN they searched for can't be found.
void Book::ISBNNotFound(long& tempISBN)
{
	cout << "ISBN: " << tempISBN << " not found." << endl << endl;
	outputFile << "ISBN: " << tempISBN << " not found." << endl << endl;
}

// This function gets the data from the input file using getline for the strings and the insertion operator for the ISBN.
void Book::GetData(ifstream &bookData)
{
	string line;
	getline(bookData, line);
	author = line;
	getline(bookData, line);
	title = line;
	bookData >> ISBN;
	bookData.ignore(1, '\n');
}

// This function simply returns the ISBN when called.
long Book::GetISBN() const
{
	return ISBN;
}

// This function opens the output file.
void OpenOutputFile()
{
	outputFile.open("MP8Output.txt");
	if (outputFile.fail())
	{
		cout << "Failed to open output file";
		return;
	}
}
