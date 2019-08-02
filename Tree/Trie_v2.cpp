#include <stdio.h>

const int RANGE = 26;
const int MAX = 1000000;
const int BUFSIZE = 31;

int total;

typedef struct NODE {
    struct NODE* child[RANGE];
    int cnt;
} Node;

typedef Node* NodePtr;

Node buffer[BUFSIZE * MAX];
int buf_idx = -1;

int strlen (const char* str) {
    int len = 0;

    while (*(str + len) != '\0') len ++;

    return len;
}

NodePtr create_node () {
    buf_idx ++;

    (buffer + buf_idx)->cnt = 0;

    for (int i = 0; i < RANGE; ++ i) {
        (buffer + buf_idx)->child[i] = 0;
    }

    return (buffer + buf_idx);
}

void insert_word (const NodePtr root, const char* str) {
    int len = strlen(str);
    NodePtr ptr;

    ptr = root;

    for (int i = 0; i < len; ++ i) {
        if (!ptr->child[*(str + i) - 'A']) {
            ptr->child[*(str + i) - 'A'] = create_node();
        }

        ptr = ptr->child[*(str + i) - 'A'];
    }

    ptr->cnt += 1;
    total += 1;
}

int delete_word (NodePtr ptr, const char* str, int idx) {

    if (idx == strlen(str)) {

        for (int i = 0; i < RANGE; ++i) {
            if (ptr->child[i]) {
                return 0;
            }
        } return 1;
    }

    if (ptr->child[*(str + idx) - 'A']) {
        if (delete_word(ptr->child[*(str + idx) - 'A'], str, idx + 1)) {
            //free(current_node)
            ptr->child[*(str + idx) - 'A'] = 0;

            for (int i = 0; i < RANGE; ++i) {
                if (ptr->child[i]) {
                    return 0;
                }
            } return 1;
        }
    }
}

int search (const NodePtr root, const char* str) {
    int len = strlen(str);
    NodePtr ptr;

    ptr = root;

    for (int i = 0; i < len; ++i) {
        if (!ptr->child[*(str + i)]) return 0;
        ptr = ptr->child[*(str + i)];
    } return ptr->cnt;
}

void search_all_words (const NodePtr ptr, char* str, int depth) {

    if (ptr->cnt > 0) {
        printf("%s", str);
    }

    for (int i = 0; i < RANGE; ++i) {
        if (ptr->child[i]) {
            *(str + depth) = (char) i + 'A';

            search_all_words(ptr->child[i], str, depth + 1);
        }
    }
}

int main (int argc, const char* argv[]) {


    return 0;
}