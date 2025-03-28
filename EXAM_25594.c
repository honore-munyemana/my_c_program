#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct xyzhotel_25594 {
    char customername[50];
    char datearrival[20];
    int numberofday;
    float roomrate;
};
void recordcustomer_25594(void);
void displaycustomer_25594(void);
void displaycustomerpermonth_25594(void);

int main()
{
    int c;
    do {
        printf("\n    Menu:\n   =======\n");
        printf("   1. record customer\n   2. Display customers\n   3. display customers per month\n   0. Exit...");
        // once you choose a case, it will call the function corresponding
        scanf("%d", &c);  // Added input for choice
        switch (c) {
        case 1:
            recordcustomer_25594();
            break;
        case 2:
            displaycustomer_25594();
            break;
        case 3:
            displaycustomerpermonth_25594();
            break;

        case 0:
            printf("See you\n");
            break;
        default:
            printf("Wrong choice. Choose again...\n");
        }
    }
    // This program will stop when a case is 0
    // or when a user enters 0
    while (c != 0);

    return 0;
}
void recordcustomer_25594(void)
{
   struct xyzhotel_25594 DMHL;
    FILE *ptr;
    ptr = fopen("xyzhotesl.txt", "a");
    if (ptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    printf("Enter customer name:  ");
    scanf("%s",DMHL.customername);
    printf("Enter date of arrival:  ");
    scanf("%s", DMHL.datearrival);
    printf("Enter Numbers of days:  ");
    scanf("%d",&DMHL.numberofday);
    printf("Enter amount/room:  ");
    scanf("%f",&DMHL.roomrate);
    fprintf(ptr, "%s\t%s\t%d\t%f\n", DMHL.customername, DMHL.datearrival, DMHL.numberofday, DMHL.roomrate);
    fclose(ptr);
    printf("customer  recorded successfully\n");
}
void displaycustomer_25594(void)
{
    struct xyzhotel_25594 DMHL;
    FILE *ptr;
    ptr = fopen("xyzhotesl.txt", "r");
    printf("List of customers:\n================\n");
    printf("customername\tdateofarrival\tnumberofdays\tamount/room\n=========\t==========\t=========\t=========\n");
    while (fscanf(ptr, "%s%s%d%f", DMHL.customername, DMHL.datearrival, &DMHL.numberofday, &DMHL.roomrate) != EOF) {
      printf("%s\t\t%s\t\t%d\t\t%f\n", DMHL.customername, DMHL.datearrival, DMHL.numberofday, DMHL.roomrate);
    }
    //fclose(ptr);
     fclose(ptr);
}
void displaycustomerpermonth_25594()
{
    struct xyzhotel_25594 DMHL;
    FILE *ptr;
    char month[40];
    int product;
    int total=0;
    ptr = fopen("xyzhotesl.txt", "r");
    printf("Enter the month: ");
    scanf("%s",month);
    printf("customername\tdateofarrival\tnumberofdays\tamount/room\n=========\t==========\t=========\t=========\n");
    while (fscanf(ptr, "%s%s%d%f", DMHL.customername, DMHL.datearrival, &DMHL.numberofday, &DMHL.roomrate) != EOF)
    {
        if (strcmp(DMHL.datearrival,month)==0)
        {
           printf("%s\t\t%s\t\t%d\t\t%f\n", DMHL.customername, DMHL.datearrival, DMHL.numberofday, DMHL.roomrate);
           product= DMHL.numberofday *  DMHL.roomrate;
           total=total+ product;
        }

    }
    printf("\n\namount collected in %s: %d",month,total);
    fclose(ptr);
}
















