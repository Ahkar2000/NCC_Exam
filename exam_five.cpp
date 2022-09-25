#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define MAX 20
int pass = 0;
char loc[MAX];

class Storage{
public:
    Storage(){
        FILE *fptr;
        fptr = fopen("store.txt","r");
        if(fptr == NULL){
            printf("File Cannot Open!");
            exit(1);
        }
        while(1){
            fscanf(fptr,"%d%10s%10d%10d%10d%10s",&id,name,&pass,&amount,&age,loc);
            if(feof(fptr)){
                break;
            }
        }
        if(id == 0){
            cout<<"There is no data yet."<<endl;
        }
        fclose(fptr);
    }
    char name[MAX];
    int id = 0;
    int amount = 0;
    int age = 0;
    void setPassword(int p){
        password = p;
    }
    int getPassword(){
        return password;
    }
    void setLocation(char l[MAX]){
        strcpy(location,l);
    }
    char *getLocation(){
        return location;
    }
private:
    int password = 0;
    char location[MAX];
};

void insertData(Storage newObj);
void view(Storage newObj);
void searchData(Storage newObj);
void deleteLine(Storage newObj,int line);
void edit(Storage newObj,int line);

int main(){
    int option = 0;
    Storage newObj;
    int trueValue = 0;

        cout<<"Please select option."<<endl;
        cout<<"Press 1 to insert data."<<endl;
        cout<<"Press 2 to search data."<<endl;
        cout<<"Press 3 to view all datas."<<endl;
        cout<<"Press 4 to delete."<<endl;
        cout<<"Press 5 to edit."<<endl;
        cout<<"> ";
        cin>>option;

        switch(option){
            case 1:
                insertData(newObj);
                break;
            case 2:
                searchData(newObj);
                break;
            case 3:
                view(newObj);
                break;
            case 4:
                int l;
                view(newObj);
                FILE *fptr;
                if(fptr == NULL){
                    printf("File Cannot Open!");
                    exit(1);
                }
                fptr = fopen("store.txt","r");
                while(!feof(fptr)){
                    fscanf(fptr,"%d%10s%10d%10d%10d%10s",&newObj.id,newObj.name,&pass,&newObj.amount,&newObj.age,loc);
                 }
                 if(newObj.id != 0){
                    fclose(fptr);
                    cout<<"Enter line number you want to delete : ";
                    cin>>l;
                    deleteLine(newObj,l);
                 }
                break;
            case 5:
                view(newObj);
                if(fptr == NULL){
                    printf("File Cannot Open!");
                    exit(1);
                }
                fptr = fopen("store.txt","r");
                while(!feof(fptr)){
                    fscanf(fptr,"%d%10s%10d%10d%10d%10s",&newObj.id,newObj.name,&pass,&newObj.amount,&newObj.age,loc);
                 }
                 if(newObj.id != 0){
                    fclose(fptr);
                    cout<<"Enter line number you want to edit : ";
                    cin>>l;
                    edit(newObj,l);
                 }
                break;
            default:
                cout<<"Please enter valid value."<<endl;
        }

return 0;
}
 void insertData(Storage newObj){
    FILE *fptr;
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    fptr = fopen("store.txt","r");
    while(!feof(fptr)){
        fscanf(fptr,"%d%10s%10d%10d%10d%10s",&newObj.id,newObj.name,&pass,&newObj.amount,&newObj.age,loc);
     }
     if(newObj.id != 0){
        cout<<"Previous id is "<<newObj.id<<",so please insert id starting from "<<newObj.id+1<<endl;
     }
    fclose(fptr);
    fptr = fopen("store.txt","a");
    cout<<"Enter id : ";
    cin>>newObj.id;
    cout<<"Enter name : ";
    cin>>newObj.name;
    cout<<"Enter password : ";
    cin>>pass;
    newObj.setPassword(pass);
    cout<<"Enter amount : ";
    cin>>newObj.amount;
    cout<<"Enter age : ";
    cin>>newObj.age;
    cout<<"Enter location : ";
    cin>>loc;
    newObj.setLocation(loc);

    while(!feof(stdin)){
        fprintf(fptr , "%d%10s%10d%10d%10d%10s\n",newObj.id,newObj.name,newObj.getPassword(),newObj.amount,newObj.age,newObj.getLocation());
        cout<<"Enter id : ";
        cin>>newObj.id;
        cout<<"Enter name : ";
        cin>>newObj.name;
        cout<<"Enter password : ";
        cin>>pass;
        newObj.setPassword(pass);
        cout<<"Enter amount : ";
        cin>>newObj.amount;
        cout<<"Enter age : ";
        cin>>newObj.age;
        cout<<"Enter location : ";
        cin>>loc;
        newObj.setLocation(loc);
    }
    fclose(fptr);
 }

 void searchData(Storage newObj){
    char sName[MAX];
    FILE *fptr;
    fptr = fopen("store.txt","r");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    cout<<"Enter name you want to search : ";
    cin>>sName;
    do{
        fscanf(fptr,"%d%10s%10d%10d%10d%10s",&newObj.id,newObj.name,&pass,&newObj.amount,&newObj.age,loc);
        if(newObj.id == 0){
            cout<<"There is no record."<<endl;
        }else{
            if(strcmp(newObj.name,sName) == 0){
            printf("%d%10s%10d%10d%10d%10s\n",newObj.id,newObj.name,pass,newObj.amount,newObj.age,loc);
            break;
        }
        }
    }
    while(!feof(fptr));

    fclose(fptr);
 }

 void view(Storage newObj){
    FILE *fptr;
    fptr = fopen("store.txt","r");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    cout<<"Data are : "<<endl;
    while(!feof(fptr)){
        fscanf(fptr,"%d%10s%10d%10d%10d%10s",&newObj.id,newObj.name,&pass,&newObj.amount,&newObj.age,loc);
        newObj.setLocation(loc);
        newObj.setPassword(pass);
        if(newObj.id == 0){
            cout<<"There is no record."<<endl;
        }else{
            if(feof(fptr)){
                break;
            }
            printf("%d%10s%10d%10d%10d%10s\n",newObj.id,newObj.name,newObj.getPassword(),newObj.amount,newObj.age,newObj.getLocation());
        }
    }
    fclose(fptr);
 }
