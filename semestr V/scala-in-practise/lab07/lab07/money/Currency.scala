package lab07.money

trait Currency {
  val name: String
  val value: String
}

object Currency {
  val conversion: Map[(Currency, Currency), BigDecimal] = Map(
    (EUR, PLN) -> BigDecimal(4.64),
    (EUR, USD) -> BigDecimal(1.13),
    (PLN, EUR) -> BigDecimal(0.22),
    (PLN, USD) -> BigDecimal(0.24),
    (USD, EUR) -> BigDecimal(0.89),
    (USD, PLN) -> BigDecimal(4.11))

  val codes: Map[String, Currency] = {
    Map(
      "€" -> EUR,
      "$" -> USD,
      "zl" -> PLN
    )
  }

  case object EUR extends Currency {
    override val name: String = "EUR"
    override val value: String = "€"
  }

  case object USD extends Currency {
    override val name: String = "USD"
    override val value: String = "$"
  }

  case object PLN extends Currency {
    override val name: String = "PLN"
    override val value: String = "zl"
  }
}