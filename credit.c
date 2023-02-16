#include <stdio.h>
#include "cs50.h"

int main(void)
{
    // Ask for credit card number
    long card_number = get_long("Enter credit card number: ");

    // Count the number of digits
    int count = 0;
    long temp = card_number;
    while (temp != 0)
    {
        count++;
        temp /= 10;
    }

    // Store each digit in an array
    int number[count];
    for (int i = 0; i < count; i++)
    {
        number[i] = card_number % 10;
        card_number /= 10;
    }

    // Compute the sum of digits in odd positions
    int f_sum = 0;
    for (int i = 1; i < count; i += 2)
    {
        int doubled = number[i] * 2;
        if (doubled > 9)
        {
            f_sum += (doubled % 10) + (doubled / 10);
        }
        else
        {
            f_sum += doubled;
        }
    }

    // Compute the sum of digits in even positions
    int the_result = 0;
    for (int i = 0; i < count; i += 2)
    {
        the_result += number[i];
    }

    // Check if the sum is divisible by 10
    if ((f_sum + the_result) % 10 == 0)
    {

        // Identify the type of credit card
        if (count == 15 && number[count - 1] == 3 && (number[count - 2] == 4 || number[count - 2] == 7))
        {
            printf("AMEX\n");
        }
        else if (count == 16 && number[count - 1] == 5 && (number[count - 2] >= 1 && number[count - 2] <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 13 || count == 16) && number[count - 1] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}

