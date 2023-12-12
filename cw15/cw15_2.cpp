#include <iostream>
#include <cstdint>

class Point {
public:
    Point() = default;
    Point(double x, double y) : x(x), y(y) {}

    double x{}, y{};

    static Point read_point() {
        Point p;
        std::cin >> p.x >> p.y;
        readed_count += 1;
        return p;
    }

    static void show_count() {
        std::cout << readed_count << '\n';
    }
protected:
    static uint32_t readed_count;
};

uint32_t Point::readed_count;

double dist(const Point& a, const Point& b) {
    return std::hypot(a.x - b.x, a.y - b.y);
}

int main() {
    double p = 0;
    Point prev = Point::read_point(), first = prev;
    while (true) {
        std::cout << "enter point? (y|n)\n";
        char ans;
        std::cin >> ans;
        if (ans != 'y' && ans != 'Y')
            break;
        Point cur = Point::read_point();
        p += dist(prev, cur);
        prev = cur;
    }
    p += dist(prev, first);
    std::cout << "p: " << p << '\n';
    Point::show_count();
}