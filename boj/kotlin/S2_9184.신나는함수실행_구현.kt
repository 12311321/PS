import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val arr = Array(21) { Array(21) { Array(21) { -1 } } }
    arr[0][0][0] = 1

    fun w(a: Int, b: Int, c: Int): Int {
        if (a <= 0 || b <= 0 || c <= 0) return 1
        if (a > 20 || b > 20 || c > 20) return w(20, 20, 20)
        if (arr[a][b][c] == -1) arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
        return arr[a][b][c]
    }
    while (true) {
        val (a, b, c) = br.readLine().split(' ').map { it.toInt() }
        if (a == -1 && b == -1 && c == -1) break
        bw.write("w($a, $b, $c) = ${w(a,b,c)}\n")
    }
    bw.flush()
}