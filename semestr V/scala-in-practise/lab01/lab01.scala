import java.io.File
import scala.io.Source
import scala.math.sqrt
import scala.util.{Random, Using}

//scalar product of two vectors xs and ys
def scalarUgly(xs: List[Int], ys: List[Int]): Int = {
  var i = 0
  var result = 0
  while (i < xs.length) {
    result += xs(i) * ys(i)
    i += 1
  }
  result
}

def scalar(xs: List[Int], ys: List[Int]): Int = {
  (for ((x, y) <- xs zip ys) yield x * y).sum
}

//quicksort algorithm
def sortUgly(xs: List[Int]): List[Int] = {
  if (xs.length <= 1) xs
  else {
    val pivot = xs(Random.nextInt(xs.length))
    var lower: List[Int] = List()
    var higher: List[Int] = List()
    var equal: List[Int] = List()
    var i = 0
    while (i < xs.length) {
      if (xs(i) < pivot) lower = lower.::(xs(i))
      else if (xs(i) > pivot) higher = higher.::(xs(i))
      else equal = equal.::(xs(i))
      i += 1
    }
    List.concat(sortUgly(lower), equal, sortUgly(higher))
  }
}

def sort(xs: List[Int]): List[Int] = {
  if (xs.length <= 1) xs
  else {
    val pivot = xs(Random.nextInt(xs.length))
    List.concat(
      sort(xs.filter(_ < pivot)),
      xs.filter(_ == pivot),
      sort(xs.filter(_ > pivot)))
  }
}

//checks if n is prime
def isPrimeUgly(n: Int): Boolean = {
  if (n < 2)
    false
  else {
    var x = 2
    while (x <= sqrt(n).ceil.toInt) {
      if (n % x != 0)
        return false
      x += 1
    }
    true
  }
}

def isPrime(n: Int): Boolean = {
  if (n < 2) false else List.range(2, sqrt(n + 1).ceil.toInt) forall (x => n % x != 0)
}

//for given positive integer n, find all pairs of integers i and j,
// where 1 ≤ j < i < n such that i + j is prime
def primePairsUgly(n: Int): List[(Int, Int)] = {
  var result = List((1, 1))
  var i = 1
  while (i < n) {
    var j = 1
    while (j < i) {
      if (isPrime(i + j))
        result = result.::(i, j)
      j += 1
    }
    i += 1
  }
  result
}

def primePairs(n: Int): List[(Int, Int)] = {
  for {i <- List.range(2, n)
       j <- List.range(1, i)
       if isPrime(i + j)} yield (i, j)
}

//create a list with all lines from given file
val filesHere: Array[File] = new java.io.File(".").listFiles

def fileLinesUgly(file: java.io.File): List[String] = {
  var result: List[String] = List()
  val bufferedSource = Source.fromFile(file)
  for (line <- bufferedSource.getLines) {
    result = result.::(line)
  }
  bufferedSource.close
  result
}

def fileLines(file: java.io.File): List[String] = {
  Using(Source.fromFile(file)) { input =>
    input.getLines().toList
  }.get
}

//print names of all .scala files which are in filesHere & are non
// empty
def printNonEmptyUgly(pattern: String): Unit = {
  for (file <- filesHere) {
    if (file.getName.matches("[A-Za-z0-9]+.scala") && file.length() > 0 && file.getName.matches(pattern))
      println(file)
  }
}

def printNonEmpty(pattern: String): Unit = {
  println(for {
    file <- filesHere.toList if file.getName.matches("[A-Za-z0-9]+.scala") && file.length() > 0 && file.getName.matches(pattern)
  } yield file.getName)
}