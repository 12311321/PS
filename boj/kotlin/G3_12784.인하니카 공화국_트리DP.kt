fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    fun DFS(pos:Int,pre:Int,adjList:Array<ArrayList<Pair<Int,Int>>>,dp:Array<Int>){
        if(pos!=0 && adjList[pos].size==1) return
        dp[pos]=0
        for(edge in adjList[pos]){
            if(edge.first==pre) continue
            DFS(edge.first,pos,adjList,dp)
            dp[pos]+=dp[edge.first].coerceAtMost(edge.second)
        }
    }
    repeat(br.readLine().toInt()) {
        val (N, M) = br.readLine().split(' ').map { it.toInt() }
        val adjList=Array(N){ArrayList<Pair<Int,Int>>()}
        val dp=Array(N){1 shl 30}
        repeat(M){
            br.readLine().split(' ').map{it.toInt()}.run{
                adjList[get(0)-1].add(get(1)-1 to get(2))
                adjList[get(1)-1].add(get(0)-1 to get(2))
            }
        }
        DFS(0,-1,adjList,dp)
        bw.write("${dp[0]}\n")
    }
    bw.close()
}