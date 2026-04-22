/*
 * Copyright (c) 2023, Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <iostream>
#include "s4_challenge.hpp"

int main(void)
{
	std::cout << "Hello, C++ world! Program build for " << CONFIG_BOARD << std::endl;
	favorite_number_challenge();
	return 0;
}