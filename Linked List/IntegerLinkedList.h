#pragma once

class SNode {
public:
	int elem;
	SNode* next;
};

class IntegerLinkedList {
private:
	SNode* head;
public:
	IntegerLinkedList() {
		head = nullptr;
	}

	void addFront(int x) {
		SNode* tmp = head;
		head = new SNode;
		head->next = tmp;
		head->elem = x;
	}

	void print(void) {

		SNode* tmp = head;

		while (tmp != nullptr)
		{
			std::cout << tmp->elem << " ";
			tmp = tmp->next;

		}

		std::cout << std::endl;
	}

	int getInteger(int position)
	{ // COMPLETE THIS
		SNode* temp = head;
		int i = 0;

		if (temp == nullptr)  //base case
		{
			return -1;
		}

		while (temp != nullptr)
		{
			if (i == position)
			{
				return temp->elem;
			}
			i++;
			temp = temp->next;
		}
		return -1;
	}

	int MaxList()
	{
		if (head == nullptr)
			return -1;
		return Max(head, head->elem);
	}

	int Max(SNode* temp, int max)
	{
		if (temp == nullptr)
			return max;
		if (temp->elem > max)
			max = temp->elem;
		return Max(temp->next, max);

		
	}

};
