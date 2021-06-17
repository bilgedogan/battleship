#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNAME 15

void print_table(char **table, char name[])
{
    printf("Table of %s\n", name);
    printf(" ");
    for(int i = -1; i < 6; i++){
        for(int j = 0; j< 6; j++){
            if(i == -1 )
                printf("\t%c", (char)(j+65));
            else {
                if(j==0)
                    printf("%d", i+1);
                printf("\t%c",table[i][j]);
            }  
        }
        printf("\n");
        
    }
    
}

bool game(char name[],char **loc)
{
    char estimation[3];
    bool bombed = false;
    printf("Make a guess, %s: ",name);
    scanf("%s",estimation);
    printf("%s ",estimation);
    for(int i = 0; i < 9; i++){
        printf("%s\n",loc[i]);
        if(estimation == loc[i]){
            printf("BOOMMM!\n");
            bombed = true;
            break;
        }
    }
    if(!bombed){
        printf("Opppsss! Wrong choice. Maybe next time...\n");
    }
    return bombed;
}

//there is a problem in this function
void read_txt(char txt1[], char **loc1, char txt2[], char **loc2)
{
    FILE *player1 = NULL;
    FILE *player2 = NULL;

    player1 = fopen(txt1,"r");

    for(int i = 0; i < 9;i++){
        char c[3];
        fscanf(player1,"%s ",c);
        int total = (int)c[0] + (int)c[2];
        //printf("%s ",c);
        loc1[i] = c;
        //printf("%s  ",loc1[i]);
    }

    fclose(player1);
    

    player2 = fopen(txt2,"r");

    for(int i = 0; i < 9;i++){
        char c[3];
        fscanf(player2,"%s ",c);
        //printf("%s ",c);
        loc2[i] = c;
        //printf("%s  ",loc2[i]);
    }

    fclose(player2);
    
}

int main()
{
    //for deciding who is gonna start randomly
    srand(time(NULL));
    int first = rand()%2+1;

    //for scores
    int score1 = 0, score2 = 0;

    //names of player and their txt files
    char name1[MAXNAME], name2[MAXNAME], txt1[MAXNAME], txt2[MAXNAME];

    //for locations
    char **loc1 = (char**)malloc(9*sizeof(char*));
    char **loc2 = (char**)malloc(9*sizeof(char*));
    for(int i = 0; i < 9; i++){
        loc1[i] = (char*)malloc(2*sizeof(char));
        loc2[i] = (char*)malloc(2*sizeof(char));
    }

    //players tables for printing step by step
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

    printf("%s, could you enter your txt file name (ex: filename.txt): ",name1);
    scanf("%s",txt1);
    printf("%s, could you enter your txt file name (ex: filename.txt): ",name2);
    scanf("%s",txt2);

    read_txt(txt1,loc1,txt2,loc2);
   
    for(int i = 0; i < 9; i++){
        printf("%s ",loc1[i]);
        printf("%s \n",loc2[i]);
    }
    printf("\n%s WILL START!\n", first == 1 ? name1 : name2);

    print_table(table1,name1);
    print_table(table2,name2);

    

    for(int i = 0; score1 != 9 && score2 != 9;i++){
    
        if(i%2 == 0){
            if(first == 1){
                if(game(name1,loc2))
                    score1++;
            }
            else{
                if(game(name2, loc1))
                    score2++;
            }
        }
        else{
            if(first == 1){
                if(game(name2,loc1))
                    score2++;
            }
            
            else{
                if(game(name1, loc2))
                    score1++;
            }
        }
        print_table(table1,name1);
        print_table(table2,name2);
        
    }

    free(table1);
    free(table2);
    free(loc1);
    free(loc2);

    return EXIT_SUCCESS;
}