struct PlayerState {
	double x,y;
	double speed;
	double angle;

	double health;
	double barrelAngle;
	int nextShootTime;

	int turn;
	int accel;
	int shoot;
	int barrelTurn;
};

#define FRAME_TIME (0.05)
#define TURN_SPEED (5.0)
#define BARREL_TURN_SPEED (5.0)
#define ACCELERATION (50.0)
#define MAX_SPEED (200.0)
#define SHOOT_TIME (200)

void setAcceleration(int player, int accel);
void setTurning(int player, int direction);
void setShoot(int player, int shoot);
void setBarrelTurn(int player, int direction);
