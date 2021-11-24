/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:57:58 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/24 17:35:30 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	Point::get_x() const
{
	return (_x);
}
Fixed	Point::get_y() const
{
	return (_y);
}

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point::Point(const Point& point) : _x(point._x), _y(point._y)
{
	return ;
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{
	return ;
}

Point	Point::operator=(const Point& point)
{
	(void)point;
	return (*this);
}

// y = ax + b;
Point	Point::get_formula(const Point& a, const Point& b)
{
	Fixed	slope;
	Fixed	intercept;

	slope = (a.get_y() - b.get_y()) / (a.get_x() - b.get_x());
	intercept = a.get_y() - (a.get_x() * slope);
	Point	formula(slope, intercept);
	return (formula);
}
