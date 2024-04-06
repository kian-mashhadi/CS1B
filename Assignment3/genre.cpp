#include "header.h"

void GenreSearch(movieNode *head,
                 string search,
                 ofstream &oFile)
{
    movieNode *searchPtr;
    int instances;

    searchPtr = head;
    instances = 0;
    cout << "\nSearching for the genre " << search;
    while (searchPtr != NULL)
    {
        if (searchPtr->genre == search || searchPtr->alternateGenre == search)
        {
            instances++;
            if (instances == 1)
            {
                oFile << "\nSearch by genre for " << search << " Found: \n";
            }
        }
        outputSearch(searchPtr, instances, oFile);
    }
    searchPtr = searchPtr->next;
    if (instances == 0)
    {
        cout << "\nSorry, no movies with the genre, " << search << " were found\n";
    }
    else
    {
        cout << "\nFound " << instances << " movies for the genre " << search
             << endl;
    }
}
