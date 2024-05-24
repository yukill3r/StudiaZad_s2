#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <math.h>
#include <boost/algorithm/string.hpp>

using namespace std;

class Point2D{
    public:
    Point2D(double x, double y);
    string toString();
    double x;
    double y;
};

Point2D::Point2D(double x, double y){
    this->x = x;
    this->y = y;
}

class Line2D{
    public:
    Line2D(double slope, double y_intercept);
    Line2D(Point2D pointA, Point2D pointB);
    void toString();
    bool contains(Point2D point1,
                  Point2D point2,
                  Point2D point3);
    // ...
    private:
    double slope;
    double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept) {
    this->slope = slope;
    this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB) {
    this->slope = (pointA.y - pointB.y)/(pointA.x-pointB.x);
    this->y_intercept = pointA.y - (this->slope*pointA.x) ;
}

void Line2D::toString() {
    printf("And the final line equation is: \ny=%sx+%s\n",to_string(int(this->slope)).c_str(),
                                                          to_string(int(this->y_intercept)).c_str());
}

bool Line2D::contains(Point2D point1,
                      Point2D point2,
                      Point2D point3)
{
    if ((point3.y - point2.y) * (point2.x - point1.x) == (point2.y - point1.y) * (point3.x - point2.x))
        return true;
    return false;
}

int main(){
    Point2D p1(0, 0);
    Point2D p2(3, 6);
    Point2D p3(-2, -4);
    Line2D ll(p1, p2);
    ll.toString();
    if (ll.contains(p1, p2, p3)){
        cout << "they are collinear\n";
    } else {
        cout << "they are not collinear\n";
    }
    return 1;
}

