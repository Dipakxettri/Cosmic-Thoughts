//
//  main.c
//  PROJECT TICTACTOE
//
//  Created by Rajiv chaudhary on 20/03/2025.
//



 
 
#include<stdio.h>


char board[] = {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};


void PrintBoard(void)
{
   
    printf("           |            |             \n");
    printf("   %c       |     %c      |      %c     \n",board[1],board[2],board[3]);
    printf("           |            |             \n");
    printf("-----------|------------|-------------\n");
    printf("           |            |             \n");
    printf("   %c       |     %c      |      %c     \n",board[4],board[5],board[6]);
    printf("           |            |             \n");
    printf("-----------|------------|-------------\n");
    printf("           |            |             \n");
    printf("   %c       |     %c      |      %c     \n",board[7],board[8],board[9]);
    printf("           |            |             \n");
}

// condition checking section
int winner_checking(void)
{
    // 3 - conditions for horizontal check
    if(board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if(board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    if(board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    // 3 - conditions for vertical check
    if(board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if(board[2] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    if(board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    // two condtions for cross check
    if(board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if(board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    
    int count = 0 ;
    for(int i = 1 ; i <= 9 ; i++)
    {
        if(board[i] == 'X' || board[i] == 'O')
           {
               count++ ;
           }
    }
    
    if(count == 9)
    {
        return 0;
    }
    
    return -1;
}



int main(void)
{
    int player = 1 , input  ;
    printf("------------------------------------\n");
    printf("         CREATED BY RAJIV           \n");
    printf("------------------------------------\n");
    
    PrintBoard();
    
    while(1) // status is actually not used so we can do while(1) i.e; infinitie loop because i can control the loop by checking winner , 1 for winner , 0 - for draw
    {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O' ;
        printf("You player %d enter the position for your move : \t",player);
        scanf("%d", &input);
        
        if(input < 1 || input > 9)
        {
            printf("INvalid move :-( \n");
        }
        
        board[input] = mark ;
        PrintBoard();
        player++ ;   // for changing the players turn alternately !
        
        int result = winner_checking();
        if(result == 1)
        {
            printf("\n");
            printf("\n");
            printf("                   JETEU SATHI                \n");
            printf("\n");
            printf("\n");
            
            return -1 ;   // this will prevent to run further code if result == 1
        }else if (result == 0)
          {
              printf("\n");
              printf("\n");
              printf("                         MATCH IS DRAW                 \n");
              printf("\n");
              printf("\n");
              return -1;
          }
    
        
    }
    
    
    return 0;
}



