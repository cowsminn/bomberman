#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <exception>
#include <string>

class CustomException : public std::exception {

private:
    std::string exceptionMessage;

public:
    explicit CustomException(std::string  = "Something went wrong.");

    [[maybe_unused]] const char *what() const noexcept override;

};

class FailedTextureLoad : public CustomException {

public:
    FailedTextureLoad();

    explicit FailedTextureLoad(const std::string &);
};
#endif