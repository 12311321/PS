import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val adjList = Array(n) { ArrayList<Pair<Int, Int>>() }
    val dist = Array(n) {-1  }
    val pre = Array(n) { -1  }

    repeat(m) {
        br.readLine().split(' ').map { it.toInt() }.run {
            adjList[get(0) - 1].add(get(1) - 1 to get(2))
            adjList[get(1) - 1].add(get(0) - 1 to get(2))
        }
    }

    val pq = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> 0
        }
    }

    repeat(n) { s ->
        dist[s] = 0
        dist.fill(1 shl 30, 0, n)
        pq.add(s to 0)

        while (pq.isNotEmpty()) {
            val now = pq.poll()
            if (dist[now.first] < now.second) continue
            for(edge in adjList[now.first]){
                val nDist=edge.second+now.second
                if(nDist<dist[edge.first]){
                    dist[edge.first]=nDist
                    pre[edge.first]=now.first
                    pq.add(edge.first to nDist)
                }
            }
        }

        for(e in 0 until n){
            if(s==e) bw.write("- ")
            else {
                var pos = e
                while (pre[pos] != s) pos = pre[pos]
                bw.write("${pos+1} ")
            }
        }
        bw.write("\n")
    }
    bw.close()
}