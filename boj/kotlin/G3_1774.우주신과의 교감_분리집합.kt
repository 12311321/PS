import java.util.*
import kotlin.math.sqrt

fun main() {
    val br = System.`in`.bufferedReader()

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val pos = Array(N) { br.readLine().split(' ').map { it.toLong() }.run { get(0) to get(1) } }
    val cost =
        Array(N) { s -> Array(N) { e -> (pos[s].first - pos[e].first).let { it * it } + (pos[s].second - pos[e].second).let { it * it } } }

    repeat(M) {
        br.readLine().split(' ').map { it.toInt() - 1 }.run {
            cost[get(0)][get(1)] = 0L
            cost[get(1)][get(0)] = 0L
        }
    }
    val pq = PriorityQueue<Pair<Int,Long>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> 0
        }
    }

    val edgeCost = Array(N) { Long.MAX_VALUE }
    val visit=Array(N){false}
    edgeCost[0] = 0
    pq.add(0 to 0L)
    while (pq.isNotEmpty()) {
        val now = pq.poll()
        if(visit[now.first]) continue
        visit[now.first]=true

        for (i in 0 until N) {
            if (now.first == i || visit[i]) continue
            if(edgeCost[i]>cost[now.first][i]){
                edgeCost[i]=cost[now.first][i]
                pq.add(i to cost[now.first][i])
            }
        }
    }
    println(String.format("%.2f",edgeCost.sumOf{sqrt(it.toDouble())}))
}