#include "game.h"
#include "helpers.h"
#include "player.h"

Game::Game(Board* brd): theBoard{brd}{}

bool Game::validMove(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);
    if (coord1[0] < 0 || coord1[0] >= Board::WIDTH || coord1[1] < 0 || coord1[1] >= Board::HEIGHT ||
        coord2[0] < 0 || coord2[0] >= Board::WIDTH || coord2[1] < 0 || coord2[1] >= Board::HEIGHT) return false; // return false if out of bounds of the board
    if (coord1 == coord2) return false; // no piece can move onto itself
    char activePiece = theBoard->getPiece(coord1[0], coord1[1])->getChar();
    char destination = theBoard->getPiece(coord2[0], coord2[1])->getChar();

    if (activePiece == ' ' || activePiece == '_') return false; // return false if there is no piece at the start
    if (state == WHITE_TURN && !isupper(activePiece)) return false; // can only move pieces on their turn
    if (state == BLACK_TURN && isupper(activePiece)) return false;
    if (destination != ' ' && destination != '_') {
        if (isupper(activePiece) == isupper(destination)) return false; // false if there are two of the same colour pieces
    }
    int dX = coord2[0] - coord1[0];
    int dY = coord2[1] - coord1[1];
    switch (tolower(activePiece)) {
        case 'k':
            // cerr << "King Move" << endl;
            if (!theBoard->getPiece(coord1[0], coord1[1])->getHasMoved()) {
                if (dY == 0) {
                    if (dX == 2) {
                        if (!theBoard->getPiece(coord1[0], 7)->getHasMoved() && tolower(theBoard->getPiece(7, coord1[1])->getChar()) == 'r' &&
                            !isPathObstructed(coord1, 7 - coord1[0], dY) && !checked) return true;
                    } else if (dX == -2) {
                        if (!theBoard->getPiece(coord1[0], 0)->getHasMoved() && tolower(theBoard->getPiece(0, coord1[1])->getChar()) == 'r' &&
                            !isPathObstructed(coord1, 0 - coord1[0], dY) && !checked) return true;
                    }
                }
            }
            if (coord2[0] > coord1[0] + 1 || coord2[0] < coord1[0] - 1 ||
                coord2[1] > coord1[1] + 1 || coord2[1] < coord1[1] - 1) return false;            
            return true;

        case 'q':
            // cerr << "Queen Move" << endl;
            if (dX != 0 && dY != 0) {
                if (abs(dX) != abs(dY)) return false;
            }
            if (isPathObstructed(coord1, dX, dY)) return false;
            return true;        

        case 'r':
            // cerr << "Rook Move" << endl;
            if (dX != 0 && dY != 0) return false;
            if (isPathObstructed(coord1, dX, dY)) return false;
            return true;

        case 'b':
            // cerr << "Bishop Move" << endl;
            if (abs(dX) != abs(dY)) return false;
            if (isPathObstructed(coord1, dX, dY)) return false;
            return true;

        case 'n':
            // cerr << "Knight Move" << endl;
            if ((abs(dX) == 2 && abs(dY) == 1) || (abs(dX) == 1 && abs(dY) == 2)) return true;
            return false;

        case 'p':
            // cerr << "Pawn Move" << endl;
            int yMult;
            if (isupper(activePiece)) yMult = 1;
            else yMult = -1;

            if (!theBoard->getPiece(coord1[0], coord1[1])->getHasMoved()) {
                if (dY != 1 * yMult && dY != 2 * yMult) return false;
            } else if (dY != 1 * yMult) return false;
            if (abs(dX > 1)) return false;
            if (dX != 0 && abs(dY) != 1) return false;
            if (isPathObstructed(coord1, dX, dY)) return false;

            if (dX == 0 && destination != ' ' && destination != '_') return false;
            if (dX != 0 && (destination == ' ' || destination == '_') &&
                theBoard->getPiece(coord2[0], coord2[1])->getEnPassant() != coord2) return false;
            return true;
    }
    return false;
}

