import java.util.*
class Solution {
    fun solution(k: Int, dungeons: Array<IntArray>): Int {
        dungeons.sortByDescending{it[0]}
        var ans=0
        val q = LinkedList<Triple<Int,Int,Int>>()
        val visit = Array(1 shl dungeons.size){false}
        visit[0]=true
        q.add(Triple(0,0,0))

        while(q.isNotEmpty()){
            val now=q.poll()
            ans=ans.coerceAtLeast(now.third)
            for(i in 0 until dungeons.size){
                val nBit = now.first or (1 shl i)
                if(now.first==nBit || visit[nBit]) continue
                val consume = now.second+dungeons[i][1]
                if(consume>k || k-now.second<dungeons[i][0]) continue
                q.add(Triple(nBit,consume,now.third+1))
                visit[nBit]=true
            }

        }

        return ans
    }
}