// @Author ●  ̿' ̿'\̵͇̿̿\з=(◕_◕)=ε/̵͇̿̿/'̿'̿ ̿ ● Elmin Didic


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* List of Symbols and their meaning
 * ♨ Tall Grass
 * ↑ Tree
 * 184 © Pokemon Center
 * 169 ® Poke Mart
 * 219 █ Rock
 * 176 ░ Floor
 * 177 ▒ Un-Used
 * 178 ▓ Water
 * 200 ╚ DownRight Road
 * 188 ╝ DownLeft Road
 * 201 ╔ UpRight Road
 * 187 ╗ UpLeft Road
 * 202 ╩ DownLeftRight Road
 * 203 ╦ UpLeftRight Road
 * 204 ╠ UpRightDown Road
 * 185 ╣ UpLeftDown Road
 * 205 ═ LeftRight Road
 * 206 ╬ AllWays Road
 * 186 ║ UpDown Road
 */
//    const char tall_grass = '♨' ; //Tall Grass
//    const char tree[3] = "↑"; //Tree
//    const char pokemon_center[3] = "©"; //Pokemon Center
//    const char poke_mart[3] = "®"; //Poke Mart
//    const char rock[3] = "█"; //Rock
//    const char bio[3] = "░"; //Floor
//    const char un_used[3] = "▒"; //Un-Used
//    const char water[3] = "▓"; //Water
//    const char downright_road[3] = "╚"; //DownRight Road
//    const char downleft_road[3] = "╝"; //DownLeft Road
//    const char upright_road[3] = "╔"; //UpRight Road
//    const char upleft_road[3] = "╗"; //UpLeft Road
//    const char downleftright_road[3] = "╩"; //DownLeftRight Road
//    const char upleftright_road[3] = "╦"; //UpLeftRight Road
//    const char uprightdown_road[3] = "╠"; //UpRightDown Road
//    const char upleftdown_road[3] = "╣"; //UpLeftDown Road
//    const char leftright_road[3] = "═"; //LeftRight Road
//    const char allways_road[3] = "╬"; //AllWays Road
//    const char updown_road[3] = "║"; //UpDown Road



//Board Size
#define width 80
#define height 21

//List of All Colors
#define BLK "\e[1;90m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//void swap(int *x, int *y)
//{
//    int temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;

//swap(&x,&y);
//}

void print_world()
{
    char board[height][width];

    time_t t;
    srand((unsigned) time(&t));

    int i,j, tileRand;


    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            if(i == 0 || i == 20 || j == 0 || j == 79)
            {


                board[i][j] = '%';
               //printf(BLK "%c", board[i][j]);
            }
            else
            {
                tileRand = rand() % 40 + 1;

                if(tileRand < 29)
                {
                    board[i][j] = '.';
                }
                else if(tileRand == 32)
                {
                    board[i][j] = ',';
                    board[i+1][j+1] = ',';
                    board[i-1][j-1] = ',';
                    board[i][j+1] = ',';
                    board[i-1][j] = ',';
                }
                else if(tileRand == 37)
                {
                    board[i][j] = '"';
                }
                else
                {
                    board[i][j] = '.';
                }

               //printf(GRN "%c", board[i][j]);
            }
        }
      // printf("\n");

    }

    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            if (i == 0 || i == 20 || j == 0 || j == 79) {


                board[i][j] = '%';
                //printf(BLK "%c", board[i][j]);
            }
        }
    }

    //road placer
    int North = rand() % 74 + 3;
    int South = rand() % 74 + 3;
    int East = rand() % 15 + 3;
    int West = rand() % 15 + 3;

    board[0][North] = 'N';
    board[20][South] = 'S';
    board[West][0] = 'W';
    board[East][79] = 'E';

    int DownRand = rand() % 10 + 5;

    for(i = 0; i < DownRand; i++)
    {
        board[i][North] = '#';
    }

    if(North > South)
    {
        for(i = North; i > South; i--)
        {
            board[DownRand][i] = '#';
        }
        for(i = 21; i > DownRand - 1; i--)
        {
            board[i][South] = '#';
        }
    }
    else
    {
        for(i = North; i < South; i++)
        {
            board[DownRand][i] = '#';
        }
        for(i = 21; i > DownRand - 1; i--)
        {
            board[i][South] = '#';
        }
    }

    int SideRand = rand() % 40 + 25;
    for(i = 0; i < SideRand; i++)
    {
        board[West][i] = '#';
    }

    if(West > East)
    {
        for(i = West; i > East; i--)
        {
            board[i][SideRand] = '#';
        }

        for(i = 81; i > SideRand - 1; i--)
        {
            board[East][i] = '#';
        }
    }
    else
    {
        for(i = West; i < East; i++)
        {
            board[i][SideRand] = '#';
        }
        for(i = 81; i > SideRand ; i--)
        {
            board[East][i] = '#';
        }
    }
    board[2][North+1] = 'M';
    board[3][North+1] = 'C';


    //print board
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {

            if(board[i][j] == '%')
            {
                printf(BLK "%c", board[i][j]);
            }
            else if(board[i][j] == '.')
            {
                printf(GRN "%c", board[i][j]);
            }
            else if(board[i][j] == 'N' || board[i][j] == 'E' || board[i][j] == 'S' || board[i][j] == 'W')
            {
                printf(RED "%c", board[i][j]);
            }
            else if(board[i][j] == '#')
            {
                printf(WHT "%c", board[i][j]);
            }
            else if(board[i][j] == '"')
            {
                printf(MAG "%c", board[i][j]);
            }
            else if(board[i][j] == ',')
            {
                printf(CYN "%c", board[i][j]);
            }
            else if(board[i][j] == 'M')
            {
                printf(RED "%c", board[i][j]);
            }
            else if(board[i][j] == 'C')
            {
                printf(YEL "%c", board[i][j]);
            }


        }
        printf("\n");

    }

}



int main(int argc, char *argv[])
{

    print_world();
    return 0;
}