bool Game::isPathObstructed(vector<int> coord1, int dX, int dY) {
    int xMult;
    int yMult;
    
    if (dX > 0) xMult = 1;
    else xMult = -1;
    
    if (dY > 0) yMult = 1;
    else yMult = -1;

    if (dX == 0) {
        for (int i = 1; i < abs(dY); i++) {    
            if (theBoard->getPiece(coord1[0], coord1[1] + i * yMult)->getChar() != ' ' &&
                theBoard->getPiece(coord1[0], coord1[1] + i * yMult)->getChar() != '_') return true;
        }
    } else if (dY == 0) {
        for (int i = 1; i < abs(dX); i++) {
            if (theBoard->getPiece(coord1[0] + i * xMult, coord1[1])->getChar() != ' ' &&
                theBoard->getPiece(coord1[0] + i * xMult, coord1[1])->getChar() != '_') return true;
        }
    } else {
        for (int i = 1; i < abs(dX); i++) {
            if (theBoard->getPiece(coord1[0] + i * xMult, coord1[1] + i * yMult)->getChar() != ' ' &&
                theBoard->getPiece(coord1[0] + i * xMult, coord1[1] + i * yMult)->getChar() != '_') return true;
        }
    }

    return false;
}

// validMoves(string start) returns a list of valid moves for the piece at start.
vector<string> Game::validMoves(string start) {
    vector<string> moves;
    string to;
    for (int i = 0; i < Board::WIDTH; ++i) {
        for (int j = 0; j < Board::HEIGHT; ++j) {
            to = convertPosition(i,j);
            if (validMove(start, to)) moves.emplace_back(to);
        }
    }
    return moves;
} // validMoves()


void Game::updateCheckmate() {
    if (checked == false) {checkmated = false; return;} // King must be threatened and no escape moves.
    string original_pos, from, to;
    vector<string> moves;
    Decorator* p;
    for (int i = theBoard->getArr().size() - 1; i >= 0; --i) { // For each piece (iterating backwards)
        p = theBoard->getArr()[i];
        original_pos = convertPosition(p->getX(), p->getY());
        moves = validMoves(original_pos);
        for (auto m: moves) { // Lookahead every move for given piece
            p->move(m);
            updateCheck();
            if (!checked) { // Found check-exiting move.
                p->move(original_pos); // move pieces back.
                checked = true; // reset check back to original value.
                checkmated = false;
                return;
            }
        }
        p->move(original_pos);
    }
    checked = true;
    checkmated = true;
} // updateCheckmate()


void Game::updateCheck() {
    char king;
    string pos;
    Decorator * curr;
    if (state == WHITE_TURN) king = 'K';
    else if (state == BLACK_TURN) king = 'k';
    for(unsigned int i = 0; i < theBoard->arr.size(); ++i) {
        curr = theBoard->arr[i];
        if(curr->getChar() == king) { // found king
            pos = convertPosition(curr->getX(), curr->getY());
            nextTurn(); // Have to swap the turn to the other player because otherwise no moves would be valid anyway.
            checked = isThreatened(pos);
            nextTurn(); // Swap player back. Only works for 2 player game.
        } // found king
    } // for
} // updateCheck()


// isThreatened(): 
// Checks if there are any piececs threatening pos.
// Slightly more efficient than just iterating over entire board. 64 vs. ~30 comparisons.
bool Game::isThreatened(string pos) { 
    vector<int> coord = convertPosition(pos);
    string from;    
    for(int i = 0; i < Board::WIDTH; ++i) { // check within row
        from = convertPosition(i, coord[1]);
        if(from != pos && validMove(from,pos)) return true;
    }
    for(int j = 0; j < Board::HEIGHT; ++j) { // check within column
        from = convertPosition(coord[0], j);
        if(from != pos && validMove(from,pos)) return true;
    }
    for(int k = 0; k < Board::HEIGHT; ++k) { // check positive diag
        int diag = coord[0] - coord[1];
        from = convertPosition(diag + k, k);
        if((diag >= k) && (diag + k < Board::WIDTH) && (from != pos) && validMove(from,pos)) return true;
    }
    for(int k = 0; k < Board::WIDTH; ++k) { // check negative diag
        from = convertPosition(k, coord[0] + coord[1] - k);
        if((coord[0] + coord[1] > k) && (coord[0] + coord[1] - k < Board::HEIGHT) && (from != pos) && validMove(from,pos)) return true;
    }
    // knight's moves away
    vector<vector<int>> knightMoves = vector{vector{1, 2}, vector{1, -2}, vector{-1, 2}, vector{-1, -2}};
    for (auto move: knightMoves) {
        if(validMove(convertPosition(coord[0] + move[0], coord[1] + move[1]), pos)) return true;
        if(validMove(convertPosition(coord[0] + move[1], coord[1] + move[0]), pos)) return true;
    }
    return false;
} // isThreatened(): 

int Game::isCastling(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);
    int dX = coord2[0] - coord1[0];
    int dY = coord2[1] - coord1[1];
    if (dY == 0 && abs(dX) == 2 && tolower(theBoard->getChar(coord1[0], coord1[1])) == 'k') {
        cerr << "Castling" << endl;
        if (dX > 0) return 1;
        if (dX < 0) return -1;
    }    
    return 0;
}

