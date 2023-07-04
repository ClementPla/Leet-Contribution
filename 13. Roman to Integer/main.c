#include <stdio.h>
#include <stdlib.h>

int checkCurrentLetter(char current){
    switch(current){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    };
}
int checkIfSubstraction(char current, char previous){

    if(previous=='I' && (current=='V' || current=='X')){ 
            return 2;
        }
    if(previous=='X' && (current=='L' || current=='C')){ 
        return 20;
    }
    if(previous=='C' && (current=='D' || current=='M')){ 
        return 200;
    }
    return 0;
    



}

int romanToInt(char s[]){
    int length = strlen(s);
    int result = 0;
    for(int i=0;i<length;i++){
        char current = s[i];
        result += checkCurrentLetter(current);
        if(i>0){
            char previous = s[i-1];
            result -= checkIfSubstraction(current, previous);
        }
    };
    return result;
}

int main(void){

    char s[] = "LVIII";
    int number = romanToInt(s);
    printf("Result %d \n", number);
    return 0;

}