#include "tictactoe.h"

int main(){

    Tictactoe tictactoe;
    TictactoeFuc.init(&tictactoe);
    while（ture）{
        uint8_t selection=0;
        TictactoeFuc.start_play(&tictactoe);
        printf("[0] Play again\n[1] exit\n");
        scanf("%d",selection);
        if(selection){
            break;
        }
    }

    return 0;
}