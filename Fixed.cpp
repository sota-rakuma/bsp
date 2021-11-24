/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:41:27 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/13 21:46:39 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_num_frac_bits = 8;

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	_raw_bits = fixed.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	return (_raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	_raw_bits = raw;
}

Fixed::Fixed(void) : _raw_bits(0)
{
	return ;
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
	return ;
}

Fixed::Fixed(const int num)
{
	_raw_bits = (num << _num_frac_bits);
}

Fixed::Fixed(const float num)
{
	float	flt;
	int		power = 1;

	for (int i = 0;i < _num_frac_bits; i++)
		power *= 2;
	flt = num * power;
	_raw_bits = (int)roundf(flt);
	if (num < 0)
		_raw_bits |= 0x80000000;
	else
		_raw_bits &= 0x7fffffff;
}

float	Fixed::toFloat(void) const
{
	float	number;
	float	fraction = 1.0f;

	number = (_raw_bits >> _num_frac_bits);
	for(int i = _num_frac_bits - 1; 0 <= i; i--)
	{
		fraction /= 2.0f;
		if ((1 << i) & _raw_bits)
			number += fraction;
	}
	return (number);
}

int	Fixed::toInt(void) const
{
	return (_raw_bits >> _num_frac_bits);
}

Fixed::~Fixed(void)
{
	return ;
}

std::ostream&	operator<<(std::ostream &os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return !(this->toFloat() == fixed.toFloat());
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	Fixed	plus;

	plus._raw_bits = this->getRawBits() + fixed.getRawBits();
	return (plus);
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	Fixed	minus;

	minus._raw_bits = this->getRawBits() - fixed.getRawBits();
	return (minus);
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	Fixed	multi;
	long	val;

	val = (long)_raw_bits * (long)fixed.getRawBits();
	val /= (1 << _num_frac_bits);
	multi.setRawBits((int)val);
	return(multi);
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	Fixed	devide;
	long	val;

	val = 0;
	if (fixed.toFloat() == 0.0f)
	{
		devide.setRawBits((int)val);
		std::cerr << "zero devide" <<std::endl;
		return (devide);
	}
	val = ((long)_raw_bits * (1 << _num_frac_bits)) / (long)fixed.getRawBits();
	devide.setRawBits((int)val);
	return(devide);
}

Fixed&	Fixed::operator++()
{
	++_raw_bits;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	--_raw_bits;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed tmp = *this;
	--(*this);
	return (tmp);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (b <= a)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}
