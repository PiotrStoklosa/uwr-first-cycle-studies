package lab07.money

class Money(val amount: BigDecimal, val currency: Currency)(implicit currencyConverter: CurrencyConverter) {

  def +(that: Money): Money = Money(amount + (that as currency).amount, currency)

  def -(that: Money): Money = this + Money(-that.amount, that.currency)

  def *(that: Int): Money = Money(amount * that, currency)

  def as(currency: Currency): Money = Money(amount * currencyConverter.convert(this.currency, currency), currency)

  def as(currency: String): Money = Currency.codes.get(currency) match {
    case None => throw new IllegalArgumentException("There is no such currency!")
    case c => Money(amount * currencyConverter.convert(this.currency, c.get), c.get)
  }

  def >(that: Money): Boolean = amount > (that as currency).amount

  def <(that: Money): Boolean = amount < (that as currency).amount

  override def toString: String = amount.toString + "(" + currency.name + ")"
}

object Money {
  def apply(amount: BigDecimal, currency: Currency)(implicit currencyConverter: CurrencyConverter): Money = {
    new Money(amount.setScale(2, BigDecimal.RoundingMode.HALF_UP), currency)
  }

  def apply(amount: BigDecimal, currency: String)(implicit currencyConverter: CurrencyConverter): Money = {
    Currency.codes.get(currency) match {
      case None => throw new IllegalArgumentException("There is no such currency!")
      case _ => Money(amount.setScale(2, BigDecimal.RoundingMode.HALF_UP), Currency.codes(currency))
    }
  }
}
