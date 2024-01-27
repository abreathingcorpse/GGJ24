#include <raylib.h>
#include "header.h"

int main(void)
{
    // --- Initialization
	int monitor = GetCurrentMonitor();
    const int screenWidth = 1024;
    const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "Healing through stand-up");

//    Vector2 nodePosition = { 0.0f, 0.0f };
    const float nodeRadius = 30.0f; // Apparently they look from from [30,50]

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float mouseWheelMove;
    Vector2 mousePosition; 

    const float MAX_WIDTH_NODES  = DivisionRounder((float)screenWidth, 60.0f);
    const float MAX_HEIGHT_NODES  = DivisionRounder((float)screenHeight, 60.0f);
    Vector2 nodePositionsArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];
    
    for ( int i=0; i < (int)MAX_WIDTH_NODES; i++) {
        for ( int j=0; j < (int)MAX_HEIGHT_NODES; j++ ) {
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].x = 60.0f * i + nodeRadius;
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].y = 60.0f * j + nodeRadius;
        }
    }

    Color colorArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];

//    Color colorArray[] = {
//         MAROON, RED, GOLD, YELLOW, LIME, GREEN, BLUE, SKYBLUE, VIOLET, PURPLE, LIGHTGRAY
//        };

    // --- End of Initialization

//  TODO: Allow for fullscreeen mode. This may require the user to close the game.
//	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "raylib [core] example - basic window");
//	ToggleFullscreen();
	
	while (!WindowShouldClose())
	{
        // --- Update 
        elapsed_time = GetFrameTime();
        mouseWheelMove = GetMouseWheelMove();
        mousePosition = GetMousePosition();
        for (int i=0; i <= (sizeof(colorArray)/sizeof(Color)); i++) {
            if (CheckCollisionPointCircle(mousePosition, nodePositionsArray[i], nodeRadius)) {
                colorArray[i] = GOLD;
            } else { colorArray[i] = LIGHTGRAY; }
        }
//        nodePosition.x += mouseWheelMove * 10.0f;
        // --- End of Update 

        // --- Drawing 
		BeginDrawing();
			ClearBackground(RAYWHITE);
//            DrawText(TextFormat("MAX_WIDTH_NODES : %.02f", MAX_WIDTH_NODES), 20, 30, 30, DARKGRAY);

            for (int i = 0; i <= (sizeof(nodePositionsArray)/sizeof(Vector2)); i++) {
                DrawCircleV(nodePositionsArray[i], nodeRadius, colorArray[i]);
            }

//            for (int i = 0; i < (sizeof(colorArray)/sizeof(Color)); i++) {
//                DrawCircle(nodePosition.x + (i * 50), nodePosition.y, nodeRadius, colorArray[i]);
//            }

		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}