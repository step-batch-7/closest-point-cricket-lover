#include <stdio.h>
#include "point.h"

int main(void)
{
	Point food_points[5] = {{18, 76}, {19, 66}, {89, 57}, {9, 71}, {55, 38}};
	Point current_location = {10, 94};
	Point closest_food_location = {0,0};
	
	get_closest_food(food_points, 5, current_location, &closest_food_location);
	printf("closest food location is [%d, %d]\n", closest_food_location.x, closest_food_location.y);
	return 0;
}