void deleteLine(Storage newObj,int line){
    FILE *fptr;
    FILE *tptr;
    fptr = fopen("store.txt","r");
    tptr = fopen("temp.txt","w");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }
    int count = 1;
    char moveData[1000];
    while ((fgets(moveData, sizeof(moveData), fptr)) != NULL){
      if (line != count){
         fputs(moveData, tptr);
      }
      count++;
   }
   fclose(fptr);
   fclose(tptr);
   remove("store.txt");
   rename("temp.txt", "store.txt");
   cout<<"Data is deleted successfully."<<endl;
   view(newObj);
}

void edit(Storage newObj,int line){
    FILE *fptr;
    FILE *tptr;
    char moveData[1000];
    int count = 1;

    fptr = fopen("store.txt","r");
    tptr = fopen("temp.txt","w");
    if(fptr == NULL){
        printf("File Cannot Open!");
        exit(1);
    }

    cout<<"Enter new id : ";
    cin>>newObj.id;
    cout<<"Enter new name : ";
    cin>>newObj.name;
    cout<<"Enter new password : ";
    cin>>pass;
    newObj.setPassword(pass);
    cout<<"Enter new amount : ";
    cin>>newObj.amount;
    cout<<"Enter new age : ";
    cin>>newObj.age;
    cout<<"Enter new location : ";
    cin>>loc;
    newObj.setLocation(loc);
    cout<<"Data is updated successfully."<<endl;
    while (fgets(moveData, sizeof(moveData), fptr)){
      if (line != count){
        fputs(moveData, tptr);
      }else{
        fprintf(tptr , "%d%10s%10d%10d%10d%10s\n",newObj.id,newObj.name,newObj.getPassword(),newObj.amount,newObj.age,newObj.getLocation());
      }
      count++;
    }
   fclose(fptr);
   fclose(tptr);
   remove("store.txt");
   rename("temp.txt", "store.txt");
   view(newObj);
}
