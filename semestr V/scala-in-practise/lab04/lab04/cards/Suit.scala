package lab04.cards

import lab04.cards.Suit.suits

case class Suit(value: String) {
  def prettyPrint(): Char = value.toLowerCase() match {
    case "club" => 0x2663.toChar
    case "diamond" => 0x2666.toChar
    case "heart" => 0x2665.toChar
    case "spade" => 0x2660.toChar
  }

  require(suits.contains(value.toLowerCase), "There is no given suit")

}

object Suit {
  val suits = List("club", "diamond", "heart", "spade")
}
