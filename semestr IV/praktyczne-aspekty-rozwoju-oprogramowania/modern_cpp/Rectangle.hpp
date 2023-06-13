#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    using Shape::Shape;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;
    Color color = Color::RED;

    double x_ = 0.0;
    double y_ = 0.0;
};
