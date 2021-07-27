#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User{
    char name[50];
    char password[20];
    char place[50];
    float price;
    int numTicket;
}user;

char state[20];

void showBrochure();
void AddUser(user*);
int LoginUser(user*);
void BookTicket(user*);
void CheckTicket(user*);
void CancelTicket(user*);
int LogoutUser();
void ChangePassword(user*);
void write(user*);
void initialize(user*);

void main()
{
    user u;
    initialize(&u);
    printf("\t\t\t~~~~~~~ || TOURISM MANAGEMENT SYSTEM || ~~~~~~~~\n");
    strcpy(state,"menu");
    int ch1,ch2,flag,l;
    while(1){
        if(strcmp(state,"menu")==0)
        {
            printf("\n\t\t\t\tAdd User - 1\n\t\t\t\tLogin User - 2\n\t\t\t\tBrochure - 3\n\t\t\t\tExit - 4\n\n\t\t\t\tEnter:");
            scanf("%d",&ch1);
            
            switch(ch1)
            {
                case 1:
                    AddUser(&u);
                    break;
                case 2:
                    flag=LoginUser(&u);
                    if(flag==1)
                    {
                    strcpy(state,"loggedIN");
                    break;
                    }
                    else
                    {
                        printf("Wrong details..");
                        break;
                    }
                case 3:
                    showBrochure();
                    break;
                case 4:
                    printf("Exiting...");
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        
        }
        else if(strcmp(state,"loggedIN")==0)
        {
            system("CLS");
            printf("\n\t\t\t\t`````````````````````````");
		    printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
		    printf("\n\t\t\t\t..........................\n");
            printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCheck Ticket - 2\n\t\t\t\tCancel Ticket - 3\n\t\t\t\tChange Password - 4"
                   "\n\t\t\t\tLogout User - 5\n\t\t\t\tBrochure - 6\n\t\t\t\tExit - 7\n");
            scanf("%d",&ch2);
             switch(ch2)
            {
                case 1:
                    BookTicket(&u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    CheckTicket(&u);
                   system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    CancelTicket(&u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    ChangePassword(&u);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    l=0;
                    l=LogoutUser();
                    if(l==1)
                    strcpy(state,"menu");
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    showBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    printf("Exiting...");
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
    }
}
void initialize(user* u){
    strcpy(u->name,"N/A");
strcpy(u->password,"N/A");
u->numTicket=0;
    strcpy(u->place,"N/A");
    u->price=0.0;
}
void AddUser(user* u){
char n[20],p[20];
   printf("Enter user name and password\n");
    scanf("%s %s",n,p);
if(strcmp(u->name,n)!=0){
    strcpy(u->name,n);
    strcpy(u->password,p);
    write(u);
    printf("Your account is succesfully created\n");
}
else
printf("Account already exsist\n");
}
void showBrochure()
{
	system("CLS");
    printf("\t\tPRICE LIST\n"); 
printf("1. LL - Kashmir Full Tour - Rs 40000\n"); 
printf("2. JK - Sikkim Local Tour - Rs 60000\n"); 
printf("3. SK - Kerala Tour - Rs 25000\n");
printf("4. SHM - Dubai Vacation - Rs 380000\n");
printf("5. AND - Andaban And Nicobar Islands Tour - Rs 120000\n");
printf("6. BHB - Lakshadweep Islands Vacation - Rs 10000\n");
printf("7. AG - Mumbai Full Tour - Rs 30000\n");
printf("8. ND - Maldives Vacation - Rs 32000\n");
printf("9. RJ - Rajasthan Vacation - Rs 45000\n");
printf("10. SI - Full USA Tour - Rs 250000\n");
}
int LoginUser(user* u){
    char a[20],b[20];
    printf("Enter User ID and Password\n");
    scanf("%s %s",a,b);
    if((strcmp(u->name,a)==0)&&(strcmp(u->password,b)==0))
        return 1;
    else 
    return 0;
}
void BookTicket(user* u){
    showBrochure();
    int n;
    char p[10];
    float price,pricelist[]={40000.0,60000.0,25000.0,380000.0,120000.0,10000.0,30000.0,32000.0,45000.0,250000.0};
    printf("\nEnter place code (eg: LL, JK)\n");
    scanf("%s",p);
    if(strcmp(p,"LL")==0){
        price=pricelist[0];
        strcpy(u->place,"Kashmir");
    }
    else if(strcmp(p,"JK")==0){
        price=pricelist[1];
        strcpy(u->place,"Sikkim");
    }
    else if(strcmp(p,"SK")==0){
        price=pricelist[2];
        strcpy(u->place,"Kerala");
    }
    else if(strcmp(p,"SHM")==0){
        price=pricelist[3];
        strcpy(u->place,"Dubai");
    }
    else if(strcmp(p,"AND")==0){
        price=pricelist[4];
        strcpy(u->place,"Andaban And Nicobar Islands");
    }
    else if(strcmp(p,"BHB")==0){
        price=pricelist[5];
        strcpy(u->place,"Lakshadweep Islands");
    }
    else if(strcmp(p,"AG")==0){
        price=pricelist[6];
        strcpy(u->place,"Mumbai");
    }
    else if(strcmp(p,"ND")==0){
        price=pricelist[7];
        strcpy(u->place,"Maldives");
    }
    else if(strcmp(p,"RJ")==0){
        price=pricelist[8];
        strcpy(u->place,"Rajasthan");
    }
    else if(strcmp(p,"SI")==0){
        price=pricelist[9];
        strcpy(u->place,"USA");
    }
    else
    {
        printf("That tour code doesn't exist\n");
        return;
    }
    printf("Enter no of tickets -\n");
    scanf("%d",&n);
    u->price=n*price;
    u->numTicket=n;
    write(u);
}
void CheckTicket(user* u){
    
    printf("Ticket details -\n");
    
      printf("User Name : %s \nPlace : %s \nNumber Of Ticket : %d \nPrice Of Ticket : %f\n",u->name,u->place,u->numTicket,u->price);
      
}
void CancelTicket(user* u){
    int flag;
    char x;
    printf("Do you really want to cancel your ticket ? (Y/N)\n");
    scanf(" %c",&x);
if(x=='Y')
{
    flag=0;
    while(flag==0)
    {
     if(strcmp(u->place,"Kashmir")==0)
        flag++;
     else if(strcmp(u->place,"Sikkim")==0)
        flag++;
     else if(strcmp(u->place,"Kerala")==0)
        flag++;
     else if(strcmp(u->place,"Dubai")==0)
        flag++;
     else if(strcmp(u->place,"Andaban And Nicobar Islands")==0)
        flag++;
     else if(strcmp(u->place,"Lakshadweep Islands")==0)
        flag++;
     else if(strcmp(u->place,"Mumbai")==0)
        flag++;
     else if(strcmp(u->place,"Maldives")==0)
        flag++;
     else if(strcmp(u->place,"Rajasthan")==0)
        flag++;
     else if(strcmp(u->place,"USA")==0)
        flag++;
     else
     {
        printf("You haven't booked a tour yet\n");
        return;
     }
    }
     while(flag==1)
     {  strcpy(u->place,"N/A");
        u->price=0.0;
        u->numTicket=0;
        printf("Your ticket is now succesfully cancelled\n");
        write(u);
        flag++;
     } 
    
}
else{
    printf("You haven't booked a tour yet\n");
        return;
 }
}
int LogoutUser(){
    return 1;
}
void ChangePassword(user* u){
    char p[20],new_p[20];
    printf("Enter your old password :\n");
    scanf("%s",p);
    if(strcmp(p,u->password)==0)
    {
      printf("Enter your new password :\n");
      scanf("%s",new_p);
      strcpy(u->password,new_p);
      write(u);
      printf("Your password is succesfully changed\n");
    }
    else
    printf("Wrong password\n");
}
void write(user *u){
    FILE *fp;
    fp=fopen("user.txt","w");
     fprintf(fp,"\t\tUser Details :\n Name : %s \n Password : %s \n Place : %s \n Price : %f \n Number Of Ticket : %d\n",u->name,u->password,u->place,u->price,u->numTicket);
    fclose(fp);
    }
