cmake_minimum_required(VERSION 3.6)

project(DungeonEscape VERSION 2.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE}")

add_subdirectory(lib/SFML)

add_executable(${PROJECT_NAME}	"src/main.cpp"
								"src/AnimatedEntity.cpp"
								"src/BackgroundTile.cpp"
								"src/Branch.cpp"
								"src/Common.cpp"
								"src/DialogBoxSprite.cpp"
								"src/Direction.cpp"
								"src/Door.cpp"
								"src/Enemy.cpp"
								"src/Entity.cpp"
								"src/GameManager.cpp"
								"src/GameText.cpp"
								"src/HeartDisplay.cpp"
								"src/MagicOrb.cpp"
								"src/MainMenuBackground.cpp"
								"src/Math.cpp"
								"src/Player.cpp"
								"src/Renderable.cpp"
								
								"src/ResourceFont.cpp"
								"src/ResourceTexture.cpp"
								"src/Room.cpp"
								"src/SkeletonEnemy.cpp"
								"src/ThreadPool.cpp"
								"src/UpdateReceiver.cpp"
								"src/WorldMap.cpp"
								"include/DungeonEscape/AnimatedEntity.h"
								"include/DungeonEscape/Array2D.h"
								"include/DungeonEscape/BackgroundTile.h"
								"include/DungeonEscape/Branch.h"
								"include/DungeonEscape/Common.h"
								"include/DungeonEscape/DialogBoxSprite.h"
								"include/DungeonEscape/Direction.h"
								"include/DungeonEscape/Door.h"
								"include/DungeonEscape/Enemy.h"
								"include/DungeonEscape/Entity.h"
								"include/DungeonEscape/GameManager.h"
								"include/DungeonEscape/GameText.h"
								"include/DungeonEscape/HeartDisplay.h"
								"include/DungeonEscape/MagicOrb.h"
								"include/DungeonEscape/MainMenuBackground.h"
								"include/DungeonEscape/Math.h"
								"include/DungeonEscape/Player.h"
								"include/DungeonEscape/Renderable.h"
								
								"include/DungeonEscape/ResourceFont.h"
								"include/DungeonEscape/ResourceTexture.h"
								"include/DungeonEscape/Room.h"
								"include/DungeonEscape/SkeletonEnemy.h"
								"include/DungeonEscape/ThreadPool.h"
								"include/DungeonEscape/UpdateReceiver.h"
								"include/DungeonEscape/WorldMap.h")


file(GLOB_RECURSE RESOURCE_FILES
     "resources/*.*"
)

foreach(file ${RESOURCE_FILES})
	file(RELATIVE_PATH CURRENT_RESOURCE_PATH ${CMAKE_SOURCE_DIR} ${file})

	get_filename_component(CURRENT_RESOURCE_NAME ${file} NAME_WE)
	string(TOUPPER ${CURRENT_RESOURCE_NAME} CURRENT_RESOURCE_NAME)
	target_compile_definitions(${PROJECT_NAME} PRIVATE RES_${CURRENT_RESOURCE_NAME}="${CURRENT_RESOURCE_PATH}")
endforeach()


target_link_libraries(${PROJECT_NAME} PUBLIC sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

IF (WIN32)
	target_link_libraries(${PROJECT_NAME} PUBLIC sfml-main)
ENDIF()

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(${PROJECT_NAME} PUBLIC "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_THREAD_LIBS_INIT})
endif()



target_include_directories(${PROJECT_NAME} PUBLIC "include")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/resources/ ${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE}/resources)
