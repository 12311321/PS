import java.util.*
import kotlin.collections.ArrayList

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val INF = Int.MAX_VALUE
    data class Edge(val dest:Int, val time:Int, val cost:Int)
    val N = br.readLine().toInt()
    val (T,M) = br.readLine().split(' ').map{it.toInt()}
    val adjList = Array(N){ArrayList<Edge>()}
    val dp = Array(N){Array(M+1){Int.MAX_VALUE} }
    repeat(br.readLine().toInt()){
        br.readLine().split(' ').map{it.toInt()}.run{
            adjList[get(0)-1].add(Edge(get(1)-1,get(2),get(3)))
            adjList[get(1)-1].add(Edge(get(0)-1,get(2),get(3)))
        }
    }

    val pq = PriorityQueue<Edge>(Comparator.comparing { it.time })
    dp[0][0]=0
    pq.add(Edge(0,0,0))
    while(pq.isNotEmpty()){
        val now = pq.poll()
        if(now.time!=dp[now.dest][now.cost]) continue
        for(edge in adjList[now.dest]){
            val nCost = now.cost+edge.cost
            val nTime = now.time+edge.time
            if(nCost>M || nTime>T) continue
            if(dp[edge.dest][nCost]<=nTime) continue
            dp[edge.dest][nCost]=nTime
            pq.add(Edge(edge.dest,nTime,nCost))
        }
    }
    var ans=-1
    for(i in 0..M){
        if(dp[N-1][i]<=T){
            ans=i
            break
        }
    }
    println(ans)

}