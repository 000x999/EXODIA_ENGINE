#include "raylib.h"
#include "planet.h"
#include "Vec2.h"
#include <cmath>
#include <iostream>

planet::planet(const Vec2& pos_in, float mass_in, float radius)
	:
	pos(pos_in),
	mass(mass_in),
	radius(radius)
{
}

void planet::DrawBall() const
{
    DrawCircleV({pos.x,pos.y}, radius, BLACK);
}

void planet::UpdatePlanet(float dt)
{

		velocity.x += acceleration.x * dt * 1e-9;
		velocity.y += acceleration.y * dt * 1e-9;
		pos.x += velocity.x * dt;
		pos.y += velocity.y * dt;
}

float planet::forceOfAttraction(double otherMass, double distance)
{

	float F;
	float G = 6.67 * 1e-11;
	F = (G * mass * otherMass) / (distance * distance);
	return F;
}
