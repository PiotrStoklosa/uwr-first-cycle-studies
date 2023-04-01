package lab05

import lab05.plugins._

object ApplicationEntryPoint {
  def main(args: Array[String]): Unit = {

    println("Tests for traits: ")

    println("\nRevert 'Test'")
    println(new Reverting {}.plugin("Test"))
    println("\nTeSt to lower case:")
    println(new LowerCasing {}.plugin("TeSt"))
    println("\nSingleSpacing for '  t  e   s t   '")
    println(new SingleSpacing {}.plugin("  t  e   s t   "))
    println("\nNoSpacing for 'ala ma   kota'")
    println(new NoSpacing {}.plugin("ala ma   kota"))
    println("\nDuplicatedRemoval for 'alzaa  cda'")
    println(new DuplicateRemoval {}.plugin("alzaa  cda"))
    println("\nRotating for 'abc'")
    println(new Rotating {}.plugin("abc"))
    println("\nDoubling for 'abcd'")
    println(new Doubling {}.plugin("abcd"))
    println("\nShortening for 'ab cd'")
    println(new Shortening {}.plugin("ab cd"))

    println("\n\n\nTests for plugins:")

    println("actionA for '  ala   ma   kota   ' => 'ala ma kota' => 'alla  maa kkotta => 'al makot'")
    println(Actions.actionA.plugin("  ala   ma   kota   "))
    println("\nactionB for 'a b c d' => 'abcd' => 'ac' => 'acc'")
    println(Actions.actionB.plugin("a b c d"))
    println("\nactionC for 'ABcD' => 'abcd' => 'abbcdd'")
    println(Actions.actionC.plugin("ABcD"))
    println("\nActionD for 'aabccdeef' => 'bdf' => 'fbd'")
    println(Actions.actionD.plugin("aabccdeef"))
    println("\nActionE for 'a b c d' => 'abcd' => 'ac' => 'acc' => 'cca'")
    println(Actions.actionE.plugin("a b c d"))
    println("\nActionF for 'abcdefg' => (5 times) => 'cdefgab'")
    println(Actions.actionF.plugin("abcdefg"))
    println("\nActionG for 't e s tt' => 't e s tt' => 't  e  s  tt' => 't  s t' => 'tst' => 'tt' => 'ttt'")
    println(Actions.actionG.plugin("t e s tt"))
  }
}
