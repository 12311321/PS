package boj_11451

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
val br= BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))
data class Pos(var r:Int, var c:Int){
    operator fun plus(a:Pos):Pos{
        return Pos(this.r+a.r,this.c+a.c)
    }
}
val dir=arrayOf(Pos(0,1),Pos(-1,0),Pos(0,-1),Pos(1,0))
val dirc=arrayOf('E','N','W','S')
fun main(){
    val T=br.readLine().toInt()
    (0..T-1).forEach{
        val (N,M)=br.readLine().split(' ').map{it.toInt()}
        val map=Array(N){br.readLine().toCharArray() }
        val dp=Array(N*M){Array<String?>(N*M){null} }
        var p1=-1
        var p2=-1
        val getPos={a:Int->Pos(a/M,a%M)}
        val getIdx={a:Pos->a.r*M+a.c}
        for(i in 0..N*M-1){
            val p=getPos(i)
            if(map[p.r][p.c]=='P'){
                when(p1){
                    -1->{
                        p1=i
                        map[p.r][p.c]='.'
                    }else->{
                        p2=i
                        map[p.r][p.c]='.'
                        break
                    }

                }
            }

        }

        val q: Queue<Pos> = LinkedList()
        dp[p1][p2]=""
        dp[p2][p1]=""
        q.add(Pos(p1,p2))
        var ans:String?=null
        while(q.isNotEmpty()){
            val t=q.poll()
            if(t.r==t.c) {
                ans = dp[t.r][t.c]
                break
            }
            var p1=getPos(t.r)
            var p2=getPos(t.c)
            for(d in 0..3){
                var np1=p1+dir[d]
                var np2=p2+dir[d]
                np1.r=(N+np1.r)%N
                np1.c=(M+np1.c)%M
                np2.r=(N+np2.r)%N
                np2.c=(M+np2.c)%M
                if(map[np1.r][np1.c]=='G' || map[np2.r][np2.c]=='G') continue
                if(map[np1.r][np1.c]=='X') np1=p1
                if(map[np2.r][np2.c]=='X') np2=p2

                val idx1=getIdx(np1)
                val idx2=getIdx(np2)

                if(dp[idx1][idx2]==null || dp[idx1][idx2]!!.length>dp[t.r][t.c]!!.length+1 ){
                    dp[idx1][idx2]=dp[t.r][t.c]!!+dirc[d]
                    dp[idx2][idx1]=dp[idx1][idx2]
                    q.add(Pos(idx1,idx2))
                }
            }
        }

        when(ans){
            null->{
                bw.write("IMPOSSIBLE\n")
            }else->{
                bw.write("${ans.length} ${ans}\n")
            }

        }
        bw.flush()

    }//T.forEach


}
