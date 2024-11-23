
#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

	/*
	static std::string ToString(ListNode* n) {
		int iNum1 = n ? n->val : 0;
		std::ostringstream oss;

		while (n != nullptr){
			n = n->next;
			iNum1 = n ? n->val : 0;
			oss << iNum1;
		}

		return oss.str();

	}
	*/

};


#endif