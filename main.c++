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
//    const float MAX_WIDTH_NODES  = DivisionRounder((float)screenWidth, 60.0f);
//    const float MAX_HEIGHT_NODES  = DivisionRounder((float)screenHeight, 60.0f);
//    const int NODE_ARRAY_SIZE = MAX_WIDTH_NODES * MAX_HEIGHT_NODES;
    const int NODE_ARRAY_SIZE = 4;

    Vector2 nodePositionsArray[NODE_ARRAY_SIZE];

    nodePositionsArray[0] = (Vector2){ screenWidth / 5.0f, screenHeight * 4.0f / 5.0f };
    nodePositionsArray[1] = (Vector2){ screenWidth / 4.0f, screenHeight * 3.0f / 5.0f };
    nodePositionsArray[2] = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    nodePositionsArray[3] = (Vector2){ screenWidth * 3.0f / 5.0f, screenHeight / 6.0f };
    
//    for ( int i=0; i < (int)MAX_WIDTH_NODES; i++) {
//        for ( int j=0; j < (int)MAX_HEIGHT_NODES; j++ ) {
//            // A matrix runs to right and then downwards
//            nodePositionsArray[j * (int)MAX_WIDTH_NODES + i].x = 2 * nodeRadius * i + nodeRadius;
//            nodePositionsArray[j * (int)MAX_WIDTH_NODES + i].y = 2 * nodeRadius * j + nodeRadius;
//        }
//    }

    Color colorArray[NODE_ARRAY_SIZE];
    int sidesInNode[NODE_ARRAY_SIZE] = { 0 }; // Default is 0 sides

    sidesInNode[0] = 4;
    sidesInNode[3] = 3;

    // Modified the sides arbitrarily for testing purposes
//    sidesInNode[1] = 3;
//    sidesInNode[2] = 4;
//    sidesInNode[3] = 5;
//    sidesInNode[4] = 6;
//    sidesInNode[5] = 7;

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
        for (int i=0; i < (sizeof(sidesInNode)/sizeof(int)); i++) {
            switch (sidesInNode[i]) {
                case 0:
                    colorArray[i] = LIGHTGRAY;
                    break;
                case 3:
                    colorArray[i] = LIME;
                    break;
                case 4:
                    colorArray[i] = YELLOW;
                    break;
                case 5:
                    colorArray[i] = RED;
                    break;
                case 6:
                    colorArray[i] = SKYBLUE;
                    break;
                case 7:
                    colorArray[i] = PURPLE;
                    break;

            }
//            if (CheckCollisionPointCircle(mousePosition, nodePositionsArray[i], nodeRadius)) {
//                colorArray[i] = GOLD;
//                sidesInNode[i] = 4;
//            } else { colorArray[i] = LIGHTGRAY; }
        }
//        nodePosition.x += mouseWheelMove * 10.0f;
        // --- End of Update 

        // --- Drawing 
		BeginDrawing();
			ClearBackground(RAYWHITE);

            // Draw the Nodes
            for (int i = 0; i < (sizeof(nodePositionsArray)/sizeof(Vector2)); i++) {
                if (sidesInNode[i] == 0) {
                    DrawCircleV(nodePositionsArray[i], nodeRadius, colorArray[i]);
                } else if (sidesInNode[i] == 3) {
                    DrawTriangle((Vector2){nodePositionsArray[i].x, nodePositionsArray[i].y - nodeRadius},
                                (Vector2){nodePositionsArray[i].x - 25.0f, nodePositionsArray[i].y + 25.0f},
                                (Vector2){nodePositionsArray[i].x + 25.0f, nodePositionsArray[i].y + 25.0f}, LIME);
                }
                else {
                    DrawPoly(nodePositionsArray[i], sidesInNode[i], nodeRadius, -90.0f, colorArray[i]);
                }
            }

            DrawText(TextFormat("mousePosition : (%.02f. %.02f)", mousePosition.x, mousePosition.y), 20, 80, 30, DARKGRAY);

		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}