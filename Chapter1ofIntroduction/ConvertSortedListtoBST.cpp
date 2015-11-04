/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(!head) return NULL;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy, *slow = head, *fast = head;
        while(fast->next && fast->next->next)
        {
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        TreeNode* l = sortedListToBST(dummy.next);
        slow = slow->next;
        TreeNode* r = sortedListToBST(slow);
        root->left = l;
        root->right = r;
        return root;
    }

};

