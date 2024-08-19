#include "piece.h"
#include <stdbool.h>

static void init(Piece *self, unsigned char flag, Coord location);

const PieceFuc_t PieceFuc = {
    .init = init
};

static void init(Piece *self, unsigned char flag, Coord location)
{
    self->will_del = false;
    self->flag = flag;
    self->location.x = location.x;
    self->location.y = location.y;
}
