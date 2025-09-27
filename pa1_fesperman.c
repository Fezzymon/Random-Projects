#include <stdio.h>

int main() {
    //
    int price_c, price_p;
    int quantity_c, quantity_p;
    int size_party;
    double tax_rate = 0.06;  
    double subtotal, tax_amount, total;
    //
    printf("Enter the number of cups of coffee ordered: ");
    scanf("%d", &quantity_c );
    printf("Enter the number of pastries ordered: ");
    scanf("%d", &quantity_p);
    printf("What is the cost of the coffee ordered: $");
    scanf("%d",&price_c);
    printf("What is the cost of the pastry ordered: $");
    scanf("%d",&price_p);
    printf("What is the size of the party: ");
    scanf("%d", &size_party);
    printf("==== RECEIPT ====\nCoffee price: %d",price_c);
    printf("\nNumber of coffees: %d",quantity_c);
    printf("\nPastry price: %d",price_p);
    printf("\nNumber of pastries: %d",quantity_p);
    printf("\nParty size: %d", size_party);
    subtotal = price_c * quantity_c + price_p * quantity_p;
    tax_amount = subtotal * tax_rate;
    total = subtotal + tax_amount;
    printf("\n\nTotal before tax: $ %.2lf", subtotal);
    printf("\nFlorida tax (6%%): $ %.2lf", tax_amount);  // use %% to print '%'
    printf("\nTotal with tax: $ %.2lf", total);
    printf("\nFor a party size of %d, each person pays: $ %.2lf", size_party, total / size_party);
    printf("\n=== THANK YOU ===\n");
    //
    return 0;
}
