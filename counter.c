#include <stdio.h>
#include <string.h>

void find_freq(char s[], int count[]){
    int c = 0;
    while (s[c]!= '\0'){
        if(s[c] >= 'a' && s[c] <= 'z'){
            count[s[c]-'a'] ++;
        }
        c++ ;
    }
}

int main(){
    char string[100];
    int c,max = 0, count[26]={0};

    printf("input a string: ");
    fgets(string,100,stdin);

    find_freq(string, count);
    for(c = 0 ; c < 26; c++){
        if (count[c] != 0){
            printf("%c \t", c + 'a');
        }
    }
    printf("\n");

    
    for(c = 0 ; c < 26; c++){
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
            printf("%c \t", c + 'a');
        }
    }

    printf(" %d", max);



}
