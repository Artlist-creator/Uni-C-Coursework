
/*
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun 05 09:32 2019

@author: artlist
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>
int indexMax(int a[], int n){
    // return index that have biggest value
    int index_max = 0, i;
    for(i =1; i < n; i++){
        if(a[i] > a[index_max]){index_max = i;};
    }
    return index_max;
}
int indexMin(int array[], int n){
    int index_min = 0, i;
    for( i = 1; i< n; i++){
        if(array[i]< array[index_min]) index_min = i;
    }
}
void insert(int a[], int &tot, int value, int index){
    //insert a value to a index's array
    if (index < 0 || index >tot) return;
    int i;
    for(i = tot; i > index; i --){
        a[i] = a[i-1];
    }
    a[index] = value; tot++;
    }
int Index(int a[], int len, int val){
    // find a index that haven a given value
    // if not find  a value return false
    int i = 0;
    for(i ; i < len - 1; i++){
        if (a[i] == val) return i;
        else return false;
    }
}

void removeIndex(int a[], int &len, int index){
    //remove index from array
    if (index < 0 || index >= len){
        printf("Index out of range");return;
    }
    else{
        for(index ; index < len -1; index ++) a[index] = a[index + 1];
        len --;
    }
}

void Swap(int &a, int &b){
    int temp;
    a = temp;
    a = b;
    b = temp;
}
void reverse(int a[], int len){
    int index;
    for (index = 0 ; index< len/2; index++) Swap(a[index], a[len-1-index]);
}
void selectionSort(int array[], int len){
    int x,z;
    for (x = 0; x < len -1; x++){
        int min  = x +1;
        for (z = x+1; z < len; z++){
            if (array[z] < array[min]) min = z;
        }
        if(array[x] > array[min]) Swap(array[x],array[min]);
    }
}

void bubbleSort(int a[],int len){
    int i , j ;
    for (i =0; i<len -1; i++)
        for(j =i +1; j < len;j++)
            if (a[i] > a[j]) Swap(a[i],a[j]);
}

void subString(char string[], int strIndex , int endIndex ,char createStr[]){
       int i,j,len;
       len = strlen(string);
       if((endIndex < len || strIndex >= 0) && strIndex < endIndex) i = strIndex; j = endIndex;
       while(i < j){
           createStr[i++]= string[i];
       }
       createStr[i] = '\0';
   }

bool isPrime(int number)
{
    int i;
    if (number == 2){
        return true;
    }
    else if(number >2){
        return false;
    }
    else{
        for(i = 0; 1 < i < number; i++){
            if (number %i == 0){
                return false;
            }
            else{
                return true;
            }
        }
    }
}

int nextPrime(int number){
    int i;
    for (i = number+1; ;i++){
        if(isPrime(i) == true){
            return i;
            break;
        }
    }
}
/* 
void substring(char s[], int k, int n, char t[]) {
	int i, j, len;
	len = strlen(s);
	if(k < 0 || k >= len || n < 0) return;
	i = k; j = 0;
	while(i < len && j < n) {
		t[j++] = s[i++];
	}
	t[j] = '\0';
}
*/

void lower(char str[]){
    int len = strlen(str), i;
    for(i= 0 ; i < len; i++) str[i] = tolower(str[i]);
}
void upper(char str[]){
    int len = strlen(str), i ;
    for(i =0; i <len; i++) str[i] = toupper(str[i]);
}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
/*
int main()
{
    char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    char** tokens;

    printf("months=[%s]\n\n", months);

    tokens = str_split(months, ',');

    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("month=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }

    return 0;
}
*/
char* join_strings(char* strings[], char* seperator, int count) {
    char* str = NULL;             /* Pointer to the joined strings  */
    size_t total_length = 0;      /* Total length of joined strings */
    int i = 0;                    /* Loop counter                   */

    /* Find total length of joined strings */
    for (i = 0; i < count; i++) total_length += strlen(strings[i]);
    total_length++;     /* For joined string terminator */
    total_length += strlen(seperator) * (count - 1); // for seperators

    str = (char*) malloc(total_length);  /* Allocate memory for joined strings */
    str[0] = '\0';                      /* Empty string we can append to      */

    /* Append all the strings */
    for (i = 0; i < count; i++) {
        strcat(str, strings[i]);
        if (i < (count - 1)) strcat(str, seperator);
    }

    return str;
}

oid printBinary(int n){
    // this function will print the binary form of decimal given
    // Do not return anything
    int a[51], num[51] ,counter = 0, bit, clone = n, i;
    while(clone != 0){
        bit = clone %2;
        clone /= 2;
        num[counter] = bit;
        counter += 1;
    }
    /*
    for(i = counter -1; i >= 0 ; i --){
        switch(a[i]){
            default: print("%d", a[i]); break;
            case 10: printf("A");break;
            case 11: printf("B"); break;
            case 12: printf("C"); break;
            case 13: printf("D");break;
            case 14: printf("E"); break;
            case 15: printf("F"); break;
        }
    }
    */
    for(i = counter -1 ; i >= 0; i--) printf("%d ", num[i]);

}


//scanf("%[^\n]",&s);