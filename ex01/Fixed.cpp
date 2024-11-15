/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:40:54 by abekri            #+#    #+#             */
/*   Updated: 2024/11/15 17:45:38 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(void) : _fxPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n) : _fxPoint(n << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const float f) : _fxPoint((int)roundf(f * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& fp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fp)
		this->_fxPoint = fp.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fxPoint);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fxPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fxPoint / (1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)_fxPoint / (1 << fractionalBits))));
}

std::ostream&	operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}

