import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val getAbs = { a: Int -> if (a > 0) a else -a }
    val minComparator = { a: Int, b: Int ->
        when {
            a > b -> 1
            a < b -> -1
            else -> 0
        }
    }
    val pq = PriorityQueue<Int> { a, b ->
        var res = minComparator(getAbs(a), getAbs(b))
        if (res == 0) {
            res = minComparator(a, b)
        }
        res
    }

    repeat(br.readLine().toInt()) {
        br.readLine().toInt().let { n ->
            if (n == 0) bw.write((if (pq.isEmpty()) "0" else pq.poll().toString()) + "\n")
            else pq.add(n)
        }
    }
    bw.close()
}