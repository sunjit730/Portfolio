#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int getNumLetters(string s);
int getNumWords(string s);
int getNumSentences(string s);
int getIndex(string s);

int main(void)
{
    //Prompt user for input
    string text = get_string("Text: ");
    
    //Store index in a variable
    int index = getIndex(text);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
    //printf("%i letter(s)\n%i word(s)\n%i sentence(s)\n", num_letters, num_words, num_sentences);
    //printf("%i\n", index);
    
}

int getNumLetters(string s)
{
    int num = 0;
    
    //Iterating through string input and using isalpha command to check if it is a letter
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            num++;
        }
    }
    return num;
}

int getNumWords(string s)
{
    int num = 0;
    
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        //Counting the number of spaces as it is directly related to number of words
        if (s[i] == ' ')
        {
            num++;
        }
    }
    return (num + 1); //Since we are counting spaces, there are always n + 1 words (where n = spaces)
}

int getNumSentences(string s)
{
    int num = 0;
    
    //Iterating through string input and counting number of periods, questions, exclamations to get number of sentences
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            num++;
        }
    }
    return num;
}

//Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
//L is the average number of letters per 100 words in the text
//S is the average number of sentences per 100 words in the text
int getIndex(string s)
{
    int num_letters = getNumLetters(s);
    int num_words = getNumWords(s);
    int num_sentences = getNumSentences(s);
    
    float L = num_letters * 100 / (float) num_words;
    float S = num_sentences * 100 / (float) num_words;
    
    float raw_index = 0.0588 * L - 0.296 * S - 15.8;
    int index = (int) round(raw_index);
    
    return index;
}