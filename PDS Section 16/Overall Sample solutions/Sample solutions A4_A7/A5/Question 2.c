// Program 2

#include <stdio.h>

char Alice[5], Bob[5], Sarah[5];
int counting_cards (char arr[ ]);

int main()
{
    // Prompting user for input of Cards gotten by the siblings and storing them in the respective strings.
    printf("Enter the cards Alice has got.\n");
    scanf("%s", &Alice);
    printf("Enter the cards Bob has got.\n");
    scanf("%s", &Bob);
    printf("Enter the cards Sarah has got.\n");
    scanf("%s", &Sarah);

    // Computing the sum of cards of the three siblings and storing them in their respective variables.
    // a : Alice , b : Bob , s : Sarah
    int a = counting_cards(Alice), b = counting_cards(Bob), s = counting_cards(Sarah);

    // Printing the sum of cards of the three siblings.
    printf("\nTotal of Alice's cards is %d.\n", a);
    printf("Total of Bob's cards is %d.\n", b);
    printf("Total of Sarah's cards is %d.\n\n", s);

    // Printing the final result of the game
    // As stated in problem statement,  if there is TIE AMONG SUM VALUES FOR ANY TWO SIBLINGS
    if (a == b || b == s || s == a)
        printf("Game tied.\n");
    // If all three sum values are distinct
    else
    {
        printf((a > b) ? (a > s) ? "Alice" : "Sarah" : (b > s) ? "Bob" : "Sarah");
        printf(" wins!\n");
    }

    return 0;
}

int counting_cards (char arr[ ])
{
    // Stores the sum value of cards.
    int sum = 0;

    // Checks each character in the string.
    for (int i = 0; i < 5; i++)
        switch (arr[i])
        {
            case 'A' : sum += 1;
                       break;
            case '2' : sum += 2;
                       break;
            case '3' : sum += 3;
                       break;
            case '4' : sum += 4;
                       break;
            case '5' : sum += 5;
                       break;
            case '6' : sum += 6;
                       break;
            case '7' : sum += 7;
                       break;
            case '8' : sum += 8;
                       break;
            case '9' : sum += 9;
                       break;
            case 'J' : sum += 11;
                       break;
            case 'K' : sum += 12;
                       break;
            case 'Q' : sum += 13;
                       break;
        }

    return sum;
}
