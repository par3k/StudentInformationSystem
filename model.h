typedef struct Student{ // Declares a structure for grade management.
	int id;				// It is related to id, name, sex, c, English, math, total score, average, and ranking.
	char name[20];
	char sex[1];
	float c;
	float eng;
	float math;
	float total;
	float avg;
	int rank;
	struct Student *next;
}st;

st* head;
st* tail;

void init(){ // constructs the initial linked list.
	head = (st*)malloc(sizeof(st));
	tail = (st*)malloc(sizeof(st));
	
	head->next = tail;
	tail->next = tail;
}
