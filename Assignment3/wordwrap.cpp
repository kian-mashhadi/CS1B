#include "Header.H"

string wordWrap(string plot)
{
    const int MAX_LEN = 75;
    int index;    // CALC     - The loop control varible
    int numLines; // CALC 	- The line number the sentence will be displayed

    int plotLen;   // CALC 	- The length of the plot sentence
    int outputLen; // CALC 	- The length of the output sentence
    int wordLen;   // CALC 	- The length of each word
    string word;   // CALC	    - Each word in one sentece
    string output; // CACL&OUT - The warpped plot of the movie

    // INITIIZNING

    output = "";
    word = "";

    plotLen = plot.length();
    numLines = 1;

    for (int index = 0; index < plotLen; index++)
    {
        if (plot[index] != ' ')
        {
            word += plot[index];
        }
        else
        {
            outputLen = output.length();
            wordLen = word.length();
            if ((outputLen + wordLen + 1) > MAX_LEN * numLines)
            {
                output += "\n";
                numLines++;
            }
            output += word + ' ';
            word.clear();
        }
        outputLen = output.length();
        wordLen = word.length();
        if ((outputLen + wordLen + 1) < MAX_LEN * numLines)
        {
            output += word + ' ';
        }
        else
        {
            output += "/r/n" + word;
        }
        return output;
    }
}
