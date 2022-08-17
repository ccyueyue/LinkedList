#include<iostream>

struct ListNode{ //�����еĵ����ڵ�Ľṹ������
	int value;
	ListNode* next;
	ListNode(int value) :value(value), next(nullptr) {};//�ó�ʼ���б�����ʼ�������Ĺ��캯��
};

ListNode* CreateLinkedList(const int* arr, const int n) { //��һ������������һ������ĺ���
	if (n == 0) return nullptr;
	ListNode* head = new ListNode(arr[0]);
	ListNode* curNode = head;
	for (int i = 1; i < n; i++) {
		curNode->next = new ListNode(arr[i]);
		curNode = curNode->next;
	}
	return head;
}

ListNode* ReverseListNode(ListNode* head) { //��תһ������ĺ���
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

void printList(ListNode* head) { //��ӡ����
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