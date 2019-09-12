#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hangman game

struct word {
	size_t len;
	char * text;
};

struct wordList {
	size_t count;
	struct word * list[90000];
	size_t maxLen;
} * words // declare words with wordlist;

// -----------------------------------
char loadWords(const char *fileName){
    /* Returns a list of valid words. Words are strings of uppercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish. */
    printf("Loading word list from file...");
    char temp[30];
    size_t index = 0;
    words = malloc(sizeof(struct wordList));
    words.maxLen = 1;

    FILE * LIST = fopen(fileName, "r");
    if (LIST == NULL){
        printf("File not found!");
        exit(1);
    }
    while (fscanf(LIST, "%s",temp)!= EOF)
    {
        size_t len = strlen(temp);
        if (words.maxlen < len){
            words.maxlen =len;
        }
        words.list[index] = malloc(sizeof(struct word));
		words.list[index].text = malloc(len*sizeof(char)+1);


    }
    
    
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




