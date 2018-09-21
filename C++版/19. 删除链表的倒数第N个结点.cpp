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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *end;
        ListNode *dummy = new ListNode(0);  //考虑删除节点为头结点的情况
        dummy->next = head;
        first = dummy;
        end = dummy;
        while(n--)
            end = end->next;
        while(end->next != NULL){
            first = first->next;
            end = end->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};