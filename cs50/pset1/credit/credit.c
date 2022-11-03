#include <stdio.h>
#include <cs50.h>

int getLength(long n);
bool checkSum(long n);
string getCardType(long n);

int main(void)
{
    //Prompt for credit card number
    long num = get_long("Number: ");
    
    //Call the getCardType function to store the card type in a string
    string card = getCardType(num);
    
    //Call the checkSum function to check if Luhn's algorithm is valid
    if (checkSum(num))
    {
        printf("%s\n", card);
    }
    else
    {
        printf("INVALID\n");
    }
    
}

//Check if Luhn's algorithm is valid
bool checkSum(long n)
{
    int length = getLength(n);
    int sumFirstSet = 0;
    int sumSecondSet = 0;
    int sumTotal = 0;

    for (int i = 1; i <= length; i++)
    {
        //If the digit is is the second to last one and every other after (aka its placement is ivisible by 2)
        if (i % 2 == 0)
        {
            int digit = n % 10;
            int digitModified = digit * 2;
            if (digitModified > 9)
            {
                //if the modified digit is 2 digits, splitting them out into two per Luhn's algorithm
                int digitModified1 = digitModified % 10;
                int digitModified2 = digitModified / 10;
                digitModified = digitModified1 + digitModified2;
            }
            sumFirstSet += digitModified; //add the digit to the running sum of the first set
        }
        //If the digit is is the last one and every other after (aka its placement is not ivisible by 2)
        else
        {
            int digit = n % 10;
            sumSecondSet += digit; //otherwise add the digit to the running sum of the second set
        }
        n = n / 10;
    }
    sumTotal = sumFirstSet + sumSecondSet;
    return (sumTotal % 10 == 0);
}

//Returns the length of the card number
int getLength(long n)
{
    int length = 0;
    do
    {
        n = n / 10;
        length++;
    }
    while (n > 0);
    return length;
}

//Returns the type of card (Visa, Mastercard, AMEX)
string getCardType(long n)
{
    int digit1;
    int digit2;
    int length = getLength(n);
    
    //Parse through card number until you get to the first and second digits, then store them
    for (int i = 1; i <= length; i++)
    {
        int digit = n % 10;
        if (i == length - 1)
        {
            digit2 = digit;
        }
        if (i == length)
        {
            digit1 = digit;
        }
        n = n / 10;
    }

    if (digit1 == 3 && (digit2 == 4 || digit2 == 7) && length == 15)
    {
        return "AMEX";
    }
    else if (digit1 == 5 && (digit2 <= 5 && digit2 >= 1) && length == 16)
    {
        return "MASTERCARD";
    }
    else if (digit1 == 4 && (length == 13 || length == 16))
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}