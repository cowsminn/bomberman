//#ifndef OOP_EXCEPTION_H
//#define OOP_EXCEPTION_H
//
//#include <exception>
//#include <string>
//
//class CustomException : public std::exception {
//
//private:
//    std::string exceptionMessage;
//
//public:
//    explicit CustomException(std::string  = "Something went wrong.");
//
//    [[nodiscard]] const char *what() const noexcept override;
//
//};
//
//class FailedTextureLoad : public CustomException {
//
//public:
//    FailedTextureLoad();
//
//    explicit FailedTextureLoad(const std::string &);
//};
//
//class BadID : public CustomException {
//
//public:
//    BadID();
//
//    explicit BadID(const std::string &);
//};
//
//#endif //OOP_EXCEPTION_H
