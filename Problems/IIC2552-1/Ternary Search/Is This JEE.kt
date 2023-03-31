import kotlin.math.sin
import kotlin.math.PI

fun f(x: Double, b : Double, c : Double): Double {
    return (x*x + b*x + c) / sin(x)
}

fun min_ternary_search(times: Int, b : Double, c : Double): Double {
    var l = 0.0
    var r = PI * .5
    repeat(times) {
        val d = (r - l) / 3.0
        val m1 = l + d
        val m2 = r - d
        val f1 = f(m1, b, c)
        val f2 = f(m2, b, c)
        if (f1 <= f2) r = m2
        if (f1 >= f2) l = m1
    }
    return f((l+r)*.5, b, c)
}

fun main() {
    val t = readInt()
    repeat(t) {
        val v = readDoubles()
        var b = v[0]
        var c = v[1]
        println(min_ternary_search(100, b, c))
    }
}

private fun readString() = readLine()!!
private fun readInt() = readString().toInt()
private fun readDoubles() = readString().split(" ").map { it.toDouble() }