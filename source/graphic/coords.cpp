#include <utility>

using namespace std;

int center[2] = {1280 / 2, 720 / 2};    // create XY of center screen.

pair<int, int> centerObj(int w, int h) {
  // Return center of object.

  return {center[0] - w / 2, center[1] - w / 2};
}


pair<int, int> coordStar(int column, int cell) {
  // Return coords of start pos. star.

  int x, y;

}
