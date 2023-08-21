#include <gb/gb.h>
#include <stdint.h>
#include "sprites/PH_Player.c"

void main(void)
{
    SPRITES_8x16;
	set_sprite_data(0, 8, PH_Player);
	set_sprite_tile(0, 0);
	move_sprite(0, 75, 75);
	SHOW_SPRITES;
    set_sprite_tile(1, 2);
    move_sprite(1, 75 + 8, 75);

    // Loop forever
    while(1) {


        wait_vbl_done();
    }
}
