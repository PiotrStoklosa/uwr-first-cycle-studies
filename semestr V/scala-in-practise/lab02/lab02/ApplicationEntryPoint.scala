import figures.{Point, Rectangle, Square, Triangle}
import numbers.Rational

object ApplicationEntryPoint {

  def main(args: Array[String]): Unit = {

    println("Tests for Rational\n")

    val rational: Rational = Rational(50, -6)
    println("Created " + rational)
    val rational2: Rational = Rational(7, 8)
    println("Created " + rational2)

    val minus: Rational = rational - rational2
    println(rational + " - " + rational2 + " = " + minus)

    val add: Rational = rational + rational2
    println(rational + " + " + rational2 + " = " + add)

    val times: Rational = rational * rational2
    println(rational + " * " + rational2 + " = " + times)

    val divide: Rational = rational / rational2
    println(rational + " / " + rational2 + " = " + divide)

    val rational3: Rational = Rational(2, 6)
    println("Created " + rational3)

    val add2: Rational = rational + rational3
    println(rational + " + " + rational3 + " = " + add2)

    println("\n\nTests for figures\n")
    val p1 = Point(0, 0)
    val p2 = Point(1, 0)
    val p3 = Point(1, 1)
    val p4 = Point(0, 1)
    val p5 = Point(0, 2)
    val p6 = Point(1, 2)
    val p7 = Point(2, 2)
    println("Created points: p1: " + p1 + "; p2: " + p2 + "; p3: " + p3 + "; p4: " + p4 + "; p5: " + p5 + "; p6: " + p6 + "; p7: " + p7)

    val triangle = Triangle(p1, p2, p3)
    println("Created: " + triangle)
    println("Area of this triangle " + triangle.area + "\n")

    val square = Square(p1, p2, p3, p4)
    println("Created: " + square)
    println("Area of this square " + square.area + "\n")

    val rectangle = Rectangle(p1, p2, p5, p6)
    println("Created: " + rectangle)
    println("Area of this triangle " + rectangle.area + "\n")

    println("All figures: ")
    singleton.printAll(List(triangle, square, rectangle))
    println()
    println("Sum of areas: " + singleton.areaSum(List(triangle, square, rectangle)))

    // val badSquare = Square(p1, p2, p5, p6) /*<- wrong square*/
    // val badRectangle = Rectangle(p1, p2, p3, p5) /*<- wrong rectangle*/
    // val badTriangle = Triangle(p1, p3, p7) /*<- wrong triangle*/

  }

}
