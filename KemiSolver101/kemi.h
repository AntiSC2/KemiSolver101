#pragma once
#include "element.h"
#include "error.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <string>


class Kemi
{
public:
        Kemi();
        ~Kemi();

        void init(std::string file);
        void run();
private:
        std::vector<Element> m_PeriodicTable;
};

