#include "header.h"

void RateSearch(movieNode *head,
				int search,
				ofstream &oFile)
{

	movieNode *searchPtr;
	int instances;

	searchPtr = head;
	instances = 0;

	cout << "\nSearching for the rating " << search;
	while(searchPtr != NULL)
	{
		if(searchPtr->rating == search)
		{
			instances++;
			if(instances == 1)
			{
				oFile << "\nSearch by rate for " << search << " Found:\n";
			}
			outputSearch(searchPtr, instances, oFile);
		}
		searchPtr = searchPtr->next;
	}

	if(instances == 0)
	{
		cout << "\nSorry, no movies for the rate, " << search << " were found.";
	}
	else
	{
		cout << "\nFound " << instances << " movies for the rate " << search
			 << '!' << endl;
	}

}