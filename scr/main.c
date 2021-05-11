#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "board_read.h"

int main(int argc, char *argv[])
{
    FILE* in = fopen("text_game.txt","r");
    if (in == NULL){
        printf ("\nErr: No such file\n");
        return 1;
    }
    Cells cell[65];
    char pos1[4] = {0}, pos2[4] = {0}, error = 0,move_color = 0;
    char buf[12] = {0}, buf2[12] = {0}, buf_name[3] = {0} ;
    int move_num = 0;
    /*   while(!feof(in)){
               error = move_read(in,buf,buf2,buf_name,&move_num);
           if (error != 0)
                   return 0;
               printf ("\n%hhu  %s  %s  %hhu  %hhu  (%d)\n",error,buf,buf2,buf_name[0],buf_name[1],move_num);
       }
       return 0;*/
    start_poz(cell);
//  int i = 0;
    move_color = WH;
    system("clear");
    printf ("\n\t\t MOVE: WH");
    print_board(cell);
    getchar ();
//	system("clear");
    while (1){
//        scanf("%s",buf);
/*        while (!(buf[i] <= 'h' && buf[i] >= 'a')){
            printf("%c",buf[i]);
            ++i;
  }*/
        error = move_read(in,buf,buf2,buf_name,&move_num);
        if (error != 0){
            printf ("\n%hhu  str#: (%d)  Err: problem with reading data\n",error,move_num);
            return 1;
        }
        decode(buf,move_num,pos1,pos2);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf[2],pos2[0],pos2[1],pos2[3]);
        //       printf("\t%c%c=%hhd %c%c=%hhd\n",pos1[0],pos1[1],pos1[2],pos2[0],pos2[1],pos2[2]);
        if (move_color == BL && cell[(int)pos1[2]].col != BL){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_color == WH && cell[(int)pos1[2]].col != WH){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_check(cell,pos1,pos2) == 0){
            move(cell,pos1,pos2);
        } else {
            printf ("\nErr: wrong move doing\n");
            return 1;
        }
        system("clear");
        if (move_color == WH){
            printf ("\n\t\t MOVE: WH");
        }
        if (move_color == BL){
            printf ("\n\t\t MOVE: BL");
        }
        print_board(cell);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf[2],pos2[0],pos2[1],pos2[3]);
//		printf("\t%d %c%c=%hhd %c%c=%hhd\n",move_num,pos1[0],pos1[1],pos1[2],pos2[0],pos2[1],pos2[2]);
        if (buf[5] == '#' || buf2[5] == '#'){
            printf ("\nEnd  of game\n");
            return 0;
        }
        getchar();
        move_color = BL;
        decode(buf2,move_num,pos1,pos2);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf2[2],pos2[0],pos2[1],pos2[3]);
//		printf("\t%d %c%c=%hhd %c%c=%hhd\n",move_num,pos1[0],pos1[1],pos1[2],pos2[0],pos2[1],pos2[2]);
        if (move_color == BL && cell[(int)pos1[2]].col != BL){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_color == WH && cell[(int)pos1[2]].col != WH){
            printf ("\nErr: Wrong color\n");
            return 1;
        }
        if (move_check(cell,pos1,pos2) == 0){
            move(cell,pos1,pos2);
        } else {
            printf ("\nErr: wrong move doing\n");
            return 1;
        }
        system("clear");
        if (move_color == WH){
            printf ("\n\t\t MOVE: WH");
        }
        if (move_color == BL){
            printf ("\n\t\t MOVE: BL");
        }
        print_board(cell);
        printf ("%d.\t%c%c%c%c%c%c\n",move_num,pos1[0],pos1[1],buf2[2],pos2[0],pos2[1],pos2[3]);
//		printf("\t%d %c%c=%hhd %c%c=%hhd\n",move_num,pos1[0],pos1[1],pos1[2],pos2[0],pos2[1],pos2[2]);
        if (buf[5] == '#' || buf2[5] == '#'){
            printf ("\nEnd  of game\n");
            return 0;
        }
        getchar();
        move_color = WH;
    }
    return 0;
}