import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val inf = Int.MAX_VALUE
    val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val map = Array(N) { br.readLine() }
    val dist = Array(N) { Array(M) { Array(2) { -1 } } }
    val q = LinkedList<Triple<Int, Int, Int>>()
    val isValidPos = { r: Int, c: Int -> r in 0 until N && c in 0 until M }
    dist[0][0][0] = 1
    q.add(Triple(0, 0, 0))
    while (q.isNotEmpty()) {
        val now = q.poll()
        for (d in dir) {
            val nr = now.first + d.first
            val nc = now.second + d.second
            if (!isValidPos(nr, nc)) continue
            val nw = now.third + map[nr][nc].code - '0'.code

            if (nw > 1) continue
            if (dist[nr][nc][nw] != -1) continue
            dist[nr][nc][nw] = dist[now.first][now.second][now.third] + 1
            q.add(Triple(nr, nc, nw))
        }
    }
    bw.write(dist[N - 1][M - 1].filter{it>0}.run{if(size==0) "-1" else minOf{it}}.toString() + "\n")
    bw.close()
}