/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:37:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/26 10:36:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_INCLUDES_WHATEVER_HPP_
#define EX00_INCLUDES_WHATEVER_HPP_

template<typename T>
void swap(T &a, T &b) {
    T c;

    c = a;
    a = b;
    b = c;
}

template<typename T>
T min(T &a, T &b) {
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T max(T &a, T &b) {
    if (a > b)
        return (a);
    return (b);
}

#endif  //  EX00_INCLUDES_WHATEVER_HPP_
