#include <iostream>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


class Player
{
public:
    Player()
    {
        cout << "Input player's name within 10 charaters!" << endl;
        cin  >> playerName;
        HP = 100;
        cout << "Player " << playerName << " is ready! " << "With full health: " << HP << endl;
    };
    
    int survivalState()
    {
        if ( HP<=0 )
        {
            //cout << "Player is dead" << endl;
            return (0);
        }
        else
        {
            //cout << "HP: " << getHP() << ". Continue..." << endl;
            return (1);
        }
    }

    int getHP()
    {
        return HP;
    }

    string getName()
    {
        return playerName;
    }

    virtual int attackAbility(){}

    virtual int attack( Player& enemy ){}

    virtual int defenceAbility() {}

    virtual int defence( int enemy_attackAbility ){ cout<<"defence in Player"<< endl;}

protected:
    int HP;
    string playerName;
    //~Player();
  
};

class Footman : public Player
{
public:
    Footman()
    {
        cout << "I am a footman!" << endl;
    };
    
    int attackAbility()
    {
        return 10;
    }

    int attack( Player& enemy )
    {
        cout << "attackAbility: " << attackAbility() << endl;
        enemy.defence(attackAbility());
    }

    int defenceAbility()
    {
        return 1;
    }

    int defence( int enemy_attackAbility )
    {
        int realDamage = (enemy_attackAbility-defenceAbility());
        HP = HP - realDamage;
        cout << "real damage: " << realDamage << endl;
    }
    //~Footman();
    
};

class Colosseo 
{
public:
    Colosseo( Player& p1, Player& p2 )
    {
        player1 = &p1;
        player2 = &p2;
        cout << "Players are entering the Colosseo!" << endl;
        //#include "colosseoGreeting.h"

        sleep_until(system_clock::now() + seconds(5));
    };

    void survivalState( Player player )
    {
        if ( !player.survivalState() )
        {
            cout << "Player " << player.getName() << " is dead!" << endl;
        }
        else
        {
            cout << "HP: " << player.getHP() << ". Continue..." << endl;
        }
    }

    void fight()
    {
        while( player1->survivalState()==1 && player2->survivalState()==1 )
        {
            player1->attack( *player2 );
            player2->attack( *player1 );
            survivalState( *player1 )  ;
            survivalState( *player2 )  ;

            sleep_until(system_clock::now() + seconds(1));
        }
    }

protected:
    Player* player1; Player* player2;
    //~Colosseo();
    
};