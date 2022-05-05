import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val N = br.readLine().toInt()
    val dp = Array(61){Array(61){Array(61){-1} } }
    val q = LinkedList<Triple<Int,Int,Int>>()
    val attackList = listOf(Triple(9,3,1),Triple(9,1,3),Triple(3,9,1),Triple(3,1,9),Triple(1,9,3),Triple(1,3,9))
    br.readLine().split(' ').map{it.toInt()}.run{
        val t = Triple(get(0),if(N>=2) get(1) else 0, if(N>=3) get(2) else 0)
        dp[t.first][t.second][t.third]=0
        q.add(t)
    }
    while(q.isNotEmpty()){
        val now = q.poll()
        attackList.forEach{
            val newHp = Triple(maxOf(0,now.first-it.first),maxOf(0,now.second-it.second),maxOf(0,now.third-it.third))
            if(dp[newHp.first][newHp.second][newHp.third]!=-1) return@forEach
            dp[newHp.first][newHp.second][newHp.third]=dp[now.first][now.second][now.third]+1
            q.add(newHp)
        }
    }
    println(dp[0][0][0])
}