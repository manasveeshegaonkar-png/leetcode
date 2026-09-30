class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* curr = head;

        for (int i = 0; i < index; i++) {
            if (curr == nullptr)
                return -1;

            curr = curr->next;
        }

        if (curr == nullptr)
            return -1;

        return curr->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {   // linked list is empty
            head = newNode;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {         // add at the head/start
            addAtHead(val);
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1; i++) {
            if (curr == nullptr)   // index is invalid
                return;

            curr = curr->next;
        }

        if (curr == nullptr)
            return;

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr)      // empty linked list
            return;

        if (index == 0) {         // delete from the start
            head = head->next;
            return;
        }

        Node* curr = head;

        for (int i = 0; i < index - 1; i++) {
            if (curr->next == nullptr)   // index is invalid
                return;

            curr = curr->next;
        }

        if (curr->next == nullptr)
            return;

        curr->next = curr->next->next;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */