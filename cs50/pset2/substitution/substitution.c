#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool isValidKey(string key);
string cipher(string text, string key);

int main(int argc, string argv[])
{
    //Requires only 1 argument, otherwise return an error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //Calls isValidKey command, if false returns error
    if (!isValidKey(argv[1]))
    {
        printf("Key must contain 26 characters, alphabetical only, using each letter exactly once.\n");
        return 1;
    }

    //gather user input
    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    //output cipher text by calling cipher comnmand
    string ciphertext = cipher(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);

}

//Returns true if the key is valid
bool isValidKey(string key)
{
    int len = strlen(key);
    //Check length is 26
    if (len != 26)
    {
        return false;
    }
    //Check if all characters are alphabetical
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    //Check if all characters are unique
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return false;
            }
        }
    }
    return true;
}

//ciphers a text given a key
string cipher(string text, string key)
{
    int len = strlen(text);
    string ciphertext = text;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i])) //if the character is uppercase
            {
                int index = text[i] - 'A';
                ciphertext[i] = toupper(key[index]);
            }
            else //if the character is lowercase
            {
                int index = text[i] - 'a';
                ciphertext[i] = tolower(key[index]);
            }
        }
    }
    return ciphertext;
}