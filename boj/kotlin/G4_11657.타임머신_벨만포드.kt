fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val inf=Long.MAX_VALUE/2
    data class Edge(val s: Int, val e: Int, val cost: Int)
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val edgeList = Array(M) {
        br.readLine().split(' ').map { it.toInt() }.run {
            Edge(get(0) - 1, get(1) - 1, get(2))
        }
    }
    val dist=Array(N){inf}
    dist[0]=0L

    fun edgeRelation():Boolean{
        var flag=false
        for(edge in edgeList){
            if(dist[edge.s]==inf) continue
            edge.run{
                val nDist=dist[s]+cost
                flag =flag or (dist[e]>nDist)
                dist[e]=dist[e].coerceAtMost(nDist)
            }
        }
        return flag
    }
    repeat(N-1){
        edgeRelation()
    }
    if(edgeRelation()) bw.write("-1")
    else{
        for(i in 1 until dist.size) bw.write(if(dist[i]==inf)"-1\n" else "${dist[i]}\n")
    }
    bw.close()
}