#include<stdio.h>
#include<string.h>
const char *accountfile="account.dat";
typedef struct {
char name[50];
int accno;
float bal;
}account;
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
 FILE *file= fopen(accountfile,"ab+");
    if(file==NULL){
        printf("\nenable to oppen file");
        return;
    } 
    account acc;
    char c;
    do{
        c=getchar();
    }while(c!='\n' && c!=EOF);

    printf("\nenter your name :");
    fgets(acc.name,sizeof(acc),stdin);
    int ind=strcspn(acc.name,"\n");
    acc.name[ind] ='\0';
    printf("\nenter your account number :");
    scanf("%d",&acc.accno);
    acc.bal=0;

    fwrite(&acc,sizeof(acc),1,file);
    fclose(file);

    printf("\naccount created sucessfully....");
}
void depositmoney(){
    FILE *file=fopen(accountfile,"rb+");
    if(file==NULL){
       printf("\nenable to open file");
       return;
    }
    int accno;
    float money;
    account acc_r;
    printf("\nenter your account number : ");
    scanf("%d",&accno);
    printf(" enter the to deposit : ");
    scanf("%f",&money);

    while(fread(&acc_r,sizeof(acc_r),1,file)){
        if(acc_r.accno==accno){
            acc_r.bal+=money;
            fseek(file,-sizeof(acc_r),SEEK_CUR);
            fwrite(&acc_r,sizeof(acc_r),1,file);
            fclose(file); 
            printf("sucessfilly deposited Rs.%.2f new balance is Rs.%.2f",money,acc_r.bal);
            return;
        }
     }
     fclose(file);
     printf("account no %d is not found your accoun number not founded....",accno);
}
void widrawmoney(){
    FILE *file=fopen(accountfile,"rb+");
    if(file==NULL){
        printf("\nenable to open file ....");
        return;
        }
        int accnm;
        float money;
        account acc_r;
        printf("\nenter your account number : ");
        scanf("%d",&accnm);
        printf("\nenter the amount you wana widraw : ");
        scanf("%f",&money);

        while(fread(&acc_r,sizeof(acc_r),1,file)){
         if(acc_r.accno==accnm){
             if(acc_r.bal>=money){
                acc_r.bal-=money;
                fseek(file,-sizeof(acc_r),SEEK_CUR);
                fwrite(&acc_r,sizeof(acc_r),1,file);
                printf("sucessefully widrawl Rs.%.2f remaning balance is Rs.%.2f",money,acc_r.bal);
                }
                else{
                    printf("\ninsufficient balance");
                }
                fclose(file);
                return;
            }
        }
        printf("account no %d is not found....  ",accnm);

    }

void checkbalance(){
    FILE *file=fopen(accountfile,"rb");
    if(file==NULL){
        printf("enable to open file");
        return;
    }
    int accno;
    account accread;
    printf("enter your account number : ");
    scanf("%d",&accno);

    while(fread(&accread,sizeof(accread),1,file)){
        if(accread.accno==accno){
            printf("your current balance is Rs.%.2f",accread.bal);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nYour accont no %d is not found...",accno);
}

