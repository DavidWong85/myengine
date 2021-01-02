#pragma once
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

namespace myengine
{
	struct Exception : public std::exception
	{
		Exception(const std::string& message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();

	private:
		std::string message;
	};
}
#endif