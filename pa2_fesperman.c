#include <stdio.h>

int main() {
    // Setting Variables for Usage, Subtotal, and Surcharge
    double use, subt, surc;
    //Setting base Surcharge to Zero
    surc = 0;
    //Asking for user input
    printf("Enter Usage (kWH): ");
    scanf("%lf", &use);
    //Determining best calculation path based on total usage
    if(use < 0){ 
        printf("Invalid Input");
    }
        //Any Usage under 100kWh is free so output $0
    else if(use <=100){
        printf("Base Bill: $0.00");
        printf("\nFinal Bill: $0.00\n");
            }
        //Only in cases of usage over 500kWh is a surcharge possible so calculations are done seperately
    else if(use>500){
        ////Knowing already that 200 kwh at $0.1 is $20, the next 200kwh at $0.2 is $40 and the first 100kwh is free, we save on calculation
        use = use - 500;
        subt = 60 + use*0.3;
        //Display Results
        printf("Base Bill: $%.2lf", subt);
        if(subt>1){
            //Calculate and display surcharge if needed
            surc = subt*0.1;
            printf("\nSurcharge (10%%): $%.2lf", surc);
                }
        printf("\nFinal Bill: $%.2lf\n", subt + surc);
        
                    }
        //Calculating all other output possiblities
    else if(use<500){
        if(use>300){
            //Knowing already that 200 kwh at $0.1 is $20 and the first 100kwh is free, we save on calculation
            use = use - 300;
            subt = 20 + use*0.2;
        }
        else{
            use = use - 100;
            subt = use*0.1;
        }
        //Display Results
        printf("Base Bill: $%.2lf", subt);
        printf("\nFinal Bill: $%.2lf\n", subt);
                }
    //
    return 0;
}
