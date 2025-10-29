// Design a linkedlist
//Brute Force (Singly Linked List)
class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    Node* head;
    MyLinkedList() { head = nullptr; }
    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp; i++) temp = temp->next;
        return temp ? temp->val : -1;
    }
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void addAtTail(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
    void addAtIndex(int index, int val) {
        if (index == 0) { addAtHead(val); return; }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; i++) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
    void deleteAtIndex(int index) {
        if (!head) return;
        if (index == 0) { Node* d = head; head = head->next; delete d; return; }
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp; i++) temp = temp->next;
        if (!temp || !temp->next) return;
        Node* d = temp->next;
        temp->next = temp->next->next;
        delete d;
    }
};

//Optimal (Doubly Linked List with Tail + Size)
class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v) : val(v), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() { head = tail = nullptr; size = 0; }
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->val;
    }
    void addAtHead(int val) {
        Node* n = new Node(val);
        if (!head) head = tail = n;
        else { n->next = head; head->prev = n; head = n; }
        size++;
    }
    void addAtTail(int val) {
        Node* n = new Node(val);
        if (!tail) head = tail = n;
        else { tail->next = n; n->prev = tail; tail = n; }
        size++;
    }
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) { addAtHead(val); return; }
        if (index == size) { addAtTail(val); return; }
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) temp = temp->next;
        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
        size++;
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* d = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
            delete d;
            size--;
            return;
        }
        if (index == size - 1) {
            Node* d = tail;
            tail = tail->prev;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete d;
            size--;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }
};