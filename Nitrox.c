//--Calculate Pressure and O2 group
//----------------------------
#include <stdio.h>
#include <stdlib.h>

//--Set symbolic constant
#define FEET_PER_ATMOSPHERE 33
//----------------------------
int main(void) {

//--declare local variables
    int depth;
    int oxygenPercent;
    float ambientPressure;
    float oxygenPressure;
    char oxygenGroup;
    
//--get input from user
    printf("\nEnter depth and percentage O2    : ");
    scanf("%d %d", &depth, &oxygenPercent);
    
//--calculate and print ambient pressure
    ambientPressure = ((depth/FEET_PER_ATMOSPHERE) + 1);
    printf("\nAmbient pressue                  : %.1f\n",ambientPressure);

//--calculate and print partial oxygen pressue
    oxygenPressure = ((oxygenPercent/100.0)*ambientPressure);
    printf("O2 pressure                      : %.2f\n",oxygenPressure);

//--calculate and print the oxygen group
    oxygenGroup = (char)((oxygenPressure * 10) + 'A');
    printf("O2 group                         : %c\n", oxygenGroup);

//--output maximal and contigency O2 results
    printf("\nExceeds maximal O2 pressure      : %s\n", (oxygenPressure > 1.4) ? "true" : "false\n");
    printf("Exceeds contingency pressure     : %s\n", (oxygenPressure > 1.6) ? "true\n" : "false\n");

//-- Exit program
    return(EXIT_SUCCESS);


}
