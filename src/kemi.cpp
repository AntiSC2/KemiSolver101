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
#include "kemi.hpp"

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
                                c++;
                                while (BufferLine[c] != ' ') {
                                        m_PeriodicTable[i].AtomicNumber += BufferLine[c] - '0';
                                        //m_PeriodicTable[i].AtomicNumber *= pow(10, c);
                                        c++;
                                }
                                c++;
                                while (BufferLine[c] != ' ') {
                                        m_PeriodicTable[i].AtomicMass += (float)BufferLine[c] - (float)'0';
                                        c++;
                                }
                                if (BufferLine[BufferLine.size() - 1] == 'N') {
					m_PeriodicTable[i].Property = type::NonMetal;
                                } else if (BufferLine[BufferLine.size() - 1] == 'M') {
					m_PeriodicTable[i].Property = type::Metal;
                                } else {
					m_PeriodicTable[i].Property = type::TransitionMetal;
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
        for(int i = 0; i < m_PeriodicTable.size(); i++) {
		std::cout << "Name: " << m_PeriodicTable[i].Name << std::endl;
		std::cout << "Mass: " << m_PeriodicTable[i].AtomicMass << std::endl;
		std::cout << "Number: " << m_PeriodicTable[i].AtomicNumber << std::endl;

	}
}
