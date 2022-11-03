#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //Prompt user for height (btwn 1-8)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    //Parse through rows up to height
    for (int i = 0; i < height; i++)
    {

        //Create spaces on the i'th row, equal to height minus 1 minus i
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        }

        //Create hashes on the i'th row, equal to i + 1
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");

    }
}