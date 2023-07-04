#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int n_indices = 2;
    returnSize = &n_indices;
    int *indices;
    indices = malloc(sizeof *indices * 2);
    for(int i=0; i < numsSize-1; i++){
        for(int j=i+1; j < numsSize; j++){
            if(nums[i] + nums[j] == target){
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
}
int main(void){
    int nums[4] = {2,7,11,15};
    int target = 9;
    int *returnSize;
    returnSize = NULL;
    int *indices;

    indices = twoSum(nums, 4, target, returnSize);
    printf("Indices: %d, %d \n", indices[0], indices[1]);
    free(indices);
    
    return 0;
}