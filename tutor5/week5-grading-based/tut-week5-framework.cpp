#include <iostream>
#include <fstream>

/*
  Tutorial of week 5. This is a grading-based tutorial. Full credit: 15 pts. 
  Task: merge two sorted linked lists into one sorted linked lists. For example, list A is: 12->13->34->50; List B is: 1->19->37
  The merged sorted linked list is: 1->12->13->19->34->37->50. 
  Below please find the framework of this task.  

  Specific requirements.
  1) read a sorted list from sortA.txt and create the first sorted linked list
  2) read a sorted list from sortB.txt and create a second sorted linked list
  3) merge the two sorted linked list; save the list in another linked list and print out its content
 */


using namespace std;

struct ListNode {
	int info;
	ListNode* link;
};

// append the new element at the end of the list
void append(ListNode*& head, int x) {
	ListNode* p = new ListNode;
	p->info = x;
	p->link = NULL;

	if (head == NULL) {
		p->link = head;
		head = p;
	}
	else {
		ListNode* prev = head;
		ListNode* cur = head->link;

		while (cur != NULL) {
			prev = cur;
			cur = cur->link;
		}

		p->link = prev->link;
		prev->link = p;
	}
}

// read file and initialize the linked list
ListNode* initialize_list(string s) {
	ListNode* head = NULL;
	ifstream inFile(s);

	if (!inFile.is_open()) {
		cout << "Error: cannot open data file" << endl;
		exit(0); //terminate the program
	}

	while (!inFile.eof()) { //not end of file
		int i;
		inFile >> i;    //read in an integer

		if (!inFile.fail())
			append(head, i); //insert into the linked list
		else
			break;
	}

	inFile.close();
	return head;
}

// print all the elements in the linked list
void print(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->info << " ";
		cur = cur->link;
	}
	cout << endl;
}
/************************ Do not modify the code above ***********************/


/*****************  Please implement the merge function here *****************/

ListNode* merge(ListNode* head1, ListNode* head2) {
	/* Please implement this function. It reads two sorted linked list and merge them into one sorted list and return its head */
	ListNode *newL = NULL;
	while (head1!=NULL && head2!=NULL)
	{
		/* code */
		if (head1->info > head2->info)
		{
			append(newL, head2->info);
			head2 = head2->link;
		}else{
			append(newL, head1->info);
			head1 = head1->link;
		}
	}
	while (head1==NULL && head2!=NULL)
	{
		append(newL, head2->info);
		head2 = head2->link;
	}

	while (head1 != NULL && head2==NULL)
	{
		append(newL, head1->info);
		head1 = head1->link;
	}
	return newL;
}

/*****************************************************************************/

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	
	head1 = initialize_list("sortA.txt");
	head2 = initialize_list("sortB.txt");

	cout << "Contents of the list A: ";
	print(head1);
	cout << "Contents of the list B: ";
	print(head2);

	ListNode* new_head = NULL;


	/*****************  Please implement the merge function *****************/
	new_head = merge(head1, head2);

	/************************************************************************/


	cout << "This is the output of the new list after merging:";
	print(new_head);
}

