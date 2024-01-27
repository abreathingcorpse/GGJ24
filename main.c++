#include <raylib.h>

int main(void)
{
    // --- Initialization
	int monitor = GetCurrentMonitor();
	InitWindow(1024, 640, "Healing through stand-up");

    const Vector2 nodePosition = { 600.0f, 250.0f };
    float nodeRadius = 30.0f; // Apparently they look from from [30,50]

    float elapsed_time; // This will hold the time in seconds for last frame drawn(delta time)
    float mouseWheelMove;

    // --- End of Initialization

//  TODO: Allow for fullscreeen mode. This may require the user to close the game.
//	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "raylib [core] example - basic window");
//	ToggleFullscreen();
	
	while (!WindowShouldClose())
	{
        // --- Update 
        elapsed_time = GetFrameTime();
        mouseWheelMove = GetMouseWheelMove();
        nodeRadius += mouseWheelMove;
        // --- End of Update 

        // --- Drawing 
		BeginDrawing();
			ClearBackground(RAYWHITE);
//			DrawText("Congrats! You crekkkkkkkkated your first window!", 190, 200, 20, LIGHTGRAY);
            DrawText(TextFormat("radius : %.02f", nodeRadius), 20, 70, 10, DARKGRAY);
            DrawCircleV(nodePosition, nodeRadius, LIGHTGRAY);
		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}