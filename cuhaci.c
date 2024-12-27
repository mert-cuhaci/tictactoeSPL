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

void incrementPlayer(){
	turn += 1;
	
	#ifdef PLAYERS == 2
		turn = turn % 2;
	#endif
	
	#ifdef PLAYERS == 3
		turn = turn % 3
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

int countInDirection(int x, int y, int dirx, int diry){
	r = 0;
	int cursorrow = y
	int cursorcol = x
	while(cursorrow < SIZE && cursorcol < SIZE && cursorrow >= 0 && cursorcol >= 0){
		if( turnToChar(lastmoveturn) == board[cursorrow][cursorcol]{
			r++;
		}
		else{
			return 0;
		}
	}
	return r
}

int gameNotOver(){
	
}

int main(void) {
    if ( !checkFeatures()){
    	return 1;
    }
    while(gameNotOver()){
	    printBoard();
	    #ifdef time
	    	time1 = (double) clock() / CLOCKS_PER_SEC;
	    #endif
	    getInput();
	    incrementPlayer();
	    #ifdef time
	    	time2 = (double) clock() / CLOCKS_PER_SEC;
	    #endif
	    updateBoard();
	    
	    }
    return 0;
}



















