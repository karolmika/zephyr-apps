/*
 * Copyright (c) 2023, Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <iostream>
#include "s4_challenge.hpp"
#include "s7_challenge.hpp"

int main(void)
{
	std::cout << "Hello, C++ world! Program build for " << CONFIG_BOARD << std::endl;

    /* Run Section 4 Challenge */
	// favorite_number_challenge();
	/* Run Section 7 Challenge */
	vectors_challenge();
	return 0;
}