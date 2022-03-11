fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Edge(val s: Int, val e: Int, val cost: Int)

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val par = Array(N){it}
    val d = Array(N){0}
    val edgeList = Array(M) {
        br.readLine().split(' ').map { it.toInt() }.run { Edge(get(0) - 1, get(1) - 1, get(2)) }
    }.apply { sortBy { it.cost } }

    fun find(a:Int):Int{
        if(par[a]!=a) par[a]=find(par[a])
        return par[a]
    }
    fun union(a:Int, b:Int):Boolean{
        val pa=find(a)
        val pb=find(b)
        if(pa==pb) return false
        if(d[pa]>d[pb]) par[pb]=pa
        else if(d[pa]<d[pb]) par[pa]=pb
        else{
            par[pb]=pa
            d[pa]++
        }
        return true
    }
    var ans=0
    var cnt=0
    for(edge in edgeList){
        if(cnt==N-2) break
        if(union(edge.s,edge.e)){
            ans+=edge.cost
            cnt+=1
        }
    }

    println("$ans\n")
}