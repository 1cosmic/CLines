#include <utility>

using namespace std;

int center[2] = {1280 / 2, 720 / 2};

pair<int, int> centerObj(int w, int h) {
  // Return center of object.

  return {center[0] - w / 2, center[1] - w / 2};
}
