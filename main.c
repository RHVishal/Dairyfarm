#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

struct customer
{
    char name[100];
    char id[15];
    char mob[12];
    char type[10];
    char adr[100];
};

void Add_New_customer();
void Copy_files(FILE *, FILE *);

int main()
{
    struct customer data;

    char ch = 'y';

    while (ch == 'y' || ch == 'Y')
    {
        printf("--------------------------------------\n");
        printf("\tDairy management system\n");
        printf("--------------------------------------\n");

        printf("Select the following option to work:\n");
        int choice;
        printf("1. Add New Customer Name\n2. Edit Customer Details\n3. Search Details\n4. Add Milk\n5. Print Details\n");
        printf("Select the opton from 1 to 4 : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("adding new customer\n");
            Add_New_customer();
            // add new customer function();
            break;
        case 2:
            printf("editing mode\n");
            // edit customer function
            break;
        case 3:
            printf("searching mode\n");
            // search details function
            break;
        case 4:
            printf("Adding milk\n");
            // add milk function
            break;
        case 5:
            printf("printing details\n");
            // add milk function
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Do you want to continue (Y/N)  :  ");
        scanf(" %c", &ch);
    }
    return 0;
}

void Copy_files(FILE *fptr, FILE *fptr1)
{
    char ch;
    while ((ch = fgetc(fptr1)) != EOF)
    {
        fputc(ch, fptr);
    }
}

void Add_New_customer()
{

    FILE *fptr = fopen("dairybook.csv", "r");
    FILE *fptr1 = fopen("temp.csv", "w");

    struct customer data;

    int count = 0;
    fscanf(fptr, "%d\n", &count);
    count++;
    fprintf(fptr1, "%d\n", count);

    for (int i = 0; i < count - 1; i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", data.name, data.id, data.mob, data.type, data.adr);
        fprintf(fptr1, "%s,%s,%s,%s,%s\n", data.name, data.id, data.mob, data.type, data.adr);
    }
    system("clear");
    printf("------------------------------------------\n");
    printf("\tEnter the customer details\n");
    printf("------------------------------------------\n");

    printf("Enter the name of the customer : ");
    scanf(" %[^\n]", data.name);

    printf("Enter the customer Id : ");
    scanf(" %[^\n]", data.id);

    printf("Enter the mobile number : ");
    scanf(" %[^\n]", data.mob);

    printf("Enter the Animal type : ");
    scanf(" %[^\n]", data.type);

    printf("Enter the Address : ");
    scanf(" %[^\n]", data.adr);

    fprintf(fptr1, "%s,%s,%s,%s,%s\n", data.name, data.id, data.mob, data.type, data.adr);
    fclose(fptr);
    fclose(fptr1);
    fptr = fopen("dairybook.csv", "w");
    fptr1 = fopen("temp.csv", "r");
    Copy_files(fptr, fptr1);
    fclose(fptr);
    fclose(fptr1);
}
//dushyants code starts from here
void edit()
{
    char id[15], name[50], mobile[12], type[10], addr[50];
    int choice, flag ;
    struct customer data;
    int count = 0;
    printf("Enter Customer ID: ");
    scanf(" %[^\n]",id);
    printf("Enter choice, What you want to edit: \n");
    printf("1. Name\n2. ID\n3. Mobile Number\n4. Animal Type\n5. Address\n");
    scanf("%d",&choice);
    FILE *mfptr = fopen("dairybook.csv","r");
    FILE *tfptr = fopen("temp.csv","w");
    if(tfptr == NULL)
    {
        printf("File not opened\n");
        exit(0);
    }
    fscanf(mfptr,"%d\n",&count);
    // printf("%d\n",count);
    fprintf(tfptr,"%d\n",count);
    for(int i=0; i<count; i++)
    {
        fscanf(mfptr," %[^,], %[^,], %[^,], %[^,], %[^,], %f\n",data.name,data.id,data.mob, data.type, data.adr, &data.t_milk);
        if( strcmp(data.id,id) == 0)
        {
            flag = 0;
            switch(choice)
            {
                case 1: printf("Enter Name to be Changed: ");
                    scanf(" %[^\n]",name);
                    strcpy(data.name,name);
                    break;
                case 2: printf("Enter ID to be changed: ");
                    scanf(" %[^\n]",id);
                    strcpy(data.id,id);
                    break;
                case 3: printf("Enter Mobile Number to be Changed: ");
                    scanf(" %[^\n]",mobile);
                    strcpy(data.mob,mobile);
                    break;
                case 4: printf("Enter Animale type to be changed: ");
                    scanf(" %[^\n]",type);
                    strcpy(data.type,type);
                    break;
                case 5: printf("Enter address to be changed: ");
                    scanf(" %[^\n]",addr);
                    strcpy(data.adr,addr);
                    break;
                default: printf("Enter valid choice: ");
                break;
            }
        }
        fprintf(tfptr,"%s,%s,%s,%s,%s,%f\n",data.name,data.id,data.mob,data.type,data.adr, data.t_milk);
    }
    if(flag == 0)
    {
        printf("Customer data Edited Successfullly...!\n");
    }
    else
    printf("Customer NOT Found....!\n");
    fclose(mfptr);
    fclose(tfptr);

    mfptr = fopen("dairybook.csv","w");
    tfptr = fopen("temp.csv","r");
    Copy_files(mfptr, tfptr);
    fclose(mfptr);
    fclose(tfptr);
}

void add_milk()
{
    struct customer data; 
    int count = 0;
    char ID[15];
    FILE *mfptr = fopen("dairybook.csv","r");
    FILE *tfptr = fopen("temp.csv","w");
    printf("---------ADD MILK---------\n");
    printf("Enter the Customer ID\n");
    scanf(" %[^\n]",ID);
    
    float milk;
    printf("Enter milk: ");
    scanf("%f",&milk);
    fscanf(mfptr,"%d",&count);
    fprintf(tfptr,"%d\n",count);
    for(int i = 0; i<count ; i++)
    {
        fscanf(mfptr," %[^,], %[^,], %[^,], %[^,], %[^,], %f\n",data.name, data.id, data.mob, data.type, data.adr, &data.t_milk);
        if(strcmp(data.id,ID) == 0)
        {
            data.t_milk += milk;
        }
        fprintf(tfptr, "%s,%s,%s,%s,%s,%f\n",data.name, data.id, data.mob, data.type, data.adr, data.t_milk);
    }
    fclose(mfptr);
    fclose(tfptr);
    
    mfptr = fopen("dairybook.csv","w");
    tfptr = fopen("temp.csv","r");
    Copy_files(mfptr,tfptr);
    fclose(mfptr);
    fclose(tfptr);
}
