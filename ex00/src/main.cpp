/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/26 10:41:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/whatever.hpp"

int main(void) {
    int a = 42;
    int b = 24;
    char aChar = 'a';
    char bChar = 'b';
    std::string aString = "aaa";
    std::string bString = "bbb";

    swap<int>(a,b);
    swap<char>(aChar, bChar);
    ::swap<std::string>(aString, bString);
    std::cout << "a === " << a << " and b === " << b << std::endl;
    std::cout << "a === " << aChar << " and b === " << bChar << std::endl;
    std::cout << "a === " << aString << " and b === " << bString << std::endl;
    std::cout << "max is " << max<int>(a, b) << std::endl;
    std::cout << "min is " << min<int>(a, b) << std::endl;
    std::cout << "max is " << max<char>(aChar, bChar) << std::endl;
    std::cout << "min is " << min<char>(aChar, bChar) << std::endl;
    std::cout << "max is " << ::max<std::string>(aString, bString) << std::endl;
    std::cout << "min is " << ::min<std::string>(aString, bString) << std::endl;

    return (0);
}