int Game::isEnPassant(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);
    int dY = coord2[1] - coord1[1];
    if (tolower(theBoard->getChar(coord1[0], coord1[1])) == 'p' &&
        theBoard->getPiece(coord2[0], coord2[1])->getEnPassant() == coord2) {
            if (dY > 0) return 1; // White
            if (dY < 0) return -1; // Black
        }
    return 0;
}

int Game::isSkipping(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);
    int dY = coord2[1] - coord1[1];
    if (abs(dY) == 2 && tolower(theBoard->getChar(coord1[0], coord1[1])) == 'p') {
        if (dY > 0) return 1; // White
        if (dY < 0) return -1; // Black
    }
    return 0;
}


bool Game::isPromoting(string pos1, string pos2) {
    vector<int> coord1 = convertPosition(pos1);
    vector<int> coord2 = convertPosition(pos2);    
    if (theBoard->getChar(coord1[0], coord1[1]) == 'P' && (coord2[1] == 7)) return true;
    if (theBoard->getChar(coord1[0], coord1[1]) == 'p' && (coord2[1] == 0)) return true;
    return false;
}

void Game::nextTurn() {
    if (state == WHITE_TURN) state = BLACK_TURN;
    else if (state == BLACK_TURN) state = WHITE_TURN;
}

bool Game::validSetup() {
    // Exactly one white and one black king
    bool seenWhiteKing = false;
    bool seenBlackKing = false;
    for (auto p: theBoard->getArr()) {
        if (p->getChar() == 'K' && seenWhiteKing) return false; // cerr << "Invalid setup: multiple white kings"<< endl;
        if (p->getChar() == 'k' && seenBlackKing) return false; // cerr << "Invalid setup: multiple black kings"<< endl;
        if (p->getChar() == 'K') seenWhiteKing = true;
        if (p->getChar() == 'k') seenBlackKing = true;
    }
    if (!seenWhiteKing || !seenBlackKing) return false;
    // No pawns on last rows.
    for (int i = 0; i < Board::WIDTH; ++i) {
        if (tolower(theBoard->getChar(i, 0) == 'p')) return false; // cerr << "Invalid setup: missing white king"<< endl;
        if (tolower(theBoard->getChar(i, Board::HEIGHT - 1) == 'p')) return false; // cerr << "Invalid setup: missing white king"<< endl; 
    }
    // Not in check.
    updateCheck();
    if (checked) {return false;}
    nextTurn(); // See if other player is in check
    updateCheck();
    nextTurn();
    if (checked) {return false;}
    return true;
}

void Game::setState(string cmd) {
    if (cmd == "white") state = WHITE_TURN;
    else if (cmd == "black") state = BLACK_TURN;
    else if (cmd == "end") state = GAME_END;
    else if (cmd == "setup") state = SETUP;
}

// Makes current player resign.
void Game::resign() {
    resigned = true;
}

void Game::updateStalemate() {
    stalemated = false;
}

void Game::updateScore(Player* white, Player* black) {    
    if ((resigned || checkmated) &&  state == Game::WHITE_TURN) black->addScore(1); 
    if ((resigned || checkmated) &&  state == Game::BLACK_TURN) white->addScore(1);
    if (stalemated) {white->addScore(0.5); black->addScore(0.5);}
}


string Game::whoseTurn() {
    if (state == WHITE_TURN) return "white";
    else if (state == BLACK_TURN) return "black";
    else return "Invalid Turn";
}


void Game::updateGame(Player* white, Player* black) {
    bool whiteTurn = (state == Game::WHITE_TURN);
    updateCheck();
    updateCheckmate();
    updateStalemate();
    updateScore(white, black);
    if(resigned || checkmated) {
        if (checkmated) {
            std::cout << "Checkmate! ";
        }
        if (whiteTurn) std::cout << "Black";
        else std::cout << "White";
        std::cout << " wins!" << endl;
        state = GAME_END;
    } else if (stalemated) {
        std::cout << "Stalemate!" << endl;
        state = GAME_END;
    }  else if (checked) {
        if (whiteTurn) std::cout << "White";
        else std::cout << "Black";
        std::cout << " is in check." << endl;
    }
}

