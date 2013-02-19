#include "wrapper-application.h"

int main (int argc, char* argv []) {
    hexDrod hd = hexDrod();
    wrapperApplication wa(&hd);
    return wa.run();
}
