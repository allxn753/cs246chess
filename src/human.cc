#include "human.h"
#include "helpers.h"

Human::Human(string playerColour, Game* game) : Player{playerColour, game}{}

void Human::makeMove() const {

    string command, arg1, arg2;

    while(cin >> command) {

        if (command == "move") {
            // move pieces on the board
            cin >> arg1 >> arg2;
            if(game->validMove(arg1, arg2)) {
                if (game->isCastling(arg1, arg2) == 1) {
                    string arg3 = arg1;
                    arg3[0] = 'h';
                    Piece* r = game->getBoard()->getPiece(arg3);
                    arg3[0] = arg1[0] + 1;
                    r->move(arg3);
                } else if (game->isCastling(arg1, arg2) == -1) {
                    string arg3 = arg1;
                    arg3[0] = 'a';
                    Piece* r = game->getBoard()->getPiece(arg3);
                    arg3[0] = arg1[0] - 1;
                    r->move(arg3);
                }
                if (game->isEnPassant(arg1, arg2) == 1) {
                    string arg3 = arg2;
                    arg3[1] = arg2[1] - 1;
                    game->getBoard()->removePiece(arg3);
                }
                else if (game->isEnPassant(arg1, arg2) == -1) {
                    string arg3 = arg2;
                    arg3[1] = arg2[1] + 1;
                    game->getBoard()->removePiece(arg3);
                }
                game->getBoard()->getArr()[0]->setEnPassant({8, 8});
                if (game->isSkipping(arg1, arg2) == 1) {
                    string arg3 = arg1;
                    arg3[1] = arg1[1] + 1;
                    game->getBoard()->getPiece(arg3)->setEnPassant(convertPosition(arg3));
                } else if (game->isSkipping(arg1, arg2) == -1) {
                    string arg3 = arg1;
                    arg3[1] = arg1[1] - 1;
                    game->getBoard()->getPiece(arg3)->setEnPassant(convertPosition(arg3));
                }
                if (game->isPromoting(arg1, arg2)) {
                    cout << "Pawn promotion! Choose a piece: (q, r, b, n)" << endl;
                    char promo;
                    while (cin >> promo) {
                        promo = tolower(promo);
                        if (promo != 'q' && promo != 'r' && promo != 'b' && promo != 'n') {
                        cout << "Invalid promotion" << endl;
                        } else {
                        game->getBoard()->removePiece(arg2);
                        if (isupper(game->getBoard()->getPiece(arg1)->getChar())) {
                            game->getBoard()->addPiece(toupper(promo), arg2);
                        } else {
                            game->getBoard()->addPiece(promo, arg2);
                        }
                        game->getBoard()->removePiece(arg1);
                        break;
                        }
                    }
                    } else {
                        Piece* p = game->getBoard()->getPiece(arg1);
                        game->getBoard()->removePiece(arg2);
                        p->move(arg2);
                    }

                game->nextTurn();
                game->getBoard()->display();
                game->updateCheck();
                break;

            } else {cout << "Invalid command" << endl;}
        }

        else if (command == "threat") {
            cin >> arg1;
            cerr << arg1 << " threatened: " << game->isThreatened(arg1) << endl;
            game->getBoard()->display();
        }

        else if (command == "resign") {
            game->end();
            if (game->whoseTurn() == "white") {
                cout << "Resignation! Black wins!" << endl;
            } else {
                cout << "Resignation! White wins!" << endl;
            }
        }
    }
}