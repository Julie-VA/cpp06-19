/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:27 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 16:05:17 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	check_num(std::string str)
{
	bool	f_check = 0;
	bool	d_check = 0;
	bool	m_check = 0;
	int		j = 0;

	if (str.size() == 1)
		return (0);

	std::string	str_cmp[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (j = 0; j < 6; j++)
	{
		if (str == str_cmp[j])
			break;
	}
	if (j < 6)
		return (j + 2);

	for	(int i = 0; str[i]; i++)
	{
		if (!(isdigit(str[i]) || str[i] == '.' || str[i] == 'f' || str[i] == '-'))
			return (1);
		if (str[i] == '.' && d_check)
			return (1);
		else if (str[i] == '.')
		{
			d_check = 1;
			continue;
		}
		if (str[i] == 'f' && f_check)
			return (1);
		else if (str[i] == 'f')
		{
			f_check = 1;
			continue;
		}
		if (str[i] == '-' && m_check)
			return (1);
		else if (str[i] == '-')
		{
			m_check = 1;
			continue;
		}
	}
	if (d_check)
		return (8);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret = 0;

	try
	{
		if (argc != 2 || (ret = check_num(argv[1])) == 1)
			throw (Scalar::BadArgumentException());

		Scalar	scalar(argv[1], ret);

		std::cout << scalar;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
