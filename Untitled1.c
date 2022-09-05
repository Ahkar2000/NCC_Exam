#include <stdio.h>
int calc(int* sum);
int main(){
    char name[50],lover[50],option;
    int length = 0;
    int sumOne = 0,sumTwo = 0,lovePercentage = 0;
    int new = 0;

    printf("Hello welcome to our love calculator.\n");
    printf("\n");
    printf("If you are single,don't worry we have also friendship calculator.\n");
    printf("Press f for friendship or press l for love : ");
    scanf(" %c",&option);
    if(option == 'l'){
        printf("Enter Your First Name Length : ");
        scanf("%d",&length);
        printf("Enter Your First Name : ");
        scanf(" %s",&name);

        for(int i =0; i<length; i++){
            sumOne += name[i];
        }

        while(new == 0){
            printf("Enter Your Lover First Name Length : ");
            scanf("%d",&length);
            printf("Enter Your Lover First Name : ");
            scanf(" %s",&lover);

            for(int i =0; i<length; i++){
                sumTwo += lover[i];
            }

            lovePercentage = calc(&sumOne) + calc(&sumTwo);

            printf("\n");
            printf("Love Percentage is %d Percent.\n",lovePercentage);
            if(lovePercentage > 85){
                printf("Your relationship will last forever.\n");
            }else if(lovePercentage < 50){
                printf("Find new friend bro.\n");
            }else{
                printf("Your relationship is good.\n");
            }
            printf("\n");
            printf("Do you want to try with someone else?\n");
            printf("Press 0 to continue or 1 to stop : ");
            scanf("%d",&new);
        }
    }else{
        printf("Enter Your First Name Length : ");
        scanf("%d",&length);
        printf("Enter Your First Name : ");
        scanf(" %s",&name);

        for(int i =0; i<length; i++){
            sumOne += name[i];
        }

        while(new == 0){
            printf("Enter Your Friend First Name Length : ");
            scanf("%d",&length);
            printf("Enter Your Friend First Name : ");
            scanf(" %s",&lover);

            for(int i =0; i<length; i++){
                sumTwo += lover[i];
            }

            lovePercentage = calcFri(&sumOne) + calcFri(&sumTwo);
            if(lovePercentage > 99){
                lovePercentage = 100;
            }
            printf("\n");
            printf("Friendship Percentage is %d Percent.\n",lovePercentage);
            if(lovePercentage > 85){
                printf("Your friendship will last forever.\n");
            }else if(lovePercentage < 50){
                printf("Leave her bro,she is not the one.\n");
            }else{
                printf("Your friendship is good.\n");
            }
            printf("\n");
            printf("Do you want to try with someone else?\n");
            printf("Press 0 to continue or 1 to stop : ");
            scanf("%d",&new);
        }
    }
return 0;
}

int calc(int* sum){
    *sum = *sum / 10;
    int total = *sum;
    return total;
}

int calcFri(int* sum){
    *sum = *sum / 10;
    int total = 100 - *sum;
    return total;
}
