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

float Kemi::molar_mass()
{
        std::string answer;
        std::cin >> answer;
        int a = m_Elements[answer];
        std::cin >> answer;
        int b = m_Elements[answer];
        std::cout << "Molar mass: " << m_PeriodicTable[a - 1].AtomicMass + m_PeriodicTable[b - 1].AtomicMass << " g/molar." << std::endl;
        return m_PeriodicTable[a - 1].AtomicMass + m_PeriodicTable[b - 1].AtomicMass;
}

float Kemi::mass()
{
        std::string answer;
        std::cin >> answer;
        int a = m_Elements[answer];
        std::cin >> answer;
        int b = m_Elements[answer];
        float molar = m_PeriodicTable[a - 1].AtomicMass + m_PeriodicTable[b - 1].AtomicMass;
        float substance = 0.0f;
        std::cin >> substance;
        std::cout << "Mass: " << substance * molar << " g." << std::endl;
        return substance * molar;
}

float Kemi::substance()
{
        std::string answer;
        std::cin >> answer;
        int a = m_Elements[answer];
        std::cin >> answer;
        int b = m_Elements[answer];
        int molar = m_PeriodicTable[a - 1].AtomicMass + m_PeriodicTable[b - 1].AtomicMass;
        float mass = 0.0f;
        std::cin >> mass;
        std::cout << "Substance: " << mass / molar << " molar." << std::endl;
        return mass / molar;
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
                                m_Elements[m_PeriodicTable[i].Name] = i + 1;
                                c++;
                                while (BufferLine[c] != ' ') {
                                	m_PeriodicTable[i].AtomicNumber *= 10;
                                        m_PeriodicTable[i].AtomicNumber += BufferLine[c] - '0';
                                        c++;
                                }
                                c++;
                                int p = -1;
                                bool point = false;
                                while (BufferLine[c] != ' ') {
                                	if (BufferLine[c] == '.') {
						point = true;
					} else if (point == true) {
						m_PeriodicTable[i].AtomicMass += (float)((BufferLine[c] - '0') * pow(10, p));
						p--;
					} else {
						m_PeriodicTable[i].AtomicMass *= 10;
						m_PeriodicTable[i].AtomicMass += (float)(BufferLine[c] - '0');
					}
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
		std::cout << "Property: ";
		if (m_PeriodicTable[i].Property == 0) {
			std::cout << "Metal" << std::endl;
		} else if (m_PeriodicTable[i].Property == 1) {
			std::cout << "Nonmetal" << std::endl;
		} else {
			std::cout << "Transitionmetal" << std::endl;
		}
	}
	bool quit = false;
	while (!quit) {
		std::string answer;
		std::cin >> answer;
		if (answer == "q") {
			quit = true;
                } else if (answer == "molar") {
                        molar_mass();
                } else if (answer == "substance") {
                        substance();
                } else if (answer == "mass") {
                        mass();
                }
	}
}
