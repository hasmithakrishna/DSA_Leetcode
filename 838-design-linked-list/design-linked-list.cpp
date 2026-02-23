class Node {
public:
    int val;
    Node* next;

    Node() {
        val = 0;
        next = nullptr;
    }
};
class MyLinkedList {
public:
Node *head = NULL;
int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
        
    }
    int get(int index) {
        if(index>=size || index<0) return -1;
        Node *p = head;
        for(int i=0; i<index; i++){
            p = p->next;
        }
        return p->val;   
    }
    
    void addAtHead(int val) {
        Node *t = new Node;
        t->val = val;
        t->next = head;
        head = t;
        size++;
    }
    
    void addAtTail(int val) {
        Node *t = new Node;
        t->val = val;
        t->next = NULL;
        if(head == NULL) head = t;
        else{
            Node *p = head;
            while(p->next){
                p = p->next;
            }
            p->next = t;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node *p = head;
        for(int i=0; i<index-1;i++){
            p = p->next;
        }
        Node *t = new Node;
        t->val = val;
        t->next = p->next;
        p->next = t;   
        size++;     
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        Node *p = head;
        if(index==0){
            Node *del = head;
            head = head->next;
            delete del;
            size--;
            return;
        }
        for(int i=0; i<index-1; i++){
            p = p->next;
            }
            Node *q = p->next;
            p->next = q->next;
            delete q;
            size--;

        
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