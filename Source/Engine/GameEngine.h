#ifndef GameEngine_h
#define GameEngine_h
#include <iostream>
using namespace std;

//game state
enum GameState
{
    GAME_STATE_UNKNOWN=0,
    GAME_STATE_START=1,
    GAME_STATE_MAP_LOAD=2,
    GAME_STATE_MAP_VALIDATED=3,
    GAME_STATE_PLAYERS_ADDED=4,
    GAME_STATE_ASSIGN_REINFORCEMENT=5,
    GAME_STATE_ISSUE_ORDERS=6,
    GAME_STATE_EXECUTE_ORDERS=7,
    GAME_STATE_WIN=8,
    GAME_STATE_END=9,
    GAME_STATE_MAX=0XFFFF,//set a max value to prevent overflow
};

//GameEngine class
class GameEngine{
    public:

        //game state
        enum GameState
        {
            GAME_STATE_UNKNOWN = 0,
            GAME_STATE_START = 1,
            GAME_STATE_MAP_LOAD = 2,
            GAME_STATE_MAP_VALIDATED = 3,
            GAME_STATE_PLAYERS_ADDED = 4,
            GAME_STATE_ASSIGN_REINFORCEMENT = 5,
            GAME_STATE_ISSUE_ORDERS = 6,
            GAME_STATE_EXECUTE_ORDERS = 7,
            GAME_STATE_WIN = 8,
            GAME_STATE_END = 9,
            GAME_STATE_MAX = 0XFFFF,//set a max value to prevent overflow
        };

        //user input
        enum game_user_input {
            /*LOADMAP,*/
            VALIDATEMAP,
            ADDPLAYER,
            ASSIGNCOUNTRIES,
            ISSUEORDER,
            ENDEXECORDERS,
            EXECORDER,
            ENDISSUEORDERS,
            WIN,
            PLAY,
            END,
        }

        static const string LOADMAP = "LOADMAP";
        const string VALIDATEMAP = "VALIDATEMAP";
        const string ADDPLAYER = "ADDPLAYER";
        const string GAMESTART = "GAMESTART";
 




        GameEngine(); //constructor
        ~GameEngine(); //destructor
        GameEngine(const GameEngine &gm); //copy constructor
        GameState getCurrentState(); //getter
        void game_run();
        GameEngine &operator=(const GameEngine &obj);//Assignment operator
        friend ostream &operator<<(ostream &out, const GameState value);//stream insertion operator
    private:
        GameState* eState;
        void setCurrentState(GameState eState);//setter

};
#endif

