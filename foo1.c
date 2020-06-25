// brute force 5 characters


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  char salt[3][3] = {"rD","fT","kv"}; 
  char hashedpass[3][14] = {"rDm4EJS49RZ3o","fTz5hLJSTAdlM","kvsFMwkz5RTo2"};
  
  //char word[] = "12345678";
  int wordlength = 8;
  char *fullline;
  char *password;
  FILE *fp;
  FILE *fp2;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
 
  // int distance = 88805853;    //for estimate time
  int distance = 380204032;    //for estimate time
  int rank = 0;
  int limit = 0;
    char word[] = "AAAAA";
    int n[5] = {0,0,0,0,0};
    for (n[0] = 0;n[0]<52;n[0]++)
    {      
        //printf("%s\n",word);                 
        for (n[1] = 0;n[1]<52;n[1]++)
        {        
            for (n[2] = 0;n[2]<52;n[2]++)
            {        
                for (n[3] = 0;n[3]<52;n[3]++)
                {        
                    for (n[4] = 0;n[4]<52;n[4]++)
                    {        
                        // YOUR CODE HERE
                        for (int isalt = 0; isalt < 1;isalt++){
                            password = crypt(word, salt[isalt]);
                            if (strcmp(password, hashedpass[isalt]) == 0)
                                printf("%s:%s\n",word,hashedpass[isalt]);
                        }                        
                        limit ++ ;
                        if (limit == 1024*1024*4)
                            {
                                limit = 0;
                                rank++;
                                printf("finish %.1f percent.\n",(rank*1024*1024*4)*100.0/distance);                                
                            }
                        // END CODE HERE
                        word[4]++;
                        if (word[4]<'a' && word[4]>'Z')
                            word[4] = 'a';
                    }
                    word[4] = 'A';  //reset to START (0)
                    word[3]++;
                    if (word[3]<'a' && word[3]>'Z')
                        word[3] = 'a';
                }
                word[3] = 'A';  //reset to START (0)
                word[2]++;
                if (word[2]<'a' && word[2]>'Z')
                    word[2] = 'a';
            }
            word[2] = 'A';  //reset to START (0)
            word[1]++;
            if (word[1]<'a' && word[1]>'Z')
                word[1] = 'a';
        }
        word[1] = 'A';  //reset to START (0)
        word[0]++;
        if (word[0]<'a' && word[0]>'Z')
            word[0] = 'a';
    }

  return 0;
}
