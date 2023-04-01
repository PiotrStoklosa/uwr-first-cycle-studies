package lab03

object ApplicationEntryPoint {

  def main(args: Array[String]): Unit = {
    println("isSorted(List(1, 2, 3, 4, 5)) = " + Utils.isSorted(List(1, 2, 3, 4, 5), (a, b) => a < b))
    println("isSorted(List(1, 3, 2, 5, 4)) = " + Utils.isSorted(List(1, 3, 2, 5, 4), (a, b) => a < b))
    println()

    println("isAscSorted(List(1, 2, 3, 4, 5)) = " + Utils.isAscSorted(List(1, 2, 3, 4, 5)))
    println("isAscSorted(List(1, 2, 3, 5, 4)) = " + Utils.isAscSorted(List(1, 2, 3, 5, 4)))
    println()

    println("isDescSorted(List(5, 4, 3, 2, 1)) = " + Utils.isDescSorted(List(5, 4, 3, 2, 1)))
    println("isDescSorted(List(5, 4, 2, 3, 1)) = " + Utils.isDescSorted(List(5, 4, 2, 3, 1)))
    println()

    println("foldLeft(List(1, 2, 3, 4, 5), 1)((a, b) => a * b) = " + Utils.foldLeft(List(1, 2, 3, 4, 5), 1)((a, b) => a * b))
    println()

    println("sum(List(1, 2, 3, 4, 5)) = " + Utils.sum(List(1, 2, 3, 4, 5)))
    println()

    println("length(List(1, 2, 3, 4, 5)) = " + Utils.length(List(1, 2, 3, 4, 5)))
    println()

    println("compose((x: Int) => x * x, (x: Int) => 2 * x)(5) = " + Utils.compose((x: Int) => x * x, (x: Int) => 2 * x)(5))
    println()

    println("repeated((x: Int) => 2 * x, 3)(3) = " + Utils.repeated((x: Int) => 2 * x, 3)(3))
    println()

    println("curry((a: Int, b: Int) => a + b)(2)(3) = " + Utils.curry((a: Int, b: Int) => a + b)(2)(3))
    println()

    println("uncurry((a: Int) => (b: Int) => a + b)(2, 3) = " + Utils.uncurry((a: Int) => (b: Int) => a + b)(2, 3))
    println()

    //  Utils.unSafe(new Exception("An exception has occurred "))(() => 0/0) /*<- this will throw exception*/

  }

}
