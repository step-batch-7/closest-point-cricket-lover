#include <math.h>
#include "point.h"

double get_distance(struct Point start, struct Point end)
{
	double sqr_of_delta_in_x = (end.x - start.x) * (end.x - start.x);
	double sqr_of_delta_in_y = (end.y - start.y) * (end.y - start.y);
	return sqrt(sqr_of_delta_in_x + sqr_of_delta_in_y);
}

void get_closest_food(struct Point food_points[], int points_length, struct Point current_location, struct Point *closest_food_location)
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