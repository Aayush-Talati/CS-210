#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;


    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }

    MonopolyBoard() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }


    bool isEqual(MonopolyBoard other) {
        if (this->propertyName == other.propertyName) {
            return true;
        } else {
            return false;
        }
    }


    void print() {
       /*Define Print Here*/
        cout<<"Property: "<<propertyName<<", Color: "<<propertyColor<<", Value: "<<value<< ", Rent: "<<rent<<endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;

public:
    CircularLinkedList() {
    headNode = nullptr;
    }
// Core Tasks
    void insertAtHead(T value) {

        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr) {
            // List is empty, make the new node point to itself
            headNode = newNode;
            newNode->nextNode = newNode;
        } else {
            Node<T>* temp = headNode;

            // Find the last node (tail node)
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }

            // Insert the new node at the head
            newNode->nextNode = headNode;
            headNode = newNode;
            temp->nextNode = headNode; // Tail should point to the new head
        }
    }

    void insertAtTail(T value) {

        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr) {
            // List is empty, make the new node point to itself
            headNode = newNode;
            newNode->nextNode = newNode;
        } else {
            Node<T>* temp = headNode;

            // Find the last node (tail node)
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }

            // Insert the new node at the tail
            temp->nextNode = newNode;
            newNode->nextNode = headNode; // New node should point to the head
        }
    }

    void insertAtPosition(T value, int position) {

        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        if (position == 1) {
            insertAtHead(value); // If position is 1, just insert at head
            return;
        }

        Node<T>* temp = headNode;
        int count = 1;

        // Traverse to the node just before the desired position
        while (count < position - 1 && temp->nextNode != headNode) {
            temp = temp->nextNode;
            count++;
        }

        if (count != position - 1) {
            cout << "Position out of range!" << endl;
            return;
        }

        // Insert the new node at the desired position
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
    }

    void deleteAtHead() {

        if (headNode == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (headNode->nextNode == headNode) {
            // Only one node in the list
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;

            // Find the tail node
            while (temp->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T>* toDelete = headNode;
            headNode = headNode->nextNode; // Update head to the next node
            temp->nextNode = headNode; // Tail should point to the new head
            delete toDelete;
        }
    }

    void deleteAtTail() {

        if (headNode == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (headNode->nextNode == headNode) {
            // Only one node in the list
            delete headNode;
            headNode = nullptr;
        } else {
            Node<T>* temp = headNode;

            // Find the second-to-last node
            while (temp->nextNode->nextNode != headNode) {
                temp = temp->nextNode;
            }

            Node<T>* toDelete = temp->nextNode;
            temp->nextNode = headNode; // Update the second-to-last node to point to the head
            delete toDelete;
        }
    }

    void deleteAtPosition(int position) {

        if (headNode == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position == 1) {
            deleteAtHead(); // If the position is 1, delete at head
            return;
        }

        Node<T>* temp = headNode;
        int count = 1;

        // Traverse to the node just before the desired position
        while (count < position - 1 && temp->nextNode != headNode) {
            temp = temp->nextNode;
            count++;
        }

        if (count != position - 1 || temp->nextNode == headNode) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node<T>* toDelete = temp->nextNode;
        temp->nextNode = toDelete->nextNode;
        delete toDelete;
    }


    bool search(T value) {

        if (headNode == nullptr) {
            cout << "List is empty." << endl; // Handle empty list case
            return false; // Property not found
        }

        Node<T>* current = headNode;

        do {
            if (current->data == value) {
                // Property found; return true
                cout << "Property found: " << current->data << endl;
                return true;
            }
            current = current->nextNode;
        } while (current != headNode); // Traverse until we circle back to headNode

        cout << "Property not found." << endl; // If not found after full traversal
        return false; // Property not found
    }
    void printList() {
        if (headNode == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        Node<T>* temp = headNode;
        do {
            temp->data.print();  // Print the Monopoly property details
            temp = temp->nextNode;
        } while (temp != headNode);
    }

    //Optional Tasks
    //Level 1
    void reverseCLList() {

        if (headNode == nullptr || headNode->nextNode == headNode) {
            // List is empty or has only one node
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* current = headNode;
        Node<T>* next = nullptr;
        Node<T>* tail = headNode;

        do {
            next = current->nextNode;
            current->nextNode = prev;
            prev = current;
            current = next;
        } while (current != headNode);

        tail->nextNode = prev;  // The new head is now 'prev'
        headNode = prev;
    }

    void sortCLList() {
        if (headNode == nullptr || headNode->nextNode == headNode) {
            cout << "List is empty or has only one node" << endl;
            return;
        }

        Node<T>* current = headNode;
        bool swapped = true;

        do {
            swapped = false;
            Node<T>* temp = current;

            do {
                Node<T>* next = temp->nextNode;
                if (next != headNode && temp->data.propertyName > next->data.propertyName) {
                    // Swap the data of the two nodes
                    T tempData = temp->data;
                    temp->data = next->data;
                    next->data = tempData;
                    swapped = true;
                }
                temp = temp->nextNode;
            } while (temp != headNode);
        } while (swapped);
    }

    void printHeadNode() {
        if (headNode == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        headNode->data.print();
    }
    void printLastNode() {

        if (headNode == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node<T>* temp = headNode;
        // Traverse to the tail (last node)
        while (temp->nextNode != headNode) {
            temp = temp->nextNode;
        }

        temp->data.print();
    }
    void isListEmpty() {
        if (headNode == nullptr) {
            cout << "The list is empty." << endl;
        } else {
            cout << "The list is not empty." << endl;
        }
    }
    void countNodes() {
        if (headNode == nullptr) {
            cout << "Node count: 0" << endl;
            return;
        }

        int count = 0;
        Node<T>* temp = headNode;

        do {
            count++;
            temp = temp->nextNode;
        } while (temp != headNode);

        cout<<count<<endl;
    }

    //Optional Tasks
    // Level2
    //void convertCLList() {
        //cout << "Convert Circular List Unwritten." << endl;
    //} void updateNodeValue() {
        //cout << "update Node value unwritten" << endl;
    //} void displaySpecificColorNode() {
        //cout << "Display Specific color Node" << endl;
    //} void mergeCLList() {
        //cout << "Merge Circular Linked List Unwritten" << endl;
    //}

};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;
    MonopolyBoard property1("Boardwalk", "Blue", 400, 50);
    MonopolyBoard property2("Park Place", "Blue", 350, 35);
    MonopolyBoard property3("Baltic Avenue", "Brown", 60, 4);

    // Insert elements at the end
    list.insertAtHead(property1);

    list.insertAtTail(property3);

    list.insertAtPosition(property2, 1);

    cout << "Monopoly Board List:" << endl;
    list.printList();
    cout<<endl;

    cout<<"Deleting head node"<<endl;
    list.deleteAtHead();
    list.printList();
    cout<<endl;

    cout<<"Deleting tail node"<<endl;
    list.deleteAtTail();
    list.printList();
    cout<<endl;

    cout<<"Deleting at position 1"<<endl;
    list.deleteAtPosition(1);
    list.printList();
    cout<<endl;

    cout<<"Putting everything back"<<endl;
    list.insertAtHead(property1);
    list.insertAtTail(property3);
    list.insertAtPosition(property2, 1);
    cout<<endl;

    //Optional Level 1 Tasks

    cout<<"Reversing list:"<<endl;
    list.reverseCLList();
    list.printList();
    cout<<endl;

    cout<<"Sorting list:"<<endl;
    list.sortCLList();
    list.printList();
    cout<<endl;

    cout<<"Printing head nodes:"<<endl;
    list.printHeadNode();
    cout<<endl;

    cout<<"Printing last node:"<<endl;
    list.printLastNode();
    cout<<endl;

    cout<<"Is list empty?"<<endl;
    list.isListEmpty();
    cout<<endl;

    cout<<"Count nodes: ";
    list.countNodes();

    //Optional Level 2 Tasks
    //list.convertCLList();
    //list.updateNodeValue();
    //list.displaySpecificColorNode();
    //list.mergeCLList();

    return 0;
}