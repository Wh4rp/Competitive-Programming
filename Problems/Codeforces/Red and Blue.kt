fun main() {
    val t = readInt()
    repeat(t) {
        var n = readInt()
        val red = readInts()
        var m = readInt()
        val blue = readInts()
        var acumlatedRed = red.scan(0) { acc, i -> acc + i }
        var acumlatedBlue = blue.scan(0) { acc, i -> acc + i }
        println(maxOf(0, acumlatedRed.max() + acumlatedBlue.max()))
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map { it.toInt() }
