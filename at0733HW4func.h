#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include<cctype>
using namespace std;

enum tiles {box= 'B', avatar = 'A' , wall = 'X' , home = 'H' , space = ' ' };
//Define an enumerated type, and its constants, that stores each of the possible types of tiles in the room(B for box, A for avatar, X for wall, H for home location, and Space for empty spots)


struct room {
  tiles type; 
  bool home ;
};
void header() ;
void fileinclude(room ** area , int size);
void display(room ** area , int size);
bool gameover(room ** area , int size);
bool toupper(room** area,int size,int xavatar,int yavatar);
bool todown(room** area,int size,int xavatar,int yavatar);
bool toleft(room** area,int size,int xavatar,int yavatar);
bool toright(room** area,int size,int xavatar,int yavatar);
bool move(room **area , int size , int xavatar , int yavatar ,int& moves);
void savefile(room** area , int size, int moves);
void reopen(room ** area , int size,int& moves);

//////////////////////////////////////////////////////////////

