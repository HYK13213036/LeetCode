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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //进位
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* pre = head;
        while(l1 != NULL || l2 != NULL || carry!=0){  //为null相当于零，但不能同时为null
            int sum = (l1 == NULL ? 0:l1->val) + (l2 == NULL ? 0:l2->val) + carry;
            ListNode* cur = new ListNode(sum%10);  //当前节点的值为个位数
            carry = sum / 10;
            pre->next = cur;
            pre = cur;   // 把pre从head指向cur

            l1 = (l1==NULL ? l1 : l1->next);   //寻找下一个节点
            l2 = (l2==NULL ? l2 : l2->next);
        }
        return head->next;
    }
};