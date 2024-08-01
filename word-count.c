#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000
#define MAX_WORD_LEN 50
#define MAX_WORDS 100

typedef struct {
	char word[MAX_WORD_LEN];
	int count;
} wrdcount;
void tolowerc(char *str) {
    for(int i=0; str[i]; i++) {
        str[i]=tolower(str[i]);
    }
}

int fndwrd(wrdcount wordcounts[], int num, const char *word) {
    for (int i=0; i<num; i++) {
        if(strcmp(wordcounts[i].word, word)==0){
            return i;
        }
    }
    return -1;
}

void countwords(char *para, wrdcount wordcounts[], int *num) {
    char *token =strtok(para," ,.-\n");
    while (token!= NULL) {
        tolowerc(token);
        int index =fndwrd(wordcounts, *num, token);
        if(index== -1) {
            strcpy(wordcounts[*num].word, token);
            wordcounts[*num].count = 1;
            (*num)++;
        } else {
          wordcounts[index].count++;
        }
        token =strtok(NULL, " ,.-\n");
    }
}

void printwordcount(wrdcount wordcounts[], int num) {
    for (int i= 0; i<num; i++) {
        printf("%s: %d\n", wordcounts[i].word, wordcounts[i].count);
    }
}

int main() {
    char para[N];
    wrdcount wrdcounts[MAX_WORDS];
    int num= 0;
    printf("enter para: ");
    fgets(para, N, stdin);
    countwords(para, wrdcounts, &num);
     printwordcount(wrdcounts, num);

	return 0;
}
