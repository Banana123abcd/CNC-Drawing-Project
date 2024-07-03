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


// Define CNC dimensions and pi
double CNCDimensions[] = {10,10};

double pi = 3.141592;


// Define a struct for pairs of coordinates
struct pairs
{
    double x;
    double y;

};


// Arrays to store points of different shapes
struct pairs circlePoints[5];
int lengthCircleArray = sizeof(circlePoints)/sizeof(circlePoints[0]);

struct pairs rectanglePoints[8];

struct pairs trianglePoints[2];

struct pairs nPolyPoints[160];



// Function to draw a circle
void circle (double radius, double centerX, double centerY)
{
   int i = 0;
   double theta = 0;
   int j = 0;

// Check if center and radius are valid
    if (0 <= centerX && centerX < CNCDimensions[1] && 0 <= centerY && centerY < CNCDimensions[1] && radius > 0)
    {
        printf("center is in plane and radius is a valid number  ");
// calculate and print coordinates
        while (i < 6)
        {
            circlePoints[i].x = (radius * cos(theta)) + centerX;
            circlePoints[i].y = (radius * sin(theta)) + centerY;
            
            printf("(%.2f,%.2f)" , circlePoints[i].x, circlePoints[i].y);
            printf("\n");

            theta = theta + (pi/3);
            i++;

        }

       
    } else
    {
        
        printf("Not in plane or radius is not valid");
    }

}


// Function to draw a rectangle
void rectangle(double length, double width, double centerX, double centerY )
{
    int i = 0;

    // Check if center and dimensions are valid
     if (0 <= centerX && centerX < CNCDimensions[1] && 0 <= centerY && centerY < CNCDimensions[1] && length > 0 && width > 0)
    {
        printf("center in plane and lengths are valid numbers \n");

        // Calculate and print coordinates of rectangle vertices
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



// Function to draw a triangle
void triangle(double sideA, double sideB, double sideC, double startingX, double startingY)
{
    // Calculate angle C using law of cosines
    double angleC = acos((pow(sideC,2) - pow(sideA,2) - pow(sideB,2))/(2*sideB*sideA));

    // Calculate and print coordinates of triangle vertices
    trianglePoints[0].x = startingX;
    trianglePoints[0].y = startingY;
    printf("(%.2f,%.2f)\n",trianglePoints[0].x,trianglePoints[0].y );

    trianglePoints[1].x = startingX + sideB;
    trianglePoints[1].y = startingY;
    printf("(%.2f,%.2f)\n",trianglePoints[1].x,trianglePoints[1].y );

    trianglePoints[2].x = trianglePoints[1].x - (cos(angleC) * sideA);
    trianglePoints[2].y = startingY + (sin(angleC) * sideA); 
    printf("(%.2f,%.2f)\n",trianglePoints[2].x,trianglePoints[2].y );



}



// Function to draw a regular polygon
void nPoly(int numberOfSides, double sideLength, double xCenter, double yCenter)
{
    nPolyPoints[numberOfSides-1];
    int i = 0;
    double radius;
    double theta;
    double insideAngle = 2 * pi / numberOfSides;

    // Calculate radius of the polygon's circumscribed circle
    radius = sideLength/(2*sin(insideAngle));


while (i < numberOfSides)
        {


            // Calculate and print coordinates of polygon vertices
            nPolyPoints[i].x = (radius * cos(theta)) + xCenter;
            nPolyPoints[i].y = (radius * sin(theta)) + yCenter;


            printf("(%.2f,%.2f)" , nPolyPoints[i].x, nPolyPoints[i].y);
            printf("\n");

            theta = theta + insideAngle;
            i++;

        }

}




















int main()
{





    
}
