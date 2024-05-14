#pragma once
#include "raylib.h"
#include "Vec2.h"
#include <cmath>
class planet {
private:
	float mass;
	float rotationSpeed;
	float radius;
public:
	Vec2 pos;
	Vec2 velocity;
	Vec2 acceleration;

	void UpdatePlanet(float dt);
	void DrawBall() const;

	void SetPosX(float val) { pos.x = val; }
	void SetPosY(float val) { pos.y = val; };
	float GetPosX() const { return pos.x; };
	float GetPosY() const { return pos.y; };

	void SetVelocityX(float val) { velocity.x = val; }
	void SetVelocityY(float val) { velocity.y = val; }
	float GetVelocityX() const { return velocity.x; }
	float GetVelocityY() const { return velocity.y; }

	void SetAccelerationX(float val) { acceleration.x = val; }
	void SetAccelerationY(float val) { acceleration.y = val; }
	float GetAccelerationX() const { return acceleration.x; }
	float GetAccelerationY() const { return acceleration.y; }
	float GetMass() const { return mass; }


	float forceOfAttraction(double otherMass, double distance);
	

	planet(const Vec2& pos, float mass, float rotSpeed);
	~planet() = default;
};