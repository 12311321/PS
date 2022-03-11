import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (N,M) = br.readLine().split(' ').map{it.toInt()}
    val board = Array(N){br.readLine().toCharArray()}
    val host = Array(N){Array(M){-1} }
    val sz = Array(N){Array(M){-1} }
    val dir=arrayOf(1 to 0, -1 to 0, 0 to 1, 0 to -1)
    val queue = LinkedList<Pair<Int,Int>>()
    val isValidPos = {r:Int,c:Int -> r in 0 until N && c in 0 until M}
    for(r in 0 until N) for(c in 0 until M){
        if(board[r][c]=='1' || host[r][c]!=-1) continue
        var s=1
        host[r][c]= r*M+c
        queue.add(r to c)
        while(queue.isNotEmpty()){
            val now= queue.poll()
            for(d in dir){
                val nr=now.first+d.first
                val nc=now.second+d.second
                if(!isValidPos(nr,nc) || board[nr][nc]=='1' || host[nr][nc]!=-1) continue
                s++
                host[nr][nc]= r*M+c
                queue.add(nr to nc)
            }
        }
        sz[r][c]=s
    }

    val ans=Array(N){Array(M){0} }
    val checkSet = HashSet<Int>()
    for(r in 0 until N) for(c in 0 until M){
        if(board[r][c]=='0') continue
        checkSet.clear()
        ans[r][c]=1
        for(d in dir){
            val nr=r+d.first
            val nc=c+d.second
            if(!isValidPos(nr,nc) || board[nr][nc]=='1' || checkSet.contains(host[nr][nc])) continue
            val hostCode = host[nr][nc]
            ans[r][c]+=sz[hostCode/M][hostCode%M]
            checkSet.add(hostCode)
        }
    }
    println(ans.joinToString("\n"){it.joinToString(""){num->(num%10).toString()} })

}