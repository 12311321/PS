import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (V, E) = br.readLine().split(' ').map { it.toInt() }
    val K = br.readLine().toInt() - 1
    val adjList = Array(V) { ArrayList<Pair<Int, Int>>() }
    val dist = Array(V) { Int.MAX_VALUE }
    repeat(E) {
        br.readLine().split(' ').map { it.toInt() }.run {
            adjList[get(0) - 1].add(get(1) - 1 to get(2))
        }
    }

    val pq = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> 0
        }
    }

    dist[K] = 0
    pq.add(K to 0)
    while (pq.isNotEmpty()) {
        val now = pq.poll()
        if (now.second > dist[now.first]) continue
        for (edge in adjList[now.first]) {
            val nDist = now.second + edge.second
            if (dist[edge.first] > nDist) {
                dist[edge.first] = nDist
                pq.add(edge.first to nDist)
            }
        }
    }

    for(d in dist) bw.write("${if(d==Int.MAX_VALUE)"INF" else d}\n")
    bw.close()
}