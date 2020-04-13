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
	double previous = get_distance(current_location, food_points[0]);
	closest_food_location->x = food_points[0].x;
	closest_food_location->y = food_points[0].y;


	for (int i = 1; i < points_length; i++)
	{
		int x1 = food_points[i].x, y1 = food_points[i].y;
		double distance = get_distance(current_location, food_points[i]);
		if (distance < previous)
		{
			closest_food_location->x = x1;
			closest_food_location->y = y1;
			previous = distance;
		}
	}
}