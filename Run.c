//Author : Vaidik
//Date : 01/01/2023
//Description: Prorgam which is able to do basic binary conversion in different Binary Decimal Code
//8-BIT
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int BinaryToDecimal(int *);
int* DecimalToBinary(int);
void PrintBinary(int *);

int main(){
    
    //Assiging Binary Values
    //             128,64,32,16,8,4,2,1
    int Binary[8] = {1,1,1,1,0,1,1,1}; //Right-MSB, Left-LSB
    PrintBinary(Binary);

    //Converting to Binary
    int Decimal = BinaryToDecimal(Binary);

    //Converting Binary -> Decimal
    int * binary = DecimalToBinary(Decimal);
    PrintBinary(binary);

    free(binary);
    printf("SUCESSFUL RUN");
    return 0;
}
int BinaryToDecimal(int *binary){
    int decimal = 0;



    //Starting from LSB
    for(int i = 7 ; i>=0; i--)
    {
        decimal += binary[i] * pow(2,7-i);
    }
    return(int) decimal;
}

int* DecimalToBinary(int decimal)
{

    int * binary = (int *)malloc(sizeof(int) * 8);
    if(binary == 0){
        printf("Memory Allocation Failed");
        exit(0);
    }

    if(decimal > 255)
    {
        //Out of range
        printf("%d is out of Range\n", decimal);
        exit(0);  
    }

    //Starting from LSB
    for(int i =0; i<8; i++){
        binary[7-i] = decimal % 2;
        decimal = decimal /2;
    }

    return binary;
}


void PrintBinary(int *binary){
    
    for(int i = 0; i<8; i++){
        printf("%d, ",binary[i]);//MSB-->LSB
    }
    printf(" --> %d\n", BinaryToDecimal(binary));
}