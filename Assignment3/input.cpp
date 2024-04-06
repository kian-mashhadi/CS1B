#include "header.h"
/******************************************************************************
 * FUNCTION GetInput
 * -----------------------------------------------------------------------------
 * 	This function will open an input file and will read in the information
 * 	of the file into a linked list
 * 		==> returns nothing - will read into a linked list.
 * -----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *			the following need a defined value pass in
 *			inFileName	: The name of the input file
 *			head 		: The head of the linked list
 *			tail		: The tail of the linked list
 *
 * POST-CONDITIONS
 * 		==> returns nothing - will read into a linked list.
 ******************************************************************************/
void GetInput(string inFileName,
              movieNode *&head,
              movieNode *&tail)
{
    fstream inFile;
    movieNode *current; // CALC - the pointer pointing to the list

    inFile.open(inFileName);

    current = new movieNode;
    while (inFile && current != NULL)
    {
        getline(inFile, current->movieName);
        getline(inFile, current->leadActor);
        getline(inFile, current->supportingActor);
        getline(inFile, current->genre);
        getline(inFile, current->alternateGenre);
        inFile >> current->year;
        inFile >> current->rating;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(inFile, current->synopsis);
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');

        if (head == NULL)
        {
            head = current;
        }
        else
        {
            tail->next = current;
        }
        tail = current;
        current = new movieNode;
    }
    delete current;

    inFile.close();
}