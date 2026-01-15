#include "tictactoe.h"
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <time.h>
static void PlayerRound(Tictactoe *self, Player player);

static void ComputerRound(Tictactoe *self, Player player);

static void init(Tictactoe *self);
static void start_play(Tictactoe *self);
static void get_input(Coord *coord);

const TictactoeFuc_t TictactoeFuc = {
    .init = init,
    .start_play = start_play,
};

static void init(Tictactoe *self) {

  ChessboardFuc.init(&self->Chessboard);

  char selection = 0;
  printf("Welcome Tictactoe Game\n");
  printf("Please Select Game Mode\n");
  printf("[0] Play with Computer\n");
  printf("[1] Play with Your Partner\n");
  scanf("%c", &selection);
  switch (selection) {
  case '0':
    self->Mode = SINGLE_PLAYER;
    PlayerFuc.init(&self->Player[0], "Player", 'A');
    PlayerFuc.init(&self->Player[1], "Computer", 'B');
    break;
  case '1':
    self->Mode = DOUBLE_PLAYER;
    PlayerFuc.init(&self->Player[0], "Player1", 'A');
    PlayerFuc.init(&self->Player[1], "Player2", 'B');
    break;
  default:
    printf("error no this selection\n");
    break;
  }
}

static void start_play(Tictactoe *self) {
  while (true) {
    unsigned char winner;

    // Player 1 Round
    PlayerRound(self, self->Player[0]);
    winner = ChessboardFuc.is_win(&self->Chessboard);
    if (winner != 'C') {
      goto end_game;
    }

    // Player 2 or Computer Round
    if (self->Mode == SINGLE_PLAYER) {
      ComputerRound(self, self->Player[1]);
    } else {
      PlayerRound(self, self->Player[1]);
    }

    winner = ChessboardFuc.is_win(&self->Chessboard);
    if (winner != 'C') {
      goto end_game;
    }
    continue;

  end_game:
    if (winner == self->Player[0].flag) {
      printf("Winner is %s\n", self->Player[0].name);
    } else if (winner == self->Player[1].flag) {
      printf("Winner is %s\n", self->Player[1].name);
    } else if (winner == 'D') // Assuming 'D' for Draw in the future, currently
                              // 'C' is continue
    {
      printf("It's a draw!\n");
    } else {
      printf("ERROR: winner==%c\n", winner);
    }
    break;
  }
}

static void PlayerRound(Tictactoe *self, Player player) {
  Coord tmp = {0, 0};
  printf("%s Round\n", player.name);
  get_input(&tmp);
  while (!ChessboardFuc.set_pieces(&self->Chessboard, player, tmp)) {
    printf("This location already have piece\n");
    get_input(&tmp);
  }
  ChessboardFuc.show((&self->Chessboard));
}

static void ComputerRound(Tictactoe *self, Player player) {
  printf("%s Round\n", player.name);
  static bool seeded = false;
  if (!seeded) {
    srand((unsigned)time(NULL));
    seeded = true;
  }
  Coord tmp = {(unsigned char)rand() % 3, (unsigned char)rand() % 3};
  while (!ChessboardFuc.set_pieces(&self->Chessboard, player, tmp)) {
    tmp.x = (unsigned char)rand() % 3;
    tmp.y = (unsigned char)rand() % 3;
  }
  ChessboardFuc.show((&self->Chessboard));
}

static void get_input(Coord *coord) {
  unsigned int x, y;
  printf("Input your location such as \"x,y\"\n");
  if (scanf("%u,%u", &x, &y) != 2) {
    printf("Invalid input format. Please use x,y (e.g., 1,1)\n");
    // Clear buffer
    while (getchar() != '\n')
      ;
    return;
  }
  coord->x = (unsigned char)x;
  coord->y = (unsigned char)y;
}