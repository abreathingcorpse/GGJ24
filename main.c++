#include <raylib.h>
#include "header.h"
#include <fstream> // for logging and debugging

void logger(Vector2 nodePositionsArray, int i) {
    std::ofstream log;
    log.open ("log.txt", std::ios_base::app);
    log << "index: " << i << "\n";
    log << "vector: (" << nodePositionsArray.x << "," << nodePositionsArray.y << ")\n";
    log.close();
}

int main(void)
{
    // --- Initialization
	int monitor = GetCurrentMonitor();
    const int screenWidth = 1024;
    const int screenHeight = 640;
	InitWindow(screenWidth, screenHeight, "Healing through stand-up");

    const float nodeRadius = 30.0f; // Apparently they look from from [30,50]

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float mouseWheelMove;
    Vector2 mousePosition; 

    const float MAX_WIDTH_NODES  = DivisionRounder((float)screenWidth, 60.0f);
    const float MAX_HEIGHT_NODES  = DivisionRounder((float)screenHeight, 60.0f);
//    const float MAX_WIDTH_NODES  = 10.0f;
//    const float MAX_HEIGHT_NODES  = 10.0f;
    Vector2 nodePositionsArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];
    
    for ( int i=0; i < (int)MAX_WIDTH_NODES; i++) {
        for ( int j=0; j < (int)MAX_HEIGHT_NODES; j++ ) {
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].x = 2 * nodeRadius * i + nodeRadius;
            nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j].y = 2 * nodeRadius * j + nodeRadius;

//            logger(nodePositionsArray[i * (int)MAX_HEIGHT_NODES + j], i * (int)MAX_HEIGHT_NODES + j);
        }
    }


    Color colorArray[(int)MAX_WIDTH_NODES * (int)MAX_HEIGHT_NODES];

//    Allowable colors
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
            if (nodePositionsArray[i].x < nodeRadius || nodePositionsArray[i].x < nodeRadius || nodePositionsArray[i].y < nodeRadius) {
                    logger(nodePositionsArray[i], i);
                } else {
                    DrawCircleV(nodePositionsArray[i], nodeRadius, colorArray[i]);
                }
//                DrawPoly(nodePositionsArray[i], 3, nodeRadius, -90.0f, colorArray[i]);
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