#include "myexception.h"

Myexception::Myexception(std::string  str,std::string  info)
    :logic_error(str)
{
  m_strInfo=info;
}

const  char*  Myexception::what() const throw()
{
   return m_strInfo.c_str();
}

Myexception::~Myexception()throw()
{
}
