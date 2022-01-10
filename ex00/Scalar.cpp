/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/10 17:09:03 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(void) : _type("Default"), _char('0'), _int(0), _float(0.0f), _double(0.0)
{
}

Scalar::Scalar(std::string str)
{
	int		i = std::atoi(str.c_str());
	double	d = std::atof(str.c_str());

	if (str.empty())
	{
		throw (Scalar::BadArgumentException());
	}
	else if (str.size() == 1)
	{
		if (isdigit(str.front()))
		{
			this->_int = i;
			this->_type = "int";
		}
		else
		{
			this->_char = str[0];
			this->_type = "char";
			i = str[0];
			d = str[0];
		}
	}
	else
	{
		if (str.find(".", 0) != std::string::npos)
		{
			if (str.find("f", 0) != std::string::npos)
			{
				this->_float = static_cast<float>(d);
				this->_type = "float";
			}
			else
			{
				this->_double = d;
				this->_type = "double";
			}
		}
		else
		{
			this->_int = i;
			this->_type = "int";
		}
	}

	std::string	types[4] = {"char", "int", "float", "double"};
	int j;

	for (j = 0; j < 4; j++)
	{
		if (this->_type == types[j])
			break;
	}

	switch (j)
	{
		case (0):
			this->_int = i;
			this->_float = static_cast<float>(d);
			this->_double = d;
			break;
		case (1):
			this->_char = static_cast<char>(i);
			this->_float = static_cast<float>(d);
			this->_double = d;
			break;
		case (2):
			this->_char = static_cast<char>(i);
			this->_int = i;
			this->_double = d;
		case (3):
			this->_char = static_cast<char>(i);
			this->_int = i;
			this->_float = static_cast<float>(d);
	}
}

Scalar::Scalar(Scalar const &src)
{
	*this = src;
}

Scalar::~Scalar(void)
{
}

Scalar	&Scalar::operator=(Scalar const &rhs)
{
	this->_type = rhs._type;
	this->_char = rhs._char;
	this->_int = rhs._int;
	this->_float = rhs._float;
	this->_double = rhs._double;
	return (*this);
}

char	Scalar::getChar(void) const
{
	return (this->_char);
}

int	Scalar::getInt(void) const
{
	return (this->_int);
}

float	Scalar::getFloat(void) const
{
	return (this->_float);
}

double	Scalar::getDouble(void) const
{
	return (this->_double);
}

std::ostream	&operator<<(std::ostream &o, Scalar const &rhs)
{
	o << "Char = '" << rhs.getChar() << "'" << std::endl
		<< "Int = " << rhs.getInt() << std::endl
		<< "Float = " << rhs.getFloat() << std::endl
		<< "Double = " << rhs.getDouble() << std::endl;
	return (o);
}
