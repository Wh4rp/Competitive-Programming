fun main() {
    val t = readInt()
    repeat(t) {
        var n = readInt()
        val red = readInts()
        var m = readInt()
        val blue = readInts()
        var acumlatedRed = red.runningReduce { acc, i -> acc + i }
        var acumlatedBlue = blue.runningReduce { acc, i -> acc + i }
        var ans = 0
        for (intermedianValueRed in acumlatedRed) {
            for (intermedianValueBlue in acumlatedBlue) {
                ans = maxOf(ans, intermedianValueRed + intermedianValueBlue)
            }
        }
        ans = maxOf(ans, acumlatedRed.maxOrNull() ?: 0)
        ans = maxOf(ans, acumlatedBlue.maxOrNull() ?: 0)
        println(ans)
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map { it.toInt() }
