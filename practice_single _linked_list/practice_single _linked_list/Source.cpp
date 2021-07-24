#include<iostream>
using namespace std;
struct node {


	int data;
	node* next;



};
node* head;
class Single_Linked{
public:
    // This function inserts a node at the begin of the linked list
    void insert_begin(int new_data) {
        // allocate new node and put it's data
        node* new_node = new node();
        new_node->data = new_data;
        // check if the linked list is empty
        if (head == NULL) {
            head = new_node;
        }
        // otherwise insert the new node in the begin of the linked list
        else {
            // set next of the new node to be the head
            new_node->next = head;
            // set the new node as a head
            head = new_node;
        }
    }
    // This function inserts a node at the end of the linked list
    void insert_end(int new_data) {
        // allocate new node and put it's data
        node* new_node = new node();
        new_node->data = new_data;
        // check if the linked list is empty
        if (head == NULL) {
            head = new_node;
        }
        // otherwise reach the end of the linked list
        else {
            // get the last node in the linked list
            node* curr = head;
            while (curr->next != NULL)
                curr = curr->next;
            // set the next of the last node to be the new node
            curr->next = new_node;
        }
    }
	// This function require a node to add the new node after it in the linked list
	void insert_node(node* prev_node, int new_data) {
		// check if the given prev node is NULL
		if (prev_node == NULL)
			return;
		// allocate new node and put it's data
		node* new_node = new node();
		new_node->data = new_data;
		// set the next of the new node to be the next of the prev node
		new_node->next = prev_node->next;
		// move the next of the prev node to be the new node
		prev_node->next = new_node;
	}

	// This function deletes the first node in the linked list
	void delete_begin() {
		// check if the linked list is empty
		if (head == NULL)
			return;
		// get the node which it will be deleted
		node* temp_node = head;
		// check if the linked list has only one node
		if (head->next == NULL) {
			// delete the temp node
			delete(temp_node);
			head = NULL;
		}
		// otherwise the linked list has nodes more than one
		else {
			// shift the head to be the next node 
			head = head->next;
			// delete the temp node
			delete(temp_node);
		}
	}

	// This function deletes the last node in the linked list
	void delete_end() {
		// check if the linked list is empty
		if (head == NULL)
			return;
		// get the last node and the prev node of it in the linked list
		node* curr = head;
		node* prev = NULL;
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		// check if the linked list has only one node
		if (prev == NULL) {
			// delete the node which selected
			delete(curr);
			head = NULL;
		}
		// otherwise the linked list has nodes more than one
		else {
			// jump the deleted node
			prev->next = curr->next;
			// delete the node which selected
			delete(curr);
		}
	}

	// This function require a node to delete the node after it in the linked list
	void delete_node(node* prev_node) {
		// check if the given prev node is NULL
		if (prev_node == NULL || prev_node->next == NULL)
			return;
		// get the deleted node in the linked list
		node* temp_node = prev_node->next;
		// jump the deleted node
		prev_node->next = temp_node->next;
		// delete the node which selected
		delete(temp_node);
	}

	// This function searches for a node in the linked list
	bool search_node(int key) {
		// iterate on the nodes till reach the last node in the linked list
		node* curr = head;
		while (curr != NULL) {
			// check if the given key exists in the linked list
			if (curr->data == key)
				return true;
			curr = curr->next;
		}
		return false;
	}

	// This function prints the contents of the linked list
	void print_linked_list() {
		// print the data nodes starting from head till reach the last node
		node* curr = head;
		while (curr != NULL) {
			cout << curr->data << ' ';
			curr = curr->next;
		}
	}

	//Count number of nodes in linked list by iterative/recursive way
	int count() {
		if (head == NULL)
			return 0;
		int counter=0;
		node* temp = head;
		while (temp!= NULL) {
			counter += 1;
			temp = temp->next;
		
		}
	
		return counter;
	
	
	}
	//function to display linked list iterative
	void display_iterative() {
		if (head == NULL)
			return;
		node* temp = head;
		while (temp != NULL) {
			
			cout << temp->data <<" ";
			temp = temp->next;
		}
	
	}
	//function to Print linked list in reversed order
	void print_reverse(node*head) {
		
		if (head == NULL)
			return;

		
		// Base case
		if (head == NULL)
			return;

		// print the list after head node
		print_reverse(head->next);

		// After everything else is printed, print head
		cout << head->data << " ";
	
	
	
	
	
	
	}
	
