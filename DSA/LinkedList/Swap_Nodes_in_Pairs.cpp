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
ListNode* Swap(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* first = head->next;
	ListNode* second = head;
	while (first != nullptr)
	{
		int temp = first->val;
		first->val = second->val;
		second->val = temp;
		if (first->next!=nullptr)
		{
			first = first->next->next;
			second = second->next->next;
		}
		else
		{
			break;
		}
	}
	return head;
}
int main()
{
	cout << "Enter the list of numbers:";
	vector<int> num1;
	do {
		int num;
		cin >> num;
		if (num == -1)
			break;
		num1.push_back(num);
	} while (true);
	ListNode* head = Create(num1);
	print(head);
	cout << endl;
	ListNode* result = Swap(head);
	cout << "Result:";
	print(result);
	return 0;
}