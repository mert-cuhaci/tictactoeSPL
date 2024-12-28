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
//THIS HAS NOTHING TO DO WITH THE FEAUTURE "BLOCKED"
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
		lastmoveturn = lastmoveturn % 3
	#endif
}

#ifdef SIZE == 3
char board[3][3] =    {	{'_', '_', '_'} , 
						{'_', '_', '_'} , 
						{'_', '_', '_'}};
#endif

#ifdef SIZE == 5
char board[5][5] =    {	{'_', '_', '_', '_', '_'} , 
						{'_', '_', '_', '_', '_'} , 
						{'_', '_', '_', '_', '_'} , 
						{'_', '_', '_', '_', '_'} , 
						{'_', '_', '_', '_', '_'}}
#endif

#ifdef SIZE == 7
char board[7][7] =    {	{'_','_','_','_','_', '_', '_'} , 
						{'_','_','_','_','_', '_', '_'} , 
						{'_','_','_','_','_', '_', '_'} ,
						{'_','_','_','_','_', '_', '_'} ,
						{'_','_','_','_','_', '_', '_'} ,
						{'_','_','_','_','_', '_', '_'} ,
						{'_','_','_','_','_', '_', '_'}};
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
		printf("\n");
	}
}

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
			cursorrow += diry;
			cursorcol += dirx;
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
	return 1;
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

int nextPlayer(){
	#ifdef PLAYERS == 2
		return (lastmoveturn + 1) % 2
	#endif
	#ifdef PLAYERS == 3
		int t = lastmoveturn + 1
		while(blocked[t % 3]){
			t++;
		}
		return t % 3
	#endif
}

void getInput(){
	int num1, num2;
	while(1){
    // Prompt the user for input
    printf("Enter row and column separated by a space: ");

    // Read input from standard input
    if (scanf("%d %d", &num1, &num2) == 2  && board[num1][num2] == '_') {
		lastmovex = num2;
		lastmovey = num1;
		board[lastmovex][lastmovey] == turnToChar(nextPlayer());
		break;
    } else {
        // Parsing failed
        printf("Error: These values arent accepted\n");
    }
    }
}

#ifdef BLOCKED
void fillBlocked(){
	int b = 1;
	#ifdef SIZE == 5
		b += 2 ;
	#endif
	
	#ifdef SIZE == 7
		b += 4;
	#endif
	
	#ifdef LEN == 4
		b -= 1;
	#endif
	
	#ifdef LEN == 5
		b -= 2;
	#endif
	
	while(b > 0){
		int r = rand() % SIZE;
		int c = rand() % SIZE;
		if(board[r][c] == '_'){
			board[r][c] = 'B';
			b--;
		}
	}
}
#endif

#ifdef JOKER
void fillJoker(){
	int j = 1;
	#ifdef SIZE == 5
	j += 1;
	#endif
	
	#ifdef SIZE == 7
	j += 2;
	#endif
	
	#ifdef LEN == 4
	j++;
	#endif
	
	#ifdef LEN == 5
	j += 2;
	#endif
	while(j > 0){
		int r = rand() % SIZE;
		int c = rand() % SIZE;
		if(board[r][c] == '_'){
			board[r][c] = 'J';
			j--;
		}
	}
}
#endif

int main(void) {
    srand(time(NULL));
    if ( !checkFeatures()){
    	while(1){}
    }
    #ifdef BLOCKED
    	fillBlocked();
    #endif
    
    #ifdef JOKER
    	fillJoker();
    #endif
    
    while(gameNotOver()){
	    printBoard();
	    #ifdef TIME
	    	time1 = ((double) clock()) / CLOCKS_PER_SEC;
	    #endif
	    getInput();
	    #ifdef TIME
	    	time2 = ( (double) clock() ) / CLOCKS_PER_SEC;
	    #endif
	    timecheck(time2-time1);
	    incrementPlayer();
	    }
    return 0;
}



















