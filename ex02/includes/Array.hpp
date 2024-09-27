/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:37:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/27 09:09:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_INCLUDES_ARRAY_HPP_
#define EX02_INCLUDES_ARRAY_HPP_
# include <iostream>

template<typename T>
class Array {
 private:
  T *array;
  unsigned int _size;
 public:
  Array(void);
  explicit Array(const unsigned int &n);
  Array(const Array &src);
  Array &operator=(const Array &src);
  ~Array(void);

  T& operator[](int index);
  const T &operator[](int index) const;
  const unsigned int &size(void) const;

  class OutOfBoundException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};
#endif  //  EX02_INCLUDES_ARRAY_HPP_
