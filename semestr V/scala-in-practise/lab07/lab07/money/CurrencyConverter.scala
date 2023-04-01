package lab07.money

case class CurrencyConverter(conversion: Map[(Currency, Currency), BigDecimal]) {
  def convert(from: Currency, to: Currency): BigDecimal = if (from == to) 1 else Currency.conversion.get(from, to) match {
    case None => throw new IllegalArgumentException("There is no such currency in the conversion table")
    case x => x.get
  }
}
