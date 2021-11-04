// All headers (do clean main.cpp).
#define MAX_WIDTH 9
#define MAX_HEIGTH 9

enum Colors {C_RED, C_ORANGE, C_YELLOW, C_GREEN, C_BLUE, C_INDIGO, C_PURPLE};


int Field[MAX_WIDTH][MAX_HEIGTH];

int color_1, color_2, color_3;

void generate_colors() {
    color_1 = rand() % 8;
    color_2 = rand() % 8;
    color_3 = rand() % 8;
}

int check_free_places(int Field[MAX_WIDTH][MAX_HEIGTH]) {
    int string, column;
    int free_place = 0;
    
    for(string = 0; string < MAX_WIDTH; ++string) {
        for(column = 0; column < MAX_HEIGTH; ++column) {
            
            if(!Field[string][column]) {
                ++free_place;

                if(free_place >= 3)
                    return true;
            }
        }
    }



}