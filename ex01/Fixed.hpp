/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:41:00 by abekri            #+#    #+#             */
/*   Updated: 2024/11/15 17:44:30 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
    public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const float f);
		Fixed(const int n);
		~Fixed();
		
		Fixed&	operator=(const Fixed &fp);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
    
    private:
		int	_fxPoint;
		static const int fractionalBits;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif
