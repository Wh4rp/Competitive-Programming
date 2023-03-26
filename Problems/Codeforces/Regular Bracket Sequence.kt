import java.util.ArrayDeque

fun main() {
    val t = readInt()
    repeat(t) {
        var s = readString()
        var stack = ArrayDeque<Char>()
        for (c in s) {
            if (stack.isEmpty()) {
                stack.push(c)
            } else {
                if ((c == ')' && stack.peek() != ')') || (c == '?' && stack.peek() == '(')) {
                    stack.pop()
                } else {
                    stack.push(c)
                }
            }
        }
        if (stack.size % 2 == 1 || stack.peek() == '(' || stack.peekLast() == ')') {
            println("NO")
        } else {
            println("YES")
        }
    }
}

private fun readString() = readLine()!!
private fun readInt() = readString().toInt()
private fun readInts() = readString().split(" ").map { it.toInt() }
