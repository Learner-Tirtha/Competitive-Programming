#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode()
	{
		this->val = 0;
		this->next = nullptr;
	}
	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};
ListNode* Create(vector<int> arr)
{
	ListNode* head = nullptr;
	ListNode* pre = nullptr;
	for (int i : arr)
	{
		ListNode* temp = new ListNode(i);
		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			pre->next = temp;
		}
		pre = temp;
	}
	return head;

}
void print(ListNode* head)
{
	while (head != nullptr)
	{
		cout << head->val << "\t";
		head = head->next;
	}
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (!list1) return list2;
	if (!list2) return list1;
	ListNode* list3 = nullptr;
	ListNode* temp = nullptr;
	while (list1 != nullptr && list2 != nullptr)
	{
		if (list1->val < list2->val)
		{

			if (list3 == nullptr)
			{
				list3 = list1;
				temp = list1;
				
			}
			else
			{
				
				temp->next = list1;
				temp = temp->next;
			}
			list1 = list1->next;
		}
		else
		{
			if (list3 == nullptr)
			{
				list3 = list2;
					temp = list2;
				
			}
			else
			{
				
				temp->next = list2;
				temp = temp->next;
			}
			list2 = list2->next;
		}
	}
	if (list1 != nullptr)
	{
		temp->next = list1;
	}
	else if (list2 != nullptr)
	{
		temp->next = list2;
	}
	return list3;
}
int main()
{
	cout << "Enter the first list :" << endl;
	vector<int> num1;
	vector<int> num2;
	do {
		int num;
		cin >> num;
		if (num == -1)
			break;
		num1.push_back(num);
	} while (true);
	cout << "second list:" << endl;
	do {
		int num;
		cin >> num;
		if (num == -1)
			break;
		num2.push_back(num);
	} while (true);

	ListNode* head1 = Create(num1);
	ListNode* head2 = Create(num2);
	ListNode* result = mergeTwoLists(head1, head2);
	cout << "Result :";
	print(result);
	return 0;
}