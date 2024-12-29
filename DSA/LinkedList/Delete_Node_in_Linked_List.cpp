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

	void deleteNode(ListNode * node) {
		if (node == nullptr) return;
		ListNode* pre = nullptr;
		while (node->next != nullptr)
		{
			node->val = node->next->val;
			pre = node;
			node = node->next;
		}
		pre->next = nullptr;
	}
	ListNode * findout(int i,ListNode * head)
	{
		while (head!=nullptr)
		{
			if (head->val == i)
				return head;
			else
				head = head->next;
		}
		return nullptr;
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
		cout << "enter the number in list" << endl;
		ListNode* Node = findout(i, head);
		deleteNode(Node);
		print(head);
		return 0;
		
	}