void Game::performMove(string arg1, string arg2, char promo) {
    if (isCastling(arg1, arg2) == 1) {
        string arg3 = arg1;
        arg3[0] = 'h';
        Piece* r = getBoard()->getPiece(arg3);
        arg3[0] = arg1[0] + 1;
        r->move(arg3);
    } else if (isCastling(arg1, arg2) == -1) {
        string arg3 = arg1;
        arg3[0] = 'a';
        Piece* r = getBoard()->getPiece(arg3);
        arg3[0] = arg1[0] - 1;
        r->move(arg3);
    }
    if (isEnPassant(arg1, arg2) == 1) {
        string arg3 = arg2;
        arg3[1] = arg2[1] - 1;
        getBoard()->removePiece(arg3);
    }
    else if (isEnPassant(arg1, arg2) == -1) {
        string arg3 = arg2;
        arg3[1] = arg2[1] + 1;
        getBoard()->removePiece(arg3);
    }
    getBoard()->getArr()[0]->setEnPassant({8, 8});
    if (isSkipping(arg1, arg2) == 1) {
        string arg3 = arg1;
        arg3[1] = arg1[1] + 1;
        getBoard()->getPiece(arg3)->setEnPassant(convertPosition(arg3));
    } else if (isSkipping(arg1, arg2) == -1) {
        string arg3 = arg1;
        arg3[1] = arg1[1] - 1;
        getBoard()->getPiece(arg3)->setEnPassant(convertPosition(arg3));
    }
    if (isPromoting(arg1, arg2)) {        
        if (promo == 'q' || promo == 'r'|| promo == 'b' || promo == 'n') { // for computer players
            getBoard()->removePiece(arg2);
                if (isupper(getBoard()->getPiece(arg1)->getChar())) {
                    getBoard()->addPiece(toupper(promo), arg2);
                } else {
                    getBoard()->addPiece(promo, arg2);
                }
            getBoard()->removePiece(arg1);
        } else {
            while (cin >> promo) {
                cout << "Pawn promotion! Choose a piece: (q, r, b, n)" << endl;
                promo = tolower(promo);
                if (promo != 'q' && promo != 'r' && promo != 'b' && promo != 'n') {
                    cout << "Invalid promotion" << endl;
                } else {
                    getBoard()->removePiece(arg2);
                    if (isupper(getBoard()->getPiece(arg1)->getChar())) {
                        getBoard()->addPiece(toupper(promo), arg2);
                    } else {
                        getBoard()->addPiece(promo, arg2);
                    }
                getBoard()->removePiece(arg1);
                }
            } // while
        }       
    } else {
        Piece* p = getBoard()->getPiece(arg1);
        getBoard()->removePiece(arg2);
        p->move(arg2);
    }
    nextTurn();  
    getBoard()->display(); 
}

void Game::gameLoop(Player* white, Player* black) {
    theBoard->display();
    while(getState() != GAME_END) {
        if (getState() == WHITE_TURN) {
            white->makeMove();
        }
        else if (getState() == BLACK_TURN) {
            black->makeMove();
        }
        updateGame(white, black);
    }    
}

void Game::reset(bool blank) {
    state = WHITE_TURN;
    checked = false;
    checkmated = false;
    stalemated = false;
    theBoard->wipe();
    if(blank) return;
    // Speeds up isInCheck();
    theBoard->addPiece('K', "e1");
    theBoard->addPiece('k', "e8");
    // Kings guarenteed to not be deleted.
    theBoard->addPiece('R', "a1");
    theBoard->addPiece('N', "b1");
    theBoard->addPiece('B', "c1");
    theBoard->addPiece('Q', "d1");    
    theBoard->addPiece('B', "f1");
    theBoard->addPiece('N', "g1");
    theBoard->addPiece('R', "h1");
    theBoard->addPiece('P', "a2");
    theBoard->addPiece('P', "b2");
    theBoard->addPiece('P', "c2");
    theBoard->addPiece('P', "d2");
    theBoard->addPiece('P', "e2");
    theBoard->addPiece('P', "f2");
    theBoard->addPiece('P', "g2");
    theBoard->addPiece('P', "h2");
    theBoard->addPiece('r', "a8");
    theBoard->addPiece('n', "b8");
    theBoard->addPiece('b', "c8");
    theBoard->addPiece('q', "d8");    
    theBoard->addPiece('b', "f8");
    theBoard->addPiece('n', "g8");
    theBoard->addPiece('r', "h8");
    theBoard->addPiece('p', "a7");
    theBoard->addPiece('p', "b7");
    theBoard->addPiece('p', "c7");
    theBoard->addPiece('p', "d7");
    theBoard->addPiece('p', "e7");
    theBoard->addPiece('p', "f7");
    theBoard->addPiece('p', "g7");
    theBoard->addPiece('p', "h7");
}

Game::~Game() {delete theBoard;}

