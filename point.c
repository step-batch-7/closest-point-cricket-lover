#include <math.h>
#include "point.h"

double get_distance(Point start, Point end)
{
	double sqr_of_delta_in_x = pow(end.x - start.x, 2);
	double sqr_of_delta_in_y = pow(end.y - start.y, 2);
	return sqrt(sqr_of_delta_in_x + sqr_of_delta_in_y);
}

void get_closest_food(Point food_points[], int points_length, Point current_location, Point *closest_food_location)
{
	double previous_distance = get_distance(current_location, food_points[0]);
	*closest_food_location = food_points[0];

	for (int i = 1; i < points_length; i++)
	{
		double current_distance = get_distance(current_location, food_points[i]);
		if (current_distance < previous_distance)
		{
			*closest_food_location = food_points[i];
			previous_distance = current_distance;
		}
	}
}