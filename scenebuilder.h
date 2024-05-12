#pragma once
#include "raylib.h"
#include "particle.h"
#include "bonds.h"
#include <cstdint>

class scene {
private:
	//Window heights and widths
	static constexpr int WIDTH = 1280;
	static constexpr int HEIGHT = 720;
	//DT
	uint32_t upTime; 
public: 

	//Default constructor and destructor
	scene() = default;
	~scene() = default;

	void UpdateScene();
	void RenderScene();
	void MoveBall(particle& p);

};