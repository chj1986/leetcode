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
        ListNode* l3=NULL;

        ListNode* tempL1=l1;
        ListNode* tempL2=l2;
        ListNode* tempL3=NULL;
        
        int oversum=0;
        while((tempL1!=NULL) || (tempL2!=NULL))
        {
            int sum=0;
            if(oversum==1)
            {
                sum++;
                oversum=0;
            }
            if(tempL1==NULL)
                sum += tempL2->val;
            else if(tempL2==NULL)
                sum += tempL1->val;
            else
                sum += tempL1->val + tempL2->val;
            if(sum>=10)
            {
                sum%=10;
                oversum=1;
            }
            ListNode* temp = new ListNode(sum);
            if(tempL3==NULL)
            {
                tempL3 = temp;
                l3 = temp;
            }
            else
            {
                tempL3->next = temp;
                tempL3=tempL3->next;
            }
            if(tempL1!=NULL)
                tempL1=tempL1->next;
            if(tempL2!=NULL)
                tempL2=tempL2->next;
        }
        if(oversum==1)
        {
            ListNode* temp = new ListNode(1);
            tempL3->next = temp;
            tempL3=tempL3->next;
        }
        return l3;
    }
};
