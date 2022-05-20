#include <stdio.h>

#include <vector>
#include <stdlib.h>

using namespace std;

int field[9][9];               // main field.
vector<int> freeSpace[9];      // field of free space.
int colors[3];                 // next color list.

void initField(void) {
    // Create & return * bx field (arrax 9x9).

    int x, y;

    // Initialization block (all pos. in field = 0 (color ID)).
    for (y = 0; y < 9; ++y)
        for (x = 0; x < 9; ++x)
            field[x][y] = 0;
}

void randomColors(void) {
    // generate random color.

    int i;  // index color.

    printf("Random colors: ");
    // Create randomize color list.
    for (i = 0; i < 3; ++i) {
        colors[i] = (rand() % 7) +1;
        printf("%i ", colors[i]);
    }
    printf("\n");
}

int checkFreeSpace(void) {
    // Check of free space in main field.
    // Return 0 if space < 3. 

    int x, y;
    int counter = 0;            // counter free cells.
    
    // Pasring field.
    for (y = 0; y < 9; ++y) {
        freeSpace[y].clear();  // clear line.

        printf("\nLine %i:", y);
        // if cell = 0 (free space) -> ++ counter.  
        for (x = 0; x < 9; ++x)
            if (!field[y][x]) {
                freeSpace[y].push_back(x);
                ++counter;
                
                printf(" %i", freeSpace[y].back());
            }   
    }
    printf("\nFree space: %i\n", counter);

    if (counter < 3) return 0;
    else return 1;    
}

void randomPutStar(void) {
    // Select randomize line & pos (in line) & put in this color.

    int i_color, i;  // for -> for c:

    int randLine, randCell;  // for human eyes.
    vector<int> freeLines;

    
    for (i_color = 0; i_color < 3; ++i_color) {

        // Clear list for search free lines.
        freeLines.clear();

        // Init this list of the number line.
        for (i = 0; i < 9; ++i)
            if (freeSpace[i].size())  // if have free cells in line, write where index.  
                freeLines.push_back(i);
        
        // Get random number of line.
        randLine = freeLines[rand() % freeLines.size()];

        // Get random cell from this line.
        randCell = rand() % freeSpace[randLine].size();  
        randCell = freeSpace[randLine][randCell];  // re-write this value.

        printf("Try, RandLine: %i. RandCell: %i. Field: %i\n", randLine, randCell, field[randLine][randCell]);

        // Put color in main field.
        field[randLine][randCell] = colors[i_color];  // put random color from list
        printf("Field[%i][%i] = %i\n", randLine, randCell, field[randLine][randCell]);

        freeSpace[randLine].erase(freeSpace[randLine].begin() + randCell);  // clear this cell from freeSpace.
        printf("Sucsess clear.");
    }
}
