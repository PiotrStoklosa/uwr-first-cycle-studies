package lab05

import lab05.plugins._

import scala.annotation.tailrec

object Actions {

  @tailrec
  private[this] def compose(arg: String, pluginable: Pluginable*): String = {
    pluginable.length match {
      case 0 => arg
      case _ => compose(pluginable.head.plugin(arg), pluginable.drop(1): _*)
    }
  }

  private[this] def compute(pluginable: Pluginable*): Pluginable = {
    (str: String) => compose(str, pluginable: _*)
  }

  @tailrec
  private[this] def compose(arg: String, times: Int, pluginable: Pluginable): String = {
    times match {
      case 0 => arg
      case _ => compose(pluginable.plugin(arg), times - 1, pluginable)
    }
  }

  private[this] def *(pluginable: Pluginable, times: Int): Pluginable = {
    (str: String) => compose(str, times, pluginable)

  }

  val actionA: Pluginable = compute(new SingleSpacing {}, new Doubling {}, new Shortening {})
  val actionB: Pluginable = compute(new NoSpacing {}, new Shortening {}, new Doubling {})
  val actionC: Pluginable = compute(new LowerCasing {}, new Doubling {})
  val actionD: Pluginable = compute(new DuplicateRemoval {}, new Rotating)
  val actionE: Pluginable = compute(new NoSpacing {}, new Shortening {}, new Doubling {}, new Reverting {})
  val actionF: Pluginable = compute(*(new Rotating, 5))
  val actionG: Pluginable = compute(actionA, actionB)


}
