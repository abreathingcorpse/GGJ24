#include <raylib.h>

int main(void)
{
    // --- Initialization
	int monitor = GetCurrentMonitor();
	InitWindow(1024, 640, "Healing through stand-up");

    Vector2 nodePosition = { 100.0f, 250.0f };
    float nodeRadius = 30.0f; // Apparently they look from from [30,50]

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float mouseWheelMove;

    Color colorArray[] = {
         MAROON, RED, GOLD, YELLOW, LIME, GREEN, BLUE, SKYBLUE, VIOLET, PURPLE, LIGHTGRAY
        };

    // --- End of Initialization

//  TODO: Allow for fullscreeen mode. This may require the user to close the game.
//	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "raylib [core] example - basic window");
//	ToggleFullscreen();
	
	while (!WindowShouldClose())
	{
        // --- Update 
        elapsed_time = GetFrameTime();
        mouseWheelMove = GetMouseWheelMove();
//        nodePosition.x += mouseWheelMove * 10.0f;
        // --- End of Update 

        // --- Drawing 
		BeginDrawing();
			ClearBackground(RAYWHITE);
            DrawText(TextFormat("node Position, x : %.02f", nodePosition.x), 20, 30, 30, DARKGRAY);

            for (int i = 0; i < (sizeof(colorArray)/sizeof(Color)); i++) {
                DrawCircle(nodePosition.x + (i * 50), nodePosition.y, nodeRadius, colorArray[i]);
            }

		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}