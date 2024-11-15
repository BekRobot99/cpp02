/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:41:22 by abekri            #+#    #+#             */
/*   Updated: 2024/11/15 20:22:41 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : _fxPoint(0)
{
	if (0)
		std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	if (0)
		std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n) : _fxPoint(n << fractionalBits)
{
	if (0)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _fxPoint((int)roundf(f * (1 << fractionalBits)))
{
	if (0)
		std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	if (0)
		std::cout << "Destructor called" << std::endl;
}

Fixed&	 Fixed::operator=(const Fixed&  fp)
{
	if (0)
		std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fp)
		this->_fxPoint = fp.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	if (0)
		std::cout << "getRawBits member function called" << std::endl;
	return (this->_fxPoint);
}

void	Fixed::setRawBits(const int raw)
{
	if (0)
		std::cout << "setRawBits member function called" << std::endl;
	this->_fxPoint = raw;
}

float	Fixed::toFloat() const
{
	return ((float)_fxPoint / (1 << fractionalBits));
}

int	Fixed::toInt() const
{
	return ((int)(roundf((float)_fxPoint / (1 << fractionalBits))));
}

std::ostream	&operator<<(std::ostream&  o, const Fixed& fp)
{
	o << fp.toFloat();
	return (o);
}


bool	Fixed::operator>(const Fixed&  fp) const
{
	return (this->_fxPoint > fp._fxPoint);
}

bool	Fixed::operator<(const Fixed& fp) const
{
	return (this->_fxPoint < fp._fxPoint);
}

bool	Fixed::operator>=(const Fixed&   fp) const
{
	return (this->_fxPoint >= fp._fxPoint);
}

bool	Fixed::operator<=(const Fixed& fp) const
{
	return (this->_fxPoint <= fp._fxPoint);
}

bool	Fixed::operator==(const Fixed& fp) const
{
	return (this->_fxPoint == fp._fxPoint);
}

bool	Fixed::operator!=(const Fixed&  fp) const
{
	return (this->_fxPoint != fp._fxPoint);
}


Fixed	Fixed::operator+(const Fixed&  fp) const
{
	return (Fixed(this->toFloat() + fp.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fp) const
{
	return (Fixed(this->toFloat() - fp.toFloat()));
}

Fixed	Fixed::operator*(const Fixed&  fp) const
{
	return (Fixed(this->toFloat() * fp.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fp) const
{
	return (Fixed(this->toFloat() / fp.toFloat()));
}


Fixed&	 Fixed::operator++()
{
	++(this->_fxPoint);
	return (*this);
}

Fixed&	 Fixed::operator--()
{
	--(this->_fxPoint);
	return (*this);
}

Fixed	Fixed::operator++(int n)
{
	Fixed	fpTmp(*this);

	if (n >= 0)
	{
		for (int i = 0; i <= n; i++)
			++(*this);
	}
	else
	{
		for (int i = 0; i <= (-n); i++)
			--(*this);
	}
	return (fpTmp);
}

Fixed	Fixed::operator--(int n)
{
	Fixed	fpTmp(*this);

	if (n >= 0)
	{
		for (int i = 0; i <= n; i++)
			--(*this);
	}
	else
	{
		for (int i = 0; i <= (-n); i++)
			++(*this);
	}
	return (fpTmp);
}

Fixed&	 Fixed::min(Fixed& fp1, Fixed& fp2)
{
	if (0)
		std::cout << "Static min function called" << std::endl;
	if (fp1 <= fp2)
		return (fp1);
	return (fp2);
}

Fixed&  Fixed::max(Fixed& fp1, Fixed& fp2)
{
	if (0)
		std::cout << "Static max function called" << std::endl;
	if (fp1 >= fp2)
		return (fp1);
	return (fp2);
}

const Fixed&	Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	if (0)
		std::cout << "Static const min overload called" << std::endl;
	if (fp1 <= fp2)
		return (fp1);
	return (fp2);
}

const Fixed&	Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	if (0)
		std::cout << "Static const max overload called" << std::endl;
	if (fp1 >= fp2)
		return (fp1);
	return (fp2);
}
