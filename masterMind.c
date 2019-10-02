#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    printf("Welcome to Master Mind!!! \n"
           "At each turn, you will enter your guess in the playing board \n"
           "A valid guess are 4 values in between 0 and 5 \n"
           "Each guess will have each number within the guess seperated by hiting the enter \n"
           "When you ready enter your first guess. \n"
           "From that point on, You will be told how many perfect and imperfect matches \n"
           "After this message, You should guess again. You have 10 chances \n"
           "Good Luck!");

    int guess[4], sol[4], turn = 0, done = 1, perfect, imperfect, concatSol, concatGuess, concatCounter, savedPos, posCounter;
    time_t strRec, endRec;

    void srand(unsigned int seed);
    srand(time(NULL));

    int getRandomNumber()
    {
        // return a number between 0-5
        return rand() % 6;
    }
    short checkPos(int SavedPos, int posCounter, int checkPos)
    {
        // return 1(true) if do not have number repeat otherwise 0(false)
        int clone = savedPos;
        for (int i = 0; i < posCounter; i++)
        {
            if (checkPos == clone % 10)
            {
                return 0;
            }
            clone /= 10;
        }
        return 1;
    }
    printf("Solution for debug: ");
    for (int i = 0; i < 4; i++)
    {
        sol[i] = getRandomNumber();
        printf("%d", sol[i]);
    }

    printf("\n");
    time(&strRec);

    while (done == 1)
    {
        perfect = 0;
        imperfect = 0;
        concatSol = 0;
        concatGuess = 0;
        concatCounter = 0;
        savedPos = 0;
        posCounter = 0;

        printf("Turn %d \n", turn);
        printf("Any guess? \n");

        for (int i = 0; i < 4; i++)
        {
            printf("insert %d ", i + 1);
            scanf("%d", &guess[i]);
            while (guess[i] > 6)
            {
                printf("You should type a valid value between 0-5 \n"
                       "Type a valid number: ");
                scanf("%d", &guess[i]);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (guess[i] == sol[i])
            {
                perfect++;
            }
            else
            {
                concatSol += sol[i] * pow(10, concatCounter);
                concatGuess += guess[i] * pow(10, concatCounter);
                concatCounter++;
            }
        }
        int cloneGuess = concatSol;
        for (int i = 0; i < concatCounter; i++)
        {
            int tempCmpNumSol = concatGuess % 10;
            int doneWithin = 0; //double check
            for (int j = 0; j < concatCounter; j++)
            {
                int tempCmpNumGuess = concatSol % 10;
                if (doneWithin == 1)
                {
                    continue;
                }
                if (tempCmpNumGuess == tempCmpNumSol && checkPos(savedPos, posCounter, i) == 1)
                {
                    imperfect++;
                    savedPos = i * pow(10, posCounter);
                    posCounter++;
                    doneWithin = 1;
                }
                concatSol /= 10;
            }
            concatGuess /= 10;
            concatSol = cloneGuess;
        }
        turn++;
        printf("You have %d perfect matches and %d imperfect matches \n", perfect, imperfect);
        if (perfect == 4)
        {
            time(&endRec);
            double totTime = difftime(endRec, strRec);
            int hours = (int)totTime / 3600;
            int minutes = ((int)totTime - hours * 3600)/ 60;
            int secs = totTime - hours * 3600 - minutes * 60;
            printf("You have won the game in %d turn(s) within %d:%d:%d", turn, hours, minutes, secs);
            done = 0;
        }
        else if (turn == 10)
        {
            printf("Sorry you have exceeded the maximum number of your turns. You lose \n"
                   "Here is the winning board \n");
            for (int i = 0; i < 4; i++)
            {
                printf("%d", sol[i]);
            }
            done = 0;
        }
    }
    return 0;
}
