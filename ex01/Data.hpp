/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:44:46 by rvan-aud          #+#    #+#             */
/*   Updated: 2022/01/11 17:20:33 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef struct s_data
{
	std::string	str;
	int			n;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
