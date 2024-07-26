#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

class Player;

class Game {
    public:
        enum gameState {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
    private:
        Board* theBoard;
        gameState state;
        bool checked = false;
        bool checkmated = false;
        bool stalemated = false;
        bool resigned = false;
    public:        
        Game() {};
        Game(Board *);

        // Accessors Methods
        Board* getBoard() { return theBoard;}
        gameState getState() {return state;}
        bool getCheck() {return checked;}
        bool getCheckmated() {return checkmated;}
        bool getStalemated() {return stalemated;}
        bool getResigned() {return resigned;}
        string whoseTurn();

        // Field Mutator Methods
        void setState(string);
        void nextTurn();
        void reset(bool blank = false);
        bool validMove(string pos1, string pos2);
        void updateCheck();
        void updateCheckmate();
        void updateStalemate();
        void resign();

        // Game Loop Methods
        bool validSetup();        
        void updateScore(Player*, Player*);
        void updateGameState(Player*, Player*);

        // Move Methods
        bool isPathObstructed(vector<int> coord1, int dX, int dY);
        int isCastling(string pos1, string pos2);
        int isEnPassant(string pos1, string pos2);
        int isSkipping(string pos1, string pos2);
        bool isPromoting(string pos1, string pos2);
<<<<<<< HEAD
        bool isThreatened(string pos);     
=======
        bool isThreatened(string pos);
        bool validSetup();
        void nextTurn();
        void updateCheck();
        bool getCheck() {return check;}
        bool isCheckmate();
        void end();
        bool isStalemate();
        void gameLoop(Player* white, Player* black);
>>>>>>> 1c37304754a43d105ee7caf437e084914deb4f8c
        vector<string> validMoves(string start);
        
};

#endif
