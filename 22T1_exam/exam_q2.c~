#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int compare(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = compare(head1, head2);
    printf("%d\n", result);

    return 0;
}

// compare should return -1 if head1 is a shorter list than head2
// compare should return  1 if head1 is a longer list than head2
// compare should return  0 if head1 is the same length as head2
int compare(struct node *head1, struct node *head2) {
    struct node *current1 = head1; 
    struct node *current2 = head2; 
    int head1_count = 0;
    int head2_count = 0; 
    
    while (current1 != NULL) {
        head1_count++; 
        current1 = current1->next;
    }
    while (current2 != NULL) {
    head2_count++; 
    current2 = current2->next;
    }
        
    if (head1_count > head2_count) {
        return 1;
    } else if (head1_count < head2_count) {
        return -1;
    } else {
        return 0; 
    }
   
}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
