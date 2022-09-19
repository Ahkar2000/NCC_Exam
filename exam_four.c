//created by Ahkar Min Htut
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int id = 0,amount = 0,password = 0,age = 0,choice = 0,n_id = 0,n_amount = 0,n_password = 0,n_age = 0,stop = 1;
char username[30],location[30],searchName[30],n_username[30],n_location[30];
FILE *fptr,*tptr;

void insertData(int id,char username[],int password,int amount,int age,char location[]);
void searchData(char searchName[]);
void viewData();
void editString();

int main(){

int tValue = 1;
int a = 0;

while(tValue == 1){
    puts("Press 1 to insert data, 2 to find data, 3 to update data, 4 to see all datas :");
    printf(">");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            puts("Enter ID,USER NAME,PASSWORD,AMOUNT,AGE,LOCATION.");
            printf(">:");
            scanf("%d%s%d%d%d%s",&id,username,&password,&amount,&age,location);
            insertData(id,username,password,amount,age,location);
            break;
        case 2:
            fptr = fopen("mini_db.txt","r");
            fseek (fptr, 0, SEEK_END);
            if(ftell(fptr) != 0){
                puts("Enter NAME you want to find.");
                scanf("%s",searchName);
                searchData(searchName);
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr);
            break;
        case 3:
            fptr = fopen("mini_db.txt","r");
            fseek (fptr, 0, SEEK_END);
            if(ftell(fptr) != 0){
                editString();
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr);
            break;
        case 4:
            fptr = fopen("mini_db.txt","r");
            fseek (fptr, 0, SEEK_END);
            if(ftell(fptr) != 0){
                viewData();
            }else{
                printf("There is no data yet!\n");
            }
            fclose(fptr);
            break;
        default:
            printf("Please enter valid value!");
    }
}



return 0;
}

void insertData(int id,char username[],int password,int amount,int age,char location[]){
    fptr = fopen("mini_db.txt","a");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    while(!feof(stdin)){
        fprintf(fptr , "%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
        printf(">:");
        scanf("%d%s%d%d%d%s",&id,username,&password,&amount,&age,location);
    }
    fclose(fptr);
}

void searchData(char searchName[]){
    char string[1000];

    fptr = fopen("mini_db.txt","r");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }

    do{
        fscanf(fptr,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location);
        if(strcmp(username,searchName) == 0){
            printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
            break;
        }else{
            printf("NO DATA FOUND!\n");
            break;
        }
    }
    while(!feof(fptr));

    fclose(fptr);
}

void viewData(){
    fptr = fopen("mini_db.txt","r");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    while(fscanf(fptr,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location) == 6){
        printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
    }
    fclose(fptr);
}

void editString(){

	fptr = fopen("mini_db.txt","r");
	tptr = fopen("temp.txt","a");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }

		printf("Enter Name you  want to edit : ");
		scanf("%s",&searchName);
        puts("Enter NEW ID,NEW USER NAME,NEW PASSWORD,NEW AMOUNT,NEW AGE,NEW LOCATION.");
        printf(">:");
        scanf("%d%s%d%d%d%s",&n_id,n_username,&n_password,&n_amount,&n_age,n_location);
		while(!feof(fptr))
		{
		    fscanf(fptr,"%d%10s%10d%10d%10d%15s",&id,username,&password,&amount,&age,location);
		    fprintf(tptr,"%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
			if(strcmp(username,searchName) == 0){
                printf("%d%10s%10d%10d%10d%15s\n",id,username,password,amount,age,location);
				fprintf(tptr,"%d%10s%10d%10d%10d%15s\n",n_id,n_username,n_password,n_amount,n_age,n_location);
			}

        }
        fclose(fptr);
        fclose(tptr);
        remove("mini_db.txt");
        rename("temp.txt","mini_db.txt");
}

