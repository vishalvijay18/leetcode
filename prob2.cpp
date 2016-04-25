/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };
*/

#include<iostream>
#include<stdlib.h>

using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void appendNode(ListNode** listHead, ListNode** l1Top, ListNode** node)
{
	if((*listHead) == NULL) {
             *listHead = *node;
	     *l1Top = *listHead;
	     //cout << (*listHead)->val << endl;
        }
        else {
             (*listHead)->next = *node;
             *listHead = *node;
        }
}

void addTwoNumbers(ListNode** l1, ListNode** l2, ListNode** res) {
	ListNode *listHead=NULL, *l1Top=NULL;
	ListNode *l1Head, *l2Head;
	l1Head = *l1; l2Head = *l2;
	int carry=0;

	while(l1Head != NULL && l2Head != NULL) {
		//cout << "inside\n";
		ListNode *node = new ListNode((l1Head->val + l2Head->val + carry)%10);
		carry = (l1Head->val + l2Head->val + carry)/10;
		//cout << node->val << endl;
		appendNode(&listHead, &l1Top, &node);
		//cout << listHead->val << endl;
		l1Head = l1Head->next;
		l2Head = l2Head->next;
	}

	if(l1Head) {
                while(l1Head != NULL) {
                        ListNode *node = new ListNode((l1Head->val + carry)%10);
                        carry = (l1Head->val + carry)/10;
                        appendNode(&listHead, &l1Top, &node);
                        l1Head = l1Head->next;
                }
        } else if(l2Head) {
                while(l2Head != NULL) {
                        ListNode *node = new ListNode((l2Head->val + carry)%10);
                        carry = (l2Head->val + carry)/10;
                        appendNode(&listHead, &l1Top, &node);
                        l2Head = l2Head->next;
                }
        }

	if(carry != 0) {
		ListNode *node = new ListNode((carry)%10);
                //cout << node->val << endl;
                appendNode(&listHead, &l1Top, &node);
	}
	

	*res = l1Top;
}

int main()
{
	ListNode *l1, *l2, *res=NULL;
	l1 = new ListNode(5);
	l1->next = new ListNode(3);
	l2 = new ListNode(9);
	l2->next = new ListNode(6);

	addTwoNumbers(&l1, &l2, &res);	
	
	while((res) != NULL) {
		cout << (res)->val << "\n";
		res = res->next;
	}
	return 0;
}
