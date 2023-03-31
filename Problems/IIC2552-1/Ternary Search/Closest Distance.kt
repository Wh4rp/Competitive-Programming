import kotlin.math.sqrt

fun min_ternary_search(times: Int, A : MutableList<Int>, B : MutableList<Int>, C : MutableList<Int>, D : MutableList<Int>): Double {
    var l = 0.0
    var r = 1.0
    repeat(times) {
        val d = (r - l) / 3.0
        val m1 = l + d
        val m2 = r - d
        val f1 = f(m1, A, B, C, D)
        val f2 = f(m2, A, B, C, D)
        if (f1 <= f2) r = m2
        if (f1 >= f2) l = m1
    }
    val min_dist = sqrt(f((l+r)*.5, A, B, C, D))
    if (min_dist < 1e-7) return 0.0
    return min_dist
}

fun distance(a_x : Double, a_y : Double, b_x : Double, b_y : Double): Double {
    return (a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y)
}

fun point_t(t : Double, x : Int, y : Int): Double {
    return x + (y - x)*t
}

fun f(t: Double, A : MutableList<Int>, B : MutableList<Int>, C : MutableList<Int>, D : MutableList<Int>): Double {
    return distance(point_t(t, A[0], B[0]), point_t(t, A[1], B[1]), point_t(t, C[0], D[0]), point_t(t, C[1], D[1]))
}

fun main(){
    val t = readInt()
    repeat(t){
        val numbers = readInts()
        var A = mutableListOf<Int>(0, 0)
        var B = mutableListOf<Int>(0, 0)
        var C = mutableListOf<Int>(0, 0)
        var D = mutableListOf<Int>(0, 0)
        A[0] = numbers[0]
        A[1] = numbers[1]
        B[0] = numbers[2]
        B[1] = numbers[3]
        C[0] = numbers[4]
        C[1] = numbers[5]
        D[0] = numbers[6]
        D[1] = numbers[7]
        println("Case ${it+1}: ${min_ternary_search(100, A, B, C, D)}")
    }
}

private fun readString() = readLine()!!
private fun readInt() = readString().toInt()
private fun readInts() = readString().split(" ").map { it.toInt() }