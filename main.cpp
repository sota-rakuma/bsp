/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:56:24 by srakuma           #+#    #+#             */
/*   Updated: 2021/11/25 17:41:28 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	test(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point) == true)
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
}

int	main(void)
{
	test(Point(), Point(Fixed(2.0f), Fixed(0.0f)), Point(Fixed(1.0f), Fixed(1.0f)),
		Point(Fixed(0.5f), Fixed(0.5f)));
	test(Point(), Point(Fixed(2.0f), Fixed(0.0f)), Point(Fixed(1.0f), Fixed(1.0f)),
		Point(Fixed(0.5f), Fixed(0.49f)));

	test(Point(), Point(Fixed(2.0f), Fixed(6.0f)), Point(Fixed(1.0f), Fixed(1.0f)),
		Point(Fixed(0.9f), Fixed(1.0f)));

	test(Point(0.0f, 3.0f), Point(Fixed(2.0f), Fixed(0.0f)), Point(Fixed(3.0f), Fixed(0.0f)),
		Point(Fixed(1.5f), Fixed(1.49f)));
}
