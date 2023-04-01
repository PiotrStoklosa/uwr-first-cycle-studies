package lab07.money

import lab07.money.Currency.{EUR, PLN, USD}

object ApplicationEntryPoint {
  def main(args: Array[String]): Unit = {
    implicit val converter: CurrencyConverter = CurrencyConverter(Currency.conversion)
    val sum1: Money = Money(100.01, USD) + Money(200, EUR)
    println("sum1 = " + sum1)

    val sum2: Money = Money(100.01, "zl") + Money(200, "$")
    println("sum2 = " + sum2)

    val sum3: Money = Money(5, "zl") + Money(3, PLN) + Money(20.5, USD)
    println("sum3 = " + sum3)

    val sub: Money = Money(300.01, USD) - Money(200, EUR)
    println("sub = " + sub)

    val mult1: Money = Money(30, "zl") * 20
    println("mult1 = " + mult1)

    val mult2: Money = Money(20, "$") * 11
    println("mult2 = " + mult2)

    val conv1: Money = Money(150.01, USD) as PLN
    println("conv1 = " + conv1)

    val conv2: Money = Money(120.01, USD) as "€"
    println("conv2 = " + conv2)

    val compare1: Boolean = Money(300.30, USD) > Money(200, "€")
    println("compare1 = " + compare1)

    val compare2: Boolean = Money(300.30, "$") < Money(200, EUR)
    println("compare2 = " + compare2)

  }

}
