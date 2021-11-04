#include <iostream>
#include "allHeads.h"

using namespace std;


int main() {
    for(int i = 0; i < 10; ++i) {
        generate_colors();
        cout << "Next colors: " << color_1 << color_2 << color_3 << endl;

    }

    return 0;
}
