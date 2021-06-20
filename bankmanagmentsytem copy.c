#include<stdio.h>
//#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main_exit;
struct credentials
{
    char name[20];
    char emailid[50];
    char phonenumber[13];
    char Aadharnum[20];
    char residence[30];
    char dob[20];
    char accountno[20];
    char password[20];
    char confirmpassword[20];
    char tp[10];//for transactional password
    char string[10];//for creation of a unique id
    char sec_answer[30];
    char y;//for further choices
    float amount;
    float tammount;
}new,check,add,upd,trans;


void signin();
void loginmainscreen();
void login();
int capcha();
void update();
void deposit();
void withdraw();
void delete_account();
void see_detail();
void exit_code();
void transwithdraw(void);
void transdeposit(void);


void delay(int k)
{
    int add=0;
    int j=k*10000000;
    for ( int i =0; i<j; i++)
    {
        add+=i;
        add*=i;
        add-=i;
    }
}
int capcha()
{
  int x ,y;
  return_capcha:
  y =rand();
  char captcha[100],b[100],m;
  char num_for_captcha[20];
  strcpy(num_for_captcha,new.accountno);
  x=(int)num_for_captcha;
  x=x+y;
  int i=0;
  while(x>0)
  {
    
    m=x%10;
    if(i%3==0)
    {
      captcha[i]=m+49;
    }
    else if(i%2==0)
     {
      captcha[i]=m+97;
     }
    else
    {
      captcha[i]=m+65;
    }
    x=x/10;
    i++;
    
  }
  int n;
  printf("\n%s\n",captcha);
  printf("\nIF YOU WANT ANOTHER CAPCHA PLEASE ENTER 1.\nELSE PRESS 0.\n");
  scanf("%d",&n);
  if(n==1)
    {
      goto return_capcha;
    }
  printf("%s",captcha);
  printf("\n ENTER THE ABOVE CAPCHA\n");
  scanf("%s",b);
    
    if(strcmp(b,captcha)==0)
    {
       return 0;
    }
    else
       return 1;

    
  

}
void login()
{
    FILE *old;
    old=fopen("record.txt","r");
    system("cls");
    
    printf("\t\t  WELCOME TO A&A BANK\t\t\t   * \n*\t\t* * * * * * * * * * * * *\n");
    printf("LOGIN\n");
    printf("ENTER YOUR ACCOUNT NUMBER : ");
    scanf("%s",check.accountno);
    
     while  ( fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {

        
        if (strcmp(check.accountno,add.accountno)==0)
        {
            
            printf("\n\nPRESS '1' TO ENTER THE PASSWORD\t\tPRESS '2' IF YOU FORGOT YOUR PASSWORD\n");
            int a;
            scanf("%d",&a);
            if(a==1)
            {
                printf("\n\nENTER YOUR PASSWORD : ");
                scanf("%s",check.password);
                printf("\n");
                int value_for_captcha=capcha();
                
                if(strcmp(check.password,add.password)==0&& value_for_captcha==0)
                {
                   
                   loginmainscreen();
                }
                else
                {
                    main();
                }
            }
            else if(a==2)
            {
                system("cls");
                printf("ENTER YOUR ADHAAR NUMBER : ");
                scanf("%s",check.Aadharnum);

                printf("\n\nENTER YOUR SECURITY ANSWER : ");
                scanf("%s",check.sec_answer);
                if(strcmp(check.Aadharnum,add.Aadharnum)==1&&strcmp(check.sec_answer,add.sec_answer)==1)
                {
                    printf("\nYOU ENTERD WRONG DETAIL");
                    add_invalid:
                    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
                    scanf("%d",&main_exit);
                    system("cls");
                    if (main_exit==1)
                    main();
                    else if(main_exit==0)
                    {
                        exit(0);
                    }
                    else
                    {
                        printf("\nInvalid!\a");
                        goto add_invalid;
                    }
                }
                else
                {
                   printf("\n\nYOUR PASSWORD IS : %s",add.password);
                    printf("\nLOADING");
                    for(int i=0;i<=6;i++)
                    {
                        delay(3);
                        printf(". ");
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
                    main();

                    
                }
            }
        }
        // else
        // {
        //     main();
        // }
        
    }
    fclose(old);
}
int main()
{
    system("cls");
    int choice;// for giving choice of login or signup;
    printf("********************\n*");
    printf("\t\t  WELCOME TO A&A BANK\t\t\t   * \n*\t\t* * * * * * * * * * * * \t\t   * \n\t\t\t\t\t\t\t   *\n");
    printf("\t\t\t\t\t\t\t   *\n\t\t\t\t\t\t\t   *\n");
    printf("*  1. LOGIN\t\t\t\t      2. SIGNUP    *\n");
    printf("*  \t\t    ENTER YOUR CHOICE\t\t\t   *\n");
    
    printf("\t\t\t\t\t\t\t   *\n\t\t\t\t\t\t\t   \n\t\t\t\t\t\t\t   \n\t\t\t\t\t\t\t   \n\t\t\t\t\t\t\t   \n\t\t\t\t\t\t\t   \n\t\t\t\t\t\t\t   \n*********************\n");
    scanf("%d*",&choice);
    if(choice==1)
    {
         printf("\nLOADING");
        for(int i=0;i<=6;i++)
        {
            delay(3);
            printf(". ");
        }
        printf("\n");
            
                system("pause");
                system("cls");
        login();

    }
    if(choice==2)
    {
        printf("\nLOADING");
        for(int i=0;i<=6;i++)
        {
            delay(3);
            printf(". ");
        }
        printf("\n");
                system("pause");
                system("cls");
                signin();
        
    }
}
void signin()
{
    FILE *ptr;
    ptr=fopen("record.txt","a+");
    system("cls");
    printf("\t\t  WELCOME TO A&A BANK \n\t\t* * * * * * * * * * * * * \n\n");
    printf("SIGNUP\n");
    printf("Enter YOUR NAME : ");
    scanf("%s",new.name);
    printf("\n\nENTER YOUR EMAIL ID : ");
    scanf("%s",new.emailid);
    printf("\n\nENTER YOUR PHONE NUMBER : ");
    scanf("%s",new.phonenumber);
    printf("\n\nENTER YOUR ADDRESS : ");
    scanf("%s",new.residence);
    printf("\n\nENTER YOUR DATE OF BIRTH  ( IN DD/MM/YYYY FORMAT) : ");
    scanf("%s",new.dob);
    printf("\n\nENTER YOUR ADHAAR NUMBER : ");
    scanf("%s",new.Aadharnum);
    printf("\n\nENTER THE AMOUNT TO BE DEPOSIT : Rs");
    scanf("%f", &new.amount);
    printf("\n\nENTER A UNIQUE 4 DIGIT NUMBER \n\n DISCLAIMER : NUMBER ENTERED MUST NOT BE SIMMILAR TO OLDER ENTER PINS \n");
    scanf("%s",new.string);
    system("cls");
    
    printf("\t\t\t\t PROVIDED ACCOUNT NUMBER IS :- ");
    
    
    
    //generating the account number
     for (int i=0; i<6; i++)
    {
        new.accountno[i]=new.Aadharnum[i];
    }
    strcat(new.accountno,new.string);
    //ACCOUNT NO IS GENERATED

    
    printf("%s\n",new.accountno);
    loginpassword:
    
    printf("ENTER YOUR PASSWORD:  ");
    scanf("%s",new.password);
    printf("\nCONFIRM PASSWORD:  ");
    scanf("%s",new.confirmpassword);
    
    if (strcmp(new.confirmpassword,new.password))
    {
        delay(1);
        printf("THE PASSWORD DO NOT MATCH\n");
        printf("Press any key to Re-Enter the password\n ");
        
        system("cls");
        goto loginpassword;
    }
    else
    {
        printf("\nLOADING");
        for(int i=0;i<=6;i++)
        {
            delay(3);
            printf(". ");
        }
        printf("\n");
                
                system("pause");
                system("cls");
        printf("ANSWER ONE OF FOLOWING QUESTION AS SECURITY QUESTION\n1.WHAT IS YOUR SCHOOL NAME?\n2. WHAT IS YOUR NICK NAME?\n3. WHAT IS YOUR FAVOURITE BOOK?\n");
        scanf("%s",new.sec_answer);
        system("cls");
        printf("MAKE YOUR TRANSACTIONAL PASSWORD\n");
        scanf("%s",new.tp);
        

    }
    fprintf(ptr,"%s %s %s %s %s %s %s %s %s %s %s %f\n ",new.accountno,new.password,new.name,new.emailid,new.phonenumber,new.residence,new.dob,new.Aadharnum,new.string,new.sec_answer,new.tp,new.amount);
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        main();
    else if(main_exit==0)
            {
                exit(0);
            }
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
        
}


void loginmainscreen()
{   int option;
    system("cls");
    printf("\t\t  WELCOME TO A&A BANK \n\t\t* * * * * * * * * * * * * \n\n");
    printf("ENTER CHOICE NUMBER\n1.UPDATE ACCOUNT INFORMATION\n2.DEPOSIT MONEY\n3.WITHDRAW MONEY\n4.DELETE ACCOUNT\n5.ACCOUNT STATEMENT\n6.EXIT\n7.transferammount\n");
    scanf("%d",&option);
    switch(option)
    {
        case(1) : update();
        break;
        case(2) : deposit();
        break;
        case(3) : withdraw();
        break;
        case(4) : delete_account();
        break;
        case(5) : see_detail();
        break;
        case(6) : exit_code();
        break;
        case(7) : transdeposit();
        break;
    }
}
void update(void)
{
    int run=1;
    strcpy(upd.accountno,check.accountno);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    while (fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {
        if (strcmp(upd.accountno,add.accountno)==0)
        {
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n3.Email id\n4.Password\n5.Transactional Password\n\nEnter your choice(1 for address  2 for phone  3 for email  4 for password   5 for transactional password):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                    printf("Enter the new address:");
                    scanf("%s",upd.residence);
                    fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,upd.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
                    system("cls");
                    printf("Changes saved!");
                    // printf("Your new address : %s",upd.residence);
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%s",upd.phonenumber);
                    fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,upd.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
                    system("cls");
                    printf("Changes saved!");
                    // printf("Your new Phone number : %s",upd.phonenumber);
                }
            else if(choice==3)
                {
                    printf("Enter the new Email Id:");
                    scanf("%s",upd.emailid);
                    fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,upd.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
                    system("cls");
                    printf("Changes saved!");
                    // printf("Your new Email Id : %s",upd.emailid);
                }
            else if(choice==4)
                {
                    printf("Enter the new Password:");
                    scanf("%s",upd.password);
                    fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,upd.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
                    system("cls");
                    printf("Changes saved!");
                    // printf("Your new Password : %s",upd.password);
                }
            else if(choice==5)
                {
                    printf("Enter the new Transactional Password:");
                    scanf("%s",upd.tp);
                    fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,upd.tp,add.amount);
                    system("cls");
                    printf("Changes saved!");
                    // printf("Your new Transactional Password : %s",upd.tp);
                }

        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
        }
    }
    if (run==1)
    {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
    }
    
    if(test==0)
    {
        system("cls");
        printf("\nRecord not found!!\n");
        edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            update();
        else
            {
                printf("\nInvalid!");
                goto edit_invalid;
            }
        }
    else
    {
        
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }
}

void deposit(void)
{
    int run=1;
    system("cls");
    float add_amount=0;
    strcpy(upd.accountno,check.accountno);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    while  ( fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {
        if (strcmp(upd.accountno,add.accountno)==0)
        {
            test=1;
            printf("%s",add.residence);
            printf("\nEnter the amount you want to deposit\n");
            scanf("%f",&add_amount);
            upd.amount=add.amount+add_amount;
            
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,upd.amount);
            system("cls");
            printf("Changes saved!");
            printf("Your account balance : %f",upd.amount);
            
        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
        }
    }
    if (run==1)
    {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
    }



    if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            deposit();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
        }
    else
    {

        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }

}
void withdraw(void)
{
    int run=1;
    system("cls");
    float sub_amount=0;
    strcpy(upd.accountno,check.accountno);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    while  ( fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {
        if (strcmp(upd.accountno,add.accountno)==0)
        {
            test=1;
            printf("\nEnter the amount you want to withdraw\n");
            scanf("%f",&sub_amount);
            upd.amount=add.amount-sub_amount;
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,upd.amount);
            system("cls");
            printf("Changes saved!");
            printf("Your account balance : %f",upd.amount);
        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
        }
    }
    if (run==1)
    {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
    }
    if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            deposit();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
    }
    else
    {

        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }


}
void transdeposit(void)
{
    int run=1;
    system("cls");
    float add_amount=0;
    char finalaccnumber[20];
    //strcpy(upd.accountno,check.accountno);
    printf("Enter the account number to which you want to transfer money");
    scanf("%s",finalaccnumber);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    while  ( fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {
        if (strcmp(finalaccnumber,add.accountno)==0)
        {
            test=1;
            //printf("%s",add.residence);
            printf("\nEnter the amount you want to deposit\n");
            scanf("%f",&add_amount);
            trans.tammount=trans.tammount+add_amount;
            
            upd.amount=add.amount+trans.tammount;
            
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,upd.amount);
            system("cls");
            //printf("Changes saved!");
            //printf("Your account balance : %f",upd.amount);
            
        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
        }
    }
    if (run==1)
    {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
    }



    if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            deposit();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
        }
    else
    {
        transwithdraw();
    }
}

