#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int chosen;
    int firstSpace;
    int Hashs = 1;
    int middle = 2;
    
    // Asks User for number of lines between 1-8
    do
    {
        chosen = get_int("How many lines? (1-8): ");
    }
    while(chosen < 1 || chosen > 8);
    
    firstSpace = chosen -1;
    
    for (int line = 0; line < chosen; line++)
    {
        // Adds spaces in front of first hash group
        for (int spaces = firstSpace; spaces > 0; spaces--)
        {
            printf(" ");
        }
        firstSpace--;
        
        // Adds the first Hashs before the space
        for (int firsthash = Hashs; firsthash > 0; firsthash--)
        {
            printf("#");
        }
        
        printf("  ");
        
        for (int secondhash = Hashs; secondhash > 0; secondhash--)
        {
            printf("#");  
        }
        Hashs++;
        
        printf("\n");
    }
    
}