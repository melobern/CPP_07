/* Copyright 2024 <mbernard>************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:29:57 by mbernard          #+#    #+#             */
/*   Updated: 2024/09/27 09:10:39 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "../includes/Array.hpp"

#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#define MAX_VAL 750

static void subjectTests(void) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];

  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;  //
}

void emptyArray(void) {
  Array<int> empty;

  std::cout << "Empty array size: " << empty.size() << std::endl;
  try {
    empty[0] = 42;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void specificSizeArray(void) {
  Array<int> specific(5);
  Array<unsigned int> unsignedArr(5);

  for (int i = 0; i < 5; i++) {
    specific[i] = i;
    unsignedArr[i] = static_cast<unsigned int>(i);
  }
  for (int i = 0; i < 5; i++) {
    std::cout << specific[i] << std::endl;
    std::cout << unsignedArr[i] << std::endl;
  }
}

void invalidSize(void) {
  try {
    Array<unsigned int> unsignedArr(-1);
    std::cout << unsignedArr.size();
    for (int i = 0; i < 5; i++) {
      unsignedArr[i] = static_cast<unsigned int>(i);
    }
    for (int i = 0; i < 5; i++) {
      std::cout << unsignedArr[i] << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

int main(int, char **) {
  std::cout << CYAN "----------- Subject Tests -----------" RESET << std::endl;
  subjectTests();
  std::cout << CYAN "------------ Empty Array ------------" RESET << std::endl;
  emptyArray();
  std::cout << CYAN "----------- Specific Size -----------" RESET << std::endl;
  specificSizeArray();
  std::cout << CYAN "----------- Invalid Size ------------" RESET << std::endl;
  invalidSize();
  return 0;
}
