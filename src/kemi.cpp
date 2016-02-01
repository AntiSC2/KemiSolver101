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
        m_Table.clear();
        m_Elements.clear();
}

float Kemi::MolarMass(std::string Atoms[], int n)
{
        try {
                float MolarMass = 0.0f;
                for (int i = 0; i < n; i++) {
                        int e = m_Elements[Atoms[i]];
                        MolarMass += m_Table[e - 1].AtmMass;
                }
                return MolarMass;
        }
        catch (std::exception &e) {
                std::cout << e.what() << std::endl;
        }
        return 0.0f;
}

float Kemi::Mass()
{
        std::string answer;
        std::cin >> answer;
        int a = m_Elements[answer];
        std::cin >> answer;
        int b = m_Elements[answer];
        float molar = 0.0f;
        molar += m_Table[a - 1].AtmMass;
        molar += m_Table[b - 1].AtmMass;
        float substance = 0.0f;
        std::cin >> substance;
        std::cout << "Mass: " << substance * molar << " g." << std::endl;
        return substance * molar;
}

float Kemi::Substance()
{
        std::string answer;
        std::cin >> answer;
        int a = m_Elements[answer];
        std::cin >> answer;
        int b = m_Elements[answer];
        float molar = 0.0f;
        molar += m_Table[a - 1].AtmMass;
        molar += m_Table[b - 1].AtmMass;
        float mass = 0.0f;
        std::cin >> mass;
        std::cout << "Substance: " << mass / molar << " molar." << std::endl;
        return mass / molar;
}

/*
 * Creates a periodic table from a file.
 * Format to follow inside the file:
 * Abbrevation_of_the_element Atomic_Number Atomic_Mass Metal_or_not
 * Example: H 1 1.008 N
 */
void Kemi::Init(std::string File)
{
        std::ifstream file_buffer;
	file_buffer.open(File);
	try {
                if (!file_buffer.is_open()) {
                        Error file_error;
                        throw file_error.set_error("Could not load file " + File + '!');
                } else {
                        std::string line = "";
                        int i = 0;
                        while (std::getline(file_buffer, line)) {
                                m_Table.emplace_back(Element());

                                int c = 0;
                                while (line[c] != ' ') {
                                        m_Table[i].Name += line[c];
                                        c++;
                                }
                                m_Elements[m_Table[i].Name] = i + 1;
                                c++;
                                while (line[c] != ' ') {
                                	m_Table[i].No *= 10;
                                        m_Table[i].No += line[c] - '0';
                                        c++;
                                }
                                c++;
                                int p = -1;
                                bool point = false;
                                while (line[c] != ' ') {
                                	if (line[c] == '.') {
						point = true;
					} else if (point == true) {
						m_Table[i].AtmMass += (float)((line[c] - '0') * pow(10, p));
						p--;
					} else {
						m_Table[i].AtmMass *= 10;
						m_Table[i].AtmMass += (float)(line[c] - '0');
					}
                                        c++;
                                }
                                if (line[line.size() - 1] == 'N') {
					m_Table[i].Property = type::NonMetal;
                                } else if (line[line.size() - 1] == 'M') {
					m_Table[i].Property = type::Metal;
                                } else {
					m_Table[i].Property = type::TransitionMetal;
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
void Kemi::Run()
{
	bool quit = false;
	while (!quit) {
		int c = 0;
		std::vector<std::string> atoms;
		std::string answer;
		std::cin >> answer;
		if (answer == "q") {
			quit = true;
                } else if (answer == "molar") {
                	if (atoms.size() > 0)
                		atoms.clear();
                	while (!std::cin.fail()) {
				std::cin >> answer;
				auto it = m_Elements.find(answer);
				if (it != m_Elements.end()) {
					atoms.push_back(answer);
				} else if (answer == "done") {
					break;
				}
                	}
                        float Result = MolarMass(atoms.data(), 3);
                        std::cout << "Molar Mass: " << Result << " g/mol." << std::endl;
                } else if (answer == "substance") {
                        Substance();
                } else if (answer == "mass") {
                        Mass();
                }
	}
}
