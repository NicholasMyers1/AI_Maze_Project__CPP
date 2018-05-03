#include "includesVoids.h"
void keyPressed(unsigned char key,int x,int y){//glutKeyboardFunc(keyPressed);
	if(key==' '){
		INIT();
	}
	if(key=='s'&&PLAYER.x!=PLAYER.end[0]&&PLAYER.y!=PLAYER.end[1]||key=='S'&&PLAYER.x!=PLAYER.end[0]&&PLAYER.y!=PLAYER.end[1]){
		start=true;
	}
	if(key=='f'||key=='F'){
		glutFullScreen();
	}
	else if(key==27){
		glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH)/1.25,glutGet(GLUT_SCREEN_HEIGHT)/1.25);
		glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH)-glutGet(GLUT_SCREEN_WIDTH)/1.25)/2,(glutGet(GLUT_SCREEN_HEIGHT)-glutGet(GLUT_SCREEN_HEIGHT)/1.25)/2);
	}
}//end void;
