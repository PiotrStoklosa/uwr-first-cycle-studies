package lab04

import lab04.cards.{Card, Rank, Suit}
import lab04.deck.Deck
import lab04.games.Blackjack

object ApplicationEntryPoint {
  def main(args: Array[String]): Unit = {
    val blackjack = Blackjack(1)
    println("Created new Blackjack with 1 deck")

    println("Lets play with 10 cards")
    blackjack.play(10)

    println("\nShortest first 21 in the game")
    blackjack.shortestFirst21()

    println("\nall 21 in the game, pretty-printed")
    blackjack.all21.foreach(Card.prettyPrintCards)

    println("Created new deck with two cards")
    val deck = Deck(List(Card(Rank("2"), Suit("club")), Card(Rank("Jack"), Suit("diamond"))))
    deck.prettyPrintDeck()

    println("\nDeck after pulling one card")
    val deckPull = deck.pull()
    deckPull.prettyPrintDeck()

    println("\nDeck after pushing Ace Heart")
    val deckPush = deckPull.push(Card(Rank("Ace"), Suit("Heart")))
    deckPush.prettyPrintDeck()

    println("\nDeck after pushing King Club")
    val deckPush2 = deckPush.push(Suit("club"), Rank("King"))
    deckPush2.prettyPrintDeck()

    val test = deckPush2

    println("\nCheck if this deck isStandard")
    println(test.isStandard)

    println("\nAmount of duplicates of King Club after pushing another King Club")
    println(test.push(Suit("club"), Rank("King")).duplicatesOfCard(Card(Rank("King"), Suit("club"))))

    println("\nAmount of diamonds in the given deck")
    println("Deck: ")
    test.prettyPrintDeck()
    println("Diamonds: " + test.amountOfColor(Suit("Diamond")))

    println("\nAmount of numerical 2")
    println("Numerical: " + test.amountOfNumerical(Card(Rank("2"), Suit("Heart"))))

    println("\nAmount with numerical after push 2 Club and 9 Heart")
    println("Numerical: " + test.push(Suit("club"), Rank("2")).push(Suit("heart"), Rank("9")).amountWithNumerical)

    println("\nAmount of King face in the given deck")
    println("Deck: ")
    test.prettyPrintDeck()
    println("Kings: " + test.amountOfFace(Rank("King")))

    println("\nAmount with faces in the given deck")
    println("Faces: " + test.amountWithFace)

  }
}
