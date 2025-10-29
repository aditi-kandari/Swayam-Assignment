struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int getCount(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}
