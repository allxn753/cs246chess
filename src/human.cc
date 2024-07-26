#include "human.h"
#include "helpers.h"

Human::Human(string playerColour, Game* game) : Player{playerColour, game}{}

void Human::makeMove() const {

    string command, arg1, arg2;

    while(cin >> command) {
        if (command == "move") {
            // move pieces on the board
            cin >> arg1 >> arg2; // >> piece; // start end promotion (e7 e8 Q)
            if(game->validMove(arg1, arg2)) {
                // Is player in check after move
                Piece * p1 = game->getBoard()->getPiece(arg1);
                Piece * p2 = game->getBoard()->getPiece(arg2);
                if (p2->getChar() != ' ' && p2->getChar() != '_') {
                    p2->move(-1, -1); // "store" p2 on an unused tile
                }
                // Look ahead
                p1->move(arg2);
                game->updateCheck();
                p1->move(arg1);
                p2->move(arg2);
                if (game->getCheck()) {
                    game->updateCheck();
                    cout << "Invalid move: Move causes player to be in check" << endl;
                    break;
                }
                game->updateCheck();
                game->performMove(arg1, arg2);
                break;   
            } else {
                cout << "Invalid Move" << endl;
            }
        } else if (command == "resign") {
            game->resign();
            cout << "Player Resigned" << endl;
            game->getBoard()->display();
            break;    
        } else {cout << "Invalid command: 3" << endl;}
    }
}