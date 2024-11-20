/*
* Name: Syed Anwer
* Section: BAI-1A
* Roll #:24K-0033
* Subject: Programming Fundamentals Assignment #2
* Question: 8
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int binaryToDecimal(int number);    //Converts a binary number to its decimal equivalent.
int decimalToBinary(int number);    //Converts a decimal number to its binary equivalent.
void decimalToHexadecimal(int number); //Converts a decimal number to its hexadecimal equivalent.
void HexadecimalToDecimal(char *hexNumber); //Converts a hexadecimal number to its decimal equivalent.
void BinaryToHexadecimal(int number); ///Converts a binary number to its hexadecimal equivalent.
void HexadecimalToBinary(char *hexNumber); //Converts a hexadecimal number to its binary equivalent.

int main() {
    int choice;
    printf("\n\t\tWelcome To AI Converter\n\n1. Binary To Decimal\n2. Decimal To Binary\n3. Decimal To Hexadecimal\n4. Hexadecimal To Decimal\n5. Binary To Hexadecimal\n6. Hexadecimal To Binary\n7. EXIT\nYour choice(1-7): ");
    scanf("%d",&choice);
    int number;
    char hexNumber[50]={0};
    switch(choice){
        case 1:
        printf("\nEnter your binary number: ");
        scanf("%d",&number);
        int store; int num = number; 
        while(num>0){
            store = num %10;
            num = num /10;
            if(store==0||store==1){
                binaryToDecimal(number);
                break;
            }
            else{
                printf("\nEnter a valid input for BINARY. ");
                break;
            }
        }//end while
        break;

        case 2:
        printf("\nEnter your decimal number: ");
        scanf("%d",&number);
        decimalToBinary(number);
        break;

        case 3:
        printf("\nEnter your decimal number: "); scanf("%d",&number);
        decimalToHexadecimal(number);
        break;

        case 4:
        printf("\nEnter  Hexadecimal number: ");
        getchar();
        fgets(hexNumber, 50, stdin);
        hexNumber[strcspn(hexNumber, "\n")] = '\0';
        HexadecimalToDecimal(hexNumber);
        break;

        case 5:
        printf("\nEnter Binary number: ");
        scanf("%d",&number);
        BinaryToHexadecimal(number); 
        break;

        case 6:
        printf("\nEnter Hexadecimal Niumber: "); getchar(); fgets(hexNumber, 50, stdin);
        hexNumber[strcspn(hexNumber, "\n")] = '\0';     //Cut the \n new line
        HexadecimalToBinary(hexNumber);
        break;

        case 7:
        printf("\nEXITING... ");
        break;
        
        default:
        printf("\ninvalid input! ");
        break;
    }
    return 0;
}//end main

int binaryToDecimal(int number){
    int temp; int i=0; int answer=0;
    while(number >0){
        temp = number%10;
        temp = temp * pow(2,i);
        number = number/10;
        answer = answer + temp;
        i++;
    }
    printf("The Decimal Equivalent is: \033[0;32m%d\033[0m\n",answer);
    return answer;
}//end function binaryToDecimal()

int decimalToBinary(int number){
    int temp; int storage[100]; int i=0; int count=0;
    while (number>0){
        temp = number%2;
        storage[i] = temp; i++;
        number = number/2;
        temp=0;
        count++;
    }
    printf("\nThe Binary Equivalent is: ");
    for(int i=0;i<count;i++){
         printf("\033[0;32m%d\033[0m",storage[i]);
    }//end for loop
    return storage[i];
}//end decimalToBinary()

void decimalToHexadecimal(int number){
    char hex[50]; int temp; int i=0; char hexa[] = "0123456789ABCDEF";
    printf("\nThe Hexadecimal Equivalent is:");
    while(number>0){
        temp = number%16;
        number = number/16;
        hex[i] = hexa[temp];
        i++;
        temp=0;
    }//end while
    for(int k=i-1;k>=0;k--){
        printf("\033[0;32m%c\033[0m", hex[k]);
    }//end for
}//end function 3

void HexadecimalToDecimal(char *hexNumber){
    int sum = 0, temp, answer=0;

    int size = strlen(hexNumber);

    for(int i =0; size > i; i++){
        char hexa_digit = hexNumber[i];
        hexa_digit = toupper(hexa_digit);
        char d;
        if(hexa_digit >= '0' && hexa_digit <= '9'){
            d = hexa_digit - '0';
        }
        else if(hexa_digit >= 'A' && hexa_digit <= 'F') d = hexa_digit - 'A' + 10;
        else{
            printf("Invalid input");
            break;
        }

        sum += d * (int)pow(16,size-i-1);
        }printf("%d", sum);
    }//end function hexaNumber()

    void BinaryToHexadecimal(int number){
        int b = binaryToDecimal(number);
        decimalToHexadecimal(b);
    }

    void HexadecimalToBinary(char *hexNumber){
        for(int i = 0; i < strlen(hexNumber); i++)
	{
		char dg = hexNumber[i];
		dg = toupper(dg);
		
		if ((dg<='9' && dg>='0') || (dg<='F' && dg>='A'))
		{
			if (dg == '0') 
             printf("0000"); 
			else if (dg== '1')
              printf("0001"); 
			else if (dg == '2')
              printf("0010"); 
			else if (dg == '3')
              printf("0011"); 
			else if (dg == '4')
              printf("0100"); 
			else if (dg == '5')
              printf("0101"); 
			else if (dg == '6')
              printf("0110"); 
			else if (dg =='7') 
            printf("0111"); 
			else if (dg =='8') 
             printf("1000"); 
			else if (dg == '9')
              printf("1001"); 
			else if (dg == 'A')
              printf("1010"); 
			else if (dg=='B')  
            printf("1011"); 
			else if (dg== 'C') 
             printf("1100"); 
			else if (dg == 'D')
              printf("1101"); 
			else if (dg == 'E')
              printf("1110"); 
			else if (dg=='F') 
             printf("1111"); 
		}
		else
		{
			printf("Invalid input");
			break;
		}
	}//end for 
}//end function HexadecimalToDecimal()   