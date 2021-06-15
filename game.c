#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXNAME 15

void print_tables(char **table1, char** table2,char name1[], char name2[])
{
    printf("\nTable of %s\n", name1);
    printf(" ");
    for(int i = -1; i < 6; i++){
        for(int j = 0; j< 6; j++){
            if(i == -1 )
                printf("\t%c", (char)(j+65));
            else {
                if(j==0)
                    printf("%d", i+1);
                printf("\t%c",table1[i][j]);
            }  
        }
        printf("\n");
        
    }

    printf("\nTable of %s\n", name2);
    printf(" ");
    for(int i = -1; i < 6; i++){
        for(int j = 0; j< 6; j++){
            if(i == -1 )
                printf("\t%c", (char)(j+65));
            else {
                if(j==0)
                    printf("%d", i+1);
                printf("\t%c",table2[i][j]);
            }  
        }
        printf("\n");
        
    }
    
}

int main()
{
    srand(time(NULL));
    int first = rand()%2+1;

    char name1[MAXNAME], name2[MAXNAME];
    char **table1 = (char**)malloc(6*sizeof(char*));
    char **table2 = (char**)malloc(6*sizeof(char*));
    for(int i = 0; i < 6; i++){
        table1[i] = (char*)malloc(6*sizeof(char));
        table2[i] = (char*)malloc(6*sizeof(char));
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            table1[i][j] = '-';
            table2[i][j] = '-';
        }
    }

    printf("\t***********************************\n\t      Welcome To Fleet Battle\n\t***********************************\n");

    printf("Please enter the first player's name: ");
    scanf("%s",name1);
    printf("Please enter the second player's name: ");
    scanf("%s",name2);

    printf("\n%s WILL START!\n", first == 1 ? name1 : name2);
    print_tables(table1,table2,name1,name2);

    free(table1);
    free(table2);

    return EXIT_SUCCESS;
}