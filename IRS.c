//-- Program to run IRS functions
//-------------------------------
#include <stdio.h>
#include <stdlib.h>

//--symbolic constants
#define STINKINRICH 500000
#define QUITERICH 200000
#define MIAMIPOOR 100000
#define AVERAGE 50000
#define REALISTIC 20000
#define HIGHRATE .25
#define MEDIUMRATE .10
#define LOWRATE .03
#define MAXTAX 50000

//--function declarations
void incomeAndDeductions(float *income, float *deductions);
float computeTaxIncome(float income, float deductions);
char chooseTaxGroup(float taxableIncome);
float computeTax(float taxableIncome, char taxGroup);
void displayResults(float income, float deductions, float taxableIncome, char taxGroup, float tax); 

//-------------------------------
//--main function
int main(void) {

//--declare local variables
    float income;
    float deductions;
    float taxableIncome;
    char taxGroup;
    float tax;

//--call incomeAndDeductions function to get income and deductions
    incomeAndDeductions(&income, &deductions);

//--get taxable income
    taxableIncome = computeTaxIncome(income, deductions);

//--get tax group
    taxGroup = chooseTaxGroup(taxableIncome);

//--compute the tax
    tax = computeTax(taxableIncome, taxGroup);

//--print out results
    displayResults(income, deductions, taxableIncome, taxGroup, tax); 
   
    return(EXIT_SUCCESS);
}
//--incomeAndDeductions function
void incomeAndDeductions(float *income, float *deductions) {
 
//--declare local variable
    float money;
//--loop for user to enter income and deductions
    while(money != 0.0) {
        printf("Enter next amount : ");
        scanf("%f", &money);
        if (money == 0.0) {
            return;
        }
	if (money < 0.0) {
            *deductions += money * -1;
        } else {
            *income += money;
        } 
     } 

}

float computeTaxIncome(float income, float deductions) {

//--compute the difference between income and deductions
    if(income >= deductions) {
        return (income - deductions);
   }else {
        return 0.0;
   }  

}

//--get the tax group
 char chooseTaxGroup(float taxableIncome) {
    
//--if else loop to get tax group
    if(taxableIncome >= STINKINRICH) {
        return 'S';    
  } else if (taxableIncome >= QUITERICH) {
        return 'Q';
  } else if (taxableIncome >= MIAMIPOOR) {
        return 'M';
  } else if (taxableIncome >= AVERAGE) {
        return 'A';
  } else if (taxableIncome >= REALISTIC) {
        return 'R';
  } else {
        return 'P';
    }

}

//--compute tax
float computeTax(float taxableIncome, char taxGroup) {

//--declare local variable
    float tax;

//--if else loop to compute tax
    if (taxGroup == 'S' || taxGroup == 'Q') {
        tax = (taxableIncome * HIGHRATE);
  } else if (taxGroup == 'M') {
        tax = (taxableIncome * MEDIUMRATE); 
  } else if (taxGroup == 'A' || taxGroup == 'R') {
	tax = (taxableIncome * LOWRATE);
  } else if (taxGroup == 'P') {
        tax = 0.0;
  } else {
        printf("Error!");
	return 0.0; 
  }
    if (tax > MAXTAX) {
        return MAXTAX;
  }
    return tax;
}

//-- display the results
void displayResults(float income, float deductions, float taxableIncome, char taxGroup, float tax) {

//--print outputs
    printf("\nIncome         = $%10.2f\n", income);
    printf("Deductions     = $%10.2f\n", deductions);
    printf("Taxable Income = $%10.2f\n", taxableIncome);
    printf("Tax group      = %c\n", taxGroup);
    printf("Tax owed       = $%10.2f\n", tax);
}
