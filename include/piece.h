#ifndef __PIECE_H__
#define __PIECE_H__

#include<stdbool.h>

typedef struct
{
    unsigned char x, y;
} Coord;

typedef struct Piece
{
    unsigned char flag;
    Coord location;
    bool will_del;
} Piece;

typedef struct PieceFuc_t
{
    void (*init)(Piece *self,unsigned char flag,Coord location);
} PieceFuc_t;

extern const PieceFuc_t PieceFuc;
#endif
