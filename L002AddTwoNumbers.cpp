#include <stdio.h>
#include <malloc.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}; 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* res;
	res = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p = res;
	int c = 0;
	while (l1 && l2) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		int tmp = l1->val + l2->val + c;
		q->val = tmp % 10;
		q->next = NULL;
		c = tmp / 10;
		p->next = q;
		p = q;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		int tmp = l1->val + c;
		q->val = tmp % 10;
		q->next = NULL;
		c = tmp / 10;
		p->next = q;
		p = q;
		l1 = l1->next;
	}
	while (l2) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		int tmp = l2->val + c;
		q->val = tmp % 10;
		q->next = NULL;
		c = tmp / 10;
		p->next = q;
		p = q;
		l2 = l2->next;
	}
	if (c) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->val = c;
		q->next = NULL;
		p->next = q;
	}
	res = res->next; 
	return res;
}

class Solution {
public:
    int add(int a, int b, int& c) {
        int temp = a + b + c;
        c = temp / 10;
        return temp % 10;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *last = NULL;
        int value = 0, c = 0;
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL) {
                value = add(0, l2->val, c);
                l2 = l2->next;
            }
            else if (l2 == NULL) {
                value = add(l1->val, 0, c);
                l1 = l1->next;
            }
            else {
                value = add(l1->val, l2->val, c);
                l1 = l1->next;
                l2 = l2->next;
            }
            
            ListNode* tempNode = new ListNode(value);
            
            if (head == NULL) {
                head = tempNode;
                last = head;
            }
            else {
                last->next = tempNode;
                last = tempNode;
            }
        }
        if (c != 0) {
            last->next = new ListNode(c);
        }
        return head;
    }
};

int main() {
	struct ListNode* l1;
	struct ListNode* l2;
	l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	int nums1[] = {2,2,8,4,7,2,0,3,4,1};
	int nums2[] = {8,7,9,2,7,6,7};
//	int nums1[] = {2,4,3};
//	int nums2[] = {5,6,4};
	struct ListNode* p = l1;
	for (int i = 0; i < 10; i++) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->val = nums1[i];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	l1 = l1->next;
	p = l2;
	for (int i = 0; i < 7; i++) {
		struct ListNode *q;
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->val = nums2[i];
		q->next = NULL;
		p->next = q;
		p = q;
	}
	l2 = l2->next;
	struct ListNode* res;
	res = addTwoNumbers(l1, l2);
	while (res) {
		printf("%d ", res->val);
		res = res->next;
	}
	return 0;
} 
