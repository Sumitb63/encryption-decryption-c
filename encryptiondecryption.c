#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    char specialChars[100], word[100], ans;
    int i, n, ecode, dcode, code,ansb;
    const char possibleSpecials[] = "!@#$^&*"; // List of possible special characters
    int numSpecials = sizeof(possibleSpecials) - 1; // Exclude the null terminator

    // Input for the number of characters in the word
    printf("How many characters of the word do you want to encrypt or decrypt: ");
    scanf("%d", &n);
    
    getchar();  // Consume the newline character left by scanf

    // Input the word to be encrypted or decrypted
    printf("Enter the characters: ");
    for (i = 0; i < n; i++) {
        scanf("%c", &word[i]);  // Read the characters
    }

    // Input the encrypted and decrypted codes
    printf("Enter the encrypted code: ");
    scanf("%d", &ecode);
    printf("Enter the decrypted code: ");
    scanf("%d", &dcode);

    getchar();  // Consume the newline character left by scanf

    // Ask the user whether they want to encrypt or decrypt
    printf("Do you want to encrypt? Write 'y' for encryption: ");
    scanf("%c", &ans);

    if (ans == 'y')
   {
        // Ask for the encryption code
        printf("Enter the encryption code: ");
        scanf("%d", &code);

        // Check if the encrypted code matches the entered code
        if (ecode == code) 
        {
            // Seed the random number generator
            srand(time(0));

            // Generate n random special characters for encryption
            for (i = 0; i < n; i++) 
            {
                specialChars[i] = possibleSpecials[rand() % numSpecials];  // Assign random special characters
            }

            // Output the encrypted form
            printf("The encrypted form is: ");
            for (i = 0; i < n; i++) 
            {
                printf("%c", specialChars[i]);  // Print the encrypted characters
            }
            printf("\n do you want to decrypt that encrypted value? write '1' for yes and '0' for no: ");
            scanf("%d",&ansb);
              if(ansb==1)
               { printf("The decrypted form is : ");
                  for(i=0;i<n;i++)
                   {
                      printf("%c",word[i]);
                   }
               }
                else 
               {
                 printf("\n Thanks for your time");
                }
            
            printf("\n");
        }
        else
           {
             // If the code does not match, ask to try again
             printf("Encryption code does not match. Try again.\n");
           }
    }
     else
       {

         printf("You need to encrypt first.\n");
        }
return 0;
}
