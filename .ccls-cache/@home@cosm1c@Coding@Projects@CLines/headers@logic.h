#include <vector>
using namespace std;

int field[9][9];           // main field.
vector<int> freeSpace[9];  // field of free space.
vector<int[4]> multiStars; // safe y,x, color, count of multiplie stars.

int colors[3];        // next color list.


// For drawing three stars -------
struct star {
  int x, y;
  int color;
};

vector<star> threeStars(3);
//----------------------------------------

void initField(void); // init field.

void destroyAll(void); // destroy all logic dynamic blocks.

int checkFreeSpace(void); // check free space in field.

void randomColors(void); // create list random colors.

void randomPutStar(void); // put color from random color-list.

void searchLines(int count); // search of multiplie colors in one line.

void printField(void); // output field in terminal.
