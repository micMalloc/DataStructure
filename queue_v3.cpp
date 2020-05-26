typedef struct QUEUE {
    struct NODE {
        int val;
        NODE *next;
        NODE() {}
        NODE(int val) : val(val), next(0) {}
    };
    
    NODE *head, *back;
    int _size;
    
    QUEUE() {
        head = back = 0;
        _size = 0;
    }
    
    void push (int val) {
        NODE *temp = new NODE(val);
        
        if (head == 0) {
            back = head = temp;
        }
        else {
            back->next = temp;
            back = temp;
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
    
    int front () {
        return head->val;
    }
    
    int size () {
        return _size;
    }
    
} Queue;
