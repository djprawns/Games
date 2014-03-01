#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 35
int i, j, space[MAX][MAX], neigh[MAX][MAX], cou, k=10000000, p;
char ch;
int position();
int check();

int main()
{
	for(i=0; i<=(MAX-1); i++)
    {
		for(j=0; j<=(MAX-1); j++)
		{
			space[i][j]='-';
			neigh[i][j]=0;
			printf("%c", space[i][j]);
		}
		printf("\n");
	}
	position();
	while(k!=0)
	{
		check();
		k--;
		Sleep(2000);
        system("cls");
        Sleep(2000);
	}
	return 0;
}

int position()
{
	printf("Would you like to fill positions? (y / n)\n");
	scanf("%c", &ch);
	while(ch=='y')
    {
		printf("Enter the row: -\n");
		scanf("%d", &i);
		fflush(stdin);
		printf("Enter the column: -\n");
		scanf("%d", &j);
		fflush(stdin);
		space[i][j]='*';
		printf("Would you like to fill more positions? (y / n)\n");
		scanf("%c", &ch);
	}
	for(i=0; i<=(MAX-1); i++)
    {
		for(j=0; j<=(MAX-1); j++)
		{
			printf("%c", space[i][j]);
        }
		printf("\n");
	}
	printf("\n");
	return 0;
}

int check() {
	int k, m;
	cou=0;
	for(i=1; i<=(MAX-1); i++)
    {
		for(j=1; j<=(MAX-1); j++)
		{
            cou=0;
			for(k=-1; k<=1; k++)
			{
				for(m=-1; m<=1; m++)
				{
					if((k!=0)||(m!=0))
					{
						if(space[i+k][j+m]=='*')
						{
							cou++;
						}
					}
				}
			}
			neigh[i][j]=cou;
		}
	}
	for(i=1; i<=(MAX-1); i++)
	{
		for(j=1; j<=(MAX-1); j++)
		{
			if(neigh[i][j]<=1||neigh[i][j]>=4)
			{
				space[i][j]='-';
				printf("%c", space[i][j]);
			}
			if(neigh[i][j]==3)
			{
				space[i][j]='*';
				printf("%c", space[i][j]);
			}
			if(neigh[i][j]==2)
			{
				printf("%c", space[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
	return 0;
}
