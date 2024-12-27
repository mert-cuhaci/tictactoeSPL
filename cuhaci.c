#include <stdio.h>
#include <time.h>

//preprocessor macros
#define SIZE 3 	//3,5 oder 7
#define PLAYERS 2 	// 2 oder 3
#define TIME 0 		//0, 10 oder 15
#define BLOCKED 0 	//1 oder 0
#define JOKER 0 	//1 oder 0
#define LEN 3		//3,4 oder 5

//global variables
int turn = 0
int lastmovex = -1
int lastmovey = -1
int lastmoveturn = -1
//its always unvalid so i will see if something is wrong

//a player gets block until the end of the game if the time runs out
#ifdef TIME && (PLAYERS == 3)
	int blocked[3] = {0,0,0}
#endif


void incrementPlayer(){
	lasmoveturn += 1;

	#ifdef PLAYERS == 2
		lastmoveturn = lastmoveturn % 2;
	#endif
	
	#ifdef PLAYERS == 3
		while(blocked[lastmoveturn % 3] == 1){
			lastmoveturn++;
		}
		lasmoveturn = lastmoveturn % 3
	#endif
}

#ifdef SIZE == 3
char board[3][3] =    {	{'.', '.', '.'} , 
						{'.', '.', '.'} , 
						{'.', '.', '.'}};
#endif

#ifdef SIZE == 5
char board[3][3] =    {	{'.', '.', '.', '.', '.'} , 
						{'.', '.', '.', '.', '.'} , 
						{'.', '.', '.', '.', '.'} , 
						{'.', '.', '.', '.', '.'} , 
						{'.', '.', '.', '.', '.'}}
#endif

#ifdef SIZE == 7
char board[3][3] =    {	{'.','.','.','.','.', '.', '.'} , 
						{'.','.','.','.','.', '.', '.'} , 
						{'.','.','.','.','.', '.', '.'} ,
						{'.','.','.','.','.', '.', '.'} ,
						{'.','.','.','.','.', '.', '.'} ,
						{'.','.','.','.','.', '.', '.'} ,
						{'.','.','.','.','.', '.', '.'}};
#endif

char turnToChar(int t){
	if(t==0){
		return 'X';
	}
	if(t==1){
		return 'O';
	}
	#ifdef PLAYERS == 3
	if(t==2){
		return 'P';
	}
	#endif 
	return 'a';
}

//displays any necessary information
void printBoard(){
	#ifdef TIME
	printf("Time Limit: %d\n", TIME);
	#endif
	printf("Turn: %c\n", turnToChar());
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			printf("%c ",board[i][j]);
		}
	}
}
#ifdef

int checkFeatures(){
	#ifdef SIZE > LEN
		printf("Feature selection is valid.");
	#else
		printf("Feature selection is invalid.");
		return 0
	#endif
	return 1
}

int countInDirection(int dirx, int diry){
	r = 0;
	int cursorrow = lastmovey
	int cursorcol = lastmovex
	while(cursorrow < SIZE && cursorcol < SIZE && cursorrow >= 0 && cursorcol >= 0){
		if( turnToChar(lastmoveturn) == board[cursorrow][cursorcol] 
			#ifdef JOKER
			|| board[cursorrow][cursorcol] == 'J'
			#endif
			){
			r++;
		}
		else{
			break;
		}
	}
	return r
}

int gameNotOver(){
	diag1 = countInDirection(  1,-1)	-1;
	diag1 += countInDirection(-1, 1);
	diag2 = countInDirection( -1,-1)	-1;
	diag2 += countInDirection( 1, 1);
	vert = countInDirection( 0, 1)		-1;
	vert += countInDirection( 0, -1);
	hor = countInDirection( -1, 0)		-1;
	hor += countInDirection( 1, 0);
	int over = diag1 >= LEN || diag2 >= LEN || ver >= LEN || hor >= LEN
	if( over ){
		printf("game over\n");
		printf("winner is: %c", turnToChar(lastmoveturn));
		while(True){}
	}
	return 0;
}

#ifdef TIME
void timecheck(double t){
	#ifdef PLAYERS == 2
		if(t > TIME){
		printf("game over:\n");
		printf("player %c lost",turnToChar( lastmoveturn ));
		while(1){}
		}
	#endif
	
	#ifdef PLAYERS == 3
		if(t > TIME){
			blocked[lastmoveturn] = 1;
		}
		if(blocked[0] + blocked[1] + blocked[2] == 2){
			printf("game over\n");
			if(blocked[0] == 0){
				printf("player X won");
			}
			if(blocked[1] == 0){
				printf("player O won");
			}
			if(blocked[2] == 0){
				printf("player P won");
			}
			while(1){}
		}
	#endif
}
#endif


int main(void) {
    if ( !checkFeatures()){
    	return 1;
    }
    while(gameNotOver()){
	    printBoard();
	    #ifdef TIME
	    	time1 = ((double) clock()) / CLOCKS_PER_SEC;
	    #endif
	    getInput();
	    incrementPlayer();
	    #ifdef TIME
	    	time2 = ( (double) clock() ) / CLOCKS_PER_SEC;
	    #endif
	    timecheck(time2-time1);
	    updateBoard();
	    
	    }
    return 0;
}



















