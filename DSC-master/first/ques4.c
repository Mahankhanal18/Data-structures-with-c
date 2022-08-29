// 4. Demonstrate the usage of pointer to a structure which reads and prints details of an employee 	

#include<stdio.h>
struct employee{
    char name[20];
    int age;
    float salary;
};
int main(){
    struct employee employee[10], *ptr;
    int i, numberOfEmployee;
    printf("Enter the number of employee ");
    scanf("%d",&numberOfEmployee);
    for (i=0; i<numberOfEmployee; i++){
    printf("Enter the name, age and salary of the employee %d \n",i);
    scanf("%s %d %f", employee[i].name, &employee[i].age, &employee[i].salary);
    }
    
    for (i=0; i<numberOfEmployee; i++){
    ptr = &employee[i];
    printf("The details of employee %d\n", i);
    printf("Name: %s \nAge: %d \nSalary: %.2f \n",ptr->name, ptr->age, ptr->salary);
    }
}