import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Edge(val dest: Int, val cost: Int)

    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    val INF = Int.MAX_VALUE
    val adjList = Array(N) { ArrayList<Edge>() }

    repeat(M) {
        val (s, e, d) = br.readLine().split(' ').map { it.toInt() }
        adjList[s - 1].add(Edge(e - 1, d))
    }
    val (s, e) = br.readLine().split(' ').map { it.toInt() - 1 }
    val distArr = Array(N) { INF }
    val pq = PriorityQueue { a: Edge, b: Edge ->
        when {
            a.cost > b.cost -> 1
            a.cost < b.cost -> -1
            else -> 0
        }
    }
    distArr[s] = 0
    pq.add(Edge(s,0))
    while(pq.isNotEmpty()){
        val now=pq.poll()
        if(distArr[now.dest]<now.cost) continue
        for(edge in adjList[now.dest]){
            val nDist=now.cost+edge.cost
            if(nDist>=distArr[edge.dest]) continue
            distArr[edge.dest]=nDist
            pq.add(Edge(edge.dest,nDist))
        }
    }
    bw.write(distArr[e].toString())
    bw.close()
}