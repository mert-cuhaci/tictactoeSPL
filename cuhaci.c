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

void incrementPlayer(){
	turn += 1;
	
	#ifdef PLAYERS == 2
		turn = turn % 2;
	#endif
	
	#ifdef PLAYERS == 3
	
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

void checkFeatures(){
	#ifdef SIZE > LEN
	printf("Feature selection is valid.");
	#else
	printf("Feature selection is invalid.");
	#endif
}


int main(void) {
    checkFeatures();
    while(True){
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



















