package lab03

import scala.annotation.tailrec

object Utils {
  def isSorted(as: List[Int], ordering: (Int, Int) => Boolean): Boolean = as.sliding(2).forall(pair => ordering(pair.head, pair.last)) //checks if as is sorted according to ordering

  def isAscSorted(as: List[Int]): Boolean = isSorted(as, (a, b) => a < b) //checks if as is sorted in ascending order

  def isDescSorted(as: List[Int]): Boolean = isSorted(as, (a, b) => a > b) //checks if as is sorted in descending order

  @tailrec
  def foldLeft[A, B](l: List[A], z: B)(f: (B, A) => B): B = { //applies binary operator to a start value and all elements of l, going left to right. Dont use build-in List.foldLeft
    l match {
      case Nil => z
      case el :: l => foldLeft(l, f(z, el))(f)
    }
  }

  def sum(l: List[Int]): Int = foldLeft[Int, Int](l, 0)((a, b) => a + b) //sum elements of l with usage of foldLeft function

  def length[A](l: List[A]): Int = foldLeft[A, Int](l, 0)((a, _) => a + 1) //length of l with usage of foldLeft function

  def compose[A, B, C](f: B => C, g: A => B): A => C = (x: A) => f(g(x)) //compose two unary functions:compose(f,g)(x) = f(g(x)). Dont use Function.compose

  def repeated[A](f: A => A, n: Int): A => A = (x: A) => { //takes unary function f with integer n & returns the n-th repeated application of the function. For example: repeated(f, 3) = f(f(f(3)))
    require(n >= 0, "Can't compose function < 0 times!")
    n match {
      case a if a == 0 => x
      case _ => repeated(f, n - 1)(f(x))
    }
  }

  def curry[A, B, C](f: (A, B) => C): A => B => C = a => b => f(a, b) //converts a binary function f of two arguments into a function of one argument that partially applies f. For example, when def add(a: Int, b: Int) = a + b, than curry(add)(1)(1) == add(1, 1)

  def uncurry[A, B, C](f: A => B => C): (A, B) => C = (a: A, b: B) => f(a)(b) //reverse of curry function. For example, uncurry(f)(1, 1)(1) == f(1)(1)

  def unSafe[T](ex: Exception)(f: () => T): T = try f() catch { //catch any exception, log the error & throw the ex exception instead
    case _: Throwable => throw ex
  }

}