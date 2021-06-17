/*
written by genericrandom64 and jammy3662
TODO pick license - unlicense?
*/

#include <clock.h>
#include <kbd.h>
#include <rect.h>
#include <graphics.h>

char press_slash[] = {
15,15,15,15,15,0 ,15,15,15,15,0 ,0 ,15,15,15,15,15,0 ,15,15,15,15,15,0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15, 254,
15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 , 254,
15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 , 254,
15,15,15,15,15,0 ,15,15,15,15,0 ,0 ,15,15,15,15,0 ,0 ,15,15,15,15,15,0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 , 254,
15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 , 254,
15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,15,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 , 254,
15,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,15,0 ,15,15,15,15,15,0 ,15,15,15,15,15,0 ,15,15,15,15,15,0 ,0 ,0 ,0 ,0 ,0 ,15,0 ,0 ,0 ,0 , 255
},
you[] = {
15, 0 , 0 , 0 , 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 0 , 0 , 0 , 15, 254,
15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 254,
15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 254,
0 , 15, 0 , 15, 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 254,
0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 254,
0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 254,
0 , 0 , 15, 0 , 0 , 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 255
},
win[] = {
15, 0 , 0 , 0 , 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 0 , 0 , 0 , 15, 254,
15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 15, 0 , 0 , 15, 254,
15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 15, 254,
15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 15, 254,
15, 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 15, 254,
15, 0 , 15, 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 15, 15, 254,
0 , 15, 0 , 15, 0 , 0 , 15, 15, 15, 15, 15, 0 , 15, 0 , 0 , 0 , 15, 255
},
lose[] = {
15, 0 , 0 , 0 , 0 , 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 254,
15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 0 , 254,
15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 0 , 254,
15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 0 , 254,
15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 0 , 254,
15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 0 , 0 , 15, 0 , 0 , 0 , 0 , 0 , 15, 0 , 15, 0 , 0 , 0 , 0 , 254,
15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 0 , 15, 15, 15, 15, 15, 255
};

rect bricks[75];
//char keys[255];

void brickset() {
	uint8_t brick_idx = 0;
	for (uint8_t column = 0; column < 5; column++) {
		for (uint8_t row = 0; row < 15; row++) {
			rect* cur_brick = &bricks[brick_idx];
			cur_brick->x = 2 + (row * 18);
			cur_brick->y = 2 + (column * 10);
			cur_brick->w = 16;
			cur_brick->h = 8;
			brick_idx++;
		}
	}
}

void kernel_entry() {
	isr_install();

	/*

	TODO - Game Loop:

	NOT STARTED
	- redo bricks to go all the way down to the bottom of the screen in harder later levels

	WIP


	VAGUE
	- collision responses
	- some of these might be done? jammy please clarify
		+ get states of all objects
		(not really a problem to 'get' them because constant access)
		+ draw all objects (is this not just rendering all the rects in bricks[]?)

	POINTLESS
	- isrs double binary size? current solution is no isrs, fix this
		+ added isrs back with stub, filesize is high but thats ok for now.
		machine code optimization can be done later when the actual game is done

	*/

	asm volatile("sti");
	init_timer(2);
	init_keyboard();

	// used to check if system timer has ticked
	uint32_t ftick = 0, score = 0;



	// TODO inline the structs
	ball gameball = {(rect){126, 180, 2, 2}, 1, 1};

	// player lives
	uint8_t lives = 3, bricks_left = 75;

	//gameball.ball = (rect){2, 2, 126, 180};
	rect paddle = (rect){116, 195, 24, 2};

 	// brick initial state
 	brickset();


	rect ball_collision_test;
	// used to clear paddle pixels as it moves. originally used
	// paddle but that causes flickering and shit
	rect clear;
	clear.y = 195;
	clear.h = 2;
	clear.w = 1;
	rect scrclr = {0,0,320,200};
	// title screen
	while(1) {
		// why the *fuck* does this need an else
		// what the fuck continue doesnt work
		if(keys[0x35] == 1) {
			plotrect(0, &scrclr);
			break;
		} else drawimg(press_slash, 141, 105);
	}
gameloop:
	// TODO make this not the entire fucking game loop
	while(1) { // ah yes good idea : while(1)  [obnoxious comment by jammy #1]
				// is testing function for isrs
				//plotrect(255, &scrclr);

		if(ftick != tick) {

			//	plotrect(255, &scrclr);
			// sync with timer
			ftick = tick;

			// handle key inputs
			// move left with comma
			if(keys[0x33] == 1 && paddle.x > 0) {
				clear.x = paddle.x+24;
				plotrect(0, &clear);
				paddle.x--;
			}

			// move right with perios
			if(keys[0x34] == 1 && paddle.x < 248) {
				clear.x = paddle.x-1;
				plotrect(0, &clear);
				paddle.x++;
			}

			// TODO realize what the interface should look like
			// scoreboard line
			//plotline(272, 0, 272, 200, 0x65);
			for(uint8_t line = 0; line < 200; line++) plotpix(0x65, 272, line);

			// move ball
			plotrect(0, &gameball.ball);
			gameball.ball.x -= gameball.vx;
			gameball.ball.y -= gameball.vy;
			ball_collision_test = rect_overlap(&gameball.ball, &paddle);

			if(gameball.ball.y < 0 || (ball_collision_test.w > 0 && ball_collision_test.h > 0)) {gameball.vy *=-1;}
			if(gameball.ball.x < 0 || gameball.ball.x > 270) {gameball.vx *=-1;}

			// slaughter the player
			if(gameball.ball.y > 199) {
				lives--;
				gameball = (ball){(rect){126, 180, 2, 2}, gameball.vx, 1};
			}

			plotrect(0x65, &gameball.ball);
			plotrect(0x65, &paddle);

		}

		for (uint8_t b = 0; b < 75; b++) {
			ball_collision_test = rect_overlap(&gameball.ball, &bricks[b]);
			if(ball_collision_test.w > 0 && ball_collision_test.h > 0) {
				plotrect(0, &bricks[b]);
				bricks[b] = (rect){0,0,0,0};
				bricks_left--;
				score++;
				if(ball_collision_test.w == 2) gameball.vy *=-1;
				if(ball_collision_test.h == 2) gameball.vx *=-1;
			}
			plotrect(0x65-(b%15), &bricks[b]);
		}
		if(lives == 0 || bricks_left == 0) break;

	}

	drawimg(you, 121, 105);
	drawimg(press_slash, 122, 115);
	
	if(bricks_left == 0) {
		// Winner
		drawimg(win, 143, 105);
	} else {
		// loser
		drawimg(lose, 143, 105);
	}
	while(1) {
		if(keys[0x35] == 1) break;
		else plotpix(0, 0, 0);
	}
	lives = 3;
	bricks_left = 75;
	brickset();
	rect rm = {121, 105, 50, 20};
	plotrect(0, &rm);
	goto gameloop;
	// TODO drop out of protected mode, fire interrupts for score, return to protected mode

}

