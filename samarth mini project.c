
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee
{
  char name[30];
  char position[30];
  char address[50];
  float salary;
}Employee;

//Global pointer for employee
Employee *employee;

int count=0;
int size;

//Add Employee
void addEmployee()
{
  system("cls");
  printf("\n\t\t\t                  * Add a New Employee Detail *");
  printf("\nEnter Employee Name: ");
  gets(employee[count].name);
  printf("\nEnter Employee Position: ");
  fflush(stdin);
  gets(employee[count].position);
  printf("\nEnter Employee Address: ");
  gets(employee[count].address);
  printf("\nEnter Employee Salary: ");
  scanf("%f",&employee[count].salary);
  count++;
}

//Show Employees
void showEmployees()
{
  int i;
  system("cls");
  printf("\n\t\t\t                               Employee Details");
  printf("\n\n\t\t---------------------------------------------------------------------------------------");
  printf("\n\t\tEmployee Name\t\tEmployee Position\tEmployee Address\tEmployee Salary");
  printf("\n\t\t---------------------------------------------------------------------------------------");
  for (i=0; i<count; i++)
  {
    printf("\n\t\t%-12s",employee[i].name);
    printf("\t\t%-12s",employee[i].position);
    printf("\t\t%-12s",employee[i].address);
    printf("\t\t%-12.2f",employee[i].salary);
  }
}

//Search Employee
void searchEmployee()
{
  char employeeName[30];
  int i;
  printf("\nEnter Employee Name to be Searched: ");
  gets(employeeName);
  for(i=0; i<count; i++)
  {
    if(stricmp(employee[i].name,employeeName)==0)
    {
      system("cls");
      printf("\n\t\t\t**** Employee Details ****");
      printf("\n\n\t\tEmployee Name : %s", employee[i].name);
      printf("\n\t\tEmployee Position : %s", employee[i].position);
      printf("\n\t\tEmployee Address : %s", employee[i].address);
      printf("\n\t\tEmployee Salary : %.2f\n", employee[i].salary);
    }
  }
}

//Remove Employee
void deleteEmployee()
{
  char employeeName[30];
  int i,j;
  printf("\nEnter Employee Name to be Removed: ");
  gets(employeeName);
  for(i=0; i<count; i++)
  {
    if(stricmp(employee[i].name,employeeName)==0)
    {
      system("cls");
      printf("\n\t\t\t**** Remove Employee Details ****");
      printf("\n\n\t\tEmployee Name : %s", employee[i].name);
      printf("\n\t\tEmployee Position : %s", employee[i].position);
      printf("\n\t\tEmployee Address : %s", employee[i].address);
      printf("\n\t\tEmployee Salary : %.2f\n", employee[i].salary);
        for(j=i; j<count; j++)
        {
            employee[i]=employee[i+1];
        }
      count--;
      return;
    }
  }
}

//Update Employee
void updateEmployee()
{
  char employeeName[30];
  int i,j;

  printf("\nEnter Employee Name to be Updated: ");
  gets(employeeName);
  for(i=0; i<count; i++)
  {
    if(stricmp(employee[i].name,employeeName)==0)
    {
      system("cls");
      printf("\n\t\t\t**** Employee Details ****");
      printf("\n\n\t\tEmployee Name : %s", employee[i].name);
      printf("\n\t\tEmployee Position : %s", employee[i].position);
      printf("\n\t\tEmployee Address : %s", employee[i].address);
      printf("\n\t\tEmployee Salary : %.2f\n", employee[i].salary);

      printf("\n\t\t\t**** Add New Employee Details ****");
      printf("\nEnter Employee Name: ");
      gets(employee[i].name);
      printf("\nEnter Employee Position: ");
      fflush(stdin);
      gets(employee[i].position);
      printf("\nEnter Employee Address: ");
      gets(employee[i].address);
      printf("\nEnter Employee Salary: ");
      scanf("%f",&employee[i].salary);
    }
  }
}

//Main
void main()
{
  int choice;
  printf("\nEnter total number of employee inputs: ");
  scanf("%d",&size);
  //Setting Dynamic Array Size
  employee = (Employee*) malloc(sizeof(Employee)*size);

  do
  {
    system("cls");
    printf("\n1.Add Employee\n2.Show All Employees\n3.Search an Employee \n4.Update Employee\n5.Delete an Employee\n6.Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice)
    {
      case 1:
        addEmployee();
        break;
      case 2:
        showEmployees();
        break;
      case 3:
        searchEmployee();
        break;
      case 4:
        updateEmployee();
        break;
      case 5:
        deleteEmployee();
        break;
      case 6:
        return;
    }
    getch();
  }while(1);
}
