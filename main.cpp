#include <iostream>
#include "enigma.h"

int main()
{
    Enigma<3> enigma{};

    std::cout << enigma.run("gokhantarim") << "\n";
}