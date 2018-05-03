/*linkers in project: 
-lglut32
-lglu32
-lopengl32
-lwinmm
-lgdi32
-lopengl32
-lmingw32
*/
/*I include these in every project, so some may not be necessary.*/
#ifndef INCLUDESVOIDS_H
#define INCLUDESVOIDS_H
		#include <future>
		#include <math.h>
		#include <ctime>
		#include <windows.h>
		#include <iostream>
		#include <stdlib.h>
		#include <stdio.h>
		#include <stdarg.h>
		#include <cstring>
		#include <fstream>
		#include <GL/glew.h>
		#include <gl\gl.h>
		#include <gl\glext.h>
		#include <gl\glaux.h>
		#include <gl\glu.h>
		#include <GL\glut.h>
		#include <assert.h>
		#include <sstream>
		#include <iomanip>
		#include <ctime>
		#include <cstring>
		#include <cmath>
		#include <fstream>
		#include <time.h>
		#include <string.h>
		#include <string>
		#include <cstdlib>
		#include <cstdio>
		#include <gl\glfw.h>
		#include <vector>
		#include <conio.h>
		#include <new>
	using namespace std;
	//DEFINITIONS: 
	//VOIDS: 
		void INIT();
			void mousemoveunpressed(int x, int y);
			void mouseclick(int button,int state,int x,int y);
			void skeyd (int key,int x,int y);
			void keyPressed(unsigned char key,int x,int y);
		void MOVE();
	//STRUCTURES: 
		struct _WALL{//this was originally going to be the wall, but it is the path the robot can move through. 
			int x,y;
		};extern vector<_WALL> WALL;extern int wallSize;extern int posFilled[100];
		struct _PLAYER{
			int x,y;//current position;
			int actualXYPosition;//from 0-99
			int previousPos;//from 0-99
			int start[2],end[2];//start position;
			vector <int> nodeVisitedPosition;//nodePosition;//
			bool endedNode;
			bool canMoveMultiplePos;
		};extern _PLAYER PLAYER;extern int savedPosSize;//used for backtracking;
	//GLOBALS: 
		extern bool INIT_;
		extern int START_;
		extern int start_[2],end_[2];//start, end points of maze;
		extern bool start;//start the robot to navigate through the maze;
		extern bool nodeMode;//is a node active or not?
		//LIST:
			extern int boardList;
			extern int wallList;
			extern int playerList;
	    //FILES: 
    	//TIMES_ETC: 
    		extern DWORD curTick;
    		extern DWORD sleepTick;
		//MAIN_LOOP STUFF: 
#endif
