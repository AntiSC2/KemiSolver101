#pragma once
#include <string>

enum type { Metal, NonMetal, TransitionMetal };

class Element {
public:
        Element();
        ~Element();

        int AtomicNumber = 1;
        float AtomicMass = 1.008f;
        type Property = type::NonMetal;
        std::string Name = "Hydrogen";
};

