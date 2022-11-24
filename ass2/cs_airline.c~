// CS Airline
// cs_airline.c
//
// This program was written by Yahya Al-Faraj (z5417171)
// on 04/04/2022
//
// Version 1.0.0 2022-04-02: Initial Release.
//
// Description of your program.
// This program will simulate a flight path from an origin airport to the 
// destination airport with multiple functions and commands. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////  CONSTANTS  /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// The buffer length is used for reading a single line
#define MAX_STRING_LEN 100
#define COMMAND_PRINT_HELP "help"
#define COMMAND_PRINT_ROUTE "print"
#define COMMAND_SUBROUTE "subroute"
#define COMMAND_CHANGE_ORIGIN "change_origin"
#define COMMAND_BYPASS "bypass"
#define COMMAND_EMERGENCY "emergency"
#define COMMAND_CANCEL "cancel"
#define COMMAND_REVERSE "reverse"
#define COMMAND_ADD_PERSON "add_person"
#define COMMAND_PRINT_MANIFEST "print_manifest"
#define COMMAND_FLIGHT_STATS "stats"
// TODO: you may choose to add additional #defines here.

#define EMERGENCY_CODE "ALT0"
#define EMERGENCY_DEPARTURE_TIME 0000
#define SAME 0 
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////  STRUCTS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Airports represent 'stops' along the flight path
// These are the 'nodes' of the linked list
struct airport {
	char code[MAX_STRING_LEN];
	int arrival_time;
	int departure_time;
	struct airport *next_airport;
}
;
// Root flight structure
// This stores the state of the current flight
// (i.e. the head and tail of the linked list)
struct flight {
	struct airport *origin_airport;
	struct airport *dest_airport;
}
;
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  FUNCTION PROTOTYPES  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Helper Functions
void remove_newline(char input[MAX_STRING_LEN]);
void do_print_help(void);
void interpret_line(
    char buffer[MAX_STRING_LEN],
    int *val0,
    int *val1,
    char word[MAX_STRING_LEN]
);
// Stage 1 Functions
struct flight *setup_flight(void);
void do_print_airports(struct flight *flight);
void print_one_airport(struct airport *ap);
struct airport *create_airport(
    char code[MAX_STRING_LEN],
    int arrival_time,
    int departure
);
// Stage 2 Functions
void do_subroute(struct flight *flight);
void do_change_origin(struct flight *flight);
// Your functions prototypes here
void bypass_airport(struct flight *flight);
void emergency(struct flight *flight);
void free_list(struct flight *flight);
void free_airports(struct airport *head);
////////////////////////////////////////////////////////////////////////////////
//////////////////////////  FUNCTION IMPLEMENTATIONS  //////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main(void) {
	// Stage 1.1
	// Complete the setup_flight function below
	struct flight *flight = setup_flight();
	// Fill out the while loop with relevant commands & functions
	// Move into and stay in operational mode until CTRL+D
	printf("Enter Command: ");
	char command_line[MAX_STRING_LEN];
	while (fgets(command_line, MAX_STRING_LEN, stdin) != NULL) {
		remove_newline(command_line);
		if (strcmp(COMMAND_PRINT_HELP, command_line) == SAME) {
			// A help command we have implemented for you.
			do_print_help();
		} else if (strcmp(COMMAND_PRINT_ROUTE, command_line) == SAME) {
			// Stage 1.2 - Complete this function below
			do_print_airports(flight);
		} else if (strcmp(COMMAND_SUBROUTE, command_line) == SAME) {
			// Stage 2.1 - Complete this function below
			do_subroute(flight);
		} else if (strcmp(COMMAND_CHANGE_ORIGIN, command_line) == SAME) {
			// Stage 2.2 - Complete this function below
			do_change_origin(flight);
		} else if (strcmp(COMMAND_BYPASS, command_line) == SAME) {
			// Stage 2.3 - Complete this function below 
			bypass_airport(flight);
		} else if (strcmp(COMMAND_EMERGENCY, command_line) == SAME) {
			// Stage 3.1 - Complete this function below 
			emergency(flight);
		} else if (strcmp(COMMAND_CANCEL, command_line) == SAME) {
		    // Stage 3.2 - TODO
		    free_list(flight);
		}
		// TODO: Add more conditions here for the remaining commands
		printf("Enter Command: ");
	}
	printf("Goodbye!\n");
	return 0;
}
// Stage 1.1
// Creates and initialises a flight by asking the user for input.
// Parameters:
//     None
// Returns:
//     Pointer to the malloc'd flight
struct flight *setup_flight(void) {
	// Create a new, empty flight
	struct flight *new_flight = malloc(sizeof(struct flight));
	new_flight->origin_airport = NULL;
	new_flight->dest_airport = NULL;
	// Read number of stops using fgets
	printf("How many stops will be enroute? ");
	char input_line[MAX_STRING_LEN] = {0};
	fgets(input_line, MAX_STRING_LEN, stdin);
	// Convert the string to a number
	int num_stops = 0;
	num_stops = atoi(input_line);
	// For each airport Use fgets to read a line and then use the
	//       provided interpret_line() function to extract information
	// the from line 155 to 163 this code will run according to n airports
	//reading in entire line (need while loop to scan multiple ports)
	char buffer[MAX_STRING_LEN];
	int arrival_time = 0;
	int departure_time = 0;
	char airport_code[MAX_STRING_LEN];
	int i = 0;
	while (i < num_stops) {
		fgets(buffer, MAX_STRING_LEN, stdin);
		interpret_line(buffer, &arrival_time, &departure_time, airport_code);
		if (departure_time < arrival_time) {
			printf("Departure time cannot be before the arrival time!\n");
		} else if (new_flight->dest_airport != NULL && new_flight->dest_airport->departure_time > arrival_time) {
			printf("New arrival time cannot be before the previous departure time\n");
		} else {
			struct airport *new_airport = create_airport(airport_code, arrival_time,
			            departure_time);
			if (new_flight->origin_airport == NULL) {
				new_flight->origin_airport = new_airport;
			} else {
				//setting the previous next airports to be new airport
				new_flight->dest_airport->next_airport = new_airport;
			}
			new_flight->dest_airport = new_airport;
		}
		i++;
	}
	return new_flight;
}
// Stage 1.2
// Given a pointer to a flight struct, prints all the info about the route
// Parameters:
//     flight = the flight which contains the flight route to print
// Returns:
//     None
void do_print_airports(struct flight *flight) {
	//call print one airport in while loop 
	struct airport *current = flight->origin_airport;
	printf("ROUTE:\n");
	while (current != NULL) {
		print_one_airport(current);
		current = current->next_airport;
	}
}
// Stage 1.2
// PROVIDED FUNCTION - DO NOT CHANGE
// Given a pointer to an airport struct,
// prints all the info about the airport
// Parameters:
//     ap = the airport to print
// Returns:
//     None
void print_one_airport(struct airport *ap) {
	printf(
	        "%8s:    %04d -> %04d\n",
	       ap->code,
	       ap->arrival_time,
	       ap->departure_time
	    );
}
// Stage 1.1
// Given the information about a new airport,
// Uses `malloc` to create memory for it and returns a pointer to
// that memory.
// Parameters:
//     code            = the airport ICAO code
//     arrival_time    = the arrival time of the new airport
//     departure_time  = the departure time of the new airport
// Returns:
//     A pointer to the malloc'd struct airport
struct airport *create_airport(
    char code[MAX_STRING_LEN],
    int arrival_time,
    int departure_time) {
	// Malloc new struct
	struct airport *new_airport = malloc(sizeof(struct airport));
	// initialise airport fields
	strcpy(new_airport->code, code);
	new_airport->arrival_time = arrival_time;
	new_airport->departure_time = departure_time;
	new_airport->next_airport = NULL;
	return new_airport;
}

