/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:31:37 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 18:06:16 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	Base	*ptr;

	switch (rand() % 3)
	{
		case (0):
			ptr = new A();
			break;
		case (1):
			ptr = new B();
			break;
		case(2):
			ptr = new C();
			break;
	}
	return (ptr);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identified class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified class C" << std::endl;
	else
		std::cout << "Couldn't identify a class" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		static_cast<void>(dynamic_cast<A &>(p));
		std::cout << "Identified class A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		static_cast<void>(dynamic_cast<B &>(p));
		std::cout << "Identified class B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		static_cast<void>(dynamic_cast<C &>(p));
		std::cout << "Identified class C" << std::endl;
	}
	catch(const std::exception& e){}
}

int	main(void)
{
	srand(time(0));

	Base	*ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}
