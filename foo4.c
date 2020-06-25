#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>

int main(void)
{
  char salt[5][3] = {"rD","fT","Db","kv","tB"}; 
  char word[] = "12345678";
  char *fullline;
  char *password;
  FILE *fp;
  FILE *fp2;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  int track = 0;    // max 50 track? because max 500,000 words
  
  int lower = track * 10000;
  int upper = (track+1)*10000 - 1;   //max 5000000?


  fp = fopen("web4","r");
  fp2 = fopen("table4","a");
  fseek(fp2,0,SEEK_END);
  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  int limit = lower;
  while ((read = getline(&line,&len,fp))!= -1 && limit < 5){
    limit ++;
    // printf("Retrieved line of length %zu:\n",read);
    // printf("%s",line);
    fullline = malloc(read);
    strncpy(fullline, line, read - 1);
    fullline[read-1]='\0';
    //fprintf(fp2,line);
    fprintf(fp2,fullline);


    for (int isalt = 0; isalt < 5;isalt++){
        fprintf(fp2,"|");
        password = crypt(fullline, salt[isalt]);
        fprintf(fp2,password);
    }
    fprintf(fp2,"\n");
  }

  fclose(fp);
  fclose(fp2);
  return 0;
}
