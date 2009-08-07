#include "player.h"
#include "bullet.h"
#include <math.h>

void updatePlayer(Player* pl, int time)
{
	double dx = FRAME_TIME*cos(pl->angle);
	double dy = FRAME_TIME*-sin(pl->angle);
	pl->speed += FRAME_TIME*ACCELERATION*pl->accel;

	pl->vx += dx*pl->speed;
	pl->vy += dy*pl->speed;

	pl->x += FRAME_TIME*pl->vx;
	pl->y += FRAME_TIME*pl->vy;

	pl->angle += pl->turn * TURN_AMOUNT * FRAME_TIME;
	pl->barrelAngle += pl->barrelTurn * BARREL_TURN_AMOUNT * FRAME_TIME;

	if (time >= pl->nextShootTime) {
		// TODO: ammu
		pl->nextShootTime += time + SHOOT_TIME;
	}
}
