#ifndef GameEngine_h
#define GameEngine_h
#include <iostream>

class Player;

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
//user input
enum game_user_input {
    LOADMAP,
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
};

//GameEngine class
class GameEngine{
    public:
        GameEngine(); //constructor
        ~GameEngine(); //destructor
        
        GameState getCurrentState(); //getter
        void game_run();

        // copy and assignment *should* be deleted since I'm implementing GameEngine as a singleton
        GameEngine(const GameEngine& gm); //copy constructor
        GameEngine &operator=(const GameEngine &obj);//Assignment operator

        Player* getNeutralPlayer() const;

        friend std::ostream &operator<<(std::ostream &out, const GameState value);//stream insertion operator

        static GameEngine& getInstance();
    private:
        GameState* eState;
        void setCurrentState(GameState eState);//setter
        Player* neutralPlayer = nullptr;

};
#endif

