import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val N = br.readLine().toInt()
    val alp = Array(N) { 0.0 }
    val str = br.readLine()
    repeat(N) {
        alp[it] = br.readLine().toDouble()
    }

    val numSt = Stack<Double>().apply {
        str.forEach {
            when (it) {
                '+' -> push(pop()+pop())
                '-' -> push(-pop()+pop())
                '*' -> push(pop()*pop())
                '/' ->push(1/pop()*pop())
                else ->push(alp[it.code-'A'.code])
            }
        }
    }
    println(String.format("%.2f",numSt.peek()))
}