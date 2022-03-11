fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val (N,R,Q) = br.readLine().split(' ').map{it.toInt()}
    val adjList= Array(N){ArrayList<Int>()}
    val visit=Array(N){1}
    repeat(N-1){
        br.readLine().split(' ').map{it.toInt()-1}.run{
            adjList[get(0)].add(get(1))
            adjList[get(1)].add(get(0))
        }
    }
    fun dfs(pos:Int, pre:Int){
        for(next in adjList[pos]){
            if(visit[next]==1 && next!=pre) {
                dfs(next,pos)
                visit[pos] += visit[next]
            }
        }
    }

    dfs(R-1,-1)
    repeat(Q){
        bw.write("${visit[br.readLine().toInt()-1]}\n")
    }
    bw.close()
}