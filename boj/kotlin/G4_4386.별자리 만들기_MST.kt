import java.util.*
import kotlin.math.sqrt

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val getDist =
        { p1: Pair<Double, Double>, p2: Pair<Double, Double> -> sqrt((p2.first - p1.first).let { it * it } + (p2.second - p1.second).let { it * it }) }
    val n = br.readLine().toInt()
    val p = Array(n) { br.readLine().split(' ').map { it.toDouble() }.run { get(0) to get(1) } }
    val dist = Array(n) { -1.0 }
    val visit=Array(n){false}
    val pq = PriorityQueue<Pair<Int, Double>>(compareBy{it.second})
    dist[0] = 0.0
    pq.add(0 to dist[0])
    while (pq.isNotEmpty()) {
        val now = pq.poll()
        if (now.second < dist[now.first]) continue
        visit[now.first]=true
        for (next in 0 until n) {
            if (visit[next]) continue
            val edgeDist = getDist(p[now.first], p[next])
            if (dist[next] == -1.0 || dist[next] > edgeDist) {
                dist[next] = edgeDist
                pq.add(next to edgeDist)
            }
        }
    }
    println(dist.sumOf { it })
}