	//function Print element at middle of linked list
	void print_middle() {
		if (head == NULL)
			return;
	   
		int counter = 0;
		node* temp = head;
		while (temp!=NULL) {
			counter += 1;
			temp = temp->next;

		}
		int countmiddle=0;
		node* tempo = head;
		while (tempo != NULL) {
			countmiddle += 1;
			if (countmiddle == counter / 2)
			{
				cout << tempo->data;
			}
			tempo = tempo->next;
		
		}
		
		
	}
	//function to Print element at position i in linked list
	void print_atposition(int i) {
		if (i < 0)
			return;
		if (head == NULL) {
			return;
		}

		int wanted_to_print = 0;
		node* tempo = head;
		while (tempo != NULL) {
			
			if (wanted_to_print == i)
			{
				cout << tempo->data;
			}
			tempo = tempo->next;
			wanted_to_print += 1;
		}
	
	
	
	}
	//function to  Insert element at position i in linked list
	void insert_at_position(int i,int new_data) {
		node* new_node = new node();
		new_node->data = new_data;
		if (i == 0) {
			new_node->next = head;
			head = new_node;
			return;
		
		}
		node* temp = head;
		//i-1 means iam on the previus node i want to insert at it position
		for (int x = 0; x < i-1&& temp->next!=NULL; x++) {
			temp = temp->next;
		
		}
		new_node->next=temp->next;
		temp->next = new_node;
	
	}
	// Delete element at position i in linked list
	void delete_at_position(int i) {
		
		if (head == NULL)
			return;
		node* temp = head;
		
		if (i == 0) {
			
			head = head->next;
			delete(temp);
			
		  
		}
		
		for (int x = 0; x < i - 1 && i != NULL; x++) {
			temp = temp->next;
		
		}
		node* temp2 = temp->next;
		temp->next = temp2->next;
		delete(temp2);
	
	
	
	}
	//Search node in linked list by iterative/recursive way
	void  search(int new_data) {
		if (head == NULL) {
			return;
		}
		node* temp = head;
		if (temp != NULL && temp->data != new_data) {

				temp = temp->next;

			cout << "not found" << endl;
		}
		else
			cout << "found" << endl;

		
		
		
			
			
				
			
		
		
	
	
	
	
	}
	
};

