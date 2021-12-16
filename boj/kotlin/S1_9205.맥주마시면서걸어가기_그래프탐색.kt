import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    class Graph {
        private val posList = ArrayList<Pair<Int, Int>>()
        private val adjList = ArrayList<ArrayList<Int>>()
        fun clear() {
            posList.clear()
            adjList.clear()
        }

        fun insert(pos: Pair<Int, Int>) {
            adjList.add(ArrayList())
            posList.forEachIndexed { idx, p ->
                if (isAdj(p, pos)) {
                    adjList.last().add(idx)
                    adjList[idx].add(adjList.lastIndex)
                }
            }
            posList.add(pos)
        }

        fun search(): Boolean {
            val visit = Array(posList.size) { false }
            val queue = LinkedList<Int>()
            queue.add(0)
            visit[0] = true
            while (queue.isNotEmpty()) {
                val now = queue.poll()
                adjList[now].forEach { next ->
                    if (!visit[next]) {
                        visit[next] = true
                        queue.add(next)
                    }
                }
            }
            return visit.last()
        }

        private fun getAbs(n: Int) = if (n < 0) -n else n
        private fun isAdj(p1: Pair<Int, Int>, p2: Pair<Int, Int>) =
            getAbs(p1.first - p2.first) + getAbs(p1.second - p2.second) <= 1000
    }

    val graph = Graph()
    repeat(br.readLine().toInt()) {
        graph.clear()
        repeat(2 + br.readLine().toInt()) {
            graph.insert(br.readLine().split(' ').run {
                Pair(get(0).toInt(), get(1).toInt())
            })
        }

        bw.write((if (graph.search()) "happy" else "sad") + "\n")
    }
    bw.flush()
}