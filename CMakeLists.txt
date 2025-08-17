#run this in the root file if it doesnt do it: (linux)
#cd build
#rm -rf *
#cmake ..
#make
#./doodleAP

#if you get an failed to load font error
#go to GameRepresentation/MenuState.cpp on line 27 change the 2 paths to this "./fonts/arial.ttf" and this "./pics/image.gif" or to this "../fonts/arial.ttf" and this "../pics/image.gif"
#go also to GameRepresentation/window.cpp on line 52 and to the same


cmake_minimum_required(VERSION 3.24)
project(doodleAP)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

set(RESOURCE_FILES
        fonts/arial.ttf
)

add_executable(doodleAP main.cpp LogicLibrary/highscoreManager.cpp fonts/arial.ttf GameRepresentation/game.h GameRepresentation/game.cpp LogicLibrary/world.h LogicLibrary/world.cpp GameRepresentation/concreteFactory.h GameRepresentation/concreteFactory.cpp LogicLibrary/abstractFactory.h LogicLibrary/stopwatch.h LogicLibrary/stopwatch.cpp LogicLibrary/entityModel.h LogicLibrary/entityModel.cpp GameRepresentation/entityView.h GameRepresentation/entityView.cpp GameRepresentation/doodleView.h GameRepresentation/doodleView.cpp LogicLibrary/doodleModel.h LogicLibrary/doodleModel.cpp LogicLibrary/subject.h LogicLibrary/observer.h GameRepresentation/window.h LogicLibrary/windowV.h GameRepresentation/window.cpp LogicLibrary/observer.cpp LogicLibrary/subject.cpp GameRepresentation/State.h GameRepresentation/StateManager.h GameRepresentation/StateManager.cpp GameRepresentation/MenuState.h GameRepresentation/MenuState.cpp GameRepresentation/LevelState.cpp GameRepresentation/LevelState.h LogicLibrary/score.cpp LogicLibrary/score.h LogicLibrary/highscoreManager.cpp LogicLibrary/highscoreManager.h LogicLibrary/malusManager.cpp LogicLibrary/malusManager.h LogicLibrary/random.h LogicLibrary/random.cpp GameRepresentation/platformView.cpp GameRepresentation/platformView.h LogicLibrary/platformModel.cpp LogicLibrary/platformModel.h LogicLibrary/BGTileModel.cpp LogicLibrary/BGTileModel.h GameRepresentation/BGTileView.cpp GameRepresentation/BGTileView.h LogicLibrary/camera.cpp LogicLibrary/camera.h LogicLibrary/bonusEffect.cpp LogicLibrary/bonusEffect.h LogicLibrary/bonusModel.cpp LogicLibrary/bonusModel.h GameRepresentation/bonusView.cpp GameRepresentation/bonusView.h)

target_include_directories(doodleAP PRIVATE
        ${SFML_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/LogicLibrary
        ${CMAKE_SOURCE_DIR}/GameRepresentation
)

target_link_libraries(doodleAP PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
)

add_custom_command(TARGET doodleAP POST_BUILD
        COMMENT "Copying resource files..."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/fonts
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/pics
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/fonts/arial.ttf ${CMAKE_BINARY_DIR}/fonts/
)




#if you want to run the game on windows:

#cmake_minimum_required(VERSION 3.24)
#project(doodleAP)
#
#set(CMAKE_CXX_STANDARD 17)
#
#add_executable(doodleAP main.cpp LogicLibrary/highscoreManager.cpp fonts/arial.ttf GameRepresentation/game.h GameRepresentation/game.cpp LogicLibrary/world.h LogicLibrary/world.cpp GameRepresentation/concreteFactory.h GameRepresentation/concreteFactory.cpp LogicLibrary/abstractFactory.h LogicLibrary/stopwatch.h LogicLibrary/stopwatch.cpp LogicLibrary/entityModel.h LogicLibrary/entityModel.cpp GameRepresentation/entityView.h GameRepresentation/entityView.cpp GameRepresentation/doodleView.h GameRepresentation/doodleView.cpp LogicLibrary/doodleModel.h LogicLibrary/doodleModel.cpp LogicLibrary/subject.h LogicLibrary/observer.h GameRepresentation/window.h LogicLibrary/windowV.h GameRepresentation/window.cpp LogicLibrary/observer.cpp LogicLibrary/subject.cpp GameRepresentation/State.h GameRepresentation/StateManager.h GameRepresentation/StateManager.cpp GameRepresentation/MenuState.h GameRepresentation/MenuState.cpp GameRepresentation/LevelState.cpp GameRepresentation/LevelState.h LogicLibrary/score.cpp LogicLibrary/score.h LogicLibrary/highscoreManager.cpp LogicLibrary/highscoreManager.h LogicLibrary/malusManager.cpp LogicLibrary/malusManager.h LogicLibrary/random.h LogicLibrary/random.cpp GameRepresentation/platformView.cpp GameRepresentation/platformView.h LogicLibrary/platformModel.cpp LogicLibrary/platformModel.h LogicLibrary/BGTileModel.cpp LogicLibrary/BGTileModel.h GameRepresentation/BGTileView.cpp GameRepresentation/BGTileView.h LogicLibrary/camera.cpp LogicLibrary/camera.h LogicLibrary/bonusEffect.cpp LogicLibrary/bonusEffect.h LogicLibrary/bonusModel.cpp LogicLibrary/bonusModel.h GameRepresentation/bonusView.cpp GameRepresentation/bonusView.h)
#
#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR C:/SFML-2.5.1/lib/cmake/SFML)
#find_package(SFML COMPONENTS audio system graphics window network REQUIRED)
#
#include_directories(C:/SFML-2.5.1/include)
#target_link_libraries(doodleAP sfml-system sfml-graphics sfml-audio sfml-window sfml-network)