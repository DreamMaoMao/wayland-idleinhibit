#include <unistd.h>
#include "idle.hpp"


int main(int argc, char *argv[]) {

    auto idle = new Idle();
    idle->update(true);
    delete idle;
}