void transwithdraw(void)
{
    int run=1;
    system("cls");
    float sub_amount=0;
    strcpy(upd.accountno,check.accountno);
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");

    while  ( fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
    {
        if (strcmp(upd.accountno,add.accountno)==0)
        {
            test=1;
            //printf("\nEnter the amount you want to withdraw\n");
            //scanf("%f",&sub_amount);
            upd.amount=add.amount-trans.tammount;
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,upd.amount);
            system("cls");
            //printf("Changes saved!");
            printf("Your account balance : %f",upd.amount);
        }
        else
        {
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,add.amount);
        }
    }
    if (run==1)
    {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
    }
    if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            deposit();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
    }
    else
    {

        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }


}

void delete_account(void)
{
    int run=1;
    system("cls");
    strcpy(upd.accountno,check.accountno);
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    
    while (fscanf(old,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
   {
        if(strcmp(add.accountno,upd.accountno)==1)
            fprintf(newrec,"%s %s %s %s %s %s %s %s %s %s %s %f\n",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,upd.amount);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   if (run==1)
   {
        fclose(old);
        fclose(newrec);
        remove("record.txt");
        rename("new.txt","record.txt");
   }
   if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            delete_account();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
    }
    else
    {

        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }
}
void see_detail(void)
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.txt","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%s",check.accountno);

        while (fscanf(ptr,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
        {
            if(strcmp(add.accountno,check.accountno)==0)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%s\nName:%s \nDOB:%s \nAddress:%s \nAdhaar card no.:%s \nPhone number:%s \nAccount Balance:Rs%f \n\n",add.accountno,add.name,add.dob,add.residence,add.Aadharnum,add.phonenumber,add.amount);
                

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%s %s %s %s %s %s %s %s %s %s %s %f",add.accountno,add.password,add.name,add.emailid,add.phonenumber,add.residence,add.dob,add.Aadharnum,add.string,add.sec_answer,add.tp,&add.amount)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount NO.:%s\nName:%s \nDOB:%s \nAddress:%s \nAdhaar card no.:%s \nPhone number:%s \nAccount Balance:Rs%f\n\n",add.accountno,add.name,add.dob,add.residence,add.Aadharnum,add.phonenumber,add.amount);
                
            }
        }
    }


    fclose(ptr);
     if(test==0)
    {
        system("cls");
        edit_invalid:
        printf("\nRecord not found!!\n");
        printf("\nEnter 0 to try again,1 to return to main menu ");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            loginmainscreen();
        else if(main_exit==0)
            see_detail();
        else
            {
                printf("\nInvalid!\a");
                goto edit_invalid;
            }
    }
    else
    {

        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          loginmainscreen();

    }

    
}
void exit_code(void)
{
    printf("!!! THANK YOU !!!\n THIS PROJECT  IS MADE BY ADITYA KUMAR");
}
