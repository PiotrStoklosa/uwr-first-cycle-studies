package lab04.cards

case class Card(rank: Rank, suit: Suit) {
  def toValue: Int = Rank.values(rank.value.toLowerCase())

  def prettyPrint(): Unit = rank.value match {
    case "10" => println(rank.value + suit.prettyPrint().toString)
    case _ => println(rank.value.head.toUpper + suit.prettyPrint().toString)
  }

  def isAce: Boolean = toValue == 1
}

object Card {
  def prettyPrintCards(list: List[Card]): Unit = {
    list.foreach(_.prettyPrint())
    println()
  }
}