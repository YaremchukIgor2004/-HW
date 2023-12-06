#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

// Lab 10 Task 4

typedef struct {
    int nomirator;
    unsigned denomirator;
} Rational;

inline Rational rat_from_int(int num) {
    return (Rational) { num, 1 };
}

inline void rat_display(Rational rat) {
    printf("%d/%u", rat.nomirator, rat.denomirator);
}

inline unsigned gcd_impl(unsigned a, unsigned b) {
    if (b == 0) return a;
    return gcd_impl(b, a % b);
}

inline Rational rat_simplify(Rational rat) {
    unsigned nom = (unsigned)abs(rat.nomirator);
    unsigned common = gcd_impl(nom, rat.denomirator);
    rat.nomirator /= common;
    rat.denomirator /= common;
    return rat;
}

inline Rational rat_add(Rational a, Rational b) {
    b.nomirator *= a.denomirator;
    a.nomirator *= b.denomirator;
    a.denomirator *= b.denomirator;
    a.nomirator += b.nomirator;
    return rat_simplify(a);
}

inline Rational rat_sub(Rational a, Rational b) {
    b.nomirator *= a.denomirator;
    a.nomirator *= b.denomirator;
    a.denomirator *= b.denomirator;
    a.nomirator -= b.nomirator;
    return rat_simplify(a);
}

inline Rational rat_mul(Rational a, Rational b) {
    a.nomirator *= b.nomirator;
    a.denomirator *= b.denomirator;
    return rat_simplify(a);
}

inline Rational rat_div(Rational a, Rational b) {
    a.denomirator *= b.nomirator;
    a.nomirator *= b.denomirator;
    return rat_simplify(a);
}

inline int rat_cmp(Rational a, Rational b) {
    return a.nomirator * b.denomirator - b.nomirator * a.denomirator;
}

int main(void) {
    // TODO
}