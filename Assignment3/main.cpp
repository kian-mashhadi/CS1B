#include "header.hpp"
using namespace std;

int main()
{
    string inFileName;
	string oFileName;
	int command;
	movieNode *head;
	movieNode *tail;
	ofstream oFile;

	head = NULL;
	tail = NULL;

	PrintHeader(cout, "Searching Linked List", 'A', 4);

	cout << "Which input file would you like to use (type d for defult file)? ";
	getline(cin, inFileName);
	cout << "Which output file would you like to use (type d for defult file)? ";
	getline(cin, oFileName);

	if(inFileName == "d")
	{
		inFileName = "inFile.txt";
	}
	if(oFileName == "d")
	{
		oFileName = "oFile.txt";
	}

	GetInput(inFileName, head, tail);
	oFile.open(oFileName);
	command = GetAndCheckInput();
	do
	{

		if(command == OUTPUT)
		{
			cout << "\nListing all movies!\n";
			Output(head, oFile);
		}
		else
		{
			Search(head, command, oFile);
		}
		command = GetAndCheckInput();
		} while(command != EXIT);


	cout << "\nThank you for using my program!";
	oFile.close();
	return 0;
}
