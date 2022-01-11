/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:17 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 16:05:39 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

class	Scalar
{
	public:

		Scalar(void);
		Scalar(std::string param, int ret);
		Scalar(Scalar const &src);
		~Scalar(void);

		Scalar	&operator=(Scalar const &rhs);

		// Getters
		std::string	getType(void) const;
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;
		bool		getSpecial(void) const;
		bool		getDeci(void) const;

		std::string const	printChar(void) const;
		std::string const	&printInt(void) const;
		void	printFloat(void) const;
		void	printDouble(void) const;

		class	BadArgumentException : public std::exception
		{
			public:

				const char	*what() const throw()
				{
					return ("Bad argument");
				}
		};

	private:

		std::string	_type;
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		bool		_special;
		bool		_deci;
};

std::ostream	&operator<<(std::ostream &o, Scalar const &rhs);
