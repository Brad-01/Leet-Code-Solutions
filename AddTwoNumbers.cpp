/*
 * Author:             Brad Buckingham
 * Date Created:       10/1/2021
 * Date Last Modified: 10/1/2021
 *
 * Problem Source:
 * https://leetcode.com/problems/add-two-numbers/
 */
// ----------------------------------------------------------------------------
// https://leetcode.com/problems/add-two-numbers/
// Add Two Numbers
// ----------------------------------------------------------------------------
/*
 * Problem Description:
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their
 * nodes contains a single digit. Add the two numbers and return the sum
 * as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except
 * the number 0 itself.
 * ----------------------------------------------------------------------------
 * Example 1:
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 * Example 2:
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 * Example 3:
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * ----------------------------------------------------------------------------
 * Constraints:
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not
 * have leading zeros.
 */
// ----------------------------------------------------------------------------
/*
 * Results:
 * Runtime: 47 ms, faster than 25.03% of C++ online submissions for Add
 *          Two Numbers.
 * Memory Usage: 71.4 MB, less than 47.49% of C++ online submissions
 *               for Add Two Numbers.
 */
// ----------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = &combine(*l1,*l2);
        ListNode* traverse = ans;
        while(traverse){
            if(traverse->val > 9){
                traverse->val = traverse->val % 10;
                if(traverse->next){
                    traverse->next->val++;
                }else{
                    traverse->next = new ListNode(1);
                }
            }
            traverse = traverse->next;
        }traverse = nullptr;

        return ans;
    }
// ----------------------------------------------------------------------------
    ListNode& combine(ListNode l1, ListNode l2){
        ListNode* first = &l1;
        ListNode* second = &l2;
        ListNode* ans = new ListNode(first->val + second->val);
        ListNode* traverse = ans;
        int sum = 0;
        first = first->next;
        second = second->next;
        // Add first List to Answer List
        while(first || second){
            sum = 0;
            if(first){
                sum += first->val;
                first = first->next;
            }if(second){
                sum += second->val;
                second = second->next;
            }
            traverse->next = new ListNode(sum);
            traverse = traverse->next;
        }
        return *ans;
    }
};
