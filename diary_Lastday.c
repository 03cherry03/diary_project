//20221791 박수현 ver.1
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_COUNT 12
#include "diary.h"


int lastday2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
struct node{
    int month_lastday;
    struct node *next;
};

void print_list(struct node* list_head)
{
    while(list_head != NULL){
        printf("%d => ", list_head -> month_lastday);
        list_head = list_head -> next;
    }
    printf("\n");
}

void def_lastday()
{
    int count=0;
    int tmp_lastday = 0;

    struct node* new_node; // 새로운 노드 위치 저장할 포인터
    struct node* list_head = NULL; // 리스트의 시작 노드

    while (count < MAX_COUNT) {
    // lastday로부터 입력
        tmp_lastday = lastday2[count];

    // 1. 노드 생성
    new_node =
        (struct node*) malloc (sizeof(struct node));
    new_node->month_lastday = tmp_lastday;

    // 2. 노드 연결
    new_node->next = list_head;
    list_head = new_node;
    print_list(list_head);
    count++;
    }
}
*/

void Feb_PM(int year) {
        if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 !=0)) )
                lastday2[1] = 29; 
        else
                lastday2[1] = 28;
}

void Year_MF(int year) {
        int k, i, j, l, yoil, line, nao;
        int tremon[3][6][7];

        printf("%4d \n", year);

        nao = year;
        Feb_PM(year);
        year = Allday(year);

    for( k=1 ; k<12 ; k+=3 ) { 
        printf("            %3d월                          %3d월                         %3d월\n", k, k+1, k+2);
        printf(" sun mon tue wed thu fri sat    sun mon tue wed thu fri sat    sun mon tue wed thu fri sat \n");

        for( i=0 ; i<3 ; i++ )
                        for( j=0 ; j<6 ; j++ )
                                for( l=0 ; l<7 ; l++ )
                                        tremon[i][j][l] = 0;
        for( i=0 ; i<3 ; i++ ) {
                        if( k + i - 2 >= 0 ) 
                                year = year + lastday2[k+i-2];
            yoil = year % 7;  
            line = 0;

            for ( j=1 ; j<=lastday2[k+i-1] ; j++ ) {
                                tremon[i][line][yoil++] = j;
                if ( yoil >= 7 ) {
                                        yoil=0; line+=1;
                                }
                        }
                }

                for( i=0 ; i<6 ; i++) {
                        for( j=0 ; j<3 ; j++) {
                                for( l=0 ; l<7 ; l++) {
                                        if(tremon[j][i][l] != 0){
                                                printf("%3d",tremon[j][i][l]);
                                                Star_PR(nao, k+j, tremon[j][i][l]);
                                        }
                    else
                                                printf("    ");
                                }
                printf("   ");
                        }
            printf("\n");
                }
        printf("\n");
        }
    printf("end \n");
}

void Month_MF(int year, int month) {
        int i, j, k, yoil, line, nao;
        int onemon[6][7];

        printf(" *========%4d년%2d월========* \n", year, month);
        printf(" sun mon tue wed thu fri sat\n");

        nao = year;
        Feb_PM(year);
        year = Allday(year);

        for( i=0 ; i<6 ; i++ ) 
                for ( j=0 ; j<7 ; j++)
                        onemon[i][j] = 0;

    for( i=1 ; i<month ; i++)
                year += lastday2[i-1];
        yoil = year % 7;
        line = 0;

        for( j=1 ; j<=lastday2[month-1] ; j++ ) {
                onemon[line][yoil++] = j;
                if( yoil >= 7) {
                        yoil=0; line+=1;
                }
        }

        for( i=0 ; i<6 ; i++) {
                for( j=0 ; j<7 ; j++) {
                        if(onemon[i][j] != 0) {
                                printf("%3d", onemon[i][j]);
                                Star_PR(nao, month, onemon[i][j]);
                        }
                        else
                                printf("    ");
                }
                printf("\n");
        }
        printf(" *======================end* \n");
}