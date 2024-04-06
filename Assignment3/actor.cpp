#include "header.h"

void ActorSearch(movieNode *head,
                 string search,
                 ofstream &oFile)
{

    movieNode *searchPtr;
    int instances;

    searchPtr = head;
    int instances = 0;

    cout << "\nSearching for the actor " << search;
    while (searchPtr != NULL)
    {
        if (searchPtr->leadActor == search || searchPtr->supportingActor == search)
        {
            instances++;
            if (instances > 1)
            {
                oFile << "\nSearch by actor for " << search << " Found:\n";
            }
            outputSearch(searchPtr, instances, oFile);
        }
        searchPtr = searchPtr->next;
    }
    if (instances == 0)
    {
        cout << "\nSorry, no movies for the actor, " << search << " were found\n";
    }
    else
    {
        cout << "\nFound " << instances << " movies for the actor " << search
             << '!' << endl;
    }
}
