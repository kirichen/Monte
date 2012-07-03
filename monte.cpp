    /* monte.cpp */
   #include <stdlib.h>
   #include <stdio.h>
   #include <time.h>
   #include <math.h>
   #include <vector>
   
   float func(float x)
   	{
   	return tan(x); //the original function
   	}

   main ()
   	{
   	int throws, area_throws = 0, i;
   	float low_limit_y = 100000.0;
   	float high_limit_y = -100000.0;
   	
   	float high_limit_x, low_limit_x, integral;
  
   	printf( "Interval?\n" );
   	scanf( "%f", &low_limit_x);
   	scanf( "%f", &high_limit_x);

   	printf( "how much random points?\n" );
   	scanf( "%i", &throws);
	std::vector <float> num_x(throws), num_y(throws), num_y_rand(throws);
   	srand(time(NULL));//24
  
   	for (int i = 0; i < throws; i++) 
   		{
  		num_x[i] = (high_limit_x - low_limit_x) * rand()/RAND_MAX + low_limit_x; //writing values of throws to the array num_x[i]
   		num_y[i] = func(num_x[i]); //writing values of throws to the array num_y[i]

   		if (num_y[i] > high_limit_y) //finding max value of function
			{
			high_limit_y = num_y[i];
			}

  		if (num_y[i] < low_limit_y) //finding min value of function
			{
			low_limit_y = num_y[i];
			}
		}

   	for (int i = 0; i < throws; i++)
		{
		num_y_rand[i] = (high_limit_y - low_limit_y) * rand()/RAND_MAX + low_limit_y; //writing values of throws to the array num_y_rand[i]
   		if (num_y[i] > num_y_rand[i]) //counting the number of points that hit the area bounded by a function
			{
			area_throws++;
			}
   		}

   	integral = (high_limit_y - low_limit_y) * (high_limit_x - low_limit_x) * area_throws/throws + low_limit_y * (high_limit_x - low_limit_x);
   	printf( "Integral = %f\n", integral);
 
   return 0;
}
