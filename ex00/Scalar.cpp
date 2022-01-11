/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:23:22 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 16:26:08 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(void) : _type("Default"), _char('0'), _int(0), _float(0.0f), _double(0.0), _special(0)
{
}

Scalar::Scalar(std::string str, int ret) : _char('0'), _int(0), _float(0.0f), _double(0.0), _special(0)
{
	if (ret > 0 && ret < 8)
	{
		this->_special = 1;
		switch (ret)
		{
			case (2):
				this->_type = "-inf";
				break;
			case (3):
				this->_type = "+inf";
				break;
			case (4):
				this->_type = "nan";
				break;
			case (5):
				this->_type = "-inf";
				break;
			case (6):
				this->_type = "+inf";
				break;
			case (7):
				this->_type = "nan";
				break;
		}
		return ;
	}

	if (ret == 8)
		this->_deci = 1;

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
	this->_special = rhs._special;
	return (*this);
}

std::string	Scalar::getType(void) const
{
	return (this->_type);
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

bool	Scalar::getSpecial(void) const
{
	return (this->_special);
}

bool	Scalar::getDeci(void) const
{
	return (this->_deci);
}

std::ostream	&operator<<(std::ostream &o, Scalar const &rhs)
{
	o << "Char = ";
	if (rhs.getSpecial() || rhs.getDouble() < 0 || rhs.getDouble() > 127)
		o << "impossible";
	else if (rhs.getDouble() < 32 || rhs.getDouble() == 127)
		o << "Non displayable";
	else
		o << "'" << rhs.getChar() << "'";
	o << std::endl;

	o << "Int = ";
	if (rhs.getSpecial())
		o << "impossible";
	else if (rhs.getType() == "float" && (rhs.getFloat() > std::numeric_limits<int>::max() || rhs.getFloat() < std::numeric_limits<int>::min()))
		o << "impossible";
	else if (rhs.getType() == "double" && (rhs.getDouble() > std::numeric_limits<int>::max() || rhs.getDouble() < std::numeric_limits<int>::min()))
		o << "impossible";
	else
		o << rhs.getInt();
	o << std::endl;

	o << "Float = ";
	if (rhs.getSpecial())
		o << rhs.getType() << "f";
	else
	{
		if (!rhs.getDeci())
			o << rhs.getFloat() << ".0f";
		else
			o << std::fixed << std::setprecision(3) << rhs.getFloat() << "f";
	}
	o << std::endl;

	o << "Double = ";
	if (rhs.getSpecial())
		o << rhs.getType();
	else
	{
		if (!rhs.getDeci())
			o << rhs.getDouble() << ".0";
		else
			o << std::fixed << std::setprecision(3) << rhs.getDouble();
	}
	o << std::endl;
	return (o);
}
