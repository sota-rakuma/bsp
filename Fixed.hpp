/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:41:37 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/13 23:15:28 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_raw_bits;
		static const int	_num_frac_bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int num);
		Fixed(const float num);
		Fixed&				operator=(const Fixed& fixed);
		bool				operator<(const Fixed& fixed) const;
		bool				operator>(const Fixed& fixed) const;
		bool				operator>=(const Fixed& fixed) const;
		bool				operator<=(const Fixed& fixed) const;
		bool				operator==(const Fixed& fixed) const;
		bool				operator!=(const Fixed& fixed) const;
		Fixed				operator+(const Fixed& fixed) const;
		Fixed				operator-(const Fixed& fixed) const;
		Fixed				operator*(const Fixed& fixed) const;
		Fixed				operator/(const Fixed& fixed) const;
		Fixed&				operator++();
		const Fixed			operator++(int);
		Fixed&				operator--();
		const Fixed			operator--(int);
		float				toFloat(void) const;
		int					toInt(void) const;
		int					getRawBits() const;
		void				setRawBits(int const raw);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed);

#endif
