#include "particle.h"

particle::particle(const Vec2& pos_in, float mass_in, bool pinned)
	:
	pos(pos_in),
	mass(mass_in),
	pinned(pinned)

{
	prev = pos; 
}

void particle::DrawBall() const {
	DrawCircleV({ pos.x, pos.y }, radius, WHITE);
}

void particle::UpdateBall(float dt, int WIDTH, int HEIGHT) {
	if (!pinned) {

		//Ball update function, this holds all the physics
		//This would take a little too long to explain here but if you're interested in it 
		//This update method is called Runge Kutta 4
		Vec2 force = { 0,121 };
		Vec2 acc = { force.x / this->mass, force.y / this->mass };
		Vec2 prevPos = { pos.x, pos.y };
		pos.x = 2 * pos.x - prev.x + acc.x * (dt * dt);
		pos.y = 2 * pos.y - prev.y + acc.y * (dt * dt);
		//Creation of a dampening factor for lateral movements.
		float vel_x = (pos.x - prevPos.x) * 0.989;
		float velocity_threshold = 0.0099999;
		//get the ABS of the velocity and compare to the threshhold
		if (std::abs(vel_x) < velocity_threshold) {
			//set to 0 
			vel_x = 0;
		}
		//update previous and current positions
		prev.x = pos.x - vel_x;
		prev.y = prevPos.y;

	}
 }

bool particle::Colliding(int WIDTH, int HEIGHT) {
	//Simple collision logic with screen edges
	//Dampening factors are multiplied after each bounce to lose velocity
	float vel_x = (pos.x - prev.x);
	float vel_y = (pos.y - prev.y);
	bool colliding = false;
	if (pos.x - radius < 0) {
		pos.x = 0 + radius;
		prev.x = pos.x + vel_x * 0.45;
		colliding = true;
	}
	else if (pos.x + radius > WIDTH) {
		pos.x = WIDTH - radius;
		prev.x = pos.x + vel_x * 0.45;
		colliding = true;
	}
	else if (pos.y - radius < 0) {
		pos.y = 0 + radius;
		prev.y = pos.y + vel_y * 0.65;
		colliding = true;
	}
	else if (pos.y + radius > HEIGHT) {
		pos.y = HEIGHT - radius;
		prev.y = pos.y + vel_y * 0.65;
		colliding = true;
	}
	return colliding;
}
