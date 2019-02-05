
#define MAX_ELEMENTS 2001

typedef struct ELEMENT {
    int key;
} Element;

typedef struct HEAP {
    Element heap[MAX_ELEMENTS];
    int heap_size;
} Heap;

typedef struct PRIORITY_QUEUE {
    Heap heap;
} priority_queue;

void insert_element_into_heap (Heap* h, Element item) {
    int i;

    i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

Element delete_element_from_heap (Heap *h) {
    int parent, child;
    Element item, tmp;

    item = h->heap[1];
    tmp = h->heap[(h->heap_size) --];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
            child ++;
        }

        if (tmp.key <= h->heap[child].key) {
            break;
        }

        h->heap[parent] = h->heap[child];

        parent = child;
        child *= 2;
    }

    h->heap[parent] = tmp;

    return item;
}
