#include "chessboard.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"

static void init(Chessboard *self);

static bool set_pieces(Chessboard *self, Player player, Coord location);


static unsigned char is_win(Chessboard *self);

void ShowChessBoard(Chessboard *board);

const ChessboardFuc_t ChessboardFuc = {
    .init = init,
    .set_pieces = set_pieces,
    .is_win = is_win,
    .show = ShowChessBoard};

void init(Chessboard *self)
{
    memset(self->data, ' ', 9);
}

static bool set_pieces(Chessboard *self, Player player, Coord location)
{
    if (self->data[location.x][location.y] != NULL_FLAG)
    {
        return false;
    }
    if (Queue_Fuc.size(player.piece_queue) > 3)
    {
        Piece *qfront = Queue_Fuc.pop(player.piece_queue);
        self->data[qfront->location.x][qfront->location.y] = NULL_FLAG;
        free(qfront);
    }
    Piece piece;
    PieceFuc.init(&piece, player.flag, location);
    Queue_Fuc.append(player.piece_queue, &piece, sizeof(piece));
    self->data[location.x][location.y] = player.flag;
    return true;
}



static unsigned char is_win(Chessboard *self)
{
    for (int i = 0; i < 3; i++)
    {
        if (self->data[i][0] == self->data[i][1] && self->data[i][1] == self->data[i][2] && self->data[i][1] != NULL_FLAG)
        {
            return self->data[i][1];
        }
    }
    // 三列
    for (int i = 0; i < 3; i++)
    {
        if (self->data[0][i] == self->data[1][i] && self->data[1][i] == self->data[2][i] && self->data[1][i] != NULL_FLAG)
        {
            return self->data[1][i];
        }
    }
    // 对角线相同
    if (self->data[0][0] == self->data[1][1] && self->data[1][1] == self->data[2][2] && self->data[1][1] != NULL_FLAG)
    {
        return self->data[1][1];
    }
    if (self->data[0][2] == self->data[1][1] && self->data[1][1] == self->data[2][0] && self->data[1][1] != NULL_FLAG)
    {
        return self->data[1][1];
    }

    // 继续
    return 'C';
}

void ShowChessBoard(Chessboard *board)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        // 数据
        for (j = 0; j < 3; j++)
        {
            printf(" %c ", board->data[i][j]);
            if (j < 3 - 1)
                printf("|");
        }
        printf("\n");
        // 分割行
        if (i < 3 - 1) // 第三行数据不用打印分割行
        {
            for (j = 0; j < 3; j++)
            {
                printf("---");
                if (j < 3 - 1)
                    printf("|");
            }
            printf("\n");
        }
    }
}