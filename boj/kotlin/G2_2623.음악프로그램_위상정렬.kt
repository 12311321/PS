import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val adjList = Array(N) { ArrayList<Int>() }
    val inDeg = Array(N) { 0 }
    repeat(M) {
        br.readLine().split(' ').map { it.toInt() - 1 }.run {
            for (idx in 2..lastIndex) {
                adjList[get(idx - 1)].add(get(idx))
                inDeg[get(idx)]++
            }
        }
    }
    val q = LinkedList<Int>()
    for (idx in inDeg.indices) {
        if (inDeg[idx] == 0) q.add(idx)
    }
    val ans = ArrayList<Int>()
    while (q.isNotEmpty()) {
        val now = q.poll()
        ans.add(now+1)
        for (next in adjList[now]) {
            inDeg[next]--
            if (inDeg[next] == 0) q.add(next)
        }
    }

    bw.write(if (ans.size == N) ans.joinToString("\n") else "0\n")
    bw.close()
}