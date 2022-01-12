fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Edge(val s: Int, val e: Int, val cost: Int)

    val N = br.readLine().toInt()
    val edgeList = ArrayList<Edge>()
    val par=Array(N){it}
    val d=Array(N){0}

    fun find(a:Int):Int{
        if(par[a]!=a) par[a]=find(par[a])
        return par[a]
    }

    fun union(a:Int,b:Int):Boolean{
        val pa=find(a)
        val pb=find(b)
        if(pa==pb) return false
        if(d[pa]==d[pb]){
            par[pb]=pa
            d[pa]++
        }else if(d[pa]>d[pb]) par[pb]=pa
        else par[pa]=pb
        return true
    }

    repeat(N) { s ->
        br.readLine().split(' ').map { it.toInt() }.forEachIndexed { e, cost ->
            if(s<e) edgeList.add(Edge(s,e,cost))
        }
    }
    var ans=0L
    edgeList.sortBy{it.cost}
    edgeList.forEach{
        if(union(it.s,it.e)) ans+=it.cost
    }
    bw.write("$ans")
    bw.close()
}