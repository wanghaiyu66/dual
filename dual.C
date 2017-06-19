#include <iostream>
#include "duallib.h"
using namespace std;

int main()
{
    Footman footman1, footman2;
    Player* player1, *player2;
    /* Choose player type here*/
    player1 =  &footman1;
    player2 =  &footman2;
    /**************************/

    //player1->attack( *player2 );       
    //player2->attack( *player1 );
    //player1->survivalState();
    //player2->survivalState();
    Colosseo col( *player1, *player2);
    col.fight();
    return 0;
}