import java.io.*
import kotlin.math.*
import java.util.*
data class Pos(var r:Int,var c:Int)
data class PosInfo(var p:Pos, var d:Int)
var R:Int=0
var C:Int=0
val Map=ArrayList<String>()
val dir:Array<Pos> = arrayOf(Pos(1,0),Pos(0,1),Pos(-1,0),Pos(0,-1))
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val st=StringTokenizer(br.readLine())
    R=st.nextToken().toInt()
    C=st.nextToken().toInt()
    for(i in 0..R-1){
        Map.add(br.readLine())
    }
    var ans=0
    for(i in 0..R-1){
        for(j in 0..C-1){
            ans=max(ans,BFS(i,j))
        }
    }
    println(ans)
}
fun BFS(r:Int, c:Int):Int{
    if(Map[r][c]!='L') return 0
    var ret=0
    val visit=Array<Array<Boolean>>(R){Array<Boolean>(C){false} }
    visit[r][c]=true
    var q:Queue<PosInfo> = LinkedList<PosInfo>()
    q.add(PosInfo(Pos(r,c),0))
    while(!q.isEmpty()){
        val t=q.poll()
        ret=max(ret,t.d)
        for(i in 0..3){
            val nr=t.p.r+dir[i].r
            val nc=t.p.c+dir[i].c
            if(nr<0 || nr>=R || nc<0 || nc>=C) continue
            if(visit[nr][nc] || Map[nr][nc]=='W') continue
            visit[nr][nc]=true
            q.add(PosInfo(Pos(nr,nc,),t.d+1))
        }
    }
    return ret
}