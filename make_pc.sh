g++ -O2 -std=c++14 -Iinclude/ -lSDL2 -lSDL2_image -lSDL2_ttf -ltinyxml2 `sdl2-config --cflags --libs` source/engine/*.cpp source/core/*.cpp source/states/*.cpp -o sdlproj