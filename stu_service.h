#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void st_select(){
	int choice;

	do{ // show the menu and wait for user's selection.
		printf("   ********          *********      ***********      *****     ****\n");
		printf("   ***   ****        *********      ***********      *****     ****\n");
		printf("   ***   *****            ****         ****          *****     ****\n");
		printf("   ***   ****             ****         ****          *****     ****\n");	
		printf("   *********              ****         ****          *****     ****\n");	
		printf("   ***   ****             ****         ****          *****     ****\n");	
		printf("   ***   *****    ****    ****         ****          *****     ****\n");	
		printf("   ***   ****      **********          ****           ****** *****\n");	
		printf("   ********         ********           ****             *********\n");
		printf("\n                       C - Programing Course\n");
		printf("\n                     Student Information System\n");	
		printf("\n                        18309002 Park Hoijai\n");	
		printf("\n                         ===== M E N U =====\n");
		printf("                          1. Input the info\n");
		printf("                          2. Delete the info\n");
		printf("                          3. Search by Name\n");
		printf("                          4. Save the table\n");
		printf("                          5. Load the file\n");
		printf("                          8. Sort by Score\n");
		printf("                          9. Print the table\n");
		printf("                          0. Exit\n");
		printf("                         ===================\n");
		printf("\nSelect > [    ]\b\b\b");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				st_insert();
				break;
			case 2:
				st_delete();
				break;
			case 3:
				st_find();
				break;
			case 4:
				st_save();
				break;
			case 5:
				st_load();
				break;
			case 8:
				st_sortPrint();
				break;
			case 9:
				st_print();
				break;
			case 0:
				printf(" \nTerminate the system!!\n");
		}
		system("pause");
		system("cls");
	}while(choice != 0); // If no 0 is selected, show the menu through continuous repetition.
}


void st_insert(){ // The part where student information is entered and stored on the node.
	st* p;
	st* q;

	q = head->next;
	p = (st*)malloc(sizeof(st)); // make a memory space
	
	printf("ID : ");
	scanf("%d",&p->id);
	printf("Name : ");
	scanf("%s",p->name);
	printf("Sex [M/F] : ");
	scanf("%s",p->sex);
	printf("C Score : ");
	scanf("%f",&p->c);
	printf("English Score : ");
	scanf("%f",&p->eng);
	printf("Math Score : ");
	scanf("%f",&p->math);

	p->total = p->c + p->eng + p->math;
	p->avg = p->total / 3.0f; // Receive inputs to calculate the total score and average
	p->rank = 1; // set the rank value is '1'
	
	while(q != tail){ // Calculate the ranking.
		if(p->total > q->total){
			q->rank = q->rank+1;
		}else{
			p->rank = p->rank +1;
		}
		q = q->next;
	}

	/*
		Rebuilds the ranking by comparing the total points of the new node
		entered with the total points on the existing node.
	*/
	
	p->next = head->next; // Connects the entered node.
	head->next = p; // add the new node next to the head.
}


void st_delete(){
	st* p;
	st* q; // it is a single linked list, two nodes are required for deletion.
	char find_name[20];

	q = head; //ex. st[0]
	p = q->next; // st[1]
	
	printf("Enter a name to delete : ");
	scanf("%s",find_name); // Enter the student name want to delete.


	while(p != tail){ // Verify that the student name entered exists in the name of the students structure.
		if(strcmp(find_name, p->name) == 0){ 
			break; // If the structure has a name, stop searching.
		}else{
			q=q->next; // st[1]
			p=q->next; // Continue the search to the Tale. st[2]** 
		}
	}

	if(p == tail){
		printf("The name %s you entered does not exist.\n",find_name);
		// Indicates that the user has searched all of the input values to the tale of the structure,
		// but it is not there.
	}else{
		printf("The entered name %s has been deleted.\n",find_name);
		q->next = p->next; //st[2] 자리에 st[3] 이 오면서
		free(p); // 기존에 있던 st[2]**가 제거 된다. 
	}
}


void st_find(){
	char find_name[20];
	st* p; 
	p = head->next;

	printf("Student Search : ");
	scanf("%s",find_name); // Enter the student name want to search.

	while(p != tail){
		if(strcmp(p->name, find_name) == 0){
			break; // If found a name, 'p' will be pointing to that node.
		}else{
			p = p->next; // or not, move to next node
		}
	}

	if(p == tail){
		printf("No student \" %s \" was searched.\n",find_name);
	}else{

		print_head();
		print_body(p); // Prints student node with names.
		print_tail();
	}
}


void st_print(){
	st* p;
	p = head->next;

	if(p == tail){
		printf("No students are registered.\n");
		return;
	}
	
	print_head();
	
	while(p != tail){
		print_body(p);
		p = p->next;
	}
	print_tail();
}


void st_sortPrint(){ // 이해가 안된다 
	//순위에 따른 출력 부분입니다.
	//노드를 재구성한것이 아니라 순위와 동일한 변수를 출력하게 만들었습니다.

	st* p;
	st* q;
	int count = 1;

	p = head->next;
	q = head->next;
	
	print_head();
	
	while(q !=tail){
		while(p != tail){
			if(p->rank == count){
				print_body(p);
				p = head->next;
				count++;
				break;
			}else{
				p = p->next;
			}
		}
		q = q->next;
	}
	//위와 같이 1씩 증가되는 변수를 하나두어
	//count와 rank가 같은 노드를 출력합니다.
	print_tail();
}


void print_head(){ // This is the top part of the table when printing.
	printf("\n=============================================================================\n");
	printf("ID\t\tName\tSex\tC\tEng\tMath\tTotal\tAVG\tRank\n");
	printf("\n=============================================================================\n");
}


void print_body(st* p){ // outputs information for that node.
	printf("%d\t",p->id);
	printf("%s\t",p->name);
	printf("%s\t",p->sex);
	printf("%.1f\t",p->c);
	printf("%.1f\t",p->eng);
	printf("%.1f\t",p->math);
	printf("%.1f\t",p->total);
	printf("%.2f\t",p->avg);
	printf("%d\n",p->rank);
}


void print_tail(){ // This is the bottom part of the table when printing.
	printf("=============================================================================\n");
}
