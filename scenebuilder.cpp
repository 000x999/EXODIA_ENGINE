#include "scenebuilder.h"
#include <iostream>
#include "raylib.h"

void scene::UpdateScene(){

	uint32_t currentTime = GetFrameTime();
	float dt = (currentTime - upTime) / 1000.0f;
	upTime = currentTime;
}

void scene::RenderScene() {
	//Delta time to calculate ur frame ticks, the higher the DT the more accurate the physics
	//At the cost of performance obviously 
	float dt = 0.060f;

	//particle objects, they take in a Vec2 with floats, next is a mass value and a pinned state
	//To use Vec2's in constructors either do {pos.x, pos.y} in the spot that takes in the vector 
	//Or simply pass in the fully initialized vector by its variable name
	particle bA(Vec2(840.0, 155.0), 1.05f, false);
	particle bB(Vec2(940.0, 250.0), 1.05f, false);

	//Bonds objects to connect two particles together, they take in two particle objects as parameters.
	bonds bAB(bA, bB);
	//Set ur fps
	SetTargetFPS(60);
	//Init ur window
	InitWindow(WIDTH, HEIGHT, "EXODIA");
	
	//Begin the game loop
	while (!WindowShouldClose()) {
		//Begin the drawing process
		BeginDrawing();
		scene::MoveBall(bA);
		//This function clears the screen after each refresh and ALWAYS has to be at the top before any draw calls, but under the first one
		ClearBackground(BLACK);
		
		//Here just call the colliding methods and update methods for both types of objects 
		//The order of ur calls should be collision > update > draw 
		//Frame updates occur from top to bottom
		bA.Colliding(WIDTH, HEIGHT);
		bA.UpdateBall(dt, WIDTH, HEIGHT);
		bA.DrawBall();
		bB.Colliding(WIDTH, HEIGHT);
		bB.UpdateBall(dt, WIDTH, HEIGHT);
		bB.DrawBall();

		bAB.DrawBonds();
		bAB.updateBonds(bA, bB);
		EndDrawing();
	}


	CloseWindow();
}

//Move ball function that takes in mouse input to move any ball u pass in 
void scene::MoveBall(particle& p){
	if (IsMouseButtonDown(0)) {
		p.pos.x = GetMouseX();
		p.pos.y = GetMouseY();
	}
}
