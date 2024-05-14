#include "RAYLIB.H"
#include "planet.h"
#include "scenebuilder.h"
#include <iostream>

void scene::UpdateScene() {

	uint32_t currentTime = GetFrameTime();
	float dt = (currentTime - upTime) / 1000.0f;
	upTime = currentTime;
}

void scene::RenderScene() {
	//Delta time to calculate ur frame ticks, the higher the DT the more accurate the physics
	//At the cost of performance obviously 
	float dt = 0.060f;
	SetTargetFPS(60);
	//Init ur window
	InitWindow(WIDTH, HEIGHT, "SOLAR_SYSTEM_V1");
	planet planet1({ 200, 200 }, 5.97 * 1e24, 15);
	planet planet2({ 800, 300 }, 7.34 * 1e22, 50);
	
	planet1.SetVelocityX(0);
	planet1.SetVelocityY(0);

	planet2.SetVelocityX(0);
	planet2.SetVelocityY(0);

	//Begin the game loop
	while (!WindowShouldClose()) {

		planet1.UpdatePlanet(GetFrameTime());
		planet2.UpdatePlanet(GetFrameTime());

		//aaaaaaaaa WHAT THE FUCK IS THIS????
		double distance_x = (planet2.pos.y - planet1.pos.y);
		double distance_y = (planet2.pos.x - planet1.pos.x);

		planet2.acceleration.x = planet1.forceOfAttraction(planet2.GetMass(), distance_x) / planet1.GetMass();
		planet2.acceleration.y = planet1.forceOfAttraction(planet2.GetMass(), distance_y) / planet1.GetMass();

		planet1.acceleration.y = planet2.forceOfAttraction(planet1.GetMass(), distance_y) / planet2.GetMass();
		planet1.acceleration.x = planet2.forceOfAttraction(planet1.GetMass(), distance_x) / planet2.GetMass();
		
		BeginDrawing();
		ClearBackground(RAYWHITE); // Clear the screen
		planet1.DrawBall();
		planet2.DrawBall();

		EndDrawing();
	}

}

