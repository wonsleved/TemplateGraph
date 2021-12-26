#include "Exceptions.h"

Exceptions::Exceptions(std::string error) : m_error(error) {}

void Exceptions::getError() const {
    std::cerr << m_error << std::endl;
}

BaseException::BaseException(int statIndex, int endIndex, std::string error)
        : Exceptions(error), m_startIndex(statIndex), m_endIndex(endIndex) {}


void BaseException::getError() const{
    std::cerr << m_error
              << " Index must be at least " << m_startIndex
              << " and at most " << m_endIndex << "." << std::endl;
}

PolynomialException::PolynomialException(int statIndex, int endIndex, std::string error)
        : Exceptions(error), m_startIndex(statIndex), m_endIndex(endIndex) {}


void PolynomialException::getError() const{
    std::cerr << m_error
              << " Index must be at least " << m_startIndex
              << " and at most " << m_endIndex << "." << std::endl;
}
