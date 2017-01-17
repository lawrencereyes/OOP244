#include "ErrorMessage.h" 
#include <cstring>

namespace sict {
	ErrorMessage::ErrorMessage() {
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage) {
		message_ = nullptr;
		message(errorMessage);
	}

	ErrorMessage & ErrorMessage::operator=(const char* errorMessage){
		message(errorMessage);
		return *this;
	}

	ErrorMessage::~ErrorMessage() {
		clear();
	}
	
	void ErrorMessage::clear() {
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear() const{
		return (message_ == nullptr);
	}

	void ErrorMessage::message(const char* value){
		clear();
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}

	const char * ErrorMessage::message() const{
		return message_;
	}

	std::ostream & operator<<(std::ostream & output, const ErrorMessage & er) {
		if (!er.isClear()) {
			output << er.message();
		}
		return output;
	}
}