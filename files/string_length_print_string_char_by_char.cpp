
#include <stdio.h>

int main()
{
    char mystring[] = "Hello world";
    
    // Get string length
    int len = strlen(mystring);
    
    // Output length
    printf("Length of string: %d\n", len);  

    // Print out string char by char    
    for (int i = 0; i < len; i++)
    {
        printf("%c\n", mystring[i]);
    }
  
    return 0;
};