/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions; atoi(argv[1]) convert a string to an integer
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J"); // \033[2J clears the entire screen(j) from top to bottom(2) 
    printf("\033[%d;%dH", 0, 0); // \033[0;0H) positions the cursor at row 0, column 0.
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000); // wait for 2 seconds
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    
    int counter=1;
    
    for(int i=0; i<d; i++)
    {
    
        for(int j=0; j<d; j++)
        {
            
            board[i][j] = d*d-counter;
            counter++;
            
        } // Iterate columns
        
    } // Iterate rows
    
    /* if d is an even number, swap 1 and 2 */
    
    if(d%2 == 0) 
    {
        int tempt = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = tempt;
        
        
    }
   
}


/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // print the current array 
    
    for(int i=0; i<d; i++)
    {
        
        for(int j=0; j<d; j++)
        {
            
            if(board[i][j]==0)
            {
                printf("%2c", '_');
            }
            
            else
            {
                printf("%2d", board[i][j]);
            }
            
        } //print col
        
        printf("\n"); //print new line
        
    } //print row

}



/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
 
bool move(int tile) 
{
    
    // if tile == board[i][j] 
    
    for(int i = 0; i < d; i++)
    {
        
        for(int j = 0; j < d; j++)
        {
            
            if(board[i][j] == tile)
            {
               
              // if user input can be found on the board, do something 
              
              
               int row_loc = i;
               int col_loc = j; 
                
                if (row_loc - 1 >= 0 && board[row_loc-1][col_loc]==0) 
                {
                    board[i][j] = 0 ;
                    board[row_loc-1][col_loc] = tile;
                    return true;
                }
                
                if (row_loc + 1 < d && board[row_loc+1][col_loc]==0) 
                {
                    board[i][j] = 0 ;
                    board[row_loc+1][col_loc] = tile;
                    return true;
                }
                
                if (col_loc - 1 >= 0 && board[row_loc][col_loc-1]==0) 
                {
                    board[i][j] = 0 ;
                    board[row_loc][col_loc-1] = tile;
                    return true;
                }
                
                if (col_loc + 1 < d && board[row_loc][col_loc+1]==0) 
                {
                    board[i][j] = 0 ;
                    board[row_loc][col_loc+1] = tile;
                    return true;
                }
               
                
            } // if board[i][j] == tile
            
        }  // iterate the col board[i][j]
    
    } // iterate the row board[i][j]
    
  
return false;
    
}
    
   
bool won(void)
{
   
   int counter = 1; 
    
    for(int i=0; i<d; i++){
        
        for(int j=0; j<d; j++){
            
            if (board[i][j] == counter) {
                
                 counter = counter + 1;
            }
            
            else if (board[d-1][d-1] == 0 && counter == d*d) {
                
                return true;
            }
    
            
        } // loop through j
        
    } // loop through i 
    
   return false;
    
}