import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Node(
        var dp: Int = 0,
        var seq: Int = -1,
        val adjList: ArrayList<Int> = ArrayList(),
        var inDeg: Int = 0,
        var isCP: Boolean = false
    )

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val nodes = Array(N) { Node() }
    val cp = ArrayList<Node>()
    val sortedNodes = ArrayList<Node>()
    repeat(M) {
        br.readLine().split(' ').map { it.toInt() - 1 }.run {
            nodes[get(0)].adjList.add(get(1))
            nodes[get(1)].inDeg++
        }
    }

    val (S, E, K) = br.readLine().split(' ').map { it.toInt() - 1 }
    repeat(K+1){nodes[br.readLine().toInt()-1].isCP=true}

    //br.readLine().split(' ').map { it.toInt() - 1 }.forEach { nodes[it].isCP = true }

    var pn = 0
    val queue: Queue<Int> = LinkedList()
    for (i in 0 until N) {
        if (nodes[i].inDeg != 0 || nodes[i].seq != -1) continue
        queue.add(i)
        while (queue.isNotEmpty()) {
            val now = queue.poll()
            nodes[now].seq = pn++
            if (now == S || sortedNodes.isNotEmpty()) {
                sortedNodes.add(nodes[now])
            }
            if (nodes[now].isCP) cp.add(nodes[now])
            nodes[now].adjList.forEach {
                nodes[it].inDeg--
                if (nodes[it].inDeg == 0) queue.add(it)
            }
        }

    }

    var nextCPIdx = 0
    nodes[S].dp = 1
    sortedNodes.forEach { now ->
        if (nextCPIdx < cp.size && cp[nextCPIdx].seq == now.seq) nextCPIdx++
        now.adjList.forEach {
            if (nextCPIdx == cp.size || nodes[it].seq <= cp[nextCPIdx].seq) nodes[it].dp += now.dp
        }
    }
    bw.write(nodes[E].dp.toString())
    bw.close()
}