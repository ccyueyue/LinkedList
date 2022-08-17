#include<iostream>

struct ListNode{ //链表中的单个节点的结构体类型
	int value;
	ListNode* next;
	ListNode(int value) :value(value), next(nullptr) {};//用初始化列表来初始化变量的构造函数
};

ListNode* CreateLinkedList(const int* arr, const int n) { //用一个数组来创建一个链表的函数
	if (n == 0) return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

ListNode* ReverseListNode(ListNode* head) { //反转一个链表的函数
	ListNode* pre =nullptr;
	ListNode* cur = head;
	while (cur != nullptr) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

void printList(ListNode* head) { //打印链表
	ListNode* curNode = head;
	for (int i = 0; i < 5; i++) {
		std::cout << curNode->value<<" ";
		curNode = curNode->next;
	}
	std::cout << std::endl;
}
int main()
{
	int arr[] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ListNode* List= CreateLinkedList(arr, n);
	printList(List);
	ListNode* List1 = ReverseListNode(List);
	printList(List1);
	system("pause");
	return 0;
}