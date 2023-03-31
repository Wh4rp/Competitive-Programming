import kotlin.math.abs

fun f(x: Long, height: List<Long>, cost: List<Long>): Long {
    var sum : Long = 0
    for (i in height.indices) {
        sum += cost[i] * abs(height[i] - x)
    }
    return sum
}

fun main() {
    var t = readInt()
    repeat (t){
        var n = readInt()
        var height = readLongs()
        var cost = readLongs()
        var left : Long = 0
        var right : Long = 10000
        while (left < right) {
            val m = (left + right) / 2
            if (f(m + 1, height, cost) >= f(m, height, cost)) {
                right = m
            } else {
                left = m + 1
            }
        }
        println(f(left, height, cost))
    }
}

private fun readString() = readLine()!!
private fun readInt() = readString().toInt()
private fun readLong() = readString().toLong()
private fun readLongs() = readString().split(" ").map { it.toLong() }