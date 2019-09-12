#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hangman game

struct word
{
    size_t len;
    char *text;
};

struct wordList
{
    struct word *index[90000];
    size_t lenOfWord;
    size_t len;
} * words; // declare words with wordlist;

// -----------------------------------

void srandom(unsigned int seed);

int getRandom(int len)
{
    /* Returns a number within a range of (0, len) */
    srand(0);
    int num = rand() % (len + 1);
    return num;
}

void loadWords(char const *fileName)
{

    /* Returns a list of valid words. Words are strings of uppercase letters.
    Assumes every word has maxium of 29 characters
    Depending on the size of the word list, this function may
    take a while to finish. */

    printf("Loading word list from file...");
    char temp[30];
    size_t counter = 0;
    words = malloc(sizeof(struct wordList));
    words->lenOfWord = 1;

    FILE *LIST = fopen(fileName, "r");
    if (LIST == NULL)
    {
        printf("File not found!");
        exit(1);
    }
    while (fscanf(LIST, "%s", temp) != EOF)
    {
        //Optimize memory in words's struct type
        size_t len = strlen(temp);
        if (words->lenOfWord < len)
        {
            words->lenOfWord = len;
        }

        //Allocate memory for words's elements
        words->index[counter] = malloc(sizeof(struct word));
        words->index[counter]->text = malloc(len * sizeof(char) + 1);

        //Get String and len for words
        strcpy(words->index[counter]->text, temp);
        words->index[counter]->len = len;
        counter++;
    }
    words->len = counter;
}

// char chooseWord(wordlist):
//     """
//     wordlist (list): list of words (strings)

//     Returns a word from wordlist at random
//     """
//     return random.choice(wordlist)

// //  Load the list of words into the variable wordlist
// //  so that it can be accessed from anywhere in the program
// wordlist = loadWords()

// int isWordGuessed(secretWord, lettersGuessed):
//    /*  secretWord: string, the word the user is guessing
//     lettersGuessed: list, what letters have been guessed so far
//     returns: boolean, True if all the letters of secretWord are in lettersGuessed;
//       False otherwise */

// char getGuessedWord(secretWord, lettersGuessed):

//    /*  secretWord: string, the word the user is guessing
//     lettersGuessed: list, what letters have been guessed so far
//     returns: string, comprised of letters and underscores that represents
//       what letters in secretWord have delbeen guessed so far.*/

// char getAvailableLetters(lettersGuessed):

//     /* lettersGuessed: list, what letters have been guessed so far
//     returns: string, comprised of letters that represents what letters have not
//       yet been guessed. */

// char hangman(secretWord):

//     /* secretWord: string, the secret word to guess.

//     Starts up an interactive game of Hangman.

//     * At the start of the game, let the user know how many
//       letters the secretWord contains.

//     * Ask the user to supply one guess (i.e. letter) per round.

//     * The user should receive feedback immediately after each guess
//       about whether their guess appears in the computers word.

//     * After each round, you should also display to the user the
//       partially guessed word so far, as well as letters that the
//       user has not yet guessed.

//     Follows the other limitations detailed in the problem write-up. */

// /* void main{
//     secretWord = chooseWord(wordlist).lower()
//     hangman(secretWord)
//     hangman(chooseWord(wordlist))
// } */




