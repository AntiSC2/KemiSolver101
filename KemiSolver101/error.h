#pragma once
#include <exception>
#include <string>

class Error : public std::exception {
public:
        Error();
        ~Error();
        virtual const char* what() const throw();
        Error& set_error(std::string error);
private:
        std::string m_Error = "Something has happened! :(";
};

