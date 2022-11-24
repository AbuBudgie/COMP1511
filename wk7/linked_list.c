// This program introduced the linked list data structure
// We are able to insert at the end of a linked list with 
// create_node function and are able to traverse the list
// with the print function.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next_address; 
    // pointer to a node, called next_address
    // int *number_ptr = pointer to an int
};


int main(void) {

    struct node *head_ptr; 
    
    head_ptr = create_node(1, NULL);
    head_ptr = create_node(3, head_ptr);
    head_ptr = create_node(5, head_ptr);
    return 0;
}

// This function creates a new node
// Output: a pointer to the node that was created
// Input: data and memory address for the node that you want to create
struct node *create_node(int data, struct node *address) {
    // returns a pointer to the memory address it created
    // you give malloc the number of bytes that you want
    
    struct node *new_node = malloc(sizeof(struct node));
    
    // (*new_node).data is the same as new_node->data
    new_node->data = data;
    new_node->next_address = address;
    
    return new_node;
};
