#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} LinkedNode;

void addTwoNumbersWithCarry(LinkedNode* l1, LinkedNode* l2, LinkedNode** result){
    if(l1==NULL && l2 == NULL && (*result)->val==0){
        *result = NULL;
        return;
    }
    int sum = (*result)->val;
    if(l2 != NULL){
        sum += l2->val;
    }
    if(l1 != NULL){
        sum += l1->val;
    }
    (*result)->val = sum%10;
    int carry = sum > 9;


    if(l1 != NULL || l2 !=NULL || carry>0){
        (*result)->next = (LinkedNode *) malloc(sizeof(LinkedNode));
        (*result)->next->val = carry;
        if(l1 && l2){
            addTwoNumbersWithCarry(l1->next, l2->next, &((*result)->next));
        }
        else if (l1)
        {
            addTwoNumbersWithCarry(l1->next, NULL, &((*result)->next));
        }
        else if (l2)
        {
            addTwoNumbersWithCarry(NULL, l2->next, &((*result)->next));
        }

    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    LinkedNode *head;
    head = (LinkedNode *) malloc(sizeof(LinkedNode));
    head->val = 0;
    addTwoNumbersWithCarry(l1, l2, &head);
    return head;
   
}

void printListNode(LinkedNode* l){
    printf("%d ", l->val);
    if (l->next)
    {
        printListNode(l->next);
    }
    printf("\n");
}

struct ListNode* createListNode(int digits[], int size){
    LinkedNode * head;
    head = (LinkedNode *) malloc(sizeof(LinkedNode));
    LinkedNode * output;
    output = head;
    for(int i=0; i<size; i++){
        head->val = digits[i];
        if(i<size-1){
            head->next = (LinkedNode *) malloc(sizeof(LinkedNode));
            head = head->next;
        }
    };
    return output;

}

int main(void){
    int digits[] = {0};
    int digits2[] = {0};

    LinkedNode *l1 = createListNode(digits, 1);
    LinkedNode *l2 = createListNode(digits2, 1);
    LinkedNode *l3 = addTwoNumbers(l1, l2);

}