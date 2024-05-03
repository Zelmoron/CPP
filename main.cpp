
#include <iostream>
#include "triangle.h"
#include "rectangle.h"
#include "elips.h"
#include "circl.h"
int main()
{
    Triangle t(6,5,2.2);
    t.name();
    std::cout<<"Perimetr: " << t.calc_perimetr() << '\n';
    std::cout << "Area: " << t.calc_area() << '\n';

    std::cout << "\n";

    Rectangle r(5, 5);
    r.name();
    std::cout << "Perimetr: " << r.calc_perimetr() << '\n';
    std::cout << "Area: " << r.calc_area() << '\n';

    std::cout << "\n";

    Elips e(1, 1,2,4);
    e.name();
    std::cout << "Perimetr: " << e.calc_perimetr() << '\n';
    std::cout << "Area: " << e.calc_area() << '\n';

    std::cout << "\n";

    Circl c(1, 1, 5);
    c.name();
    std::cout << "Perimetr: " << c.calc_perimetr() << '\n';
    std::cout << "Area: " << c.calc_area() << '\n';



}

