/*
	Nicholas Cullen
	3/22/20
	Dungeon Escape : A small GUI C++ game where you attempt to escape a dungeon full of skeletons
*/

//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp> //Contains many essential SFML classes and functions for rendering
#include <string> //Contains std::string
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <DungeonEscape/Common.h> //Contains many common game functions and variables
#include <DungeonEscape/WorldMap.h> //Contains the WorldMap class
#include <DungeonEscape/UpdateReceiver.h> //Contains the UpdateReceiver class for receiving update events
#include <mutex> //Contains std::mutex and std::recursive_mutex for resource locking and to prevent data races //Contains std::mutex and std::recursive_mutex for mutual exclusion of resources and prevents data races
#include <DungeonEscape/GameManager.h> //Contains the GameManager class, which contains the main logic of the game
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <DungeonEscape/Input.h>
#include <iostream>
#include <SDL_gpu.h>

using namespace std; //Prevents me from having to type std everywhere
//using namespace sf; //Prevents me from having to type sf everywhere


//The start of the program
int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	Common::MainWindow = SDL_CreateWindow("Dungeon Escape",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (Common::MainWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	Common::MainWindowSurface = SDL_GetWindowSurface(Common::MainWindow);

	Common::MainWindowRenderer = SDL_CreateRenderer(Common::MainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (Common::MainWindowRenderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	//Create all the common sprites
	Common::CreateSprites();


	//Common::MainWindow.setVerticalSyncEnabled(true);

	//Refresh the window size
	Common::RefreshWindow();

	//Create the game manager
	GameManager manager{};

	//Start the game manager
	manager.Start();

	//Start the time clock
	//Clock clock;

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 prev = 0;
	double dt = 0;

	int counter = 0;

	//double averageFPS = 0;

	//Repeat until the game manager is complete
	while (!manager.IsComplete())
	{
		prev = now;
		now = SDL_GetPerformanceCounter();
		dt = (double)((now - prev) / (double)SDL_GetPerformanceFrequency());
		auto fps = 1.0 / dt;

		//averageFPS = (averageFPS + fps) / 2.0;


		//std::cout << "FPS = " << (1.0 / dt) << "\n";
		//std::cout << counter << "\n";

		//The current window event
		//Event e;

		//Reset the clock and get the time between the last frame and the current frame
		//auto dt = clock.restart();


		{

			//Lock the updatables list lock
			auto lockObject = unique_lock<recursive_mutex>(UpdateReceiver::GetMutex());
			//Get the updatable objects
			auto updatables = UpdateReceiver::GetUpdatables();

			//Loop over all the updatable objects
			for (auto i = updatables.rbegin(); i != updatables.rend(); i++)
			{
				//Call their update function
				(**i).Update(dt);
			}
		}

		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				manager.EndTheGame();
				break;
			case SDL_WINDOWEVENT:
				switch (e.window.event)
				{
				case SDL_WINDOWEVENT_CLOSE:
					manager.EndTheGame();
					break;
				case SDL_WINDOWEVENT_RESIZED:

					Common::MainWindowSurface = SDL_GetWindowSurface(Common::MainWindow);

					auto oldRenderer = Common::MainWindowRenderer;

					SDL_DestroyRenderer(oldRenderer);

					Common::MainWindowRenderer = SDL_CreateRenderer(Common::MainWindow, -1, SDL_RENDERER_ACCELERATED);

					if (Common::MainWindowRenderer == nullptr)
					{
						printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
					}

					{
						//Lock the renderable object list
						auto lockObject = unique_lock<recursive_mutex>(Renderable::GetMutex());

						//Get the list of renderable objects
						auto& renderables = Renderable::GetRenderables();

						//Loop over all the renderable objects
						for (auto i = rbegin(renderables); i != rend(renderables); i++)
						{
							//Render each of the objects to the main window
							(**i).OnRebuild(Common::MainWindowRenderer,oldRenderer);
						}
					}


					break;
				}
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDL_KeyCode::SDLK_DOWN:
					Input::down_arrow = true;
					break;
				case SDL_KeyCode::SDLK_UP:
					Input::up_arrow = true;
					break;
				case SDL_KeyCode::SDLK_LEFT:
					Input::left_arrow = true;
					break;
				case SDL_KeyCode::SDLK_RIGHT:
					Input::right_arrow = true;
					break;
				case SDL_KeyCode::SDLK_w:
					Input::w = true;
					break;
				case SDL_KeyCode::SDLK_a:
					Input::a = true;
					break;
				case SDL_KeyCode::SDLK_s:
					Input::s = true;
					break;
				case SDL_KeyCode::SDLK_d:
					Input::d = true;
					break;
				case SDL_KeyCode::SDLK_SPACE:
					Input::space = true;
					break;
				case SDL_KeyCode::SDLK_RETURN:
					Input::enter = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch (e.key.keysym.sym)
				{
				case SDL_KeyCode::SDLK_DOWN:
					Input::down_arrow = false;
					break;
				case SDL_KeyCode::SDLK_UP:
					Input::up_arrow = false;
					break;
				case SDL_KeyCode::SDLK_LEFT:
					Input::left_arrow = false;
					break;
				case SDL_KeyCode::SDLK_RIGHT:
					Input::right_arrow = false;
					break;
				case SDL_KeyCode::SDLK_w:
					Input::w = false;
					break;
				case SDL_KeyCode::SDLK_a:
					Input::a = false;
					break;
				case SDL_KeyCode::SDLK_s:
					Input::s = false;
					break;
				case SDL_KeyCode::SDLK_d:
					Input::d = false;
					break;
				case SDL_KeyCode::SDLK_SPACE:
					Input::space = false;
					break;
				case SDL_KeyCode::SDLK_RETURN:
					Input::enter = false;
					break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button)
				{
				case SDL_BUTTON_LEFT:
					Input::left_arrow = true;
					break;
				case SDL_BUTTON_RIGHT:
					Input::right_arrow = true;
					break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch (e.button.button)
				{
				case SDL_BUTTON_LEFT:
					Input::left_arrow = false;
					break;
				case SDL_BUTTON_RIGHT:
					Input::right_arrow = false;
					break;
				}
				break;
			}
		}

		//Poll the window for events
		/*while (Common::MainWindow.pollEvent(e))
		{
			//If the event is to close the window
			if (e.type == e.Closed)
			{
				//Close the window
				Common::MainWindow.close();
				//Tell the manager to end the game
				manager.EndTheGame();
			}

			//if the event is to resize the window
			if (e.type == e.Resized)
			{
				//Refresh the window size
				Common::RefreshWindow();
			}
		}*/

		//Clear all the window's contents
		SDL_RenderClear(Common::MainWindowRenderer);

		{
			//Lock the renderable object list
			auto lockObject = unique_lock<recursive_mutex>(Renderable::GetMutex());

			//Get the list of renderable objects
			auto& renderables = Renderable::GetRenderables();

			int count = 0;
			//Loop over all the renderable objects
			for (auto i = rbegin(renderables); i != rend(renderables); i++)
			{
				//Render each of the objects to the main window
				(**i).Render(Common::MainWindowRenderer);
				count += 1;
			}

		}

		//Display the window's contents to the screen
		//Common::MainWindow.display();
		SDL_RenderPresent(Common::MainWindowRenderer);

		//if the game manager is complete
		/*if (manager.IsComplete())
		{
			//Close the main window
			Common::MainWindow.close();
		}*/

	}

	//End the game
	manager.EndTheGame();
}
