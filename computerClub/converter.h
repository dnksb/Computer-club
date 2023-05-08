#ifndef CONV_HPP
#define CONV_HPP
#include <string>
class Conv {
public: 
	static System::String^ ToSystemString(std::string);
	static std::string ToStdString(System::String^);
	static System::Drawing::Color^ ToColor(System::Drawing::Color);
};

#endif