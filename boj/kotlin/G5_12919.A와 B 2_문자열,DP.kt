import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    var S = br.readLine()
    val T = br.readLine()

    val visit = Array(T.length){Array(T.length){Array(2){false} } }
    val q = LinkedList<Triple<Int,Int,Int>>()
    visit[0][T.lastIndex][0]=true
    q.add(Triple(0,T.lastIndex,0))

    while(q.isNotEmpty()){
        val now = q.poll()
        if(now.second-now.first+1==S.length){
            var str = T.substring(now.first,now.second+1).run{if(now.third==1) reversed() else this}
            if(str==S){
                println(1)
                return
            }
            continue
        }

        if(now.third==0){
            if(T[now.second]=='A' && !visit[now.first][now.second-1][now.third]){
                visit[now.first][now.second-1][now.third]=true
                q.add(Triple(now.first,now.second-1,now.third))
            }
            if(T[now.first]=='B' && !visit[now.first+1][now.second][1-now.third]){
                visit[now.first+1][now.second][1-now.third]=true
                q.add(Triple(now.first+1,now.second,1-now.third))
            }
        }else{
            if(T[now.first]=='A' && !visit[now.first+1][now.second][now.third]){
                visit[now.first+1][now.second][now.third]=true
                q.add(Triple(now.first+1,now.second,now.third))
            }
            if(T[now.second]=='B' && !visit[now.first][now.second-1][1-now.third]){
                visit[now.first][now.second-1][1-now.third]=true
                q.add(Triple(now.first,now.second-1,1-now.third))
            }
        }
    }

    println(0)
}