typedef struct STACK {
    struct NODE {
        int val;
        NODE *next;
        NODE() {}
        NODE(int val) : val(val), next(0) {}
    };
    NODE *head;
    int _size;
    
    STACK() {
        head = 0;
        _size = 0;
    }
    
    void push (int val) {
        NODE *temp = new NODE(val);
        
        if (head == 0) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        _size ++;
    }
    
    void pop () {
        NODE *temp = head;
        head = head->next;
        delete temp;
        _size --;
    }
    
    bool is_empty () {
        return _size == 0;
    }
    
    int top () {
        return head->val;
    }
    
    int size () {
        return _size;
    }
} Stack;
