#include "allHeads.h"

int main() {

    initialise_units();

    for(int i = 0; i < 10; ++i) {
        generate_colors(nextColors);
    }

    return 0;
}
