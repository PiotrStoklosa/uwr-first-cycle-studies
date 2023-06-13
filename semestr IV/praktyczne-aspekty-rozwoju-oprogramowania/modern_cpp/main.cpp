#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second){
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < x);
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape> s)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fib(int number){
    if (number == 1 || number == 2)
        return 1;

    return fib(number - 1) + fib(number - 2);
}

int main()
{

    Rectangle rectangleTemp(Color::RED);
    Circle circleTemp(Color::GREEN);
    Square squareTemp(Color::BLUE);

    //cout << fib(45) <<'\n';

    Collection shapes = {make_shared<Circle>(2.0), make_shared<Circle>(3.0), nullptr,
                         make_shared<Circle>(4.0), make_shared<Rectangle>(10.0, 5.0), make_shared<Square>(3.0),
                         make_shared<Circle>(4.0)};

    /*
    shapes.push_back(make_shared<Circle>(2.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shared<Circle>(4.0));
    shapes.push_back(make_shared<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shared<Square>(3.0));
    shapes.push_back(make_shared<Circle>(4.0));
     */
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}