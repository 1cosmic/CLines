#include <iostream>

#include <algorithm>
#include <vector>

#include <stdlib.h>
#include <time.h>

using namespace std;

int field[9][9];          // main field.
vector<int> freeSpace[9]; // field of free space.
int colors[3];            // next color list.

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

  int i; // indexcolor.

  srand(time(NULL));

  /* printf("Random colors: "); */
  // Create randomize color list.
  for (i = 0; i < 3; ++i) {
    colors[i] = (rand() % 7) + 1;
    /* printf("%i ", colors[i]); */
  }
  /* printf("\n"); */
}

int checkFreeSpace(void) {
  // Check of free space in main field.
  // Return 0 if space < 3.

  int x, y;
  int counter = 0; // counter free cells.

  // Pasring field.
  for (y = 0; y < 9; ++y) {
    freeSpace[y].clear(); // clear line.

    /* printf("\nLine %i:", y); */
    // if cell = 0 (free space) -> ++ counter.
    for (x = 0; x < 9; ++x)
      if (!field[y][x]) {
        freeSpace[y].push_back(x);
        ++counter;

        /* printf(" %i", freeSpace[y].back()); */
      }
  }
  /* printf("\nFree space: %i\n", counter); */

  if (counter < 3)
    return 0;
  else
    return 1;
}

void randomPutStar(void) {
  // Select randomize line & pos (in line) & put in this color.

  vector<int> freeLines;
  int i_color, i; // for -> for c:

  vector<int> *line;
  vector<int>::iterator iCell; // index cell for cleaning free cell.
  int randLine, randCell;      // for human eyes.

  for (i_color = 0; i_color < 3; ++i_color) {

    // Clear list for search free lines.
    freeLines.clear();

    // Init this list of the number line.
    for (i = 0; i < 9; ++i)
      if (freeSpace[i].size()) // if have free cells in line, write where index.
        freeLines.push_back(i);

    // Get random number of line.
    randLine = freeLines[rand() % freeLines.size()];

    // Get random cell from this line.
    randCell = rand() % freeSpace[randLine].size();
    randCell = freeSpace[randLine][randCell]; // re-write this value.

    // Put color in main field.
    field[randLine][randCell] = colors[i_color]; // put random color from list

    /* printf("Field[%i][%i] = %i\n", randLine, randCell,
     * field[randLine][randCell]); */

    // Search iterator of cell from freeSpace (for free).
    line = &freeSpace[randLine];

    // Delete this cell from freeSpace.
    iCell = find(line->begin(), line->end(), randCell);
    line->erase(iCell);
  }
}

void searchLines(int count) {
  // Search for lines, that contain multiplie start in a row.

  int lastColor;         // last color.
  int i_lastColor;       // index of last color.
  int counter_lastColor; // counter of last color.

  int x, y; // for parsing of field[x][y].  x - cell, y - row.

  for (y = 0; y < 9; ++y) {

    lastColor = -1;        // last color.
    i_lastColor = 0;       // index of last color.
    counter_lastColor = 0; // counter of last color.

    for (x = 0; x < 9; ++x) {
      if (field[y][x] && lastColor == field[y][x])
        counter_lastColor++;

      else {
        if (counter_lastColor >= count)
          printf("I find multiplie color. y/x: %i/%i, color: %i, start/count: "
                 "%i/%i\n",
                 y, x, lastColor, i_lastColor, counter_lastColor);

        lastColor = field[y][x];
        i_lastColor = x;
        counter_lastColor = 1;
      }
    }
  }
}

void printField(void) {
  // print field in terminal-read-mode.

  int line, cell;

  for (line = 0; line < 9; ++line) {

    printf("Line %i:", line);

    for (cell = 0; cell < 9; ++cell)
      cout << field[line][cell] << " ";

    cout << endl;
  }
}
