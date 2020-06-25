#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>

void changeUpperWord(char *source, char *des, int position, int sourcelength){
    strncpy(des, source, sourcelength);    // since length(des) =8
    des[sourcelength] = '\0';
    int start = 0;
    do{
        if (position%2 == 1)
            des[start] = toupper(source[start]); 
        else
        {
            des[start] = source[start];
        }
        start++;
        position = position / 2;
    }
    while (position > 0);
}

int main(void)
{
  char salt[5][3] = {"rD","fT","Db","kv","tB"}; 
  char word[] = "12345678";
  int wordlength = 8;
  char *fullline;
  char *password;
  FILE *fp;
  FILE *fp2;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  int track = 1;    // max 50 track? because max 500,000 words
  int distance = 120000;

  int lower = track * distance;
  int upper = (track+1)*distance - 1;   //max 5000000?


  fp = fopen("web4","r");
  fp2 = fopen("table4","a");
  fseek(fp2,0,SEEK_END);
  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  int limit = 0;
  char *preword = malloc(9);
  strncpy(preword, word, 8);    // since length(word) =8
  preword[8] = '\0';
  while ((read = getline(&line,&len,fp))!= -1 && limit <= upper){
    limit ++;
    if (limit <= lower)
        continue;    
    // printf("Retrieved line of length %zu:\n",read);
    // printf("%s",line);
    fullline = malloc(read);
    strncpy(fullline, line, read - 1);
    fullline[read-1]='\0';
    

    if (read > 9)
        wordlength = 8;
    else
    {
        wordlength = read-1;
    }    
    // convert to one of uppercase of 256 cases
    for (int i = 0; i < 1 << wordlength; i++){
        // printf("%d\n",i);
        changeUpperWord(fullline,preword,i,wordlength);

        fprintf(fp2,preword);
        for (int isalt = 0; isalt < 5;isalt++){
            fprintf(fp2,"|");
            password = crypt(preword, salt[isalt]);
            fprintf(fp2,password);
        }
        fprintf(fp2,"\n");
    }
    if (limit % 1000 == 0)
        printf("finish %.1f percent.\n",(limit-lower)*100.0/distance);
  }


  fclose(fp);
  fclose(fp2);
  return 0;
}
