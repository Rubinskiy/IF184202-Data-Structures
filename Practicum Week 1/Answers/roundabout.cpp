#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

// Node structure
struct SListNode 
{
    int data;
    SListNode *next;
}; 

/* Structure of Singly Linked List */
struct SinglyList
{
    SListNode *_head;
    unsigned _size;

    void init() {
        _head = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return (_head == NULL);
    }

    void pushFront(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            
            if (isEmpty()) newNode->next = NULL;
            else newNode->next = _head;
            _head = newNode;
        }
    }

    void pushBack(int value)
    {
        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            _size++;
            newNode->data = value;
            newNode->next = NULL;
            
            if (isEmpty()) 
                _head = newNode;
            else {
                SListNode *temp = _head;
                while (temp->next != NULL) 
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    void popFront()
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            _head = _head->next;
            free(temp);
            _size--;
        }
    }

    void popBack()
    {
        if (!isEmpty()) {
            SListNode *nextNode = _head->next;
            SListNode *currNode = _head;

            if (currNode->next == NULL) {
                free(currNode);
                _head = NULL;
                return;
            }

            while (nextNode->next != NULL) {
                currNode = nextNode;
                nextNode = nextNode->next;
            }
            currNode->next = NULL;
            free(nextNode);
            _size--;
        }
    }

    void insertAt(int index, int value)
    {
        if (isEmpty() || index >= _size) {
            pushBack(value);
            return;
        }
        else if (index == 0) {
            pushFront(value);
            return;
        }

        SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
        if (newNode) {
            SListNode *temp = _head;
            int _i = 0;
            
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void removeAt(int index)
    {
        if (!isEmpty()) {
            
            /* Kasus apabila posisinya melebihi batas */
            if (index >= _size) {
                popBack();
                return;    
            }
            else if (index == 0 || index < 0) {
                popFront();
                return;
            }

            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index-1) {
                temp = temp->next;
                _i++;
            }
            SListNode *nextinto = temp->next->next;
            free(temp->next);
            temp->next = nextinto;
            _size--;
        }
    }

    void remove(int value)
    {
        if (!isEmpty()) {
            SListNode *temp, *prev;
            temp = _head;

            if (temp->data == value) {
                popFront();
                return;
            }
            while (temp != NULL && temp->data != value) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) return;
            prev->next = temp->next;
            free(temp);
            _size--;
        }
    }

    int front() {
        if (!isEmpty()) return _head->data;
        else exit(-1);
    }

    int back() 
    {
        if (!isEmpty()) {
            SListNode *temp = _head;
            while (temp->next != NULL)
                temp = temp->next;
            return temp->data;
        }
        else exit(-1);
    }

    int getAt(int index) {
        if (!isEmpty()) {
            SListNode *temp = _head;
            int _i = 0;
            while (temp->next != NULL && _i < index) {
                temp = temp->next;
                _i++;
            }
            return temp->data;
        }
        else exit(-1);
    }
};

int main(int argc, char const *argv[])
{
    SinglyList list1;
    SinglyList output;
    list1.init();
    output.init();
    int id;

    for (int i = 0; i < 6; i++) {
        cin >> id;
        cin.ignore();
        list1.pushBack(id);
    }

    int command, temp, amount = 0;

    while(true) {
        cin >> command;
        cin.ignore();
        if (command == 1) {
            // add a car to the roundabout
            cin >> id;
            cin.ignore();

            // push the id to the back
            list1.pushBack(id);

            // push the id to the output
            int pos = list1.getAt(2);
            output.pushBack(pos);

            // remove the id from the front
            list1.removeAt(2);

            // increase the amount
            amount++;
        } else if (command == 0) {
            // move the cars counter clockwise
            int temp = list1.front();
            list1.popFront();
            list1.pushBack(temp);
        } else if (command == -1) {
            // stop the program and print output
            if (amount > 0) {
                cout << "Cars left the Roundabout: ";
                for (int i = 0; i < amount; i++) {
                    cout << output.front() << " ";
                    output.popFront();
                }
            } else {
                cout << "No cars left the Roundabout";
            }
            break;
        }
    }

    return 0;
}