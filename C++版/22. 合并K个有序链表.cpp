//方法一: 分而治之的思想，递归。。。
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKListsHelper(const vector<ListNode*>& lists, int begin, int end){
        if(begin > end)
            return nullptr;
        if(begin == end)
            return lists[begin];
        return mergeTwoLists(mergeKListsHelper(lists, begin, (begin + end) / 2),
                             mergeKListsHelper(lists, (begin + end) / 2 + 1, end));
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

//方法二： 优先级队列
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution3 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        auto *cur = &dummy;

        struct Compare {
            bool operator() (const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
        };

        // Use min heap to keep the smallest node of each list
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (const auto& n : lists) {
            if (n) {
                min_heap.emplace(n);
            }
        }

        while (!min_heap.empty()) {
            // Get min of k lists.
            auto *node = min_heap.top();
            min_heap.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                min_heap.emplace(node->next);
            }
        }

        return dummy.next;
    }
};