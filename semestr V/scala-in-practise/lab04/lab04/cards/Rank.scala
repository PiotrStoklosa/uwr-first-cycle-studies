package lab04.cards

import lab04.cards.Rank.ranks

case class Rank(value: String) {
  require(ranks.contains(value.toLowerCase))

  def this(value: Int) {
    this(value.toString)
  }

}

object Rank {
  def apply(value: Int): Rank = {
    new Rank(value)
  }

  val ranks = List("2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace")
  val faces = List("jack", "queen", "king")
  val values = Map("2" -> 2, "3" -> 3, "4" -> 4, "5" -> 5, "6" -> 6, "7" -> 7, "8" -> 8, "9" -> 9, "10" -> 10, "jack" -> 10, "queen" -> 10, "king" -> 10, "ace" -> 1)
}