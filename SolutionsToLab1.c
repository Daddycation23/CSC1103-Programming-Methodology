#include <stdio.h>

int main() 
{
    /*read P1 and P2*/
    float x1, y1, x2, y2;
    printf("Enter the coordinates of P1(x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("Enter the coordinates of P2(x2, y2): ");
    scanf("%f %f", &x2, &y2);

    /*calculate m*/
    float m = (y2 - y1) / (x2 - x1);

    /*calculate y-intercept*/
    float c = y1 - m * x1;

    /*print values*/
    printf("gradient, m = %f\n", m);
    printf("y-intercept, c = %f\n", c);

    /*finding y with given x*/
    printf("Enter the value of x:");
    float x;
    scanf("%f", &x);
    float y = m * x + c;
    printf("y = %f\n", y);

    return 0;
}
