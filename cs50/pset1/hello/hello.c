#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Ask user for name and output hello, "name"
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}