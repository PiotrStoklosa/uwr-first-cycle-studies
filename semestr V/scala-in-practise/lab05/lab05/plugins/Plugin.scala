package lab05.plugins

trait Reverting extends Pluginable {
  override def plugin(str: String): String = str.reverse
}

trait LowerCasing extends Pluginable {
  override def plugin(str: String): String = str.toLowerCase()
}

trait SingleSpacing extends Pluginable {
  override def plugin(str: String): String = str.replaceAll(" +", " ").trim
}

trait NoSpacing extends Pluginable {
  override def plugin(str: String): String = str.replaceAll(" ", "")
}

trait DuplicateRemoval extends Pluginable {
  override def plugin(str: String): String = str.filter(chr => str.count(_ == chr) == 1)
}

class Rotating extends Pluginable {
  override def plugin(str: String): String = str.takeRight(1) + str.substring(0, str.length - 1)
}

trait Doubling extends Pluginable {
  override def plugin(str: String): String = (str.flatMap(_.toString * 2).toList.zipWithIndex collect { case (char, index) if index % 4 != 0 => char }).mkString
}

trait Shortening extends Pluginable {
  override def plugin(str: String): String = (str.toList.zipWithIndex collect { case (char, index) if index % 2 != 1 => char }).mkString
}

