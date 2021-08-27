import java.io.*
import java.util.*
data class Edge(val dest:Int, val cost:Int)
var N=0
var M=0
val Adjlist=Array(50000){ArrayList<Edge>()}

fun main() {
    val br=BufferedReader(InputStreamReader(System.`in`))
    val bw=BufferedWriter(OutputStreamWriter(System.out))
    var st=StringTokenizer(br.readLine())
    N=st.nextToken().toInt()
    M=st.nextToken().toInt()
    for(i in 1..M){
        st=StringTokenizer(br.readLine())
        val A=st.nextToken().toInt()
        val B=st.nextToken().toInt()
        val C=st.nextToken().toInt()
        Adjlist[A-1].add(Edge(B-1,C))
        Adjlist[B-1].add(Edge(A-1,C))
    }
    println(dijkstra())

}
fun dijkstra():Int{
    val pq=PriorityQueue{a:Edge,b:Edge ->
        when{
            a.cost==b.cost->0
            a.cost>b.cost->1
            else->-1
        }
    }
    val mcost=Array(N){Int.MAX_VALUE}
    pq.add(Edge(0,0))
    while(!pq.isEmpty()){
        val t=pq.poll()
        if(t.cost>mcost[t.dest]) continue
        for(i in Adjlist[t.dest]){
            val ncost=t.cost+i.cost
            if(mcost[i.dest]>ncost){
                mcost[i.dest]=ncost
                pq.add(Edge(i.dest,ncost))
            }
        }
    }
    return mcost[N-1]
}