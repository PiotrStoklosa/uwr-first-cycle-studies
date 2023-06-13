#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    using Rectangle::Rectangle;
    Square(double x);
    Square(const Square & other) = default;

    double getArea() const;
    double getPerimeter() const;
    void print() const;

private:
    double getY()= delete; // should not have Y dimension
    Square() = delete;
    Color color = Color::GREEN;
};