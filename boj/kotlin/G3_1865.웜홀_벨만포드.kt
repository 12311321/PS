fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    data class Edge(val s: Int, val e: Int, val cost: Int)

    fun edgeRelation(edgeList:ArrayList<Edge>,dist:Array<Long>):Boolean{
        var flag=false
        for(edge in edgeList){
            edge.run{
                val nDist=dist[s]+cost
                flag =flag or (dist[e]>nDist)
                dist[e]=dist[e].coerceAtMost(nDist)
            }
        }
        return flag
    }

    repeat(br.readLine().toInt()){
        val (N, M,W) = br.readLine().split(' ').map { it.toInt() }
        val edgeList=ArrayList<Edge>()

        repeat(M){
            br.readLine().split(' ').map{it.toInt()}.run{
                edgeList.add(Edge(get(0)-1,get(1)-1,get(2)))
                edgeList.add(Edge(get(1)-1,get(0)-1,get(2)))
            }
        }
        repeat(W){
            br.readLine().split(' ').map{it.toInt()}.run{
                edgeList.add(Edge(get(0)-1,get(1)-1,-get(2)))
            }
        }

        val dist=Array(N){0L}
        repeat(N-1){
            edgeRelation(edgeList,dist)
        }
        if(edgeRelation(edgeList,dist)) bw.write("YES\n")
        else bw.write("NO\n")
    }
    bw.close()

}