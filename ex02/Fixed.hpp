/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:41:27 by abekri            #+#    #+#             */
/*   Updated: 2024/11/15 20:19:28 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed	operator+(const Fixed& fp) const;
		Fixed	operator-(const Fixed& fp) const;
		Fixed	operator*(const Fixed& fp) const;
		Fixed	operator/(const Fixed& fp) const;
		
		Fixed&	operator=(const Fixed& fp);
		bool	operator>(const Fixed& fp) const;
		bool	operator<(const Fixed& fp) const;
		bool	operator>=(const Fixed& fp) const;
		bool	operator<=(const Fixed& fp) const;
		bool	operator==(const Fixed& fp) const;
		bool	operator!=(const Fixed& fp) const;

		

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed&	min(Fixed& fp1, Fixed& fp2);
		static Fixed&	max(Fixed& fp1, Fixed& fp2);
		static const Fixed&	min(const Fixed& fp1, const Fixed& fp2);
		static const Fixed&	max(const Fixed& fp1, const Fixed& fp2);
		
		private:
		int	_fxPoint;
		static const int fractionalBits;
};

std::ostream&	operator<<(std::ostream& o, const Fixed& fp);

#endif
