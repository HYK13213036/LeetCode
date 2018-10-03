
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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* tmp = head;
        ListNode *last = NULL;
        while(tmp)
        {
            length ++;
            last = tmp;
            tmp = tmp->next;
        }   //计算链表的长度
        if(length == 0 || k==0) return head;
        k= k%length;
        ListNode *newhead = head;  //建立一个闭合的环
        last->next = head;
         
        for(int i=k;i<length;i++){
            tmp = newhead;
            newhead = newhead->next;   
                 
        }
        tmp->next = NULL;   //找到对应位置断开环
        return newhead;
        
    }
};