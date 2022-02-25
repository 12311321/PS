import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    var (N,M,f) = br.readLine().split(' ').map{it.toInt()}
    val inf = 1 shl 30
    val dir=arrayOf(1 to 0, -1 to 0, 0 to 1, 0 to -1)
    val arr2=Array(N){Array(N){-1 to -1} }
    val q: Queue<Pair<Int, Int>> = LinkedList()
    val dist=Array(N){Array(N){-1} }
    val resetDist={repeat(N){dist[it].fill(inf,0,N)} }
    val isValidPos={r:Int,c:Int->r in 0 until N && c in 0 until N}


    val arr=Array(N){br.readLine().split(' ').map{it.toInt()}}
    var pos=br.readLine().split(' ').map{it.toInt()-1}.run{get(0) to get(1)}
    repeat(M){
        br.readLine().split(' ').map{it.toInt()-1}.run{
            arr2[get(0)][get(1)]=get(2) to get(3)
        }
    }

    fun BFS(s:Pair<Int,Int>){
        resetDist()
        q.clear()
        dist[s.first][s.second]=0
        q.add(s)
        while(q.isNotEmpty()){
            val now=q.poll()
            for(d in dir){
                val nr=now.first+d.first
                val nc=now.second+d.second
                if(!isValidPos(nr,nc) || arr[nr][nc]==1 || dist[nr][nc]!=inf) continue
                dist[nr][nc]=dist[now.first][now.second]+1
                q.add(nr to nc)
            }
        }

    }
    fun search():Boolean{
        var mDist=inf
        var target=-1 to -1
        BFS(pos)

        for(r in 0 until N) for(c in 0 until N){
            if(arr2[r][c].first!=-1 && dist[r][c]<mDist) {
                mDist=dist[r][c]
                target=r to c
            }
        }
        f-=mDist
        if(f<0) return false

        BFS(target)
        val dest=arr2[target.first][target.second]
        if(f<dist[dest.first][dest.second]) return false
        f+=dist[dest.first][dest.second]
        pos=dest
        arr2[target.first][target.second]=-1 to -1
        return true
    }
    var flag=true
    for(i in 0 until M){
        flag=search()
        if(!flag) break
    }
    println(if(flag) "$f\n" else "-1\n")
}