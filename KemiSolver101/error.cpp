#include "error.h"

Error::Error()
{
        ;
}


Error::~Error()
{
        ;
}

const char* Error::what() const throw()
{
        return m_Error.c_str();
}

Error& Error::set_error(std::string error)
{
        m_Error = error;
        return *this;
}
