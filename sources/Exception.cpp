#include "../headers/Exception.h"

#include <utility>

CustomException::CustomException(std::string exceptionMessage) : exceptionMessage(std::move(exceptionMessage)) {}

const char *CustomException::what() const noexcept {
    return exceptionMessage.c_str();
}

// FailedTextureLoad
FailedTextureLoad::FailedTextureLoad() :
        CustomException(std::string("Failed to load texture.")) {}

FailedTextureLoad::FailedTextureLoad(const std::string &textureFileName) :
        CustomException(std::string("Failed to load texture: \"") + textureFileName + std::string("\".")) {}