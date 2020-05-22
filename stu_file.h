#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void st_save(){ // saves a saved node as a file by receiving a character input.
	st* p;
	FILE* file;
	char file_name[20];
	p = head->next;

	printf("Enter a file name to save (EX: score.txt) : ");
	scanf("%s",file_name);

	file = fopen(file_name,"w"); // Enter the file name you want to save.

	while(p != tail){ // Search head to tail and save them all.
		fprintf(file,"%d ",p->id);
		fprintf(file,"%s ",p->name);
		fprintf(file,"%s ",p->sex);
		fprintf(file,"%.1f ",p->c);
		fprintf(file,"%.1f ",p->eng);
		fprintf(file,"%.1f ",p->math);
		fprintf(file,"%.1f ",p->total);
		fprintf(file,"%.2f ",p->avg);
		fprintf(file,"%d\n",p->rank);
		p = p->next;
	}
	fclose(file);
}


void st_load(){ // reconstructs a node by loading the file.
	st* p;
	FILE* file;
	char file_name[20];
	
	p = (st*)malloc(sizeof(st));

	printf("Enter a file name to load (EX: score.txt) : ");
	scanf("%s",file_name);
	
	file = fopen(file_name, "r"); // Enter the file name you want to load.
	deleteAll_node(); // Call the deleteAll_node() function to delete all preconfigured nodes
					  // before reconfiguring the nodes.
					  
	while(fscanf(file, "%d%s%s%f%f%f%f%f%d", &p->id,p->name,p->sex,&p->c,&p->eng,&p->math,&p->total,&p->avg,&p->rank) != -1){
		p->next = head->next;
		head->next = p;
		p = (st*)malloc(sizeof(st));
	}
}


void deleteAll_node(){ // delete all previously stored nodes.
	st* p;
	st* q;

	q = head;
	p = q->next;

	while(p !=tail){
		q->next = p->next;
		free(p); // cleared the memory
		p = q->next;
	}
}




