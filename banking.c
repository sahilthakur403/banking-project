#include<stdio.h>
void creataccount();
void depositmoney();
void widrawmoney();
void checkbalance();
int main(){
    int choise;
    while(choise!=5){
        printf("\n\n *** Banking System *** \n");
        printf("\n1.Create Account : ");
        printf("\n2.Deposit Money : ");
        printf("\n3.Widraw Money : ");
        printf("\n4.Check Balance : ");
        printf("\n5.Exit : ");
        printf("\nchose one option : ");
        scanf("%d",&choise);

        switch (choise)
        {
        case 1:creataccount();
        break;
        case 2:depositmoney();
        break;
        case 3:widrawmoney();
        break;
        case 4:checkbalance();
        break;
        case 5: printf("\n exiting....please weight a sec.. \n");
         break;
        
        default: printf("\nyou choose wrong option plese chose one of these options whichh are given");
            break;
        }
        
    }
    return 0;
}
void creataccount(){
    printf("\n work in progress try this option some time latter...");
}
void depositmoney(){
    printf("\n work in progress try this option some time latter...");
}
void widrawmoney(){
    printf("\n work in progress try this option some time latter...");
}
void checkbalance(){
    printf("\n work in progress try this option some time latter...");
}