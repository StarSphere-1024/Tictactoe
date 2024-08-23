#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "queue.h"
#define NULL_FLAG ' '


typedef struct Player
{
    const char *name;
    unsigned char flag;
    Queue *piece_queue;
}Player;


typedef struct PlayerFuc_t
{
    void (*init)(Player *self, const char *name, unsigned char flag);
}PlayerFuc_t;

extern const PlayerFuc_t PlayerFuc;

#endif