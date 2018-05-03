#include "includesVoids.h"
void MOVE(){
	cout<<"Current position: "<<PLAYER.actualXYPosition;//<<"||"<<START_;
	bool possibilities[4]={0,0,0,0};//[0] for checking the possible directions; 0,1,2,3
	//always try to move to the left first then right then up then down; then if an endpoint is found, backtrack.//should have multiple backtrack points. one per position found;
	if(PLAYER.x-1==PLAYER.end[0]&&PLAYER.y==PLAYER.end[1]){//end next to player position?
		PLAYER.previousPos=PLAYER.actualXYPosition;
		PLAYER.actualXYPosition-=1;PLAYER.x-=1;
	}
	else if(PLAYER.x+1==PLAYER.end[0]&&PLAYER.y==PLAYER.end[1]){
		PLAYER.previousPos=PLAYER.actualXYPosition;
		PLAYER.actualXYPosition+=1;PLAYER.x+=1;
	}
	else if(PLAYER.x==PLAYER.end[0]&&PLAYER.y+1==PLAYER.end[1]){
		PLAYER.previousPos=PLAYER.actualXYPosition;
		PLAYER.actualXYPosition+=10;PLAYER.y+=1;
	}
	else if(PLAYER.x==PLAYER.end[0]&&PLAYER.y-1==PLAYER.end[1]){
		PLAYER.previousPos=PLAYER.actualXYPosition;
		PLAYER.actualXYPosition-=10;PLAYER.y-=1;
	}//end not found: 
	else if(PLAYER.previousPos==0){//from start position;
		if(	PLAYER.actualXYPosition==19||PLAYER.actualXYPosition==29||PLAYER.actualXYPosition==39||PLAYER.actualXYPosition==49||
			PLAYER.actualXYPosition==59||PLAYER.actualXYPosition==69||PLAYER.actualXYPosition==79||PLAYER.actualXYPosition==89
		){
			possibilities[0]=1;//
			PLAYER.actualXYPosition-=1;PLAYER.x-=1;
			PLAYER.previousPos=PLAYER.actualXYPosition+1;
		}
		else if(PLAYER.actualXYPosition==10||PLAYER.actualXYPosition==20||PLAYER.actualXYPosition==30||PLAYER.actualXYPosition==40||
				PLAYER.actualXYPosition==50||PLAYER.actualXYPosition==60||PLAYER.actualXYPosition==70||PLAYER.actualXYPosition==80
		){
			possibilities[1]=1;//
			PLAYER.actualXYPosition+=1;PLAYER.x+=1;
			PLAYER.previousPos=PLAYER.actualXYPosition-1;
		}
		else if(PLAYER.actualXYPosition>0&&PLAYER.actualXYPosition<9){
			possibilities[2]=1;//
			PLAYER.actualXYPosition+=10;PLAYER.y+=1;
			PLAYER.previousPos=PLAYER.actualXYPosition-10;
		}
		else if(PLAYER.actualXYPosition>90&&PLAYER.actualXYPosition<99){
			possibilities[3]=1;//
			PLAYER.actualXYPosition-=10;PLAYER.y-=1;
			PLAYER.previousPos=PLAYER.actualXYPosition+10;
		}
	}//end initial position;
	else{
		if(posFilled[PLAYER.actualXYPosition-1]==1){possibilities[0]=true;}//can move left;
		if(posFilled[PLAYER.actualXYPosition+1]==1){possibilities[1]=true;}//can move right;
		if(posFilled[PLAYER.actualXYPosition+10]==1){possibilities[2]=true;}//can move up;
		if(posFilled[PLAYER.actualXYPosition-10]==1){possibilities[3]=true;}//can move down;
		if(possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]==1&&PLAYER.endedNode==false){//check for backtracking;
			PLAYER.endedNode=true;
		}
		else if(PLAYER.endedNode==true&&possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]>2){//check for backtracking;
			PLAYER.endedNode=false;
		}
		if(PLAYER.x-1==PLAYER.start[0]&&PLAYER.y==PLAYER.start[1]){possibilities[0]=false;}//check for start position;
		else if(PLAYER.x+1==PLAYER.start[0]&&PLAYER.y==PLAYER.start[1]){possibilities[1]=false;}//check for start position;
		else if(PLAYER.x==PLAYER.start[0]&&PLAYER.y+1==PLAYER.start[1]){possibilities[2]=false;}//check for start position;
		else if(PLAYER.x==PLAYER.start[0]&&PLAYER.y-1==PLAYER.start[1]){possibilities[3]=false;}//check for start position;
		//cout<<"::possibilities: ("<<possibilities[0]<<","<<possibilities[1]<<","<<possibilities[2]<<","<<possibilities[3]<<"); ";
		if((possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]==2)){//boolean for multiple positions the player can move;
			PLAYER.canMoveMultiplePos=true;
		}
		else{//boolean for multiple positions the player can move;
			PLAYER.canMoveMultiplePos=false;
		}
		if((possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]!=1&&PLAYER.canMoveMultiplePos==false)){//not at an endpoint;
			for(int n=0;n<savedPosSize-1;n++){
				if(PLAYER.nodeVisitedPosition[n]==PLAYER.actualXYPosition-1){//l//check position currently at +1+10,-1-10,+10+10,-10-10
					possibilities[0]=false;
					PLAYER.canMoveMultiplePos=false;//cout<<"left";
				}
				if(PLAYER.nodeVisitedPosition[n]==PLAYER.actualXYPosition+1){
					possibilities[1]=false;
					PLAYER.canMoveMultiplePos=false;//cout<<"right";
				}
				if(PLAYER.nodeVisitedPosition[n]==PLAYER.actualXYPosition+10){
					possibilities[2]=false;
					PLAYER.canMoveMultiplePos=false;//cout<<"up";
				}
				if(PLAYER.nodeVisitedPosition[n]==PLAYER.actualXYPosition-10){
					possibilities[3]=false;
					PLAYER.canMoveMultiplePos=false;//cout<<"down";
				}
				if(n==savedPosSize-2){//if all the positions are 0, we can't move: 
					if(possibilities[0]==false&&possibilities[1]==false&&possibilities[2]==false&&possibilities[3]==false){//cout<<"ALL FALSE;";
					cout<<"\tStuck, choosing a semi-random connected position.\n";
						while(1){
							possibilities[0]=false;
							possibilities[1]=false;
							possibilities[2]=false;
							possibilities[3]=false;
							possibilities[rand()%4]=true;
							if(possibilities[0]==true&&PLAYER.actualXYPosition-1==START_){
								possibilities[0]=false;
							}
							if(possibilities[1]==true&&PLAYER.actualXYPosition+1==START_){
								possibilities[1]=false;
							}
							if(possibilities[2]==true&&PLAYER.actualXYPosition+10==START_){
								possibilities[2]=false;
							}
							if(possibilities[3]==true&&PLAYER.actualXYPosition-10==START_){
								possibilities[3]=false;
							}//cout<<"0000possibilities: ("<<possibilities[0]<<","<<possibilities[1]<<","<<possibilities[2]<<","<<possibilities[3]<<"); ";
							if(	posFilled[PLAYER.actualXYPosition-1]==1&&possibilities[0]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition-1&&PLAYER.actualXYPosition-1!=START_||
								posFilled[PLAYER.actualXYPosition+1]==1&&possibilities[1]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition+1&&PLAYER.actualXYPosition+1!=START_||
								posFilled[PLAYER.actualXYPosition+10]==1&&possibilities[2]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition+10&&PLAYER.actualXYPosition+10!=START_||
								posFilled[PLAYER.actualXYPosition-10]==1&&possibilities[3]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition-10&&PLAYER.actualXYPosition-10!=START_
							){
								break;
							}
						}
					}
				}
			}
		}
		if(possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]==1){//can move in one position;
			if(possibilities[0]==true){//l
				PLAYER.actualXYPosition-=1;PLAYER.x-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+1;
			}
			else if(possibilities[1]==true){//r
				PLAYER.actualXYPosition+=1;PLAYER.x+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-1;
			}
			else if(possibilities[2]==true){//u
				PLAYER.actualXYPosition+=10;PLAYER.y+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-10;
			}
			else if(possibilities[3]==true){//d
				PLAYER.actualXYPosition-=10;PLAYER.y-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+10;
			}		
		}
		else if(possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]>1&&PLAYER.canMoveMultiplePos==true){//can move in multiple positions and more than one position;
			if(possibilities[0]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition-1){//l
				PLAYER.actualXYPosition-=1;PLAYER.x-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+1;
			}
			else if(possibilities[1]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition+1){//r
				PLAYER.actualXYPosition+=1;PLAYER.x+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-1;
			}
			else if(possibilities[2]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition+10){//u
				PLAYER.actualXYPosition+=10;PLAYER.y+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-10;
			}
			else if(possibilities[3]==true&&PLAYER.previousPos!=PLAYER.actualXYPosition-10){//d
				PLAYER.actualXYPosition-=10;PLAYER.y-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+10;
			}
		}
		else if(possibilities[0]+possibilities[1]+possibilities[2]+possibilities[3]>1&&PLAYER.canMoveMultiplePos==false){//can move in multiple positions, but only one position; 
			if(possibilities[0]==true){//l
				PLAYER.actualXYPosition-=1;PLAYER.x-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+1;
			}
			else if(possibilities[1]==true){//r
				PLAYER.actualXYPosition+=1;PLAYER.x+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-1;
			}
			else if(possibilities[2]==true){//u
				PLAYER.actualXYPosition+=10;PLAYER.y+=1;
				PLAYER.previousPos=PLAYER.actualXYPosition-10;
			}
			else if(possibilities[3]==true){//d
				PLAYER.actualXYPosition-=10;PLAYER.y-=1;
				PLAYER.previousPos=PLAYER.actualXYPosition+10;
			}
		}
	}
	cout<<"\tPossibilities: ("<<possibilities[0]<<","<<possibilities[1]<<","<<possibilities[2]<<","<<possibilities[3]<<");";
	cout<<"\tCan move to multiple positions? "<<!PLAYER.canMoveMultiplePos<<"\t Backtrack?: "<<PLAYER.endedNode<<"\n";
		//update every visited position and save it: 
			PLAYER.nodeVisitedPosition[savedPosSize-1]=PLAYER.actualXYPosition;
			savedPosSize+=1;
			PLAYER.nodeVisitedPosition.resize(savedPosSize+1);
	if(PLAYER.x==PLAYER.end[0]&&PLAYER.y==PLAYER.end[1]){//end found;
		start=false;
		cout<<"Current position: "<<PLAYER.actualXYPosition<<" found end with "<<savedPosSize-1<<" moves.";
	}
}
