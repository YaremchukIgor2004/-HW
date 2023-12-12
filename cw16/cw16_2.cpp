#include <iostream>
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

class Point {
public:
    double x, y;

    Point() : x(0), y(0) {}

    int input() {
        std::cout << "input x and y: ";
        std::cin >> x >> y;
        return 0;
    }

    void show() const {
        std::cout << "(" << x << ", " << y << ")";
    }
private:
    int dimension = 2;
};

class Point_3d : public Point {
public:
    double z;

    Point_3d() : z(0) {}

    int input() {
        Point::input();
        std::cout << "input z: ";
        std::cin >> z;
        return 0;
    }

    void show() const {
        Point::show();
        std::cout << ", " << z;
    }
private:
    int dimension = 3;
};

class Segment_2d {
public:
    Point start, end;

    Segment_2d() {}

    int input() {
        std::cout << "input coordinates for the start point of the segment:\n";
        start.input();
        std::cout << "input coordinates for the end point of the segment:\n";
        end.input();
        return 0;
    }

    void show() const {
        std::cout << "Segment: ";
        start.show();
        std::cout << " to ";
        end.show();
    }

    double length() const {
        return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
    }
};

class Segment_3d {
public:
    Point_3d start, end;

    Segment_3d() {}

    int input() {
        std::cout << "input coordinates for the start point of the segment:\n";
        start.input();
        std::cout << "input coordinates for the end point of the segment:\n";
        end.input();
        return 0;
    }

    void show() const {
        std::cout << "Segment: ";
        start.show();
        std::cout << " to ";
        end.show();
    }

    double length() const {
        return sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2) + pow(end.z - start.z, 2));
    }
};

bool Intersecting_2d(const Segment_2d& seg1, const Segment_2d& seg2) {
    double x1 = seg1.start.x, y1 = seg1.start.y;
    double x2 = seg1.end.x, y2 = seg1.end.y;
    double x3 = seg2.start.x, y3 = seg2.start.y;
    double x4 = seg2.end.x, y4 = seg2.end.y;

    double ua = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) /
        ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    double ub = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) /
        ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    return ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1;
}

bool Intersecting_3d(const Segment_3d& seg1, const Segment_3d& seg2) {
    double x1 = seg1.start.x, y1 = seg1.start.y, z1 = seg1.start.z;
    double x2 = seg1.end.x, y2 = seg1.end.y, z2 = seg1.end.z;
    double x3 = seg2.start.x, y3 = seg2.start.y, z3 = seg2.start.z;
    double x4 = seg2.end.x, y4 = seg2.end.y, z4 = seg2.end.z;

    double vec1x = x2 - x1, vec1y = y2 - y1, vec1z = z2 - z1;
    double vec2x = x4 - x3, vec2y = y4 - y3, vec2z = z4 - z3;

    double c = (vec1x * vec2x + vec1y * vec2y + vec1z * vec2z) / (seg1.length() * seg2.length());

    return acos(c) * 180.0 / M_PI != 0;
}

int main() {
    int d;
    std::cout << "input dimension: ";
    std::cin >> d;

    if (d == 2) {
        Segment_2d segment1, segment2;

        std::cout << "first segment:\n";
        segment1.input();

        std::cout << "second segment:\n";
        segment2.input();

        std::cout << "\nfirst segment:\n";
        segment1.show();
        std::cout << "\nLength of the first segment: " << segment1.length() << std::endl;

        std::cout << "\nsecond segment:\n";
        segment2.show();
        std::cout << "\nLength of the second segment: " << segment2.length() << std::endl;

        if (Intersecting_2d(segment1, segment2)) {
            std::cout << "\nSegments are intersecting.\n";
        }
        else {
            std::cout << "\nSegments are not intersecting.\n";
        }
    }

    else if (d == 3) {
        Segment_3d segment1, segment2;

        std::cout << "first segment:\n";
        segment1.input();

        std::cout << "second segment:\n";
        segment2.input();

        std::cout << "\nfirst segment:\n";
        segment1.show();
        std::cout << "\nLength of the first segment: " << segment1.length() << std::endl;

        std::cout << "\nsecond segment:\n";
        segment2.show();
        std::cout << "\nLength of the second segment: " << segment2.length() << std::endl;

        if (Intersecting_3d(segment1, segment2)) {
            std::cout << "\nSegments are intersecting.\n";
        }
        else {
            std::cout << "\nSegments are not intersecting.\n";
        }
    }
    else {
        std::cout << "input 2 or 3: ";
        std::cin >> d;
    }

    return 0;
}