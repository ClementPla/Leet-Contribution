#include <stdio.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

bool isPalindrome(int x){
    if(x<0 || (x%10 == 0 && x>0)){
        return false;
    }
    int right2left = 0;
    while(x>right2left){
        right2left = right2left*10 + x % 10;
        x /= 10;
    }
    return (x==right2left || x==right2left/10);
}

int main(void){


    return 0;
}