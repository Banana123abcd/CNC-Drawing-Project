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
struct pairs
{
    double x;
    double y;

};

struct pairs rectanglePoints[8];




void circle(double radius, double centerX, double centerY)
{
   double xValue;
   int i = 2;
   int j = 0;

    if (0 <= centerX && centerX < CNCDimensions[1] && 0 <= centerY && centerY < CNCDimensions[1] && radius > 0)
    {
        printf("center is in plane and radius is a valid number  ");

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
        
        printf("Not in plane or radius is not valid");
    }

}



void rectangle(double length, double width, double centerX, double centerY )
{
    int i = 0;
     if (0 <= centerX && centerX < CNCDimensions[1] && 0 <= centerY && centerY < CNCDimensions[1] && length > 0 && width > 0)
    {
        printf("center in plane and lengths are valid numbers \n");

        rectanglePoints[0].x = centerX;
        rectanglePoints[0].y = centerY + length/2;

        rectanglePoints[1].x = centerX;
        rectanglePoints[1].y = centerY - length/2;

        rectanglePoints[2].x = centerX + width/2;
        rectanglePoints[2].y =  rectanglePoints[0].y;

        rectanglePoints[3].x = centerX - width/2;
        rectanglePoints[3].y =  rectanglePoints[0].y;

        rectanglePoints[4].x = centerX + width/2;
        rectanglePoints[4].y =  rectanglePoints[0].y - length/2; 

        rectanglePoints[5].x = centerX - width/2;
        rectanglePoints[5].y =  centerY; 

        rectanglePoints[6].x = centerX - width/2;
        rectanglePoints[6].y =  centerY; 

        rectanglePoints[7].x = centerX - width/2;
        rectanglePoints[7].y =  centerY - length/2; 

        rectanglePoints[8].x = centerX + width/2;
        rectanglePoints[8].y =  centerY - length/2; 



 for (i = 0; i < 9; i++)
        
        {

         printf("(%.2f , %.2f)" , rectanglePoints[i].x, rectanglePoints[i].y);
    
         printf("\n");
        }

     

    } else
    {
        printf("center is not in plane");
    }
} 





















int main()
{

   // circle(2,5,2);

   rectangle(8,2,2,3);


    
}