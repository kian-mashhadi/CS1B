/******************************************************************************
 * AURHOR			:	Kian Mashhadi
 * STUDENT ID		:	1231868
 * ASSIGNMENT#3		:	Searching linked ists
 * CLASS			:	CS1B
 * SECTION			:	MW - 7:30pm - 9:50pm
 * ****************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
#include <limits>
#include <string>
#include <ostream>
using namespace std;

const string MENU = "\nDVD MENU OPTIONS\n"
                    "\n1 - Output entire list\n"
                    "2 - Title Search\n"
                    "3 - Genre Search\n"
                    "4 - Actor Search\n"
                    "5 - Year Search\n"
                    "6 - Rating Search (0-9)\n"
                    "0 - Exit\n"
                    "Enter an option (0 to exit): ";

struct movieNode
{
    string movieName;
    string leadActor;
    string supportingActor;
    string genre;
    string alternateGenre;
    int year;
    int rating;
    string synopsis;
    movieNode *next;
};

enum MenuOption
{
    EXIT,         // 0
    OUTPUT,       // 1
    TITLESEARCH,  // 2
    GENRESEARCH,  // 3
    ACTORSEARCH,  // 4
    YEARSEARCH,   // 5
    RATINGSEARCH, // 6
};

/******************************************************************************
 * PrintHeader
 * 	This function receives an assignment name, type and number then outputs
 * 	the appropriate header
 *	 ==> returns nothing - This will output the class heading.
 *******************************************************************************/
void PrintHeader(ostream &output, // IN/OUT - output file
                 string asName,   // IN - assignment Name - used for output
                 char asType,     // IN - assignment Type
                              //	 - (LAB or ASSIGN) - used for output
                 int asNum); // IN - assignment Name - used for output
/******************************************************************************
 * GetAndCheckInput
 * 	This function gets input and checks if the input is valid. If the input is
 * 	invalid, a error message will output.
 * 	==> Returns input selected by the user
 ******************************************************************************/
int GetAndCheckInput();
/*******************************************************************************
 * GetInput
 * This function will open an input file and will read in the information
 * 	of the file into a linked list
 * 			==> returns nothing - will read into a linked list.
 ******************************************************************************/
void GetInput(string inFileName,
              movieNode *&head,
              movieNode *&tail);
/*******************************************************************************
 * 	Output
 * 	This function receives the head of the linked list and the output file name
 * 	and it will output all the movies from the input file
 * 	 ==> returns nothing - this function output the movies from the linked list
 *******************************************************************************/
void Output(movieNode *&head,
            ofstream &oFile);
/*******************************************************************************
 *	WordWrap
 *	This function will recieve a string and if the string is greater than
 * 	the max size it will wrapp the string and displaye it in 2 or more lines
 * 		==> returns the new string that has been wrapped
 *******************************************************************************/
string WordWrap(string plot);
/*******************************************************************************
 *	Search
 *	This function will search through the linked list based on the users
 *	choice
 *	 ==> returns nothing
 *******************************************************************************/
void Search(movieNode *&head,
            int command,
            ofstream &oFile);
/*******************************************************************************
 * TitleSearch
 * This function receives the head of the linked list and the name of the movie
 * 	being searched. then it will search through the linked list for the name
 * 	of the movie
 * 		==> returns nothing
 *******************************************************************************/
void TitleSearch(movieNode *head,
                 string search,
                 ofstream &oFile);
/*******************************************************************************
 * GenreSearch
 * 	This function will recieve the head of the linked list and the genre being
 * 	search. then it will search through the linked list for the genre
 * 	==> returns nothing
 *******************************************************************************/
void GenreSearch(movieNode *head,
                 string search,
                 ofstream &oFile);
/*******************************************************************************
 * ActorSearch
 * 	This function will recieve the head of the linked list and the actor being
 * 	search. then it will search through the linked list for the actor
 * 	==> returns nothing
 *******************************************************************************/
void ActorSearch(movieNode *head,
                 string search,
                 ofstream &oFile);
/*******************************************************************************
 * YearSearch
 * 	This function will recieve the head of the linked list and the year being
 * 	searched. then it will search through the function for movies that were
 * 	released on the year
 * 		==> returns nothing
 ******************************************************************************/
void YearSearch(movieNode *head,
                int search,
                ofstream &oFile);

/*******************************************************************************
 * RateSearch
 * 	This function will recieve the head of the linked list and the rate being
 * 	searched. then it will search through the function for movies with the
 * 	specific rating
 * 		==> returns nothing
 ******************************************************************************/
void RateSearch(movieNode *head,
                int search,
                ofstream &oFile);

/******************************************************************************
 *	outputSearch
 *		This function will output the information of the movie being searched
 *		==> returns nothing- will output the information
 ******************************************************************************/
void outputSearch(movieNode *movieRec,
                  int index,
                  ofstream &oFile);

#endif