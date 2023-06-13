#pragma once

enum class Color : unsigned char
{
    RED,
    BLUE,
    GREEN
};

class Shape
{
public:
    Shape() = default;
    Shape(Color c);
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
private:
    Color color;
};