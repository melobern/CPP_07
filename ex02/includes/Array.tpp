/* Copyright 2024 <mbernard>*************************************************  #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 08:38:04 by mbernard          #+#    #+#              #
#    Updated: 2024/09/27 09:14:01 by mbernard         ###   ########.fr        #
#                                                                              #
# ****************************************************************************
*/

#include "Array.hpp"

#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
Array<T>::Array(void) {
  this->_size = 0;
  this->_array = new T[0];
  return;
}

template <typename T>
Array<T>::Array(const unsigned int& size) {
  if (size < 0 || size > INT_MAX) {
    std::cerr << RED "Error: Invalid size: Size must be between 0 and ";
    std::cerr << INT_MAX << RESET << std::endl;
    throw Array::OutOfBoundException();
  }
  this->_size = size;
  this->_array = new T[size];
  for (unsigned int i = 0; i < size; i++) {
    this->_array[i] = T();
  }
}

template <typename T>
Array<T>::Array(const Array& src) {
  *this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& src) {
  if (this != &src) {
    this->_size = src._size;
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++) {
      this->_array[i] = src._array[i];
    }
  }
  return (*this);
}

template <typename T>
Array<T>::~Array() {
  delete[] (this->_array);
}

template <typename T>
T& Array<T>::operator[](int index) {
  if (index < 0 || static_cast<unsigned int>(index) >= this->_size) {
    throw Array::OutOfBoundException();
  }
  return (this->_array[index]);
}

template <typename T>
T const& Array<T>::operator[](int index) const {
  if (index < 0 || index >= this->_size) {
    throw Array::OutOfBoundException();
  }
  return (this->_array[index]);
}

template <typename T>
const unsigned int& Array<T>::size() const {
  return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw() {
  return (RED "Error: Out of bound" RESET);
}
