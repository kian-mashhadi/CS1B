#include "header.h"
/******************************************************************************
 * FUNCTION Output
 * -----------------------------------------------------------------------------
 * 	This function receives the head of the linked list and the output file name
 * 	and it will output all the movies from the input file
 * 	 ==> returns nothing - this function output the movies from the linked list
 * -----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *			the following need a defined value pass in
 *			head 		: The head of the linked list
 *			oFileName	: The name of the output file
 * POST-CONDITIONS
 * 		==>	Returns nothing - this function output the class heading.
 ******************************************************************************/
void Output(movieNode *&head,
            ofstream &fout)
{
    const int MAX_LEN = 75;
    const int TITLE_COL = 7;
    const int YEAR_COL = 6;
    const int NUM_COL = 12;
    const int RATE_COL = 8;
    const int NAME_COL = 18;
    const int ACTOR_NAME = 25;
    const int GENRE_COL = 9;

    string moviePlot;
    string result;

    movieNode *ptr;

    PrintHeader(fout, "Searching Linked Lists", 'A', 4);

    ptr = head;
    while (ptr != NULL)
    {
        fout << setfill('*') << setw(MAX_LEN) << '*' << endl;
        fout << setfill(' ');
        fout << left << setw(TITLE_COL) << "Title: " << ptr->movieName << endl;
        fout << setfill('-') << setw(MAX_LEN) << '-' << endl;
        fout << setfill(' ');
        fout << setw(YEAR_COL) << "Year: " << setw(NUM_COL) << ptr->year
             << setw(RATE_COL) << "Rating: " << ptr->rating << endl;
        fout << setfill('-') << setw(MAX_LEN) << '-' << endl;
        fout << setfill(' ');
        fout << setw(NAME_COL) << "Leading Actor: " << setw(ACTOR_NAME)
             << ptr->leadActor << setw(GENRE_COL) << "Genre 1: "
             << ptr->genre << endl;
        fout << setw(NAME_COL) << "Supporting Actor: " << setw(ACTOR_NAME)
             << ptr->supportingActor << setw(GENRE_COL) << "Genre 2: "
             << ptr->alternateGenre << endl;
        fout << setfill('-') << setw(MAX_LEN) << '-' << endl;
        fout << setfill(' ');
        fout << "PLOT:\n";
        moviePlot = ptr->synopsis;
        result = WordWrap(moviePlot);
        fout << result << endl;
        fout << setfill('*') << setw(MAX_LEN) << '*' << endl
             << endl
             << endl;
        fout << setfill(' ');
        ptr = ptr->next;
    }
}