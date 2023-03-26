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
                if (c == ')' && stack.peek() == '(') {
                    stack.pop()
                } else {
                    stack.push(c)
                }
            }
        }
        if (stack.size % 2 == 1) {
            println("NO")
            return@repeat
        } else {
            while (stack.isNotEmpty()) {
                var c1 = stack.poll()
                var c2 = stack.pollLast()
                if (c1 == '?') {
                    c1 = ')'
                    if (stack.isNotEmpty()) {
                        if (stack.peek() == '(') {
                            stack.poll()
                            stack.addLast(c2)
                            continue
                        }
                    }
                }
                if (c2 == '?') {
                    c2 = '('
                    if (stack.isNotEmpty()) {
                        if (stack.peekLast() == ')') {
                            stack.pollLast()
                            stack.addFirst(c1)
                            continue
                        }
                    }
                }
                if (c1 == ')' && c2 == '(') {
                    continue
                } else {
                    println("NO")
                    return@repeat
                }
            }

            println("YES")
        }
    }
}

private fun readString() = readLine()!!
private fun readInt() = readString().toInt()
private fun readInts() = readString().split(" ").map { it.toInt() }
