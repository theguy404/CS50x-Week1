#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardNum;
    int length = 0;
    
    // Promt for input
    do
    {
        cardNum = get_long("What is your Credit Card number? ");
    }
    while (cardNum < 0);
    
    // Count length of card and add up checksum
    long count = cardNum;
    bool evenCount = false;
    int checksum = 0;
    
    while (count > 0)
    {
        if (evenCount == true)
        {
            int addTo = count % 10;
            addTo *= 2;
            if (addTo > 9)
            {
                addTo -= 10;
                checksum++;
            }
            checksum += addTo;
            evenCount = false;
        }
        else
        {
            int addTo = count % 10;
            checksum += addTo;
            evenCount = true;
        }
        count = count / 10;
        length++;
    }
    
    // Check the length and first digits for correct card type
    if (checksum % 10 == 0 && length >= 13 && length <= 16)
    {
        int digits;
        
        switch (length)
        {
            case 13:
                digits = cardNum / 1000000000000;
                if (digits == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 14:
                digits = cardNum / 10000000000000;
                if (digits == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 15:
                digits = cardNum / 10000000000000;
                if (digits == 34 || digits == 37)
                {
                    printf("AMEX\n");
                }
                else if (digits / 10 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
            case 16:
                digits = cardNum / 100000000000000;
                if (digits >= 51 && digits <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (digits / 10 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}