package lab04.games

import lab04.cards.Card
import lab04.deck.Deck

import scala.annotation.tailrec
import scala.io.StdIn.readLine

class Blackjack(deck: Deck) {

  def askForValue(): Int = {
    println("There is an Ace, if you want to take value 1 type '1'. If you want value 11 type '11'")
    readLine() match {
      case "1" => 1
      case _ => 11
    }
  }

  @tailrec
  private def play(n: Int, sum: Int): Unit = {
    n match {
      case 0 => println("Sum of cards: " + sum)
      case _ =>
        deck.topCard.prettyPrint()
        deck.topCard match {
          case card if card.isAce => Blackjack(deck.pull()).play(n - 1, sum + askForValue())
          case card => Blackjack(deck.pull()).play(n - 1, sum + card.toValue)
        }
    }
  }

  def play(n: Int): Unit = {
    require(n > 0, "number of cards must be positive!")
    play(n, 0)
  }

  lazy val all21: List[List[Card]] = {
    Range(2, deck.length).flatMap(deck.sliding).toList.filter {
      list => list.map(_.toValue).sum == 21 || list.map(_.toValue).sum == 11 && list.exists(_.isAce)
    }
  }

  def shortestFirst21(): Unit = Range(2, deck.length).flatMap(deck.sliding).toList.find {
    list => list.map(_.toValue).sum == 21 || list.map(_.toValue).sum == 11 && list.exists(_.isAce)
  }.get.foreach(_.prettyPrint())

}

object Blackjack {
  def apply(numOfDecks: Int): Blackjack = {
    require(numOfDecks > 0, "number of decks must be positive!")
    new Blackjack(Deck(numOfDecks))
  }

  def apply(deck: Deck): Blackjack = {
    new Blackjack(deck)
  }
}