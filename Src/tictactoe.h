#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

#include "player.h"
#include "chessboard.h"

typedef enum {
    SINGLE_PLAYER=0,
    DOUBLE_PLAYER
}GameMode;

typedef struct Tictactoe
{
    Player Player[2];
    Chessboard Chessboard;
    GameMode Mode;
} Tictactoe;

typedef struct TictactoeFuc_t
{
    void (*init)(Tictactoe *self);
    void (*start_play)(Tictactoe *self);
} TictactoeFuc_t;

extern const TictactoeFuc_t TictactoeFuc;
#endif
