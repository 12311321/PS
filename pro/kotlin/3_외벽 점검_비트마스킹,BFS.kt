import java.util.*
class Solution {
    fun solution(n: Int, weak: IntArray, dist: IntArray): Int {
        var ans = Int.MAX_VALUE
        val dp = Array(1 shl dist.size){0}
        val q = LinkedList<Pair<Int,Int>>()
        for(start in weak.indices){
            dp.fill(0,0,(1 shl dist.size))
            q.add(0 to 0)
            while(q.isNotEmpty()){
                val now = q.poll()
                if(dp[now.first]>=weak.size) ans=ans.coerceAtMost(now.second)
                for(i in 0 until dist.size){
                    val nBit = now.first or (1 shl i)
                    if(nBit == now.first) continue
                    var nowIdx = (start+dp[now.first]+1)%weak.size
                    var move = 0
                    var cnt=0
                    while(move<=dist[i]){
                        move+= (n+weak[(nowIdx+1)%weak.size] - weak[nowIdx])%n
                        cnt++
                        nowIdx = (nowIdx+1)%weak.size
                    }
                    dp[nBit] = dp[nBit].coerceAtLeast(dp[now.first]+cnt)
                    q.add(nBit to now.second+1)
                }
            }
        }
        return if(ans==Int.MAX_VALUE) -1 else ans
    }
}