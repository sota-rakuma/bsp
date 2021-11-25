/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:58:42 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/25 17:39:36 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	is_point_inside(Point const max, Point const median, \
							Point const min, Point const point)
{
	Point	max_min(Point::get_formula(min, max));// ca 間の式
	Point	max_med(Point::get_formula(max, median));// ab 間の式
	Point	med_min(Point::get_formula(median, min));// bc 間の式
	Fixed	val[3];

	if ((max.get_x() <= point.get_x()) || (point.get_x() <= min.get_x()))
		return (false);
	val[0] = max_min.get_x() * point.get_x() + max_min.get_y();
	val[1] = max_med.get_x() * point.get_x() + max_med.get_y();
	val[2] = med_min.get_x() * point.get_x() + med_min.get_y();
	if ((point.get_x() < median.get_x()))
	{
		return ((Fixed::min(val[0], val[2]) < point.get_y())
			&& (point.get_y() < Fixed::max(val[0], val[2])));
	}
		return ((Fixed::min(val[0], val[1]) < point.get_y())
			&& (point.get_y() < Fixed::max(val[0], val[1])));
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (a.get_x() == Fixed::max(a.get_x(), Fixed::max(b.get_x(), c.get_x())))
	{
		if (b.get_x() == Fixed::min(b.get_x(), c.get_x()))
		{
			return (is_point_inside(a, c, b, point));
		}
		return (is_point_inside(a, b, c, point));
	}
	else if (b.get_x() == Fixed::max(b.get_x(), Fixed::max(a.get_x(), c.get_x())))
	{
		if (a.get_x() == Fixed::min(a.get_x(), c.get_x()))
		{
			return (is_point_inside(b, c, a, point));
		}
		return (is_point_inside(b, a, c, point));
	}
	if (a.get_x() == Fixed::min(a.get_x(), b.get_x()))
	{
		return (is_point_inside(c, b, a, point));
	}
	return (is_point_inside(c, a, b, point));
}
