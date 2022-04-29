import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val dir = arrayOf(1 to 0, -1 to 0, 0 to 1, 0 to -1)
    val isValidPos = { r: Int, c: Int -> r in 0 until N && c in 0 until N }
    val adjList = Array(N){Array(N){ArrayList<Pair<Int,Int>>()} }
    val visit = Array(N){Array(N){false to false} }
    repeat(M){
        br.readLine().split(' ').map{it.toInt()-1}.run{
            adjList[get(0)][get(1)].add(get(2) to get(3))
        }
    }

    visit[0][0] = true to true
    val q = LinkedList<Pair<Int,Int>>()
    q.add(0 to 0)
    while(q.isNotEmpty()){
        val now = q.poll()
        for(d in dir){
            val nr=now.first+d.first
            val nc=now.second+d.second
            if(!isValidPos(nr,nc) || visit[nr][nc].first) continue
            visit[nr][nc] = visit[nr][nc].run{true to second}
            if(visit[nr][nc].run{first && second}) q.add(nr to nc)
        }

        for(edge in adjList[now.first][now.second]){
            if(visit[edge.first][edge.second].second) continue
            visit[edge.first][edge.second] = visit[edge.first][edge.second].run{first to true}
            if(visit[edge.first][edge.second].run{first && second}) q.add(edge)
        }
    }
    println(visit.sumOf{ it -> it.count{ it.second }})
}