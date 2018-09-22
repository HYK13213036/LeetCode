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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next && cur->next->next){
            ListNode* nextone = cur->next;
            ListNode* nexttwo = nextone->next;
            ListNode* nextthree = nexttwo->next;
            cur->next = nexttwo;
            nextone->next = nextthree;
            nexttwo->next = nextone;
            cur = nextone;
        }
        return dummy->next;
    }
};
