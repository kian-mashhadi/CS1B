#include "header.h"

void outputSearch(movieNode *movieRec,
                  int index,
                  ofstream &oFile)
{
    const int MAX = 10;
    const int MOVIE_COL = 7;
    const int TIT_COL = 48;
    const int YR_COL = 4;
    const int rate_COL = 6;
    const int GEN_COL = 18;
    const int ALT_GEN_COL = 18;
    const int ACTOR_COL = 20;

    if (index == 1)
    {
        oFile << left << setw(MOVIE_COL) << "MOVIE #"
              << setw(TIT_COL + 1) << " TITLE"
              << setw(YR_COL) << " Year"
              << setw(rate_COL) << " rating"
              << setw(GEN_COL) << " GENRE"
              << setw(ALT_GEN_COL) << " ALT GENRE"
              << setw(ACTOR_COL) << " Lead Actor"
              << setw(ACTOR_COL) << " Supporting Actor" << endl;

        oFile << left << setw(MOVIE_COL) << "-------"
              << setw(TIT_COL) << " ------------------------------------------------"
              << setw(YR_COL) << " ----"
              << setw(rate_COL) << " ------"
              << setw(GEN_COL) << " -----------------"
              << setw(ALT_GEN_COL) << " -----------------"
              << setw(ACTOR_COL) << " -------------------"
              << setw(ACTOR_COL) << " ---------------------" << endl;
    }
    if (index <= MAX)
    {
        oFile << setw(3) << "" << setw(MOVIE_COL - 3) << index
              << setw(2) << ""
              << setw(TIT_COL) << movieRec->movieName
              << setw(YR_COL) << movieRec->year
              << setw(3) << "" << setw(rate_COL - 3) << movieRec->rating
              << setw(3) << "" << setw(GEN_COL) << movieRec->genre
              << setw(ALT_GEN_COL) << movieRec->alternateGenre
              << setw(ACTOR_COL) << movieRec->leadActor
              << setw(ACTOR_COL) << movieRec->supportingActor << endl;
    }
    if (index == MAX + 1)
    {
        oFile << "..." << endl;
    }
}