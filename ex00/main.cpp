/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/10 17:19:08 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	check_num(std::string str)
{
	if (str.size() == 1)
		return (0);
	for	(int i = 0; str[i]; i++)
	{
		if (!(isdigit(str[i]) || str[i] == '.' || str[i] == 'f' || str[i] == '-'))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2 || check_num(argv[1]))
			throw (Scalar::BadArgumentException());

		Scalar	scalar(argv[1]);

		std::cout << scalar;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
