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
ListNode* Add(ListNode * l1,ListNode* l2)
{
	if (l1 == nullptr && l2 == nullptr) return 0;
	else if (l1 == nullptr) return l2;
	else if (l2 == nullptr) return l1;
	int carry = 0;
	ListNode* l3 = nullptr;
	ListNode* pre = nullptr;
	while (l1 && l2)
	{

		int sum = l1->val + l2->val;
		int add = (sum + carry) % 10;
		carry = (sum + carry) / 10;
		ListNode* temp = new ListNode();
		temp->val = add;
		if (l3 == nullptr)
		{
			l3 = temp;
		}
		else
		{
			pre->next = temp;
		}

		pre = temp;
		l1 = l1->next;
		l2 = l2->next;


	}
	if (l1 != nullptr)
	{
		while (l1)
		{
			int add = (l1->val + carry) % 10;
			carry = (l1->val + carry) / 10;
			ListNode* temp = new ListNode();
			temp->val = add;
			pre->next = temp;
			pre = temp;
			l1 = l1->next;
		}
	}
	else if (l2 != nullptr)
	{
		while (l2)
		{
			int add = (l2->val + carry) % 10;
			carry = (l2->val + carry) / 10;
			ListNode* temp = new ListNode();
			temp->val = add;
			pre->next = temp;
			pre = temp;
			l2 = l2->next;
		}
	}
	if (carry != 0)
	{
		ListNode* temp = new ListNode();
		temp->val = carry;
		pre->next = temp;
		pre = temp;
	}
	return l3;
}

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
		cout << head->val <<"\t";
		head = head->next;
	}
}
int main()
{
	cout << "Enter the number in right to left form" << endl << "First num:" << endl;
	vector<int> num1;
	vector<int> num2;
	do {
		int num;
		cin >> num;
		if (num == -1)
			break;
		num1.push_back(num);
	} while (true);
	cout << "second number" << endl;
	do {
		int num;
		cin >> num;
		if (num == -1)
			break;
		num2.push_back(num);
	} while (true);

	ListNode* head1 = Create(num1);
	ListNode* head2 = Create(num2);
	ListNode* result = Add(head1, head2);
	cout << "num1 :";
	print(head1);
	cout << endl;
	cout << "num2 :";
	print(head2);
	cout << endl;
	cout << "Result :";
	print(result);
	return 0;
}