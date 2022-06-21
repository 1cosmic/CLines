std::vector<int[3]> lastStars(3); // array star: X, Y, Color.

void initField(void); // init field.

void destroyAll(void); // destroy all logic dynamic blocks.

int checkFreeSpace(void); // check free space in field.

void randomColors(void); // create list random colors.

void randomPutStar(void); // put color from random color-list.

void searchLines(int count); // search of multiplie colors in one line.

void printField(void); // output field in terminal.
