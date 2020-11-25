#include <stdio.h>
#include <stdbool.h>
#define INF 1000000

void wypisz(char plansza[3][3])
{
    printf(" %c | %c | %c \n",plansza[0][0],plansza[0][1],plansza[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",plansza[1][0],plansza[1][1],plansza[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",plansza[2][0],plansza[2][1],plansza[2][2]);
}

int ocena(char plansza[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
        if(plansza[i][0] == plansza[i][1] && plansza[i][1]== plansza[i][2] && plansza[i][0]== 'x')return 10;
        else if(plansza[i][0] == plansza[i][1] && plansza[i][1]== plansza[i][2] && plansza[i][0]== 'o')return -10;
        else if(plansza[0][i]==plansza[1][i]&& plansza[1][i]==plansza[2][i]&& plansza[0][i]=='x')return 10;
        else if(plansza[0][i]==plansza[1][i]&& plansza[1][i]==plansza[2][i]&& plansza[0][i]=='o')return -10;
    }

    if(plansza[0][0]==plansza[1][1]&& plansza[1][1]==plansza[2][2]&& plansza[0][0]=='x')return 10;
    if(plansza[0][2]==plansza[1][1]&& plansza[0][2]==plansza[2][0]&& plansza[0][2]=='x')return 10;
    if(plansza[0][0]==plansza[1][1]&& plansza[1][1]==plansza[2][2]&& plansza[0][0]=='o')return -10;
    if(plansza[0][2]==plansza[1][1]&& plansza[0][2]==plansza[2][0]&& plansza[0][2]=='o')return -10;

    return 0;
}

int minimax(char plansza[3][3], int depth, char player, int *x, int *y)
{
    int k,m;
    int remis=1;
    int maxE;
    int minE;
    if((depth==0) || (ocena(plansza) != 0))
    {
        return ocena(plansza);
    }
    int war;
    if(player=='x')
    {
        maxE = -INF;
        int i;
        for(i=0;i<3;i++)
        {
            int j;
            for(j=0;j<3;j++)
            {
                if(plansza[i][j]==' ')
                {
                    remis =0;
                    plansza[i][j]='x';
                    war = minimax(plansza, depth-1, 'o', &k,&m);
                    plansza[i][j]= ' ';
                    if(war > maxE)
                    {
                        maxE = war;
                        *x =i;
                        *y = j;
                    }
                }
            }
        }
        if(remis==1)return 0;
        return maxE;
    }
    else if(player == 'o')
    {
        minE = INF;
        int i;
        for(i=0;i<3;i++)
        {
            int j;
            for(j=0;j<3;j++)
            {
                if(plansza[i][j]==' ')
                {
                    remis =0;
                    plansza[i][j]='o';
                    war = minimax(plansza, depth-1, 'x', &k,&m);
                    plansza[i][j]= ' ';

                    if(war < minE)
                    {
                        minE = war;
                    }
                }
            }
        }
        if(remis==1)return 0;
        return minE;
    }
}

int main()
{
    char pl[3][3]={' ',' ',' ',' ','x',' ',' ',' ',' '};
    int counter = 4;
    int x,y;
    int k,m;
    bool rm = true;
    printf("Komputer:\n");
    wypisz(pl);
    while(counter)
    {
        printf("Ruch: ");
        scanf("%d %d",&x,&y);
        pl[x][y]='o';
        wypisz(pl);
        if(ocena(pl)==-10)
        {
            printf("WYGRALES GRATULACJE!!!\n");
            rm = false;
            break;
        }

        minimax(pl,10,'x', &k,&m);
        int z =minimax(pl, 10, 'x',&k,&m);
        printf("%d\n", z);
        printf("Komputer:\n");
        pl[k][m]='x';

        wypisz(pl);

        if(ocena(pl)==10)
        {
            printf("Komputer wygral\n");
            rm = false;
            break;
        }

        counter--;
    }
    if(rm)printf("REMIS");

    return 0;
}
