#include <gb/gb.h>
#include <stdint.h>
#include "sprites/PH_Player.c"
#include "sprites/Projectile.c"


void main(void)
{

	//Player Coords
    uint8_t joydata;
	UINT8 player[2];
	player[0] = 55;
	player[1] = 75;

	//Define projectiles (max 3) Sprites 4,5,6
	UINT8 proj1[2] = {-8 , -8};
	UINT8 proj3[2] = {-8 , -8};
	UINT8 proj2[2] = {-8 , -8};


	//Set Sprite Mode
    SPRITES_8x8;
	//Create Player Sprites in Memory, 2x2 array of 8x8 Sprites
	set_sprite_data(0, 4, PH_Player);
	set_sprite_tile(0, 0);
	move_sprite(0, player[0], player[1]);
    set_sprite_tile(1, 2);
    move_sprite(1, player[0] + 8, player[1]);
	set_sprite_tile(2,1);
	move_sprite(2, player[0], player[1] +8);
	set_sprite_tile(3,3);
	move_sprite(3,player[0]+8,player[1]+8);
	//Create Projectile Sprites in Memory
	set_sprite_data(4,1, Projectile);
	set_sprite_tile(4,4);
	set_sprite_tile(5,4);
	set_sprite_tile(6,4);

	SHOW_SPRITES;
    // Loop forever
    while(1) {


    joydata = joypad(); // Read once per frame and cache the result
	if(joydata & J_A) {


		move_sprite(4,player[0]+16,player[1]+8);
		}
		// if() {

		// }
		scroll_sprite(4, 1, 0);

	//Define Movement
    if (joydata & J_RIGHT) // If RIGHT is pressed
		{
			if(player[0] + 16 < 168) {
			player[0]++;
			}}
    if (joydata & J_LEFT)  // If LEFT is pressed
		{
			if(player[0]>8){
			player[0]--;
			}}
	if (joydata & J_UP)  // If UP is pressed
		{ 
			if(player[1]>16){
			player[1]--;
			}}
	if (joydata & J_DOWN)  // If DOWN is pressed
		{ if(player[1]+8<152){
			player[1]++;		
			}}
		move_sprite(0,player[0],player[1]);
		move_sprite(1, player[0] + 8, player[1]);
		move_sprite(2, player[0], player[1] + 8);
		move_sprite(3, player[0] + 8, player[1] + 8);
		//END MOVEMENT DEFINITION
        wait_vbl_done();
    }
}