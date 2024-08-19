#include "player.h"

static void init(Player *self, const char *name, unsigned char flag);

const PlayerFuc_t PlayerFuc = {
    .init = init,
 };
static void init(Player *self, const char *name, unsigned char flag)
{

    self->piece_queue = Queue_Fuc.createQueue();
    self->name = name;
    self->flag = flag;
}
