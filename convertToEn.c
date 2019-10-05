#include <string.h>
#include <stdio.h>
#include <math.h>
const char *digits[] = { NULL, "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine " };
const char *tens[] = { NULL, "ten ", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
const char *teens[] = { "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
const char *scales[] = { "", "thousand ", "million ", "billion " };

int numLength(int n){
    if ( n == 0){
        return 1;
    }
    else{
        return floor(log10(abs(n))) + 1;
    }
}

int main()
{
        int count = 0, j, temp, number;
        char * word_string[1000];
        printf("Enter A Number:\t");
        scanf("%d", &number);
        int numLen = numLength(number);
        while(number)
        {
                if (numLen != 2){
                    temp = number%10;
                    number = number/10;
                    word_string[count++] =
                }
                
        }
        for(j = count - 1; j >= 0; j--)
        {
            printf("%s ", word_string[j]);
        }
        return 0;
}