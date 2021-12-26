#ifndef LAB3_EXCEPTIONS_H
#define LAB3_EXCEPTIONS_H


#include <iostream>
#include <exception>

namespace ExceptionConsts {
    const std::string INVALID_INDEX = "Invalid index!";
    const std::string INVALID_SIZE  = "Invalid size! Size must not be less than 0.";
    const std::string INVALID_COUNT = "Invalid count! Count must not be less than 0.";
    const std::string INVALID_SHIFT = "Invalid shift! Cannot shift empty array.";
    const std::string INVALID_POP   = "Invalid pop! Cannot pop empty array.";
    const std::string EMPTY_ARRAY   = "Array is empty!";
    const std::string EMPTY_LIST    = "List is empty!";
    const std::string EMPTY_POL     = "Polynomial is zero!";
}

class Exceptions
{
protected:
    std::string m_error;
public:
    explicit Exceptions(std::string error);
    virtual void getError() const;
};

class BaseException : public Exceptions
{
private:
    int m_startIndex;
    int m_endIndex;
public:
    explicit BaseException(int statIndex, int endIndex, std::string error);
    virtual void getError() const override;
};

class PolynomialException : public Exceptions
{
private:
    int m_startIndex;
    int m_endIndex;
public:
    explicit PolynomialException(int statIndex, int endIndex, std::string error);
    virtual void getError() const override;
};



#endif
