import java.util.*
class Solution {
    fun solution(info: IntArray, edges: Array<IntArray>): Int {
        var ans=0
        val adjList = Array(info.size){ArrayList<Int>()}
        edges.forEach{
            adjList[it[0]].add(it[1])
            adjList[it[1]].add(it[0])
        }
        val check = Array(1 shl info.size){-1 to -1}
        check[1] = 1 to 0
        val q = LinkedList<Int>()
        q.add(1)
        while(q.isNotEmpty()){
            val now= q.poll()
            ans=ans.coerceAtLeast(check[now].first)
            for(i in 0 until info.size){
                if((now and (1 shl i)) ==0) continue
                for(next in adjList[i]){
                    val nBit = now or (1 shl next)
                    if(nBit == now || check[nBit].first!=-1) continue
                    val nNum = check[now].first+1-info[next] to check[now].second+info[next]
                    if(nNum.second>=nNum.first) continue
                    check[nBit] = nNum
                    q.add(nBit)
                }
            }
        }
        return ans
    }
}