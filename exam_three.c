//created by Ahkar Min Htut for assignment 3
#include <stdio.h>
#include <string.h>
void rightAns(char* ptr,char a);
int main (){

char a1[8] = {'n','o','_','i','c','e'};
char a2[8] = {'a','_','x','i','o','u','s'};
char a3[5] = {'_','o','a','d'};
char a4[7] = {'w','o','_','k','e','r'};
char a5[8] = {'t','r','o','l','_','e','y'};
char mword;
int correct = 0;
int chance = 5;
int exit = 0;

printf("Welcome to our vocabulary game!\n");
for(int i=0; i<31; i++){
    printf("-");
}
printf("\n");
printf("Fill the words to get the answer.You have 5 chances.Good luck!\n");

while(chance != 0){
    rightAns(&a1[2],'_');
    rightAns(&a2[1],'_');
    rightAns(&a3[0],'_');
    rightAns(&a4[2],'_');
    rightAns(&a5[4],'_');

    do{
        printf("\n");
        printf("Question NO.1 : %s\n",a1);
        printf("Enter the missing word : ");
        scanf(" %c",&mword);
        if(mword == 'v'){
            printf("Correct.\n");
            rightAns(&a1[2],mword);
            printf("Answer is %s\n",a1);
            correct = 1;
        }else{
            printf("Wrong answer!\n");
            chance--;
            printf("You have %d chances left.\n",chance);
        }
    }while(correct == 0);

    do{
        printf("\n");
        printf("Question NO.2 : %s\n",a2);
        printf("Enter the missing word : ");
        scanf(" %c",&mword);
        if(mword == 'n'){
            printf("Correct.\n");
            rightAns(&a2[1],mword);
            printf("Answer is %s\n",a2);
            correct = 1;
        }else{
            printf("Wrong answer!\n");
            correct = 0;
            chance--;
            printf("You have %d chances left.\n",chance);
        }
    }while(correct == 0);

    do{
        printf("\n");
        printf("Question NO.3 : %s\n",a3);
        printf("Enter the missing word : ");
        scanf(" %c",&mword);
        if(mword == 't'){
            printf("Correct.\n");
            rightAns(&a3[0],mword);
            printf("Answer is %s\n",a3);
            correct = 1;
        }else{
            printf("Wrong answer!\n");
            correct = 0;
            chance--;
            printf("You have %d chances left.\n",chance);
        }
    }while(correct == 0);

    do{
        printf("\n");
        printf("Question NO.4 : %s\n",a4);
        printf("Enter the missing word : ");
        scanf(" %c",&mword);
        if(mword == 'r'){
            printf("Correct.\n");
            rightAns(&a4[2],mword);
            printf("Answer is %s\n",a4);
            correct = 1;
        }else{
            printf("Wrong answer!\n");
            correct = 0;
            chance--;
            printf("You have %d chances left.\n",chance);
        }
    }while(correct == 0);

    do{
        printf("\n");
        printf("Question NO.5 : %s\n",a5);
        printf("Enter the missing word : ");
        scanf(" %c",&mword);
        if(mword == 'l'){
            printf("Correct.\n");
            rightAns(&a5[4],mword);
            printf("Answer is %s\n",a5);
            correct = 1;
            printf("Congratulations you won!\n");
        }else{
            printf("Wrong answer!\n");
            correct = 0;
            chance--;
            printf("You have %d chances left.\n",chance);
        }
    }while(correct == 0);
    if(correct != 0){
        break;
    }
}
return 0;
}
void rightAns(char* ptr,char a){
    *ptr = a;
}
