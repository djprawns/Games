#include <stdio.h>
#define UNIT 3

int compute(int p);
int check();
int arr[UNIT][UNIT], p1=1, p2=2, add=0, winner=0, p, q, flag=0;
                                                                           //Initialization of Global Variables
int main()
{
    int s=(UNIT*UNIT);
    printf("This represents the game space for tic-tac-toe: -\n1 | 2 | 3\n--+---+--\n4 | 5 | 6\n--+---+--\n7 | 8 | 9\n");
    printf("Enter the number where you'd like to mark.\n");
    for(q=0;q<3;q++)                                                                                         //Default-Value Initialization
    {
           for(p=0;p<3;p++)
           {
                 arr[q][p]=0;
           }
    }
    while((s!=0)&&(winner==0))                                        //Control Snippet
    {
         if((s%2)==0)
         {
              compute(p2);
              --s;
              winner=check();
         }
         else
         {
              compute(p1);
              --s;
              winner=check();
         }
    }
    if(winner==p1)                                                    //Display
    {
                  printf("Player 1 is the winner.");
    }
    else if(winner==p2)
    {
                  printf("Player 2 is the winner.");
    }
    else
    {
                  printf("Match resulted in a draw.");
    }
    fflush(stdin);
    getchar();
    return 0;
}
int compute(int input)                                                      //This function computes the address of input.
{
    scanf("%d", &add);
    int count=0;
    q=0,flag=0;
    for(p=-1;((p<3)&&(flag==0));p++)
    {
         ++count;
         if(count==add)
         {
               flag=1;
         }
         if(((p==2)&&(flag==0)))
         {
              ++q;
              p=-1;
         }
    }
    arr[q][p]=input;
    return 0;
}
int check()                                                                 //This function checks for a win or draw.
{
      int status=0;
      flag=0;
      for(q=0;q<3;q++)
      {
           for(p=0;p<3;p++)
           {
                if (arr[q][p]==1)
                {
                    printf("* ",arr[q][p]);
                }
                if (arr[q][p]==2)
                {
                    printf("X ",arr[q][p]);
                }
                if (arr[q][p]==0)
                {
                    printf("O ",arr[q][p]);
                }
           }
           printf("\n");
      }
      for(q=0;((q<3)&&(flag==0));q++)
      {
              if((arr[q][0]==arr[q][1])&&(arr[q][1]==arr[q][2]))      //Horizontal Check
              {
                        if(arr[q][0]==p1)
                        {
                               status=p1;
                               flag=1;
                        }
                        if(arr[q][0]==p2)
                        {
                               status=p2;
                               flag=1;
                        }
              }
      }
      for(p=0;((p<3)&&(flag==0));p++)
      {
              if((arr[0][p]==arr[1][p])&&(arr[1][p]==arr[2][p]))      //Vertical Check
              {
                        if(arr[0][p]==p1)
                        {
                                status=p1;
                                flag=1;
                        }
                        if(arr[0][p]==p2)
                        {
                                 status=p2;
                                 flag=1;
                        }
              }
      }
      if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2]))            //Diagonal Check(Top-Left to Bottom Right)
      {
                        if(arr[0][0]==p1)
                        {
                                 status=p1;
                                 flag=1;
                        }
                        if(arr[0][0]==p2)
                        {
                                 status=p2;
                                 flag=1;
                        }
      }
      else if((arr[0][2]==arr[1][1])&&(arr[1][1]==arr[2][0]))      //Diagonal Check(Top-Right to Bottom Left)
      {
                        if(arr[0][2]==p1)
                        {
                                 status=p1;
                                 flag=1;
                        }
                        if(arr[0][2]==p2)
                        {
                                 status=p2;
                                 flag=1;
                        }
      }
      return status;
}
