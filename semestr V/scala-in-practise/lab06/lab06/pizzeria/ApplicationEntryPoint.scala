package lab06.pizzeria

import lab06.pizzeria.orders.{Lemonade, Order, Senior, Student}

object ApplicationEntryPoint {
  def main(args: Array[String]): Unit = {
    println("Tests for pizzeria: ")
    println("\n Created some pizzas")
    val p1: Pizza = Pizza(Pepperoni, Regular, Thin, Salami, Garlic)

    val p2: Pizza = Pizza(Margarita, Small, Thick, None, Some(Ketchup))
    println(p1)
    println(p2)
    println("First pizza price: " + p1.price)
    println("Second pizza price: " + p2.price)

    println("Creating orders")
    val o1 = new Order("First order", "Briarwood 207", "123 456 789", List(p1, p2), List(), Some(Senior), Some("Knock"))
    val o2 = new Order("Second order", "Oak Lane 76", "555 666 777", List(p1, p2), List(Lemonade), Some(Student), Some("Be careful, I have a dog"))

    println(o1)
    println(o2)

    println("First order price: " + o1.price)
    println("Second order price: " + o2.price)

    println("Price of the Margarita in first order: " + o1.priceByType[Margarita.type])
    println("Price of the Pepperoni in first order: " + o1.priceByType[Pepperoni.type])
    println("Price of the Funghi in first order: " + o1.priceByType[Funghi.type])

    println("Extra meat cost in second order: " + o2.extraMeatPrice)
    println("Drinks cost in second order: " + o2.drinksPrice)
    println("Pizza cost in second order: " + o2.pizzasPrice)

  }

}

