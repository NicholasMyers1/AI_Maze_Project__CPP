#include "includesVoids.h"
//GLOBALS
	int start_[2],end_[2];
	bool start=false;
	bool nodeMode;
	bool INIT_=true;
	int START_=0;
	//_BOARD_MAZE
		vector<_WALL> WALL;
		int wallSize=100;
		_PLAYER PLAYER;
		int savedPosSize;
		int posFilled[100];
	//LIST:
		int boardList=1;
		int wallList=2;
		int playerList=3;
	//TIMES ETC: 
	   	DWORD curTick=0;
    	DWORD sleepTick=0;
