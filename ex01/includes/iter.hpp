/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:37:56 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/26 13:28:40 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_INCLUDES_ITER_HPP_
#define EX01_INCLUDES_ITER_HPP_

template<typename T, typename R>
void iter(T *arr, size_t length, R f) {
    for (size_t i = 0; i < length; i++) {
        f(arr[i]);
    }
}

#endif  //  EX01_INCLUDES_ITER_HPP_