int main() {
	Single_Linked s;
	// Functionality Testing

	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items:
	----------------------------------------------------
	*/

	cout << "adding the following elements 10 20 30 40 50\n";
	s.insert_end(10);
	s.insert_end(20);
	s.insert_end(30);
	s.insert_end(40);
	s.insert_end(50);
	cout << "the above elements have been added to the linked list\n";

	/* Expected Output:
	adding the following elements 10 20 30 40 50
	the above elements have been added to the linked list
	*/

	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 10 20 30 40 50
	----------------------------------------------------
	*/

	cout << "add element 60 at the end of the linked list\n";
	s.insert_end(60);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 60 at the end of the linked list
	Linked List items: 10 20 30 40 50 60
	----------------------------------------------------
	*/

	cout << "add element 20 at the begin of the linked list\n";
	s.insert_begin(20);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 20 at the begin of the linked list
	Linked List items: 20 10 20 30 40 50 60
	----------------------------------------------------
	*/

	cout << "add element 70 at position 4 : \n";
	s.insert_node(head->next->next->next, 70);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 70 at position 4 :
	Linked List items: 20 10 20 30 70 40 50 60
	----------------------------------------------------
	*/

	cout << "add element 90 at position 7 : \n";
	s.insert_node(head->next->next->next->next->next->next, 90);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	add element 90 at position 7 :
	Linked List items: 20 10 20 30 70 40 50 90 60
	----------------------------------------------------
	*/

	cout << "delete the first element \n";
	s.delete_begin();
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the first element
	Linked List items: 10 20 30 70 40 50 90 60
	----------------------------------------------------
	*/

	cout << "delete the last element \n";
	s.delete_end();
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete the last element
	Linked List items: 10 20 30 70 40 50 90
	----------------------------------------------------
	*/

	cout << "delete element at position 3 : \n";
	s.delete_node(head->next->next);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete element at position 3 :
	Linked List items: 10 20 30 40 50 90
	----------------------------------------------------
	*/

	cout << "delete element at position 2 : \n";
	s.delete_node(head->next);
	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	delete element at position 2 :
	Linked List items: 10 20 40 50 90
	----------------------------------------------------
	*/

	if (s.search_node(40))
		cout << "element " << 40 << " in the linked list\n";
	else
		cout << "element " << 40 << " not in the linked list\n";

	if (s.search_node(100))
		cout << "element " << 100 << " in the linked list\n";
	else
		cout << "element " << 100 << " not in the linked list\n";
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	element 40 in the linked list
	element 100 not in the linked list
	----------------------------------------------------
	*/

	cout << "deleting the following elements 10 20 40 50 90\n";
	s.delete_end();
	s.delete_end();
	s.delete_end();
	s.delete_end();
	s.delete_end();
	cout << "the above elements have been deleted from the linked list\n";

	/* Expected Output:
	deleting the following elements 10 20 40 50 90
	the above elements have been deleted from the linked list
	*/

	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items:
	----------------------------------------------------
	*/

	cout << "adding the following elements 30 20 10\n";
	s.insert_begin(10);
	s.insert_begin(20);
	s.insert_begin(30);
	cout << "the above elements have been added to the linked list\n";

	/* Expected Output:
	adding the following elements 30 20 10
	the above elements have been added to the linked list
	*/

	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items: 30 20 10
	----------------------------------------------------
	*/

	cout << "deleting the following elements 30 20 10\n";
	s.delete_begin();
	s.delete_begin();
	s.delete_begin();
	cout << "the above elements have been deleted from the linked list\n";

	/* Expected Output:
	deleting the following elements 30 20 10
	the above elements have been deleted from the linked list
	*/

	cout << "Linked List items: ";
	s.print_linked_list();
	cout << '\n';
	cout << "----------------------------------------------------\n";

	/* Expected Output:
	Linked List items:
	----------------------------------------------------
	*/
	//add 4 item
	s.insert_end(10);
	s.insert_end(20);
	s.insert_end(30);
	s.insert_end(40);
	s.insert_end(50);
	s.insert_end(60);
	//print them 
	
	cout << "the node list is "<<endl;
	s.print_linked_list();
	cout << endl;
	//check for count function
	cout << "the count of node is " << s.count() << endl;
	cout << "----------------------------------------------------\n";

	//check function to display linked list iterative
	cout << "display node iterative  "<<endl ;
	s.display_iterative();
	cout << endl;
	cout << "----------------------------------------------------\n";



	//check for function to Print linked list in reversed order
	 cout << "linked list after revers" << endl;
	 s.print_reverse(head);
	 cout << endl;
	 cout << "----------------------------------------------------\n";
	 



	 //check for function Print element at middle of linked list
	 cout << "the middle element is" << endl;
	 s.print_middle();
	 cout << endl;
	 cout << "----------------------------------------------------\n";

	 //check for function to Print element at position i in linked list
	 cout << "print at position 0" << endl;
	 s.print_atposition(0);
	 cout << endl;
	 cout << "----------------------------------------------------\n";



	 //check for function tp Insert element at position i in linked list
	 cout << "insert 90 at position 2" << endl;
	 s.insert_at_position(2, 90);
	 s.print_linked_list();
	 cout << endl;
	 cout << "----------------------------------------------------\n";

	 //check for  Delete element at position i in linked list
	 
	 cout << "delete position 2 the iteem is 90" << endl;
	 s.delete_at_position(2);
	 s.print_linked_list();
	 cout << endl;
	 cout << "----------------------------------------------------\n";


	 //check for function  node in linked list by iterative/recursive way
	 s.search(890);
	 cout << endl;
	 cout << "----------------------------------------------------\n";
	 
}