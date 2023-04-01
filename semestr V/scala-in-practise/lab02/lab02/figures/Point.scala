package figures

import numbers.Rational

import scala.math.{pow, sqrt}

class Point(val x: Rational, val y: Rational) {

  val possibleComputationMistake: Double = 0.01

  override def toString: String = "x: " + x.toString + " , y: " + y.toString

  def distance(other: Point): Double = {
    sqrt(pow((other.x - x).toDouble, 2) + pow((other.y - y).toDouble, 2))
  }

  def IsOrthogonal(p1: Point, p2: Point): Boolean = {
    ((p1.x - x) * (p1.x - p2.x) + (p1.y - y) * (p1.y - p2.y)).toDouble <= possibleComputationMistake
  }

}

object Point {
  def apply(x: Rational, y: Rational): Point = {
    new Point(x, y)
  }

  def apply(x: Int, y: Int): Point = {
    new Point(Rational(x), Rational(y))
  }
}
