#include "includesVoids.h"
void INIT(){
	system("CLS");
	curTick=0;
    sleepTick=0;
	start=false;
	PLAYER.previousPos=0;
	PLAYER.canMoveMultiplePos=false;
	PLAYER.endedNode=false;
	nodeMode=false;
	//_BOARD
	WALL.resize(wallSize);//set the size of the vector;
		wallSize=100;
		for(int n=0;n<100;n++){//set the values of the nonwalls;
			WALL[n].x=0;
			WALL[n].y=0;
			posFilled[n]=0;
		}
		savedPosSize=1;
	//LIST:
		boardList=1;
		wallList=2;
		playerList=3;
		INIT_=true;
	//TIMES ETC: 
	   	curTick=0;
    	sleepTick=0;
	glNewList(boardList,GL_COMPILE_AND_EXECUTE);
		glBegin(GL_POINTS);
			glVertex2f(-1,1);
			glVertex2f(1,1);
			glVertex2f(1,-1);
			glVertex2f(-1,-1);
		glEnd();
	glEndList();
	///////////////////////////////
	glNewList(wallList,GL_COMPILE_AND_EXECUTE);
		glBegin(GL_POLYGON);
			glVertex2f(-1,1);
			glVertex2f(1,1);
			glVertex2f(1,-1);
			glVertex2f(-1,-1);
		glEnd();
	glEndList();
	///////////////////////////////
	glNewList(playerList,GL_COMPILE_AND_EXECUTE);
		glBegin(GL_POLYGON);
			glVertex2f(-.5,.5);
			glVertex2f(.5,.5);
			glVertex2f(.5,-.5);
			glVertex2f(-.5,-.5);
		glEnd();
	glEndList();
		//time_t seed=1490771120;//1489015745;//1488499038;/*1488350758;*//*1488217348;*//*1488184311;*//*1488155501*//*1488152772*//*1488151440*/;
		//srand(seed);//specific seed;
		time_t seed;srand(time(&seed));//random seed;
		cout<<"Seed: "<<seed<<"\n";
	int xx,yy,xOrY;//rand for x or y first;
	int loopCount=0;
	while(loopCount<2){
		xOrY=rand()%2+0;
		if(xOrY==0){
			xx=rand()%10+0;//0 through 9
			yy=rand()%2/*2*/+0;//0 or 9;
			if(yy==0){
				yy=0;
			}
			if(yy==1){
				yy=9;
			}
		}
		else{
			yy=rand()%10+0;//0 through 9;
			xx=rand()%2/*2*/+0;//0 or 9
			if(xx==0){
				xx=0;
			}
			if(xx==1){
				xx=9;
			}
		}
		if(loopCount==0){
			start_[0]=xx;start_[1]=yy;
		}
		else{
			end_[0]=xx;end_[1]=yy;
		}
		if(loopCount==1){//make sure that the endpoint is not on the same x or y to the startpoint;
			if(start_[0]==end_[0]||start_[1]==end_[1]){
				loopCount=-1;
			}
		}
		loopCount+=1;//guarantee that the position cannot be 0,0;0,9;9,9;9,0;
		if(	start_[0]==0&&start_[1]==0||start_[0]==0&&start_[1]==9||start_[0]==9&&start_[1]==9||start_[0]==9&&start_[1]==0){
			loopCount=0;
		}
		if(	end_[0]==0&&end_[1]==0||end_[0]==0&&end_[1]==9||end_[0]==9&&end_[1]==9||end_[0]==9&&end_[1]==0){
			loopCount=1;
		}
	}
cout<<"start:\t("<<start_[0]<<","<<start_[1]<<")\nfinish:\t("<<end_[0]<<","<<end_[1]<<")\n";//this is the starting point on any edge of the map;
//fill with spaces around walls;
	bool finished=false;
	int count_=0;
	int direction=-1;//1=left;2=right;3=down;4=up;
	int generatePath=0;
	while(finished==false){//create a path for the maze to work with;
		if(count_==0){
			direction=-1;
				xx=start_[0];
				yy=start_[1];
			WALL[0].x=xx;
			WALL[0].y=yy;
			count_+=1;
			bool while1=false;
			while(	xx==1&&yy==0&&direction!=4||xx==8&&yy==0&&direction!=4||xx==1&&yy==9&&direction!=3||xx==8&&yy==9&&direction!=3||
					xx==0&&yy==1&&direction!=2||xx==9&&yy==1&&direction!=1||xx==0&&yy==8&&direction!=2||xx==9&&yy==8&&direction!=1
			){
				direction=rand()%4+1;//move in a random direction;//cout<<direction<<"\t";
				while1=true;
			}
			if(while1==false){//make the path in range;
				if(xx+1>=9){xx-=1;direction=1;}//move left, so direction=1;
				if(xx-1<=0){xx+=1;direction=2;}//move right, so direction=2;
				if(yy+1>=9){yy-=1;direction=3;}//move down, so direction=3;
				if(yy-1<=0){yy+=1;direction=4;}//move up, so direction=4;
			}
			WALL[count_].x=xx;
			WALL[count_].y=yy;
			count_+=1;
				generatePath=rand()%7+1;//between 8 and 0; move a random number of spots in that direction;
			for(int n=0;n<generatePath;n++){
				if(direction==1)xx-=1;
				if(direction==2)xx+=1;
				if(direction==3)yy-=1;
				if(direction==4)yy+=1;
					WALL[count_].x=xx;
					WALL[count_].y=yy;
				count_+=1;
			}
		}
		else{
			if(	(xx+1)==end_[0]&&(yy)==end_[1]||
				(xx-1)==end_[0]&&(yy)==end_[1]||
				(xx)==end_[0]&&(yy-1)==end_[1]||
				(xx)==end_[0]&&(yy+1)==end_[1]
			){
			finished=true;//path created to end;//cout<<"FOUND END\n";
				break;
			}
			if(count_>=98){
				count_=0;
				xx=start_[0];
				yy=start_[1];
				for(int n=0;n<100;n++){
					WALL[n].x=0;
					WALL[n].y=0;
				}
				continue;//cout<<"COUNT LIMIT REACHED"<<"\n";
			}
			direction=rand()%4+1;//move in a random direction;
			while(xx+1>=9&&direction==2||xx-1<=0&&direction==1||yy+1>=9&&direction==4||yy-1<=0&&direction==3){
				direction=rand()%4+1;//move in a random direction;
			}
			generatePath=rand()%7+1;//between 8 and 0; move a random number of spots in that direction;
			for(int n=0;n<generatePath;n++){
				if((xx+1)>=9&&direction==2||(xx-1)<=0&&direction==1||(yy+1)>=9&&direction==4||(yy-1)<=0&&direction==3||count_>98){;generatePath=0;break;}
				if(direction==1)xx-=1;
				if(direction==2)xx+=1;
				if(direction==3)yy-=1;
				if(direction==4)yy+=1;
					WALL[count_].x=xx;
					WALL[count_].y=yy;
				count_+=1;
			}
		}
	}
	WALL[0].x=start_[0];
	WALL[0].y=start_[1];
	WALL[99].x=end_[0];
	WALL[99].y=end_[1];
	//set player inits: 
PLAYER.nodeVisitedPosition.resize(savedPosSize);
			PLAYER.start[0]=start_[0];//x
			PLAYER.start[1]=start_[1];//y
			PLAYER.end[0]=end_[0];//x
			PLAYER.end[1]=end_[1];//y
			PLAYER.x=PLAYER.start[0];
			PLAYER.y=PLAYER.start[1];
		cout<<"Map generated: ";
	for(int n=0;n<100;n++){
		if(WALL[n].x!=0&&WALL[n].y!=0||WALL[n].x==start_[0]&&WALL[n].y==start_[1]||WALL[n].x==end_[0]&&WALL[n].y==end_[1]){
			cout<<"("<<WALL[n].x<<", "<<WALL[n].y<<")\t";
			posFilled[((100-((10*(10-(WALL[n].y+1)))+(10-(WALL[n].x+1))))-1)]=1;
			if(WALL[n].x==start_[0]&&WALL[n].y==start_[1]){
				PLAYER.actualXYPosition=((100-((10*(10-(WALL[n].y+1)))+(10-(WALL[n].x+1))))-1);
			}
		}
	}cout<<"\n";
	START_=((100-((10*(10-(WALL[0].y+1)))+(10-(WALL[0].x+1))))-1);//cout<<"player.x: "<<PLAYER.x<<", player.y: "<<PLAYER.y<<", start_[0]"<<start_[0]<<", start_[1]"<<start_[1]<<"\n";
	/*END INIT*/INIT_=false;
}
