#include <DungeonEscape/ThreadPool.h> //Contains the thread pool for running code asynchronously
#include <thread> //Contains std::thread for executing code on a seperate thread
#include <list> //Contains std::list for storing items in a linked list
#include <mutex> //Contains std::mutex and std::recursive_mutex for resource locking and to prevent data races //Contains std::mutex and std::recursive_mutex for mutual exclusion of resources and prevents data races
#include <iostream>
#include <SDL.h>

using namespace std; //Prevents me from having to type std everywhere

namespace
{
	volatile bool running = false; //Whether the thread pool is running or not
	SDL_Thread* poolThread; //The actual thread
	recursive_mutex poolMutex; //The mutex to prevent data races when adding and removing from the function list

	list<function<void()>> threadPoolFunctions; //The list of functions to execute

	//The main thread pool loop
	int ThreadPoolMain(void* data);
}

//Start the thread pool
void ThreadPool::Start()
{
	//If the thread pool is not running yet
	if (!running)
	{
		//Start the thread
		running = true;

		//poolThread = SDL_CreateThread(ThreadPoolMain);
		poolThread = SDL_CreateThread(ThreadPoolMain, "ThreadPoolThread", (void*)nullptr);
	}
}

//Adds a new function to the thread pool queue to be executed
void ThreadPool::AddToQueue(std::function<void()>&& func)
{
	//Lock the function list
	unique_lock<recursive_mutex> lock(poolMutex);

	//Add the fucntion to the list of functions to execute
	threadPoolFunctions.emplace_back(std::move(func));
}


void ThreadPool::Stop()
{
	//If the thread is running
	if (running)
	{
		//Stop the thread and join with it
		running = false;
		SDL_WaitThread(poolThread, nullptr);
	}
}



namespace
{
	//The main thread pool loop
	int ThreadPoolMain(void* data)
	{
		//Repeat untill the thread should stop running
		while (true)
		{
			//This is to prevent some compilers (like GCC) from optimizing this while loop away, preventing any of the code below from getting executed
#ifndef _MSC_VER
			asm(" ");
#endif
			//If the thread is to stop running
			if (running == false)
			{
				//Break out of the loop
				break;
			}
			//The current function to execute
			function<void()> currentFunction;

			{
				//If there are no thread pool functions to execute
				if (threadPoolFunctions.size() == 0)
				{
					//Go back to the top of the loop
					continue;
				}
				//Lock the thread pool function mutex
				unique_lock<recursive_mutex> lock(poolMutex);
				//Remove the next function to execute from the list
				currentFunction = std::move(threadPoolFunctions.front());
				threadPoolFunctions.pop_front();
			}
			
			//Execute the function
			currentFunction();
		}

		return 0;
	}
}
