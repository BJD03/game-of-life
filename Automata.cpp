#include <iostream>
#include <cstdlib> 
#include <thread> 
#include <chrono> 
#include <cstdlib>

using namespace std;
const int rows = 30;
const int col = 100;
const float percentage = 0.12;
const int frameRate = 500; 

void clearConsole() {
      system("cls");
}

int main(){
    //booting sequence
    clearConsole();
    char quit;
    cout << "WELCOME TO AUTOMATA";
    for(int i = 0; i < 5; i++){
        cout << "." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    clearConsole();
    cout << "PRESS 'Q' TO QUIT DURING GAMEPLAY";
     for(int i = 0; i < 3; i++){
        cout << "." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "ENJOY!";
    this_thread::sleep_for(chrono::seconds(2));
    clearConsole();

    //creating the grid
    char grid[rows][col];   
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < col; j++){
            grid[i][j] = '-';
            cout << grid[i][j];
    }
    cout << "\n";
    }
    
    //seeds a random number based on the current time
    srand(time(0));
    //brings a random 20% of the cells to life.
    //0 means alive and - means dead
    for(int i = 0; i < (rows * col)* percentage; i++) {
        grid[(rand() % rows) + 0][(rand() % col) + 0] = '0';
    }
    //begining of the main loop
    while(true) {
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                cout << grid[i][j];
                //check to see if the cell is alive
                bool isAlive;
                int aliveNeighbors = 0;
                if(grid[i][j] == '0'){
                    isAlive = true;
                } else {
                    isAlive = false;
                }

                for(int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) continue;
                        int r = i + dr;
                        int c = j + dc;

                        if( r >= 0 && r < rows && c >= 0 && c < col) {
                            if (grid[r][c] == '0'){
                                aliveNeighbors += 1;
                            }
                        }
                    }
                }  
                // cout << "\n" << aliveNeighbors << " Alive neighbors";
                // this_thread::sleep_for(chrono::seconds(2));
                if(isAlive && (aliveNeighbors == 3 || aliveNeighbors == 2)){
                    grid[i][j] = '0';
                } else if(isAlive && (aliveNeighbors < 2 || aliveNeighbors > 3)){
                    grid[i][j] = '-';
                } else if (!isAlive && (aliveNeighbors == 3)){
                    grid[i][j] = '0';
                }             
        }
        cout << "\n";
        }
        this_thread::sleep_for(chrono::milliseconds(frameRate));
        clearConsole();
    }
    //this_thread::sleep_for(chrono::seconds(5));
    return 0;
}