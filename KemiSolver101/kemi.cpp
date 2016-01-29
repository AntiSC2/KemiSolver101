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
#include "kemi.h"

Kemi::Kemi()
{
        ;
}


Kemi::~Kemi()
{
        ;
}

/*Loads a file and reads in all the information to create a periodic table*/
void Kemi::init(std::string file)
{
        std::ifstream File;
        File.open(file);
        try {
                if (!File.is_open()) {
                        Error FileError;
                        throw FileError.set_error("Could not load file " + file + '!');
                } else {
                        std::string BufferLine = "";
                        int i = 0;
                        while (std::getline(File, BufferLine)) {
                                m_PeriodicTable.emplace_back(Element());

                                int c = 0;
                                while (BufferLine[c] != ' ') {
                                        m_PeriodicTable[i].Name += BufferLine[c];
                                        c++;
                                }

                                c = 0;
                                while (BufferLine[c] != ' ') {
                                        m_PeriodicTable[i]. += BufferLine[c];
                                        c++;
                                }

                                c = 0;
                                while (BufferLine[c] != ' ') {
                                        m_PeriodicTable[i].Name += BufferLine[c];
                                        c++;
                                }
                                i++;
                        }
                }
        }
        catch (std::exception &e) {
                std::cout << e.what() << std::endl;
        }
}

/*Handles user input and events and corresponds with the correct functions*/
void Kemi::run()
{
        return;
}
