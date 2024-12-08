/*Question 04
You are creating a system to track employee performance ratings over multiple evaluation periods.
...............................................................................................
prevent memory leaks. see full question in q4.md
*/

#include <stdio.h>
#include <stdlib.h>
void inputEmployees(int** ratings, int numEmployees, int numPeriods);
void displayPerformance(int** ratings, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods);


typedef struct Employee{
    int** ratings;
    int totalScore;
}Emp;
int main()
{
    Emp emp;
    int numEmployees;
    printf("\nEnter no of employees in the company: ");
    scanf("%d",&numEmployees);
    int numPeriods;
    printf("\nEnter total periods/years: ");
    scanf("%d",&numPeriods);
    emp.ratings = (int**)malloc(sizeof(int*)*numPeriods);
    for(int i=0;i<numPeriods;i++){
        emp.ratings[i] = (int*)malloc(sizeof(int)*numEmployees); 
    }
    if(emp.ratings==NULL){
        printf("\nDMA failed");
        return 1;
    }
    inputEmployees(emp.ratings,numEmployees,numPeriods); 
    displayPerformance(emp.ratings,numEmployees,numPeriods);
    findEmployeeOfTheYear(emp.ratings,numEmployees,numPeriods);
    printf("\nThe worst employee of the time: Employee %d",findWorstPerformingEmployee(emp.ratings,numEmployees,numPeriods));
    printf("\nHighest Rated Period: Year %d",findHighestRatedPeriod(emp.ratings,numEmployees,numPeriods));
    for(int i=0;i<numPeriods;i++){
    free(emp.ratings[i]);
    }
    free(emp.ratings);
    return 0;
}

void inputEmployees(int** ratings, int numEmployees, int numPeriods){
    for(int i=0;i<numPeriods;i++){
        printf("\nYear %d: ",1+i);
        for(int j=0;j<numEmployees;j++){
            printf("\nEnter Employee %d rating from 1 to 10: ",j+1);
            scanf("%d",&ratings[i][j] );
            if(!(ratings[i][j]>=0&&ratings[i][j]<=10)){
                printf("\nNot a valid input for rating! Rating set to 0 default.");
                ratings[i][j] = 0;
            }
        }
    }
}//end inputEmployees

void displayPerformance(int** ratings, int numEmployees, int numPeriods){
    for(int i=0;i<numEmployees;i++){
        printf("\nEmployee %d Performance: ",i+1);
        for(int j = 0;j<numPeriods;j++){
            printf("\nYear %d rating: %d",j+1,ratings[j][i]);
        }
        printf("\n");
    }
}//end displayPerformance

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods){
    int sum[numEmployees]       ;
    int target = numPeriods*10, findEmp=0;
    for(int i=0;i<numEmployees;i++){
        sum[i] = 0;
    }
    for(int i=0;i<numEmployees;i++){           

        for(int j=0;j<numPeriods;j++){
            sum[i] += ratings[j][i] ;
            // printf("\nI am rating[%d][%d]: %d",j,i,ratings[j][i]);
            // printf("\nI am sum[%d]: %d",j,sum[i]);
        }//end for inner block
    }//end for block
    for(int i=0;i<numEmployees;i++){
       if(sum[i]<target){
         target = sum[i];
         findEmp = i+1;
       }
    }//end for block
    //printf("Employee %d is the Worse performing employee with score %d out of %d",findEmp,target,numPeriods*10);
    return findEmp;
}//end int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods);

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods){
    int high[numPeriods];
    int target=0,findPer =0;
    for(int i=0;i<numPeriods;i++){
        high[i] =0;
    }
    for(int i=0;i<numPeriods;i++){
        for(int j =0 ;j<numEmployees;j++){
            high[i] += ratings[i][j];
        }
    }
    for(int i=0;i<numPeriods;i++){
        if(high[i]>target){
            target = high[i];
            findPer = i+1;
        }//end if block
    }
    //printf("\nPeriod %d is the best period with score %d ",findPer,target);
    return findPer;
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods){
    int find[numPeriods], findEmp[numPeriods] ;
    for(int i = 0;i<numPeriods;i++){
        find[i] = 0;
        findEmp[i] =0;
    } //for block end  // initialize 
    for(int i = 0;i<numPeriods;i++){
        for(int j=0;j<numEmployees;j++){
            if(ratings[i][j]>find[i]){
                find[i] = ratings[i][j];
                findEmp[i] = j+1;
            }
        }
    }

    for(int i=0;i<numPeriods;i++){
        printf("\nEmployee %d is the Employee of this year %d",findEmp[i],i+1);
    }
    return 0;
}   