/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/27 08:22:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/whatever.hpp"

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void) {
    int c = 24;
    int d = 42;
    char cChar = 'c';
    char dChar = 'd';
    std::string cString = "ccc";
    std::string dString = "ddd";

    swap<int>(c,d);
    swap<char>(cChar, dChar);
    ::swap<std::string>(cString, dString);
    std::cout << "c === " << c << " and d === " << d << std::endl;
    std::cout << "c === " << cChar << " and d === " << dChar << std::endl;
    std::cout << "c === " << cString << " and d === " << dString << std::endl;
    std::cout << "max is " << max<int>(c, d) << std::endl;
    std::cout << "min is " << min<int>(c, d) << std::endl;
    std::cout << "max is " << max<char>(cChar, dChar) << std::endl;
    std::cout << "min is " << min<char>(cChar, dChar) << std::endl;
    std::cout << "max is " << ::max<std::string>(cString, dString) << std::endl;
    std::cout << "min is " << ::min<std::string>(cString, dString) << std::endl;

    Awesome a(2), b(4);

    swap(a, b);
    std::cout << a << " " << b << std::endl;
    std::cout << max(a, b) << std::endl;
    std::cout << min(a, b) << std::endl;
    return (0);
}
