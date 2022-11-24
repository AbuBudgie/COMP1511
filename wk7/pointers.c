#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
void initialise_student (struct student *student_ptr, int zid, double wam, char name[MAX_LENGTH])


struct student {
    int zID;
    double wam;
    char name[MAX_LENGTH];
};

int main (void) {

    struct student Yahya;
    Yahya.zID = 5417171;
    Yahya.wam = 50;
    //Yahya.name = "Yahya" (same as strcopy)
    strcpy(Yahya.name, "Yahya");
    
  //  struct student *student_ptr = &Yahya;
 //   (*student_ptr).zID = 5115261;
  //  (*student_ptr).wam = 60;
  //  strcpy((*student_ptr.name, "Yahya")
    
   // initialise_student (&Yahya, 5234325, 60, "Yahya")
     
    printf("%s (z%d) has a wam of %lf\n", Yahya.name, Yahya.zID, Yahya.wam);


    return 0;
    
}

void initialise_student (struct student *student_ptr, int zid, double wam, char name[MAX_LENGTH]) {

    student_ptr->zID = zid;
    student_ptr->wam = wam;
    strcpy(student_ptr->name, name);

}


