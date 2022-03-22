import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var st = StringTokenizer(br.readLine())

    val V = st.nextToken().toInt()
    val E= st.nextToken().toInt()
    val adjList = Array(V) { ArrayList<Pair<Int, Int>>() }
    repeat(E) {
        st = StringTokenizer(br.readLine())
        val u=st.nextToken().toInt()-1
        val v=st.nextToken().toInt()-1
        val w=st.nextToken().toInt()
        adjList[u].add(v to w)
        adjList[v].add(u to w)
    }

    st = StringTokenizer(br.readLine())
    val M = st.nextToken().toInt()
    val x = st.nextToken().toInt()
    st=StringTokenizer(br.readLine())
    val mv = Array(M){-1}
    for(i in 0 until M){
        mv[i]=st.nextToken().toInt()-1
    }

    st = StringTokenizer(br.readLine())
    val S = st.nextToken().toInt()
    val y = st.nextToken().toInt()
    val sv = Array(S){-1}
    st=StringTokenizer(br.readLine())
    for(i in 0 until S){
        sv[i]=st.nextToken().toInt()-1
    }


    val check = Array(V) { false }
    fun dijkstra(dist: Array<Int>, start: Array<Int>, check: Array<Boolean>) {
        val pq = PriorityQueue<Pair<Int, Int>>(Comparator.comparing { it.second })
        for (s in start) {
            check[s] = true
            dist[s] = 0
            pq.add(s to 0)
        }
        while (pq.isNotEmpty()) {
            val now = pq.poll()
            if (now.second > dist[now.first]) continue
            for (edge in adjList[now.first]) {
                val nDist = edge.second + now.second
                if (dist[edge.first] > nDist) {
                    dist[edge.first] = nDist
                    pq.add(edge.first to nDist)
                }
            }
        }
    }


    val mDist = Array(V) { Int.MAX_VALUE / 2 }
    val sDist = Array(V) { Int.MAX_VALUE / 2 }
    dijkstra(mDist, mv, check)
    dijkstra(sDist, sv, check)

    var ans = Int.MAX_VALUE

    for (i in 0 until V) {
        if (mDist[i] > x || sDist[i] > y || check[i]) continue
        ans = ans.coerceAtMost(mDist[i] + sDist[i])
    }
    println(if (ans == Int.MAX_VALUE) -1 else ans)
}