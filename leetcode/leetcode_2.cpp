/**
 * Definition for singly-linked list. //should be in headfile
 * struct ListNode { 
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //return address of value of function is ListNode type
        ListNode* res = new ListNode(0);// line6 new construction fuction
        ListNode* head = res; // * get value from add
        int add = 0;
        while(l1 && l2){  //logical and , 1. l1:2,l2:5
            //cout << l1->val << " " << l2->val << endl;
            add = l1->val + l2->val + add; // -> get valure of pointer,add:7
            l1->val = add % 10; //l1:7
            add = add / 10; //add:0
            head = head->next = l1; 
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1)
            head->next = l2;
        if(!l2)
            head->next = l1;

        ListNode* last = head;
        head = head->next;
        while(head){ //head 
            head->val = head->val + add;
            if(head->val < 10){
                add = 0;
                break;
            }
            head->val = head->val % 10;
            add = 1;
            last = last->next;
            head = head->next;
        }

        if(add == 0)
            return res->next;
        else{
            last = last->next = res; //add a single new linked list
            res->val = 1;
            res = res->next;
            last->next = NULL;
            return res;
        }
    }
};
