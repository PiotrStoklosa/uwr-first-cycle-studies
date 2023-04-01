package lab04.deck

import lab04.cards.Rank.{faces, ranks}
import lab04.cards.Suit.suits
import lab04.cards.{Card, Rank, Suit}

import scala.language.implicitConversions
import scala.util.{Random, Try}

class Deck(cards: List[Card]) {

  val sizeOfStandardDeckOfCards = 52
  private[this] val firstCard = 1

  val length: Int = cards.length

  def sliding(n: Int): Iterator[List[Card]] = cards.sliding(n)

  def pull(): Deck = {
    require(cards.nonEmpty, "You cannot pull a card from empty deck!")
    Deck(cards.drop(firstCard))
  }

  def topCard: Card = {
    require(cards.nonEmpty, "You cannot look at the card from empty deck!")
    cards.head
  }

  def push(c: Card): Deck = Deck(c :: cards)

  def push(color: Suit, value: Rank): Deck = Deck(Card(value, color) :: cards)

  val isStandard: Boolean = cards.distinct.length == sizeOfStandardDeckOfCards

  def duplicatesOfCard(card: Card): Int = cards.count(_ == card) match {
    case 0 => 0
    case x => x - 1
  }

  def amountOfColor(color: Suit): Int = cards.count(_.suit.value.toLowerCase == color.value.toLowerCase)

  def amountOfNumerical(numerical: Card): Int = {
    require(Try(numerical.rank.value.toInt).isSuccess, "The cart must be numerical!")
    cards.count(_.rank == numerical.rank)
  }

  val amountWithNumerical: Int = cards.flatMap(_.rank.value.toIntOption).length

  def amountOfFace(face: Rank): Int = {
    require(Try(face.value.toInt).isFailure || face.value.toLowerCase == "ace", "This is not a face!")
    cards.count(_.rank == face)
  }

  val amountWithFace: Int = cards.count(faces contains _.rank.value.toLowerCase())

  def prettyPrintDeck(): Unit = {
    Card.prettyPrintCards(cards)
  }

}

object Deck {
  def apply(): Deck = Deck(1)

  def apply(cards: List[Card]): Deck = {
    new Deck(cards)
  }

  def apply(numberOfDecks: Int): Deck = {
    require(numberOfDecks > 0, "Number of decks must be positive!")
    Deck(Random.shuffle(for {
      rank <- ranks.flatMap(List.fill(numberOfDecks)(_))
      suit <- suits.flatMap(List.fill(numberOfDecks)(_))
    } yield Card(Rank(rank), Suit(suit))))
  }
}
