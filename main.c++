#include <raylib.h>

int main(void)
{
    // --- Initialization
	int monitor = GetCurrentMonitor();
	InitWindow(1024, 640, "Healing through stand-up");

    const Vector2 nodePosition = { 600.0f, 250.0f };
    const float nodeRadius = 3.0f;

    // --- End of Initialization

//  TODO: Allow for fullscreeen mode. This may require the user to close the game.
//	InitWindow(GetMonitorWidth(monitor), GetMonitorHeight(monitor), "raylib [core] example - basic window");
//	ToggleFullscreen();
	
	while (!WindowShouldClose())
	{
        // --- Update 
        // --- End of Update 

        // --- Drawing 
		BeginDrawing();
			ClearBackground(RAYWHITE);
//			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawCircleV(nodePosition, nodeRadius, LIGHTGRAY);
		EndDrawing();
        // --- End of Drawing 
	}

	CloseWindow();

	return 0;
}