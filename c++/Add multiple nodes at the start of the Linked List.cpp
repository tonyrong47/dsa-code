#include <iostream>
using namespace std;

class Link {
public:
    int data;
    Link* next;

    Link(int num) {
        data = num;
        next = NULL;
    }
};

void insert_head(Link* &head, int data) {
    Link* new_node = new Link(data);
    new_node->next = head;
    head = new_node;
}

void disp(Link* head) {
    Link* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Link* head = NULL;

    insert_head(head, 30);
    disp(head);

    insert_head(head, 32);
    disp(head);

    insert_head(head, 35);
    disp(head);

    return 0;
}