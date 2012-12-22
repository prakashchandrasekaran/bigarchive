#include "append_store_exception.h"
#include <string>

ExceptionBase::ExceptionBase(const std::string& message) throw()
    : mMessage(message)
{}

ExceptionBase::~ExceptionBase() throw()
{}



