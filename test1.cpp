#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_MEMBER 100

struct member{
	int id;
	char name[30];
	int actPoint;
	int grId;
};

struct member allMembers[MAX_MEMBER];
int memberLength = 0;

int addMember(){
	printf("id: ");
	scanf("%d", &allMembers[memberLength].id);
	fflush(stdin);	
	printf("name: ");
	gets(allMembers[memberLength].name);
	printf("actPoint: ");
	scanf("%d", &allMembers[memberLength].actPoint);
	printf("grId: ");
	scanf("%d", &allMembers[memberLength].grId);
	memberLength++;
	
	printf("Add member done!\n");
}

void showAllMembers(){
	printf("$$$$ All members of VIT $$$$\n");
	for(int i = 0; i < memberLength; i++){
		printf("id: %d\n", allMembers[i].id);
		printf("name: %s\n", allMembers[i].name);
		printf("actPoint: %d\n", allMembers[i].actPoint);
		printf("grId: %d\n", allMembers[i].grId);
	}
}

void readFile(){
	FILE *f;
	
	if((f = fopen("D:\\vit_coder\\allMembers.txt", "r")) == NULL){
		printf("Error opening file!");
		exit(1);
	}
	
	fscanf(f, "So luong thanh vien: %d\n", &memberLength);
	fscanf(f, "==========================\n");
	for(int i = 0; i < memberLength; i++){
		fscanf(f, "id: %d\n", &allMembers[i].id);
		fscanf(f, "name: %[a-zA-Z ]\n", allMembers[i].name);
		fscanf(f, "actPoint: %d\n", &allMembers[i].actPoint);
		fscanf(f, "grId: %d\n", &allMembers[i].grId);
	}
	
	fclose(f);
}

void writeFile(){
	FILE *f;
	
	if((f = fopen("D:\\vit_coder\\allMembers.txt", "w")) == NULL){
		printf("Error opening file!");
		exit(1);
	}
	
	fprintf(f, "So luong thanh vien: %d\n", memberLength);
	fprintf(f, "==========================\n");
	for(int i = 0; i < memberLength; i++){
		fprintf(f, "id: %d\n", allMembers[i].id);
		fprintf(f, "name: %s\n", allMembers[i].name);
		fprintf(f, "actPoint: %d\n", allMembers[i].actPoint);
		fprintf(f, "grId: %d\n", allMembers[i].grId);
	}
	fclose(f);
	printf("Write to file done!\n");
}

int main(){
	readFile();
	
	printf("Press NOT q for start program!\n");
	char c = getch();
	while(c != 'q'){

		int choice;
		printf("Hello!\n");
		printf("1. Add member.\n");
		printf("2. Edit member.\n");
		printf("3. Delete member.\n");
		printf("4. Show members.\n");
		printf("Press 'q' for finish!\n");
		printf("You's choice?\n");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:{
				addMember();
				c = getch();
				continue;
			}
			case 2:{
				addMember();
				c = getch();
				continue;
			}
			case 3:{
				addMember();
				c = getch();
				continue;
			}
			case 4:{
				showAllMembers();
				c = getch();
				continue;
			}
		}
	}
	
	writeFile();
}
