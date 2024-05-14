#include "bonds.h"
#include "raylib.h"
#include <iostream>

bonds::bonds(particle& p0, particle& p1)
	:
	p0(p0),
	p1(p1),
	length(bonds::getDist(p0, p1))
{
}

void bonds::updateBonds(particle& p0, particle& p1) {
	//Get the distance between each particles x and y
	float dx = p1.pos.x - p0.pos.x;
	float dy = p1.pos.y - p0.pos.y;
	//pythagore to find the length of the distance
	float dist = sqrt(dx * dx + dy * dy);
	//find the difference between the original length and the new one
	float diff = (this->length) - dist;
	//parametrize it and transform it into half percentage
	float percent = diff / dist * 0.5;
	//set the dx and dy to an offset
	float offx = dx * percent;
	float offy = dy * percent;

	//adjust each position accordingly
	if (!p0.GetState()) {
		p0.pos.x -= offx;
		p0.pos.y -= offy;
	}

	if (!p1.GetState()) {
		p1.pos.x += offx;
		p1.pos.y += offy;
	}
}

void bonds::DrawBonds() {
	DrawLineV({ p0.pos.x, p0.pos.y }, { p1.pos.x, p1.pos.y }, WHITE);
}

float bonds::getDist(particle& p0, particle& p1)
{
	float dx = p1.GetPosX() - p0.GetPosX();
	float dy = p1.GetPosY() - p0.GetPosY();
	return sqrt(dx * dx + dy * dy);;
}
