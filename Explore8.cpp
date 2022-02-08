
#include <iostream>
using namespace std;
struct Point {
	double x;
	double y;
	Point();
	Point(double xVal, double yVal);
};
struct Line {
    Point start;
    Point end;
    Line(Point s, Point e);
};
Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

Line::Line(Point s, Point e) {
    start = s;
    end = e;
}

void PrintPoint(Point p) {
    cout << ": x = " << p.x << ", y = " << p.y << endl;
}


void PrintLine(Line l) {
    cout << "  Start";
    PrintPoint(l.start);
    cout << "   End";
    PrintPoint(l.end); 
    cout << endl;
}

// This is new
Point FindMidPoint(Line l) {
    Point mid;
    mid.x = (l.start.x + l.end.x)/2.0;
    mid.y = (l.start.y + l.end.y)/2.0;
    return mid;
}

Point findLowestPoint(Line n) {
  Point lowest;
  lowest.y = n.start.y;
  lowest.x = n.start.x;
  if (n.end.y < n.start.y){
    lowest.y = n.end.y;
    lowest.x = n.end.x;
  }

  return lowest;
}

int main() {
    Line a(Point(3,9), Point(12,22));
    Line b(Point(7,-9), Point(8,-15));
    cout << "Line a";
    PrintLine(a);
    cout << "Line b";
    PrintLine(b);
    cout << "Line a's midpoint";
    // This is new
    Point midPoint = FindMidPoint(a);
    PrintPoint(midPoint);
    cout << endl;

    Point lowestPoint = findLowestPoint(a);
    cout << "Lowest point in line a";
    PrintPoint(lowestPoint);

    lowestPoint = findLowestPoint(b);
    cout << "Lowest point in line b";
    PrintPoint(lowestPoint);
    return 0;
}


