#include <iostream>
#include <cstring>
#include <cctype>
#include "Wisielec.h"
#include "Utils.h"

using namespace std;

const int IGNORE_CHARS = 256; //to do main
const char * INPUT_ERROR_STRING = "input error! Please, try again.";

//Play Game
void PlayGame()
{
    const int MAX_LENGTH_OF_SECRET_PHRASE = 256;
    const int MAX_NUMBER_OF_GUESSES = 6;

    char secretPhrase[MAX_LENGTH_OF_SECRET_PHRASE];
    char* optrHiddenPhrase = nullptr;
    int nubmerOfGuessesLeft = MAX_NUMBER_OF_GUESSES;

    int secretPhraseLength = GetSecretPhrase(secretPhrase, MAX_LENGTH_OF_SECRET_PHRASE);//z t¹ lnijk¹ by³ problem

    optrHiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);

    DrawBoard(nubmerOfGuessesLeft, optrHiddenPhrase);

    do
    {
        char guess = GetGuess();
        UpdateBoard(guess, optrHiddenPhrase, secretPhrase, secretPhraseLength, nubmerOfGuessesLeft);
        DrawBoard(nubmerOfGuessesLeft, optrHiddenPhrase);

    }while(!isGameOver(nubmerOfGuessesLeft, optrHiddenPhrase, secretPhraseLength));

    DisplayResult(secretPhrase, nubmerOfGuessesLeft);

    delete [] optrHiddenPhrase;
}


char GetGuess()
{
    return GetCharacter("Let's input your guess: ", INPUT_ERROR_STRING);
}

void UpdateBoard(char guess, char*optrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int&numberOfGuessesLeft)
{
    bool found = false;

    for(int i=0; i<secretPhraseLength; i++)
    {
        if(tolower(secretPhrase[i])==guess){
            optrHiddenPhrase[i] = secretPhrase[i];
            found = true;}
    }
    if(found==false)
    {
        numberOfGuessesLeft--;
    }
}

bool isGameOver(int numberOfGuessesLeft, const char*noptrHiddenPhrase, int secretPhraseLength)
{
    bool hasDash =  false;
    for(int i=0;i<secretPhraseLength;i++)
    {
        if(noptrHiddenPhrase[i]=='-')
        {
            hasDash = true;
            break;
        }
    }return numberOfGuessesLeft==0 || !hasDash;
}

void DisplayResult(const char*secretPhrase, int numberOfGuessesLeft)
{
    if(numberOfGuessesLeft>0)
    {
        cout<<"You got it! The phrase was: "<<secretPhrase<<endl;
    }
    else
    {
        cout<<"You didn't get it...The phrases was: "<<secretPhrase<<endl;
    }
}

bool WantToPlayAgain()
{
    const char validInputs[] = {'y','n'};
    char response = GetCharacter("Would you like to play again? (y/n)", INPUT_ERROR_STRING, validInputs, 2);
    return response == 'y';
}

//Get Secret Phrase
int GetSecretPhrase(char secretPhrase[], int maxLength)
{
    bool failure;
    int length;
    do
    {
        failure = false;
        cout<<"Enter the secret phrase: ";
        cin.get(secretPhrase, maxLength);

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << INPUT_ERROR_STRING << endl;
            failure = true;
        }
        else
        {
            length = strlen(secretPhrase);

            if(length==0)
            {
                cout<<"You didn't enter any characters. Please, enter a word."<<endl;
                failure = true;
            }
        }

    }while(failure);
    return length;
}
//Make Hidden Phrase
char*MakeHiddenPhrase(const char*secretPhrase, int secretPhraseLength)
{
    char* hiddenPhrase = new char[secretPhraseLength+1];
    for(int i=0;i<secretPhraseLength;i++)
    {
        if(secretPhrase[i] != ' ')
        {
            hiddenPhrase[i]='-';
        }
        else hiddenPhrase[i] = ' ';
    }
    hiddenPhrase[secretPhraseLength]='\0';
    return hiddenPhrase;
}
//Draw Board
void DrawBoard(int numberOfGuessesLeft, const char* noptrHiddenPhrase)
{
    switch(numberOfGuessesLeft)
    {
    case 0:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |  /|\\"<<endl
            <<" |  / \\"<<endl
            <<"-+-"<<endl<<endl;
    }break;
    case 1:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |  /|\\"<<endl
            <<" |  / "<<endl
            <<"-+-"<<endl<<endl;
    }break;

    case 2:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |  /|\\"<<endl
            <<" |  "<<endl
            <<"-+-"<<endl<<endl;
    }break;
    case 3:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |  /|"<<endl
            <<" |  "<<endl
            <<"-+-"<<endl<<endl;
    }break;
    case 4:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |   |"<<endl
            <<" |  "<<endl
            <<"-+-"<<endl<<endl;
    }break;
    case 5:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   O"<<endl
            <<" |  "<<endl
            <<" |  "<<endl
            <<"-+-"<<endl<<endl;
    }break;
    case 6:
    {
        cout<<" +---+"<<endl
            <<" |   |"<<endl
            <<" |   "<<endl
            <<" |  "<<endl
            <<" |  "<<endl
            <<"-+-"<<endl<<endl;
    }break; default: break;
    }cout<<"Secret Phrase: "<<noptrHiddenPhrase<<endl<<endl;
}

/*char GetCharacter(const char* prompt, const char*error)
{
    char input;
    bool failure;

    do
    {
        failure=false;
        cout<<prompt;
        cin>>input;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << error << endl;
            failure=true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');

            if(isalpha(input))
            {
                input = tolower(input);
            }
            else
            {
                cout<<error<<endl;
                failure = true;
            }
        }
    }while(failure); return input;
}

char GetCharacter(const char* prompt, const char* error, const char validInput[], int validInputLength)
{
    char input;
    bool failure;

    do
    {
        failure=false;
        cout<<prompt;
        cin>>input;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << error << endl;
            failure=true;
        }
        else
        {
            cin.ignore(IGNORE_CHARS, '\n');

            if(isalpha(input))
            {
                input = tolower(input);

                for (int i=0;i<validInputLength;i++)
                {
                    if(input==validInput[i])
                    {
                        return input;
                    }
                }
            }
            cout<<error<<endl;
            failure=true;
        }
    }while(failure); return input;
} */

