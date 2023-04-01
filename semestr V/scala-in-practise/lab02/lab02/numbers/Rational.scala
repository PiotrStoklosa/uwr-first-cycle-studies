package numbers

class Rational(val n: Int, val d: Int) {
  require(d != 0, "Denominator cannot be equal to 0!")

  override def toString: String = if (d > 0) printWithWholeNumbers(n, d)
  else printWithWholeNumbers(-n, -d)

  private[this] def printWithWholeNumbers(n: Int, d: Int): String = {
    if (toDouble.isWhole) toInt.toString
    else if (n / d == 0) (n / GCD(n, d)).toString + "/" + (d / GCD(n, d)).toString
    else toInt.toString + " " + ((n - n / d * d).abs / GCD(n, d)) + "/" + (d / GCD(n, d)).toString
  }

  private[this] def GCD(n: Int, d: Int): Int = {
    d match {
      case 0 => n
      case x if x < 0 => GCD(-n, -d)
      case _ => GCD(d, n % d)
    }
  }

  private def shortenRational: Rational = {
    new Rational(n / GCD(n, d), d / GCD(n, d))
  }

  def +(other: Rational): Rational = {
    new Rational(n * other.d + d * other.n, d * other.d).shortenRational
  }

  def -(other: Rational): Rational = {
    new Rational(n * other.d - d * other.n, d * other.d).shortenRational
  }

  def *(other: Rational): Rational = {
    new Rational(n * other.n, d * other.d).shortenRational
  }

  def /(other: Rational): Rational = {
    new Rational(n * other.d, d * other.n).shortenRational
  }

  def toDouble: Double = {
    n.toDouble / d.toDouble
  }

  def toInt: Int = {
    n / d
  }
}

object Rational {
  def apply(n: Int, d: Int = 1): Rational = {
    new Rational(n, d)
  }

  def one: Rational = {
    new Rational(1, 1)
  }

  def zero: Rational = {
    new Rational(0, 1)
  }
}
