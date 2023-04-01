package lab06.pizzeria

case class Pizza(
                  typ: Type,
                  size: Size,
                  crust: Crust,
                  extraMeat: Option[Meat],
                  extraTopping: Option[Topping]
                ) {

  override def toString: String = "{Pizza: " + size.toString + " " + crust.toString + " crust " + typ.toString + extraMeat.map(" with extra " + _.toString).getOrElse("") + extraTopping.map(" with extra " + _.toString).getOrElse("") + "}"

  val price: Double = typ.price * size.percentValue + crust.cost + extraMeat.map(_.cost).getOrElse(0.0) + extraTopping.map(_.cost).getOrElse(0.0)

}

sealed abstract class Type {
  val price: Double
}

case object Margarita extends Type {
  override val price: Double = 5.0

  override def toString: String = "Margarita"
}

case object Pepperoni extends Type {
  override val price: Double = 6.5

  override def toString: String = "Pepperoni"
}

case object Funghi extends Type {
  override val price: Double = 7.0

  override def toString: String = "Funghi"
}

sealed abstract class Size {
  val percentValue: Double
}

case object Small extends Size {
  override val percentValue: Double = 0.9

  override def toString: String = "small"
}

case object Regular extends Size {
  override val percentValue: Double = 1.0

  override def toString: String = "regular"
}

case object Large extends Size {
  override val percentValue: Double = 1.5

  override def toString: String = "large"
}

sealed abstract class Crust {
  val cost: Double
}

case object Thin extends Crust {
  override val cost: Double = 0.0

  override def toString: String = "thin"
}

case object Thick extends Crust {
  override val cost: Double = 0.0

  override def toString: String = "thick"
}


sealed abstract class Topping {
  val cost: Double
}

case object Ketchup extends Topping {
  override val cost: Double = 0.5

  override def toString: String = "ketchup"
}

case object Garlic extends Topping {
  override val cost: Double = 0.5

  override def toString: String = "garlic"
}

sealed abstract class Meat {
  val cost: Double
}

case object Salami extends Meat {
  override val cost: Double = 1.0

  override def toString: String = "salami"
}

object Pizza {
  def apply(typ: Type,
            size: Size,
            crust: Crust,
            extraMeat: Meat,
            extraTopping: Topping): Pizza = {
    Pizza(typ, size, crust, Some(extraMeat), Some(extraTopping))
  }
}