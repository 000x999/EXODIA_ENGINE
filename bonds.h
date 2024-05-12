#pragma once
#include "Vec2.h"
#include "particle.h"
#include "raylib.h"

class particle;
class bonds {

private:
	//Reference to two particle objects so they can be used in the class without being passed as parameters
	particle& p0; 
	particle& p1;
	//State variables
	bool isActive; 
	bool isSelected;
	float length; 

public:
	//constructor that initializes the particle objects.
	bonds(particle& p0, particle& p1); 
	~bonds() = default;
	//Updates the bonds each frame
	void updateBonds(particle& p0, particle& p1); 
	void DrawBonds(); 
	//Gets the distance between two particlee
	static float getDist(particle& p0, particle& p1);
	//getters and setters
	bool GetIsSelected() const { return isSelected; };
	void SetIsSelected(bool val) { isSelected = val; };
	bool GetIsActive() const { return isActive; };
	void breakOff() { isActive = false; };
	

};