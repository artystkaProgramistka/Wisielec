#ifndef __ WISIELEC_H__
#define __WISIELEC_H__


#include <iostream>

using namespace std;

void PlayGame();
bool WantToPlayAgain();
char*MakeHiddenPhrase(const char*secretPhrase, int secretPhraseLength);
void DrawBoard(int numberOfGuessesLeft, const char* noptrHiddenPhrase);
int GetSecretPhrase(char secretPhrase[], int maxLength);
char GetGuess();
void UpdateBoard(char guess, char*optrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int&numberOfGuessesLeft);
bool isGameOver(int numberOfGuessesLeft, const char*noptrHiddenPhrase, int secretPhraseLength);
void DisplayResult(const char*secretPhrase, int numberOfGuessesLeft);

//char GetCharacter(const char* prompt, const char*error);
//char GetCharacter(const char* prompt, const char*error, const char validInput[], int validInputLength);
#endif
