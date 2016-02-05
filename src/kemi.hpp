/*
Copyright (c) 2016 Jakob Sinclair

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include "element.hpp"
#include "error.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <map>
#include <string>
#include <cmath>

/*Handles the execution of the program*/
class Kemi
{
public:
        Kemi();
        ~Kemi();

        void Init(std::string File);
        void Run();
private:
        float MolarMass(std::string Atoms[], int n = 0);
        float Mass(std::string Atoms[], int n = 0, float s = 0.0f);
        float Substance(std::string Atoms[], int n = 0, float m = 0.0f);

        void LoadString(std::string line, int i = 0);

        std::vector<Element> m_Table;
        std::map<std::string, int> m_Elements;
};

