
#include <iostream>
#include "triangle.h"
#include "rectangle.h"
#include "elips.h"
#include "circl.h"
#include <vector>

double sum(const std::vector<Geometric_Figure*>& list) {
    double result = 0;
    for (auto sm : list) {
        result += sm->calc_area();
    }
    return result;
}

int main()
{
    std::vector<Geometric_Figure*> list;
  
    Triangle t(6,5,2.2);         
    list.push_back(&t);
    Triangle k(0,0,0,3,3,0);
    list.push_back(&k);
    Rectangle r(5, 5);
    list.push_back(&r);
    Rectangle r_k(0, 0,0,3,5,3,5,0);
    list.push_back(&r_k);
    Elips e(1, 1,2,4);
    list.push_back(&e);
    Circl c(1, 1, 5);
    list.push_back(&c);

    for (auto figure : list) {
        figure->name();
        std::cout << "Perimetr: " << figure->calc_perimetr() << '\n';
        std::cout << "Area: " << figure->calc_area() << '\n';
    }
    
    std::cout << sum(list);

}

