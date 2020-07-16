#pragma once

#include <iostream>

template <typename T> void f(T) {
	std::cout << "f(T)" << std::endl;
}

template <typename T> void f(const T*) {
	std::cout << "f(const T*)" << std::endl;
}

template <typename T> void g(T) {
	std::cout << "g(T)" << std::endl;
}

template <typename T> void g(T*) {
	std::cout << "g(T*)" << std::endl;
}