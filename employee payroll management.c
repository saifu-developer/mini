#include <stdio.h>
#include<string.h>
int main()
{
char employee_name[20];
int days_worked;
float rate_perday;
float total_salary;
printf("Employee_name is:\n",employee_name);
scanf("%s\n",&employee_name);
printf("days_worked is:\n",days_worked);
scanf("%d\n",&days_worked);
printf("rate_perday:\n",days_worked);
scanf("%f\n",&rate_perday);
total_salary=days_worked*rate_perday;
printf("total salary is:%f\n",total_salary);
scanf("%f\n",&total_salary);
return 0;
}