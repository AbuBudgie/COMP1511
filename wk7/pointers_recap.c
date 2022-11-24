// Pointers recap 
// declaring, intialising and dereferencing a pointer.


#include <stdio.h>

int main (void) {

    // 1. create a variable which stores a random variable
    int num = 21;
    

    // 2. create a pointer to the variable which stores the address of num.
    int *pointer = &num; 
    
    // pointer with no value 
    // int *pointer = NULL;
    
    // print the address of num
    printf("The address of num is %p\n", &num);
    printf("The address of num is %p\n", pointer);
    
    //the address of pointer
    printf("The address of pointer is %p\n", &pointer);
    
    // dereferencing the pointer
    printf("the value of num is %d\n", *pointer);
    printf("the value of num is %d\n", num); 


    return 0; 
}







