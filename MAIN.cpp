#include "includesVoids.h"
void mainV(){
	curTick=GetTickCount();
	if(INIT_==true)INIT();//after initialization:
	if(curTick-sleepTick>50/*250*/&&start==true){//greater than roughly 50 milliseconds (50 ticks);
		MOVE();
		sleepTick=GetTickCount();
	}
	int count1=0;
	for(int n=0;n<10;n++){//n=x in this case;
		for(int o=0;o<10;o++){//o=y in this case;//cout<<"count1: "<<count1<<", ("<<WALL[count1].x<<","<<WALL[count1].y<<")\n";
			if(WALL[count1].x!=NULL&&WALL[count1].y!=NULL||count1==99||count1==0||WALL[count1].x!=0&&WALL[count1].y!=0){
				glLoadIdentity();//load the spaces between the walls;
				glColor4f(1,1,1,1);
				glTranslatef((WALL[count1].x*2)-9,(WALL[count1].y*2)-9,-15);//-9,-7,-5,-3,-1,1,3,5,7,9;
				if(count1==0||WALL[count1].x==start_[0]&&WALL[count1].y==start_[1])glColor3f(0,1,0);
				if(count1==99)glColor3f(1,0,0);
				glCallList(wallList);
			}//load the board/maze;
			glLoadIdentity();
			glColor4f(1,1,1,1);
			glTranslatef((n*2)-9,(o*2)-9,-15);
			glCallList(boardList);
			count1+=1;//increase the counter;
		}
		glLoadIdentity();//load the player;
		glColor4f(1,.4,.2,1);
		glTranslatef((PLAYER.x*2)-9,(PLAYER.y*2)-9,-15);
		glCallList(playerList);
	}
;}//end void;
void display(void){
	glLoadIdentity();
		/*I enable these in every project, so some may not be necessary.*/
		glEnable(GL_TEXTURE_3D);
		glEnable(GL_NORMALIZE);
		glEnable(GL_POLYGON_OFFSET_FILL);
		glEnable(GL_COLOR_MATERIAL); 
		glEnable(GL_BLEND);glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glClearColor(0,0,0,1);
			glDepthFunc(GL_GEQUAL);glClearDepth(0);
    	mainV();
	    glutSwapBuffers();//glutFullScreen();
}//end void;
void reshape(GLint w,GLint h){
	glMatrixMode(GL_PROJECTION);//regular view;
		glLoadIdentity();
		glViewport(0,0,w,h);
		gluPerspective(90.f,(GLfloat)w/(GLfloat)h,0.0f,1.0f); 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
}//end void;
int main(int argc,char **argv){//main and set window properties;//	srand(time(NULL));
    glutInit(&argc,argv);
    	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/1.25,glutGet(GLUT_SCREEN_HEIGHT)/1.25);
    	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-glutGet(GLUT_SCREEN_WIDTH)/1.25)/2,(glutGet(GLUT_SCREEN_HEIGHT)-glutGet(GLUT_SCREEN_HEIGHT)/1.25)/2);
		glutCreateWindow("AI MAZE");
    glutDisplayFunc(display);glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed);
    glutMainLoop();
    return 0;
}
