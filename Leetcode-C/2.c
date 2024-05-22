/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    int carry,add,i = 0;
    //int result[7] = {};
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

    while(l1 != NULL && l2 != NULL){
        add = l1->val + l2->val  + carry;
        carry = 0;
        if(add > 10) {
            add = add - 10;
            carry++;
        }
        //result[i] = add;
        //i++;
        l1 = l1->next;
        l2 = l2->next;
        newNode->val = add;
        newNode = newNode->next;
    }

    return newNode;
    //return newNode;
    //return result;
}
