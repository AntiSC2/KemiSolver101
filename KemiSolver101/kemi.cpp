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
