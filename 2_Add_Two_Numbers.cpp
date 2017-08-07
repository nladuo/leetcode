/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1, num2, carry = 0, sum = 0;
        ListNode *head_node = NULL, **p_node = &head_node;
        
        while(l1 != NULL || l2 != NULL){
            num1 = num2 = 0;
            if(l1 != NULL){
                num1 = l1->val;l1 = l1 -> next;
            }
            if(l2 != NULL){
                num2 = l2->val;l2 = l2 -> next;
            }
            sum = num1 + num2 + carry;
            
            *p_node = new ListNode(sum % 10);
            p_node = &((*p_node)->next); 
            
            carry = sum / 10;
        }
        if(carry == 1){
            *p_node = new ListNode(1);
        }
        
        return head_node;
    }
};