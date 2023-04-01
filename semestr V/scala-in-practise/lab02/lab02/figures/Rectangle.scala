package figures

class Rectangle(a: Point, b: Point, c: Point, d: Point) extends Figure {

  require(isValid, "This is not a valid rectangle!")

  override def area: Double = {
    new Triangle(a, b, c).area * 2
  }

  protected def isValid: Boolean = {
    isValid(a, b, c, d) || isValid(c, a, b, d) || isValid(b, c, a, d)
  }

  private[this] def isValid(a: Point, b: Point, c: Point, d: Point): Boolean = {
    a.IsOrthogonal(b, c) && b.IsOrthogonal(c, d) && c.IsOrthogonal(d, a)
  }

  override val description: String = "Rectangle"

  override def toString: String = "Rectangle: " + a + "; " + b + "; " + c + "; " + d
}

object Rectangle {
  def apply(a: Point, b: Point, c: Point, d: Point): Rectangle = {
    new Rectangle(a, b, c, d)
  }
}
