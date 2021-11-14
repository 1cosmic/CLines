#include <iostream>

// All headers (do clean main.cpp).
#define MAX_WIDTH 9
#define MAX_HEIGTH 9

using namespace std;


enum Colors {C_RED = 1, C_ORANGE, C_YELLOW, C_GREEN, C_BLUE, C_INDIGO, C_PURPLE};
int nextColors[3] = {0, 0, 0};  // next three colors.
int free_places = 72;  // counter of free space.
int i, str, col;

bool free_string[MAX_WIDTH];
int Field[MAX_WIDTH][MAX_HEIGTH];  // field of game.

void generate_colors(int nextColors[]) {
    // Generate next three color and put it in nextColors.

    int color;

    cout << "Next colors: ";
    for(i = 0; i < 3; ++i) {

        color = rand() % 7;  // select color.
        // If color ID == 0, set ID = 7.
        nextColors[i] = (color > 0) ? color : 7;
        cout << nextColors[i] << '|';
    }

    cout << endl;
}

bool check_free_places(const int free_places) {
    // Return True, if we have > 3 free places.

    if ((free_places - 3) >= 0)
        return true;
    else
        return false;
}

int select_string(bool select_string[]) {
    // Select free string.
    int str;

    while(str = rand() % MAX_WIDTH) {
        return true;
    }
    
}

bool put_colors(const int nextColors[]) {
    int color;
    for(color = 0; color < 3; ++color) {

    }

    return true;
}

void initialise_units(void) {
    // Initialise Field, free_string.

    for(str = 0; str < MAX_WIDTH; ++str) {
        free_string[str] = true;

        for (col = 0; col < MAX_HEIGTH; ++col)
            Field[str][col] = 0;
    }

    cout << "Initialisation was been completed." << endl;
}