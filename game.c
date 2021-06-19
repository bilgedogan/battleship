#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAXNAME 15

void print_table(char **table, char name[])
{
    printf("\n");
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

bool game(char name[],char **loc,char **table)
{
    char estimation[3];
    bool bombed = false;
    printf("\nMake a guess, %s: ",name);
    scanf("%s",estimation);
    //printf("%s ",estimation);

    //for locations (index of table)
    int x=0,y=0;
    x = (int)(estimation[0])-49; //49 is ascii value of '1'
    y = (int)estimation[1] - 65; //65 is ascii value of 'A'

    while((x >= 6) || (y >= 6)|| table[x][y]!='-' ){
        if(x >= 6 || y >= 6){
            printf("%s is not in 6*6 table so guess again: ", estimation);
        //printf("x:%d y:%d est:%s\n", x,y,estimation);
        }
        else{
             printf("%s, you said this location before guess again: ",name);
        
        //printf("x:%d y:%d est:%s\n", x,y,estimation);
        }

        scanf("%s",estimation);
        x = (int)(estimation[0])- 49;
        y = (int)estimation[1] - 65;
    }

    for(int i = 0; i < 9; i++){
        //printf("%s\n",loc[i]);
        if(strcmp(estimation, loc[i])==0){
            //printf("%s %s\n",estimation, loc[i]);
            bombed = true;
            printf("\nBOOMMM!\n");
            table[x][y] = 'X';
            break;
        }
    }
    if(!bombed){
        printf("\nOpppsss! Wrong choice. Maybe next time...\n");
        table[x][y] = '*';
    }
    /*for(int i = 0; i < 9; i++){
        printf("%s ",loc[i]);
        printf("\n");
    }*/
    
    return bombed;
}

//there is a problem in this function
void read_txt(char txt1[], char **loc1)
{
    FILE *player1 = NULL;
    FILE *player2 = NULL;

    player1 = fopen(txt1,"r");

    for(int i = 0; i < 9;i++){
        char c[3];
        fscanf(player1,"%s ",c);
        //printf("%s ",c);
        loc1[i][0] = c[0];
        loc1[i][1] = c[1];
        loc1[i][2] = c[2];
        //printf("%s  ",loc1[i]);
    }

    fclose(player1);
    
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
        loc1[i] = (char*)malloc(3*sizeof(char));
        loc2[i] = (char*)malloc(3*sizeof(char));
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

    read_txt(txt1,loc1);
    read_txt(txt2,loc2);
   
    //printf("%s", loc1[0]);
    /*for(int i = 0; i < 9; i++){
        printf("%s ",loc1[i]);
        printf("%s \n",loc2[i]);
    }*/

    printf("\n%s WILL START!\n", first == 1 ? name1 : name2);

    print_table(table1,name1);
    print_table(table2,name2);

    for(int i = 0; score1 != 9 && score2 != 9;i++){
        if(i%2 == 0){
            if(first == 1){
                //printf("%d is starting\n\n", first);
                if(game(name1,loc2,table2)){
                    score1++;
                    //printf("score: %d\n",score1);
                }
            }
            else{
                //printf("%d is starting\n\n", 2);
                if(game(name2, loc1,table1)){
                    score2++;
                }
            }
        }
        else{
            if(first == 1){
                //printf("2 will continue");
                if(game(name2,loc1,table1)){
                    score2++;
                }
            }
            else{
                //printf("1 will continue");
                if(game(name1, loc2,table2)){
                    score1++;
                }
            }
        }
        print_table(table1,name1);
        print_table(table2,name2);
        printf("\n\tSCORES\n%s: %d - %s: %d\n",name1,score1,name2,score2);
    }

    printf("\n\n***************************************\n    CONGRATULATIONS WINNER IS %s\n***************************************", score1==9? name1 : name2);

    free(table1);
    free(table2);
    free(loc1);
    free(loc2);

    return EXIT_SUCCESS;
}