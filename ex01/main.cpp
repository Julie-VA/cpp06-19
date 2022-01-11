/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:44:19 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 17:22:11 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main(void)
{
	Data		test;
	uintptr_t	ptr;

	test.str = "Hello";
	test.n = 42;

	ptr = serialize(&test);

	Data	*ret = deserialize(ptr);

	std::cout << ret->str << std::endl << ret->n << std::endl;
	return (0);
}