// Stage 2.1
// reads an airport code and calculates the hours and minutes between the origin
// 's departure time and the given airport's arrival time 
void do_subroute(struct flight *flight) {
	struct airport *current = flight->origin_airport;
	char airport_code[MAX_STRING_LEN];
	// start = origin airport's departure_time
	int start = flight->origin_airport->departure_time;
	// end = given airport's arrival time
	int end = 0;
	int does_exist = 0;
	printf("Enter airport code: ");
	fgets(airport_code, MAX_STRING_LEN, stdin);
	remove_newline(airport_code);
	while (current != NULL) {
		if (strcmp(current->code, airport_code) == 0) {
			end = current->arrival_time;
			does_exist = 1;
		}
		current = current->next_airport;
	}
	//calculating the time difference and converting into hours and mins
	int hours = (end / 100) - (start / 100);
	int mins = (end % 100) - (start % 100);
	int minute_diff = hours * 60 + mins;
	if (minute_diff < 0) {
		minute_diff *= -1;
	}
	hours = minute_diff / 60;
	mins = minute_diff % 60;
	if (does_exist == 1) {
		printf("Time for subroute: %d hrs & %d mins \n", hours, mins);
	} else {
		printf("Desired subroute destination does not exist!\n");
	}
}
// Stage 2.2
// inserts a new origin into the flight list 
void do_change_origin(struct flight *flight) {
	int new_arrival;
	int new_departure;
	char new_origin_code[MAX_STRING_LEN];
	char buffer[MAX_STRING_LEN];
	struct airport *head = flight->origin_airport;
	struct airport *current = head;
	printf("Enter new origin info: ");
	fgets(buffer, MAX_STRING_LEN, stdin);
	interpret_line(buffer, &new_arrival, &new_departure, new_origin_code);
	//error checking using an error counter
	int error = 0;
	// checking for code uniqueness
	int code_compare = 0;
	while (current != NULL) {
		if (strcmp(current->code, new_origin_code) == 0) {
			code_compare++;
			error++;
		}
		current = current->next_airport;
	}
	if (new_arrival > new_departure) {
		printf("Departure time cannot be before arrival time\n");
		error++;
	} else if (new_departure > head->arrival_time) {
		printf("Departure of new origin cannot be after the arrival time of the next airport!\n");
		error++;
	} else if (code_compare > 0) {
		printf("New airport code is not unique!\n");
		// if the code is unique and no errors then create new_origin
	} else if (code_compare == 0 && error == 0) {
		struct airport *new_origin = create_airport(new_origin_code, new_arrival, new_departure);
		flight->origin_airport = new_origin;
		flight->origin_airport->next_airport = head;
		printf("Added: %s\n", new_origin_code);
	}
	return;
}
// Stage 2.3 
// Reads in the code of the airport given by user and removes it from flight 
// route. 
void bypass_airport(struct flight *flight) {
	struct airport *head = flight->origin_airport;
	struct airport *current = head;
	struct airport *value_check = head;
	char value[MAX_STRING_LEN];
	int there_is_value = 0;
	printf("Enter airport code: ");
	fgets(value, MAX_STRING_LEN, stdin);
	remove_newline(value);
	// records if desired code is present in the flight
	while (value_check != NULL) {
		if (strcmp(value, value_check->code) == 0) {
			there_is_value++;
		}
		value_check = value_check->next_airport;
	}
	// checks if list not empty and value is present
	if (current != NULL && there_is_value > 0) {
		// if next airport is not NULL
		if (current->next_airport != NULL) {
			// finds the code to be deleted 
			while (strcmp(value, current->code) != 0) {
				current = current->next_airport;
			}
			if (current == head) {
				head = current->next_airport;
				free(current);
			} else {
				// reassigns previous airport to current->next airport
				struct airport *previous = head;
				while (previous->next_airport != current) {
					previous = previous->next_airport;
				}
				previous->next_airport = current->next_airport;
				free(current);
			}
		} else {
			//if one node is in the list        
			free(current);
			flight->origin_airport = NULL;
		}
	} else if (there_is_value == 0) {
		// if no value is found inside the list
		printf("No airport of that code exists!\n");
		flight = NULL;
	} else {
		//if list is empty 
		flight->origin_airport = NULL;
	}
	return;
}
// Stage 3.1 
// Reads in time of emergency from user and implements an emergency landing
// at a new airport after the specified period of time. 
void emergency(struct flight *flight) {
	struct airport *head = flight->origin_airport;
	struct airport *destination = flight->dest_airport;
	struct airport *current = head;
	printf("How long until emergency: ");
	char input[MAX_STRING_LEN];
	fgets(input, MAX_STRING_LEN, stdin);
	int hours = 0;
	hours = atoi(input);
	int emergency_time = current->departure_time + (hours * 100);
	
	if (hours == 0) {
		current = current->next_airport;
		free_airports(current);
		head->next_airport = NULL;
		head->departure_time = EMERGENCY_DEPARTURE_TIME;
	} else if (emergency_time > destination->arrival_time) {
		printf("Flight was safe!\n");
	} else {
		struct airport *prev = head;
		while (head != NULL) {
			if (current->arrival_time > emergency_time) {
				// creating an airport emergency landing
				struct airport *emergency = malloc(sizeof(struct airport));
				emergency->arrival_time = emergency_time;
				emergency->departure_time = EMERGENCY_DEPARTURE_TIME;
				strcpy(emergency->code, EMERGENCY_CODE);
				emergency->next_airport = NULL;
				// linking it in and deleting other airports
				prev->next_airport = emergency;
				flight->dest_airport = emergency;
				free_airports(head);
				head = NULL;
			} else {
				head = head->next_airport;
				current = head;
				if (head->arrival_time < emergency_time) {
					prev = head;
				}
			}
		}
	}
	return;
}
void free_airports(struct airport *head) {
	struct airport *current = head;
	while (head != NULL) {
		current = head;
		head = head->next_airport;
		free(current);
	}
}
void free_list(struct flight *flight) {
	struct airport *head = flight->origin_airport;
	free_airports(head);
	free(flight);
	printf("Flight cancelled. Now accepting a new flight:\n");
    setup_flight();
}
////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  HELPER FUNCTIONS  //////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Helper Function
// You likely do not need to change this function.
//
// Given a raw string will remove and first newline it sees.
// The newline character wil be replaced with a null terminator ('\0')
// Parameters:
//     flight  = the flight to move people along of
// Returns:
//     None
void remove_newline(char input[MAX_STRING_LEN]) {
	// Find the newline or end of string
	int index = 0;
	while (input[index] != '\n' && input[index] != '\0') {
		index++;
	}
	// Goto the last position in the array and replace with '\0'
	// Note: will have no effect if already at null terminator
	input[index] = '\0';
}
// Helper Function
// You DO NOT NEED TO UNDERSTAND THIS FUNCTION, and will not need to change it.
//
// Given a raw string in the following foramt: [integer0] [integer1] [string]
// This function will extract the relevant values into the given pointer variables.
// The function will also remove any newline characters.
//
// For example, if given: "0135 0545 YSSY"
// The function will put the integer values
//     135 into the val1 pointer
//     545 into the val2 pointer
// And will copy a null terminated string
//     "YSSY" into the 'word' array
//
// If you are interested, `strtok` is a function which takes a string,
// and splits it up into before and after a "token" (the second argument)
//
// Parameters:
//     buffer  = A null terminated string in the following format
//               [integer0] [integer1] [string]
//     val0    = A pointer to where [integer0] should be stored
//     val1    = A pointer to where [integer1] should be stored
//     word    = An array for the [string] to be copied into
// Returns:
//     None
void interpret_line(
    char buffer[MAX_STRING_LEN],
    int *val0,
    int *val1,
    char word[MAX_STRING_LEN]
) {
	// Remove extra newline
	remove_newline(buffer);
	// Extract value 1 as int
	char *val0_str = strtok(buffer, " ");
	if (val0_str != NULL) {
		*val0 = atoi(val0_str);
	} else {
		*val0 = -1;
	}
	// Extract value 2 as int
	char *val1_str = strtok(NULL, " ");
	if (val1_str != NULL) {
		*val1 = atoi(val1_str);
	} else {
		*val1 = -1;
	}
	char *word_str = strtok(NULL, " ");
	if (word_str != NULL) {
		// Extract word
		strcpy(word, word_str);
	}
	if (val0_str == NULL || val1_str == NULL || word_str == NULL) {
		// If any of these are null, there were not enough words.
		printf("Could not properly interpret line: %s.\n", buffer);
	}
}
void do_print_help(void) {
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| Command Name      | How to Use                                                             |\n");
	printf("+===================+========================================================================+\n");
	printf("| PRINT ROUTE       | Enter command: print                                                   |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| SUBROUTE          | Enter command: subroute                                                |\n");
	printf("|                   | Enter airport code: [AIRPORT CODE]                                     |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| CHANGE ORIGIN     | Enter command: change_origin                                           |\n");
	printf("|                   | Enter new origin info: [ARRIVAL TIME] [DEPARTURE TIME] [AIRPORT CODE]  |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| BYPASS            | Enter command: bypass                                                  |\n");
	printf("|                   | Enter airport code: [AIRPORT CODE]                                     |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| EMERGENCY         | Enter command: emergency                                               |\n");
	printf("|                   | How long until emergency: [TIME IN HOURS]                              |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| CANCEL            | Enter command: cancel                                                  |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| REVERSE           | Enter command: reverse                                                 |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("|                   | Enter command: add_person                                              |\n");
	printf("| ADD PERSON        | Enter the airport code: [AIRPORT CODE]                                 |\n");
	printf("|                   | Enter the passenger name: [NAME]                                       |\n");
	printf("|                   | Enter the passenger weight: [WEIGHT]                                   |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| PRINT MANIFEST    | Enter command: print_manifest                                          |\n");
	printf("|                   | Enter the airport code: [AIRPORT CODE]                                 |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
	printf("| FLIGHT STATISTICS | Enter command: stats                                                   |\n");
	printf("+-------------------+------------------------------------------------------------------------+\n");
}
