#include "header.h"
/******************************************************************************
 * FUNCTION search
 * -----------------------------------------------------------------------------
 * 	This function receives the head of the linked list and the command which the
 * 	user has entered and will search the linked list based on what the user
 * 	had inputed.
 * -----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *				head 	: The head of the function
 *				command : The users choice based on the menu
 *				oFile 	: The variable for the output file
 *
 * POST-CONDITIONS
 * 		==>	Returns nothing - this function output the class heading.
 ******************************************************************************/
void Search(movieNode *&head, int command, ofstream &oFile)
{
    const int LOWER_BOUND = 1878;
    const int UPPER_BOUND = 3000;
    const int RLOWER_BOUND = 0;
    const int RUPPER_BOUND = 9;

    string searchName;
    int searchInt;
    searchInt = 0;

    switch (command)
    {
    case TITLESEARCH:
        cout << "\nWhich Title are you looking for? ";
        getline(cin, searchName);
        TitleSearch(head, searchName, oFile);
        break;
    case GENRESEARCH:
        cout << "\nWhich genre are you looking for? ";
        getline(cin, searchName);
        GenreSearch(head, searchName, oFile);
        break;
    case ACTORSEARCH:
        cout << "\nWhich actor are you looking for? ";
        getline(cin, searchName);
        ActorSearch(head, searchName, oFile);
        break;
    case YEARSEARCH:
        cout << "\nWhich year are you looking for? ";
        cin >> searchInt;
        while ((!cin >> searchInt) ||
               searchInt < LOWER_BOUND || searchInt > UPPER_BOUND)
        {
            if (!cin >> searchInt)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                cout << "\n**** The number " << searchInt << " is an "
                                                             "invalid input ****\n";
            }
            cout << "**** Please input a number between " << LOWER_BOUND
                 << " and " << UPPER_BOUND << " ****\n";
            cout << "\nWhich year are you looking for? ";
            cin >> searchInt;
        }
        YearSearch(head, searchInt, oFile);
        break;
    case RATINGSEARCH:
        cout << "\nWhich rate are you looking for? ";
        cin >> searchInt;

        while ((!cin >> searchInt) ||
               searchInt < RLOWER_BOUND || searchInt > RUPPER_BOUND)
        {
            if (!cin >> searchInt)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                cout << "\n**** The number " << searchInt << " is an "
                                                             "invalid input ****\n";
            }
            cout << "**** Please input a number between "
                 << RLOWER_BOUND << " and " << RUPPER_BOUND
                 << " ****\n";
            cout << "\nWhich rate are you looking for? ";
            cin >> searchInt;
        }
        RateSearch(head, searchInt, oFile);
        break;
    default:
        cout << "\n**** The number " << command << " is an invalid entry ****\n"
                                                   "**** Please input a number between 0 and 6 ****\n";
    }
}