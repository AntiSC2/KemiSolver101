#include "kemi.h"
#include <iostream>

int main(int argc, char *argv[])
{
        Kemi k;
        k.init("Elements.txt");
        k.run();
        std::cin.get();
        return 0;
}