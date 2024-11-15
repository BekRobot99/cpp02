/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 06:40:32 by abekri            #+#    #+#             */
/*   Updated: 2024/11/15 16:22:52 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &copy);
        Fixed&	operator = (const Fixed& fp);
		~Fixed();
		
		
		int		getRawBits(void) const;
		void	setRawBits(const int raw);

    private:
		int					_fxPoint;
		static const int	_fraxn;
};

#endif
