/*
	Student Information System
	input, output, delete, search, sort, save / load a file
*/


#include "model.h"
#include "stu_file.h"
#include "stu_service.h"

// model.h
void init();			//The function that constructs the initial linked list.

// stu_service.h
void st_select();		//The function that selects a menu.
void st_insert();		//Function to receive input.
void st_delete();		//Deletion of selected student by name.
void st_find();			//The part where you search for students by name.

void st_print();		//A function that outputs in order of input.
void st_sortPrint();	//A function that outputs by order of grades.

void print_head();		//Function that constructs the upper part of the output
void print_body(st* p);	//A function that outputs students on that node.
void print_tail();		//The function that constructs the lower part of the output.


// stu_file.h 
void st_save();			//A function that saves a saved node as a file by receiving a character input.
void st_load();			//It is a function that reconstructs a node by entering a file.
void deleteAll_node();	//Function required when reconfiguring nodes.


int main(){
	init();
	st_select();
}





