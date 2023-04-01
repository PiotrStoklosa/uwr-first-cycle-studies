package figures

class Square(a: Point, b: Point, c: Point, d: Point) extends Rectangle(a, b, c, d) {

  require(isValid, "This is not a valid square!")

  private[this] def validDistance: Boolean = {
    (for {
      p1 <- List(a, b, c, d)
      p2 <- List(a, b, c, d) if p1 != p2
    } yield p1.distance(p2)).distinct.length == 2
  }

  override protected def isValid: Boolean = {
    super.isValid && validDistance
  }

  override val description: String = "Square"

  override def toString: String = "Square: " + a + "; " + b + "; " + c + "; " + d
}

object Square {
  def apply(a: Point, b: Point, c: Point, d: Point): Square = {
    new Square(a, b, c, d)
  }
}
