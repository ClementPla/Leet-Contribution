#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} LinkedNode;

void addTwoNumbersWithCarry(LinkedNode* l1, LinkedNode* l2, LinkedNode* result){
    int sum = result->val;
    sum += l2->val;
    sum += l1->val;
    result->val = sum%10;
    int carry = sum > 9;


    if(l1 != NULL || l2 !=NULL || carry){
        result->next = (LinkedNode *) malloc(sizeof(LinkedNode));
        result->next->val = carry;

    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    LinkedNode *head;
    head = (LinkedNode *) malloc(sizeof(LinkedNode));
    head->val = 0;
    addTwoNumbersWithCarry(l1, l2, head);
    return head;

    
}

void printListNode(LinkedNode* l){
    printf("%d \n", l->val);
    if (l->next)
    {
        printListNode(l->next);
    }   
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
    int digits[] = {1,2,3,4,8};
    int digits2[] = {4,2,3,6};

    LinkedNode *l1 = createListNode(digits, 5);
    LinkedNode *l2 = createListNode(digits2, 4);
    LinkedNode *l3 = addTwoNumbers(l1, l2);

    printListNode(l3);

}