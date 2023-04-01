package figures

class Triangle(a: Point, b: Point, c: Point) extends Figure {
  require(isValid, "This is not a valid triangle!")

  val possibleComputationMistake: Double = 0.01

  protected def isValid: Boolean = {
    a.distance(b) + a.distance(c) > b.distance(c) + possibleComputationMistake &&
      a.distance(b) + b.distance(c) > a.distance(c) + possibleComputationMistake &&
      a.distance(c) + b.distance(c) > a.distance(b) + possibleComputationMistake
  }

  override def area: Double = {
    (0.5 * ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)).toDouble).abs
  }

  override val description: String = "Triangle"

  override def toString: String = "Triangle: " + a + "; " + b + "; " + c
}

object Triangle {
  def apply(a: Point, b: Point, c: Point): Triangle = {
    new Triangle(a, b, c)
  }
}
