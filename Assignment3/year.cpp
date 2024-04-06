#include "header.h"

void YearSearch(movieNode *head,
				int search,
				ofstream &oFile)
{
	movieNode *searchPtr;
	int instances;

	searchPtr = head;
	instances = 0;

	cout << "\nSearching for the year " << search;
	while(searchPtr != NULL)
	{
		if(searchPtr->year == search)
		{
			instances++;
			if(instances == 1)
			{
				oFile << "\nSearch by Year for " << search << " Found:\n";
			}
			outputSearch(searchPtr, instances, oFile);
		}
		searchPtr = searchPtr->next;
	}

	if(instances == 0)
	{
		cout << "\nSorry, no movies for the year, " << search << " were found.\n";
	}
	else
	{
		cout << "\nFound " << instances << " movies for the year " << search
			 << '!' << endl;
	}

}