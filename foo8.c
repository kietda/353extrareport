// creating web21 from web2 using combo 2 words + 8
// creating web51 from web5 using combo 2 words + 8
// creating web61 from web6 using combo 2 words + 8

// creating web42 from web4 using combo 2 words + 7
// creating web52 from web5 using combo 2 words + 8
// creating web62 from web6 using combo 2 words + 8

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
  char *one[60];
  char *two[168];
  char *three[1435];
  char *four[5293];
  char *five[10245];
  char *six[17722];
  char *seven[23891];
  int amountOfWords[9] = {0,0,0,0,0,0,0,0,0};

  char salt[5][3] = {"kv","rD","fT","Db","tB"}; 
  char word[] = "12345678";
  int wordlength = 8;
  char *fullline;
  char *password;
  FILE *fp;
  FILE *fp2;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  
  int track = 0;    // max 50 track? because max 500,000 words
  int distance = 120000;

  int lower = track * distance;
  int upper = (track+1)*distance - 1;   //max 5000000?


  fp = fopen("web6","r");
  fp2 = fopen("web62","w");
  fseek(fp2,0,SEEK_END);
  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  int limit = 0;
  char *preword = malloc(9);
  strncpy(preword, word, 8);    // since length(word) =8
  preword[8] = '\0';
  while ((read = getline(&line,&len,fp))!= -1 && limit <= 1){
    //limit ++;
    // if (limit <= lower)
    //     continue;    

    fullline = malloc(read);
    strncpy(fullline, line, read - 1);
    fullline[read-1]='\0';
    
    switch (read - 1){
        case 1:
            one[amountOfWords[read-1]] = fullline;
            break;
        case 2:
            two[amountOfWords[read-1]] = fullline;
            break;
        case 3:
            three[amountOfWords[read-1]] = fullline;
            break;
        case 4:
            four[amountOfWords[read-1]] = fullline;
            break;
        case 5:
            five[amountOfWords[read-1]] = fullline;
            break;                                                
        case 6:
            six[amountOfWords[read-1]] = fullline;
            break;
        case 7:
            seven[amountOfWords[read-1]] = fullline;
            break;
        default:
            break;
    }
    if (read <= 8)
        amountOfWords[read-1]++;
    else
    {
        amountOfWords[8]++;
    }
    
  }

    // // 7*1
    // for (int i = 0; i<amountOfWords[7];i++)
    // {
    //     for (int j = 0; j<amountOfWords[1];j++){
    //         fprintf(fp2,seven[i]);
    //         fprintf(fp2,one[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,one[j]); 
    //         fprintf(fp2,seven[i]);    
    //         fprintf(fp2,"\n");
    //     }
    // }
    // // 6*(1+2)
    // for (int i = 0; i<amountOfWords[6];i++)
    // {
    //     for (int j = 0; j<amountOfWords[1];j++){
    //         fprintf(fp2,six[i]);
    //         fprintf(fp2,one[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,one[j]); 
    //         fprintf(fp2,six[i]);    
    //         fprintf(fp2,"\n");
    //     }
    //     for (int j = 0; j<amountOfWords[2];j++){
    //         fprintf(fp2,six[i]);
    //         fprintf(fp2,two[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,two[j]); 
    //         fprintf(fp2,six[i]);    
    //         fprintf(fp2,"\n");
    //     }
    // }
    // // 5*(1+2+3)
    // for (int i = 0; i<amountOfWords[5];i++)
    // {
    //     for (int j = 0; j<amountOfWords[1];j++){
    //         fprintf(fp2,five[i]);
    //         fprintf(fp2,one[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,one[j]); 
    //         fprintf(fp2,five[i]);    
    //         fprintf(fp2,"\n");
    //     }
    //     for (int j = 0; j<amountOfWords[2];j++){
    //         fprintf(fp2,five[i]);
    //         fprintf(fp2,two[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,two[j]); 
    //         fprintf(fp2,five[i]);    
    //         fprintf(fp2,"\n");
    //     }
    //     for (int j = 0; j<amountOfWords[3];j++){
    //         fprintf(fp2,five[i]);
    //         fprintf(fp2,three[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,three[j]); 
    //         fprintf(fp2,five[i]);    
    //         fprintf(fp2,"\n");
    //     }
    // }
    // // 4* (1+2+3)
    // for (int i = 0; i<amountOfWords[4];i++)
    // {
    //     for (int j = 0; j<amountOfWords[1];j++){
    //         fprintf(fp2,four[i]);
    //         fprintf(fp2,one[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,one[j]); 
    //         fprintf(fp2,four[i]);    
    //         fprintf(fp2,"\n");
    //     }
    //     for (int j = 0; j<amountOfWords[2];j++){
    //         fprintf(fp2,four[i]);
    //         fprintf(fp2,two[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,two[j]); 
    //         fprintf(fp2,four[i]);    
    //         fprintf(fp2,"\n");
    //     }
    //     for (int j = 0; j<amountOfWords[3];j++){
    //         fprintf(fp2,four[i]);
    //         fprintf(fp2,three[j]);     
    //         fprintf(fp2,"\n");
    //         fprintf(fp2,three[j]); 
    //         fprintf(fp2,four[i]);    
    //         fprintf(fp2,"\n");
    //     }
    // }
    // //4*4
    // for (int i = 0; i<amountOfWords[4];i++)
    // {
    //     for (int j = 0; j<amountOfWords[4];j++){
    //         fprintf(fp2,four[i]);
    //         fprintf(fp2,four[j]);     
    //         fprintf(fp2,"\n");
    //     }
    // }  

    //4*3
    //5*2
    //6*1
    //3*3
    for (int i = 0; i<amountOfWords[4];i++)
    {
        for (int j = 0; j<amountOfWords[3];j++){
            fprintf(fp2,four[i]);
            fprintf(fp2,three[j]);     
            fprintf(fp2,"\n");
            fprintf(fp2,three[j]); 
            fprintf(fp2,four[i]);    
            fprintf(fp2,"\n");
        }
    }
    for (int i = 0; i<amountOfWords[5];i++)
    {
        for (int j = 0; j<amountOfWords[2];j++){
            fprintf(fp2,five[i]);
            fprintf(fp2,two[j]);     
            fprintf(fp2,"\n");
            fprintf(fp2,two[j]); 
            fprintf(fp2,five[i]);    
            fprintf(fp2,"\n");
        }
    }
    for (int i = 0; i<amountOfWords[6];i++)
    {
        for (int j = 0; j<amountOfWords[1];j++){
            fprintf(fp2,six[i]);
            fprintf(fp2,one[j]);     
            fprintf(fp2,"\n");
            fprintf(fp2,one[j]); 
            fprintf(fp2,six[i]);    
            fprintf(fp2,"\n");
        }
    }    
    for (int i = 0; i<amountOfWords[3];i++)
    {
        for (int j = 0; j<amountOfWords[3];j++){
            fprintf(fp2,three[i]);
            fprintf(fp2,three[j]);     
            fprintf(fp2,"\n");
        }
    } 

    //3*3*1
    //3*2*2  
    //4*2*1

 

  


   // convert to one of uppercase of 256 cases
    // for (int i = 0; i < 1 << wordlength; i++){
    //     // printf("%d\n",i);
    //     changeUpperWord(fullline,preword,i,wordlength);

    //     fprintf(fp2,preword);
    //     for (int isalt = 0; isalt < 5;isalt++){
    //         fprintf(fp2,"|");
    //         password = crypt(preword, salt[isalt]);
    //         fprintf(fp2,password);
    //     }
    //     fprintf(fp2,"\n");
    // }
    // if (limit % 1000 == 0)
    //     printf("finish %.1f percent.\n",(limit-lower)*100.0/distance);

    for (int i =1; i< 9; i++)
    {
        printf("Number of words having %d characters is %d\n",i,amountOfWords[i]);
    }
  fclose(fp);
  fclose(fp2);
  return 0;
}
