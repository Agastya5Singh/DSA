#include<stdio.h>
struct emp
{
    char gen[10];
    char name[50];
    char desg[30];
    char dept[30];
    float salary;
    float grossTotal,DA,HRA;
};
void input(struct emp p[], int n)
{
    printf("Enter employee information\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter name\n");
    scanf("%s",&p[i].name);
    printf("Enter gender\n");
    scanf("%s",&p[i].gen);
    printf("Enter designation\n");
    scanf("%s",&p[i].desg);
    printf("Enter dept\n");
    scanf("%s",&p[i].dept);
    printf("Enter salary\n");
    scanf("%f",&p[i].salary);
        
    }
}
void gross(struct emp p[], int n)
{

    for(int i=0;i<n;i++){
        p[i].DA=(p[i].salary*75)/100.0;
         p[i].HRA=(p[i].salary*25)/100.0;
         p[i].grossTotal=p[i].salary+p[i].DA+p[i].HRA;
    }

}
void display(struct emp p[], int n)
    {
        gross(p, n);
        printf("\n Employee Information\n");
        for (int i = 0; i < n; i++)
        {
            printf("Name= %s\n",p[i].name);
            printf("Gender= %s\n",p[i].gen);
            printf("Designation= %s\n",p[i].desg);
            printf("Salary = %f\n",p[i].salary);
            printf("Gross Pay = %f\n",p[i].grossTotal);
        }
    }
int main(){
    int n;
        printf("Enter value of n\n");
        scanf("%d",&n);
        struct emp p[n];
        input(p, n);
        display(p, n);
    return 0;
}



// OUTPUT
// Enter value of n
// 2
// Enter employee information
// Enter name
// RAM
// Enter gender
// Male
// Enter designation
// Manager
// Enter dept
// Accounts   
// Enter salary
// 40000
// Enter name
// Rajesh
// Enter gender
// MALE
// Enter designation
// Clerk  
// Enter dept
// Accounts
// Enter salary
// 30000

//  Employee Information
// Name= RAM
// Gender= Male
// Salary = 40000.000000
// Gross Pay = 80000.000000
// Name= Rajesh
// Gender= MALE
// Designation= Clerk
// Salary = 30000.000000
// Gross Pay = 60000.000000