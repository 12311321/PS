import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Edge(val r: Int, val c: Int, val cost: Int)

    val inf = Int.MAX_VALUE

    val arr = Array(125) { Array(0) { 0 } }
    val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
    val cost = Array(125) { Array(125) { inf } }

    val pq = PriorityQueue<Edge> { a, b ->
        when {
            a.cost > b.cost -> 1
            a.cost < b.cost -> -1
            else -> 0
        }
    }

    val isValidPos = { r: Int, c: Int, N: Int -> r in 0 until N && c in 0 until N }
    var ct = 1
    var N = br.readLine().toInt()
    while (N != 0) {

        repeat(N) { r ->
            arr[r] = br.readLine().split(' ').map { k -> k.toInt() }.toTypedArray()
            cost[r].fill(inf, 0, N)
        }
        cost[0][0] = arr[0][0]
        pq.add(Edge(0, 0, arr[0][0]))

        while (pq.isNotEmpty()) {
            val now = pq.poll()
            if (now.cost > cost[now.r][now.c]) continue
            for (d in dir) {
                val nr = now.r + d.first
                val nc = now.c + d.second
                if (!isValidPos(nr, nc, N)) continue
                val nCost = now.cost + arr[nr][nc]
                if (nCost < cost[nr][nc]) {
                    cost[nr][nc] = nCost
                    pq.add(Edge(nr, nc, nCost))
                }
            }
        }

        bw.write("Problem ${ct++}: ${cost[N - 1][N - 1]}\n")
        N = br.readLine().toInt()
    }
    bw.close()
}