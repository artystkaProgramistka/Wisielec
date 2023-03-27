#include <iostream>
#include "Wisielec.h"

using namespace std;

int main()
{
    const int IGNORE_CHARS = 256;
    const char * INPUT_ERROR_STRING = "input error! Please, try again.";
    do
    {
        PlayGame();
    }while(WantToPlayAgain());

    return 0;
}
