#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;


int getValFromNode(Node *n) {
    return n->val;
}

Node *insertNode(int value, Node *head) {
    // create & allocate memory for new node
    Node *newNode = malloc(sizeof(Node));
    Node *current;
    // make the newNode's value = the given val
    newNode->val = value;
    // have the new node's next point to Null since it'll be end of ist
    newNode->next = NULL;

    // check if this is beginning of list. if so, just return this node.
    if (head == NULL) {
        return newNode;
    }
    // otherwise, start at head
    current = head;
    // iterate thru list until you find the next is NULL (last node)
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

Node *deleteNode(int value, Node *head) {

    return head;
}

Node *insertOrderedNode(int value, Node *head) {
    return head;
}

int getMaxVal(Node *n) {
    int currentMax = getValFromNode(n);
    Node *current = n->next;
    while (current != NULL) {
        if (getValFromNode(current) > currentMax) {
            currentMax = getValFromNode(current);
        }
        current = current->next;
    }
    return currentMax;
}

int length(Node *n) {
    int length = 0;
    Node *current = n;
    while (current != NULL) {
        length ++;
        current = current->next;
    }
    return length;
}

int firstVal(Node *n) {
    return getValFromNode(n);
}

int lastVal(Node *n) {
    Node *current = n;
    while (current->next != NULL) {
        current = current->next;
    }
    return getValFromNode(current);
}

int main(int argc, char *argv[]) {
    Node *head1, *head2, *head3;
    int passed = 1;

    head1 = insertNode(5, head1);
    head1 = insertNode(7, head1);
    head1 = insertNode(1, head1);
    printf("Length: %d\n", length(head1));
    if(length(head1) != 3) {
        passed = 0;
    }
    printf("firstVal: %d\n", firstVal(head1));
    if(firstVal(head1) != 5) {
        passed = 0;
    }
    printf("lastVal: %d\n", lastVal(head1));
    if(lastVal(head1) != 1) {
        passed = 0;
    }
    printf("MaxVal: %d\n", getMaxVal(head1));
    if(getMaxVal(head1) != 7) {
        passed = 0;
    }
    head1 = deleteNode(7, head1);
    if(firstVal(head1) != 5) {
        passed = 0;
    }
    if(lastVal(head1) != 1) {
        passed = 0;
    }
    if(getMaxVal(head1) != 5) {
        passed = 0;
    }
    if (passed == 1) {
        printf("You passed the first test (basic ops)!");
    }
    passed = 1;

    head1 = insertOrderedNode(5, head1);
    head1 = insertOrderedNode(7, head1);
    head1 = insertOrderedNode(1, head1);
    if(length(head1) != 3) {
        passed = 0;
    }
    if(firstVal(head1) != 1) {
        passed = 0;
    }
    if(lastVal(head1) != 7) {
        passed = 0;
    }
    if(getMaxVal(head1) != 7) {
        passed = 0;
    }
    head1 = deleteNode(7, head1);
    if(firstVal(head1) != 1) {
        passed = 0;
    }
    if(lastVal(head1) != 5) {
        passed = 0;
    }
    if(getMaxVal(head1) != 5) {
        passed = 0;
    }
    if (passed == 1) {
        printf("You passed the second test (ordered ops)!");
    }

    return 0;
}
