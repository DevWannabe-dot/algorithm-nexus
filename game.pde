/**
* @file    jogo.pde
* @brief   Resolution of the Conway's Game of Life problem @ OBI 2024 (P2)
* @author  Pedro Henrique Pinto de Oliveira
* @date    2024-06-29
*/

/* Constants */
public static final int SUCCESS = 0;
public static int WINDOW_W;
public static int WINDOW_H;
public static final int MAX_N = 50;
public static final int ALIVE = 1;
public static final int DEAD = 0;
public static final int BORDER = 2;
public static final int CHAR_INT_OFFSET = 48;

int [][]m = new int[MAX_N+BORDER][MAX_N+BORDER];
int [][]m1 = new int[MAX_N+BORDER][MAX_N+BORDER];

/* Functions */
/**
* (system) Allows defining the parameters to size() with a variable.
*/
void settings()
{
  WINDOW_W = (displayHeight > 1280 ? 640 : displayHeight/2);
  WINDOW_H = WINDOW_W;
  
  size(WINDOW_W, WINDOW_H);
}
/**
* (system) Runs once when the program starts.
*/
void setup()
{
  fill(255);
  frameRate(1);
  noLoop();
  
  main();
}
/**
* (user) Draws a N*N matrix
* @param N Dimensions of the cell
*/
void drawSquareMatrix(int N)
{
  int w = WINDOW_W/N;
  int h = WINDOW_H/N;
  
  for(int i = 1; i < N+1; i++){
    for(int j = 1; j < N+1; j++){
      fill(255 - (m[i][j]*255));
      stroke(84);
      rect((j-1)*w, (i-1)*h, w, h);
    }
  }
}
/**
* (user) Updates the cell to the next state
* @param N Dimensions of the cell
*/
void nextCellState(int N)
{
  for(int i = 1; i < N; i++){
    for(int j = 1; j < N+1; j++){
      int sum = (m[i-1][j-1] + m[i-1][j] + m[i-1][j+1]) + (m[i][j-1] + m[i][j+1]) + (m[i+1][j-1] + m[i+1][j] + m[i+1][j+1]);
      if(m[i][j] == DEAD){
        m1[i][j] = (sum == 3 ? ALIVE : DEAD);
      } else if (m[i][j] == ALIVE){
        m1[i][j] = ( ((sum == 3) || (sum == 2)) ? ALIVE : DEAD );
      }
    }
  }
  // Shallow copy m1 to m
  for(int i = 1; i < N+1; i++){
    System.arraycopy(m1[i], 0, m[i], 0, N+1);
  }
}
/**
* (user) Runs the algorithm routines and coordinates function calls.
*/
int main()
{
  // Parse input from file
  int nRowsCols, nSteps;
  String[] input = loadStrings("examples/game.txt");
  
  nRowsCols = (int)(input[0].charAt(0) - CHAR_INT_OFFSET);
  nSteps = (int)(input[0].charAt(2) - CHAR_INT_OFFSET);
  
  // Receive initial state
  for(int i = 0; i < nRowsCols; i++){
    for(int j = 0; j < nRowsCols; j++){
      char c = input[i+1].charAt(j); // skips first input line with nRowsCols and nSteps
      m[i+1][j+1] = (int)(c-CHAR_INT_OFFSET); // considers northern and western borders
    }
  }
  // Shallow copy m to m1
  for(int i = 1; i < nRowsCols+1; i++){
    System.arraycopy(m[i], 0, m1[i], 0, nRowsCols+1);
  }
  drawSquareMatrix(nRowsCols);
  
  // Process Qth state
  for(int i = 0; i < nSteps; i++){
    nextCellState(nRowsCols);
    drawSquareMatrix(nRowsCols);
  }
  return SUCCESS;
}

void draw()
{
  
  // Keyboard interaction (rewind, fast forward)
  // makes use of Processing's matrix stack
  // redraw();
}
