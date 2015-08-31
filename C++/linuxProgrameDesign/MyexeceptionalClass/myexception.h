#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>
#include <stdexcept>
#include <string>
class Myexception : public  std::logic_error
{
public:
    Myexception(std::string  str,std::string  info);
    const char*  what() const throw();
     ~Myexception() throw();
private:
    std::string  m_strInfo;
};

#endif // MYEXCEPTION_H
