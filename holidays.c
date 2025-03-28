#include<stdio.h>
#include<string.h>
struct student
{
    int id,age;
    char name[50];
};

void record_student(void);
void display_student(void);
void update_student(void);
int main()
{
    int c;
    do {
        printf("\nMENU\n====\n");
    printf("1.Record student\n2.display student\n3.update student\n4.Exit..");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        record_student();
        break;
    case 2:
        display_student();
        break;
    case 3:
        update_student();
        break;
    case 4:
        printf("\nsee you\n ");
        break;
    default:
        printf("\nyou enter wrong choice!\n");
    }

    }
    while(c != 0);

}
