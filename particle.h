#pragma once
#include "raylib.h"
#include "bonds.h"
#include <iostream>
class bonds; 
class particle {

private: 
	//Bonds array for adding objects automatically
	bonds* bondsArr[2] = { nullptr };
	//States
	bool pinned; 
	float mass; 
	bool isSelected;
	//Physics values, adjust these to your liking to get ur desired effect
	static constexpr float decay = 0.55f;
	static constexpr float radius = 7.0f;
	static constexpr float grav = 0.9f;
	static constexpr float fric = 0.999f;

public:
	//Position vectors
	Vec2 pos;
	Vec2 prev;
	//Constructor and destructor
	particle(const Vec2& pos_in, float mass_in, bool pinned);
	~particle() = default;

	void DrawBall() const; 
	void UpdateBall(float dt, int WIDTH, int HEIGHT);
	bool Colliding(int WIDTH, int HEIGHT);
	//Getters and setters
	bool GetState() const { return pinned; };
	void SetPosX(float val) { pos.x = val; }
	void SetPosY(float val) { pos.y = val; };
	float GetPosX() const { return pos.x; };
	float GetPosY() const { return pos.y; };

};