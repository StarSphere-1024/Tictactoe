#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__

#include "player.h"
#include "piece.h"

typedef struct Chessboard
{
    unsigned char data[3][3];
}Chessboard;


typedef struct ChessboardFuc_t
{
    void (*init)(Chessboard *self);
    bool (*set_pieces)(Chessboard* self, Player player, Coord location);
    unsigned char (*is_win)(Chessboard* self);
    void (*show)(Chessboard* self);
    
}ChessboardFuc_t;

extern const ChessboardFuc_t ChessboardFuc;

#endif