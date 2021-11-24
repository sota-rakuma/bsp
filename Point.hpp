/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:58:07 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/24 17:17:50 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	const	_x;
		Fixed	const	_y;
	public:
		Point();
		~Point();
		Point(const Point&);
		Point(Fixed x, Fixed y);
		Fixed			get_x() const;
		Fixed			get_y() const;
		Point			operator=(const Point&);
		static Point	get_formula(const Point& a, const Point& b);
};

bool	is_point_inside(Point const max, Point const median, \
							Point const min, Point const point);
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
