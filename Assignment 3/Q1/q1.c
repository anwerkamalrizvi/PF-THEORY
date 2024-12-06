/*
Write a program that contains a structure named Employee which contains the following
data members:
● employeeCode
● employeeName
● dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of each
employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.
*/
#include <stdio.h>

typedef struct Employee{
    int employeeCode;
    char employeeName[20];
    char dateOfJoining[10];
}Data;

void displayEmployees(char *ptr, int i, Data emp[], float tmp,int k, int count){
    for (;k < i; k++)
    {
        printf("\nEmployee's Code: %d ",emp[k].employeeCode);   //print the employee code
        printf("\nEmployee's Name: %s ",emp[k].employeeName);   // print the name of employee
        printf("\nDate of Joining: %s ",emp[k].dateOfJoining);  // print the date the employee joined
        printf("\nTenure of the Employee: %.2f years ago since %s",tmp,ptr);    // main work of the program
        printf("\nCounter for more than three years tenure employees: %d",count);      // counter for more than three years tenure employees 
        return;
    }
}
void tenureOfEmployee(char* ptr, int i, Data emp[]){
    int day, month, year;
    float tmp=0; int count=0;
    int d, m, y; int mm=0;  //month difference to avoid the calculation mistakes
    int dd=0;
    if(sscanf(ptr,"%d/%d/%d",&day,&month,&year) == 3){ //sscanf is being used to convert char to int only
                    // this condition is for extracting the entered date by the user the current date actully
        for(int k=0;k<i;k++)        
        {//for
            if(sscanf(emp[k].dateOfJoining,"%d/%d/%d",&d,&m,&y) == 3){      //this will extract the date of joining of the employee
                tmp = year - y;     //just to avoid the calculation mistakes
                mm = m - month;     //same for here
                 if (mm<0) {
                    tmp -= (float)(-mm) / 12;       //formula to cut off the total months if the months are changed
                }

                dd= d- day;
                if (dd < 0) {
                    tmp -= (float)(-dd) / 365;      //formula for days to cut off total days
                }
                if(tmp>=3.0){
                    printf("\nTenure of this employee is more than 3 years. ");     //as the requirement
                    count++;        //this is counter for tenure of the employee having more than 3 years
                    displayEmployees(ptr,i,emp,tmp,k,count);
                }else{
                    //printf("\nI am tmp %d",tmp);
                    displayEmployees(ptr,i,emp,tmp,k,count);
                }
            }//end if inner block
    }//end for block

    }//end if block
    else
    {
        printf("\n Format of date is invalid.");
        return;
    }//end else block

}

int main(void) 
{
    Data emp[10];
    int i=0;
    int choice;
    char date[10];
    while(choice!=3){
        printf("\nWelcome!\nEnter:\n1. Add Employee Details\n2. Calculate Tenure of each employee.\n3. Exit\nYour choice(1-3): ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter employee's code: ");
            scanf("%d",&emp[i].employeeCode);
            printf("\nEnter employee's name: ");
            scanf("%s",emp[i].employeeName);
            printf("\nEnter employee's date of joining in format dd/mm/yy : ");
            scanf("%s",emp[i].dateOfJoining);
            i++;
            break;

            case 2:
            printf("\nEnter current date in format dd/mm/yy: "); scanf("%s",date);      //enter current date mr.user!
            char* ptr = date;       //just to point the date to use in the function easily
            //printf("\nI am ptr %s ",ptr);    
            tenureOfEmployee(ptr,i,emp);
            break;

            case 3:
            printf("\nThe program ends ");
            break;

            default:
            printf("\nProvide a valid input! ");
            break;
        }//end switch
    }

    return 0;
}

/*        printf("\nDay is: %d ",day);
        printf("\nMonth is: %d ",month);
        printf("\nYear is: %d",year);*/