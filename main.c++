#include <raylib.h>
#include "header.h"

int main(void)
{
    // --- Initialization
    const int screenWidth = 1024;
    const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "Healing through stand-up");

    const float nodeRadius = 30.0f; // Apparently they look from from [30,50]

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float mouseWheelMove;
    Vector2 mousePosition; 

    // Just tried to check whether having multiple nodes would mess anything or not
    const float MAX_WIDTH_NODES  = DivisionRounder((float)screenWidth, 60.0f);
    const float MAX_HEIGHT_NODES  = DivisionRounder((float)screenHeight, 60.0f);
    Vector2 nodePositionsArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];
    
    for ( int i=0; i < (int)MAX_WIDTH_NODES; i++) {
        for ( int j=0; j < (int)MAX_HEIGHT_NODES; j++ ) {
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].x = 2 * nodeRadius * i + nodeRadius;
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].y = 2 * nodeRadius * j + nodeRadius;
        }
    }

    Color colorArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];

//    Allowable colors
//    Color colorArray[] = {
//         MAROON, RED, GOLD, YELLOW, LIME, GREEN, BLUE, SKYBLUE, VIOLET, PURPLE, LIGHTGRAY
//        };

    // --- End of Initialization

//  TODO: Allow for fullscreeen mode. This may require the user to close the game.
//	int monitor = GetCurrentMonitor();
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

            // Draw the Nodes
            for (int i = 0; i <= (sizeof(nodePositionsArray)/sizeof(Vector2)); i++) {
            if (nodePositionsArray[i].x < nodeRadius || nodePositionsArray[i].x < nodeRadius || nodePositionsArray[i].y < nodeRadius) {
                    logger(nodePositionsArray[i], i);
                } else {
                    DrawCircleV(nodePositionsArray[i], nodeRadius, colorArray[i]);
                }
//                DrawPoly(nodePositionsArray[i], 3, nodeRadius, -90.0f, colorArray[i]);
            }

		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}