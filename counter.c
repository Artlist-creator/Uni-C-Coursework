#include <stdio.h>
#include <string.h>

void find_freq(char s[], int count[]){
    int c = 0;
    while (s[c]!= '\0'){
        if(s[c] >= 'A' && s[c] <= 'Z'){
            count[s[c]-'A'] ++;
        }
        if(s[c] >= 'a' && s[c] <= 'z'){
            count[s[c]-'G'] ++;
        }
        c++ ;
    }
}

int main(){
    char string[100];
    int c,max = 0, count[51]={0};

    printf("input a string: ");
    fgets(string,100,stdin);

    find_freq(string, count);
    for(c = 0 ; c < 26; c++){
        if (count[c] != 0){
            printf("%c \t", c + 'A');
        }
    }
    
    for(c = 26 ; c < 51; c++){
        if (count[c] != 0){
            printf("%c \t", c + 'G');
        }
    }

    printf("\n");

    
    for(c = 0 ; c < 51; c++){
        if (count[c] != 0){
            printf("%d \t", count[c]);
            if(max < count[c]){
                max = count[c];
            }
        }
    }

    printf("\n");
    for(c = 0 ; c < 26; c++){
        if (count[c] == max){
            printf("%c \t", c + 'A');
        }
    }
    for(c = 26 ; c < 51; c++){
        if (count[c] == max){
            printf("%c \t", c + 'G');
        }
    }

    printf(" %d", max);



}
