#include <stdio.h>
#include <math.h>

/*
***Notes to self for tommorow***
-make cnc plane a cartesian plane. 
-set bottom left as origin
-select shape, parameters for shape are center point and other stuff depending on shape(radius, side length, etc)
    - for a line other info will be needed since only center wont fork for position
-using shape parameters "plot" points of verticies on cnc cartesian plane
- if a point is out of plane throw an error
- start with circle, then try triangle
- prpbably use array for dimensions on plane and shape information

*/

double CNCDimensions[] = {10,10};
double circlePoints[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void circle(double radius, double centerX, double centerY)
{
   double xValue;
   int i = 2;
   int j = 0;

    if (0 <= centerX && centerX < CNCDimensions[1] && 0 <= centerY && centerY < CNCDimensions[1])
    {
        printf("center is in plane   ");

        circlePoints[0] = centerX;
        circlePoints[1] = centerY + radius;

        while (i < 22)
        {
            circlePoints[i+1] = circlePoints[i-1] - (0.4 * radius);// gets y position
            xValue = pow(radius,2) - pow(circlePoints[i+1] - centerY, 2);
            circlePoints[i] = centerX + sqrt(xValue);// gets x position

            circlePoints[i + 3] = circlePoints[i + 1];// y positions are same
            circlePoints[i + 2] = (2 * centerX) + (-1 * circlePoints[i]);

            i = i + 4;

        }


        circlePoints[22] = centerX;
        circlePoints[23] = centerY - radius;


//printf("%d" , circlePoints[1]);
printf("coodinates  ");
        for (j = 0; j < 22; j= j+2)
        
        {
        
         printf("(");
         printf("%.2f" , circlePoints[j]);
         printf("  ,  ");
         printf("%.2f" , circlePoints[j+1]);
         printf(")  ");
         printf("\n");
        }

    } else
    {
        
        printf("Not in plane");
    }

}




int main()
{

//double CNCDimensions[] = {10,10};
double circlePoints[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
    circle(2,5,2);

//circlePoints[2] = 3;
                 
   // printf(" this is the value   %f" , arrays[2]);
    
}