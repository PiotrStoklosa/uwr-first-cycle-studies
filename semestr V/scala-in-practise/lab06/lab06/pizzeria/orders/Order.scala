package lab06.pizzeria.orders

import lab06.pizzeria.Pizza
import lab06.pizzeria.orders.Order.parsePrice

import scala.reflect.ClassTag
import scala.util.matching.Regex

class Order(
             name: String,
             address: String,
             phone: String,
             pizzas: List[Pizza],
             drinks: List[Drink],
             discount: Option[Discount],
             specialInfo: Option[String]
           ) {

  val validPhone: Regex = "^\\d{9}$".r

  require(isPhoneValid, "This is no valid phone!")

  def isPhoneValid: Boolean = {
    validPhone.matches(phone.replaceAll(" ", ""))
  }

  def calculatePromotion(str: String): Double = {
    if (discount.isDefined) {
      discount.get.discounts.getOrElse(str, 1.0)
    } else {
      1.0
    }
  }

  override def toString: String = {
    "Order{ name: " + name + " phone: " + phone + " address: " + address + " pizzas: " + pizzas + " drinks: " +
      drinks + " discount: " + discount.map(_.toString).getOrElse("lack of") + " special info: " +
      specialInfo.getOrElse("lack of") + "}"
  }

  def extraMeatPrice: Option[Double] = pizzas.flatMap(_.extraMeat) match {
    case Nil => None
    case x => Some(parsePrice(x.map(_.cost).sum))
  }

  def pizzasPrice: Option[Double] = pizzas match {
    case Nil => None
    case _ => Some(parsePrice(pizzas.map(_.price).sum))
  }

  def drinksPrice: Option[Double] = drinks match {
    case Nil => None
    case _ => Some(parsePrice(drinks.map(_.cost).sum))
  }

  def priceByType[T: ClassTag]: Option[Double] = {

    pizzas.filter(pizza => pizza.typ match {
      case _: T => true
      case _ => false
    })
  } match {
    case Nil => None
    case pizzas => Some(parsePrice(pizzas.map(_.price).sum))
  }

  val price: Double = parsePrice(pizzasPrice.getOrElse(0.0) * calculatePromotion("Pizza") +
    extraMeatPrice.getOrElse(0.0) + drinksPrice.getOrElse(0.0) * calculatePromotion("Drinks"))

}


sealed abstract class Discount {
  val discounts: Map[String, Double]

}

case object Student extends Discount {
  override val discounts = Map("Pizza" -> 0.95)


  override def toString: String = "student's discount"
}

case object Senior extends Discount {
  override val discounts = Map("Pizza" -> 0.93, "Drinks" -> 0.93)

  override def toString: String = "senior's discount"
}

sealed abstract class Drink {
  val cost: Double
}

case object Lemonade extends Drink {
  override val cost: Double = 2
}

object Order {
  def apply(name: String,
            address: String,
            phone: String,
            pizzas: List[Pizza],
            drinks: List[Drink],
            discount: Option[Discount],
            specialInfo: Option[String]): Order = {
    new Order(name, address, phone, pizzas, drinks, discount, specialInfo)
  }

  def apply(name: String,
            address: String,
            phone: String,
            pizzas: List[Pizza]): Order = {
    apply(name, address, phone, pizzas)
  }

  def parsePrice(price: Double): Double = {
    (math floor (price * 100)) / 100.0
  }
}