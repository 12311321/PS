import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashSet

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Node(val adjList: ArrayList<Int> = ArrayList(), var inDeg: Int = 0)

    val alpSet = HashSet<Int>()
    val N = br.readLine().toInt()
    val nodeArr = Array(26) { Node() }
    val alpArr = Array(N) { "" }

    repeat(N) {
        alpArr[it] = br.readLine()
        alpArr[it].forEach { c -> alpSet.add(c.code - 'a'.code) }
    }
    var f1=true
    for (i in 1 until N) {
        var idx = 0
        while (true) {
            if(idx==alpArr[i].length || idx==alpArr[i-1].length){
                if(alpArr[i-1].length>alpArr[i].length) {
                    println("!")
                    return
                }
                break
            }
            if (alpArr[i - 1][idx] != alpArr[i][idx]) {
                val s = alpArr[i - 1][idx].code - 'a'.code
                val e = alpArr[i][idx].code - 'a'.code
                nodeArr[s].adjList.add(e)
                nodeArr[e].inDeg++
                break
            }
            idx++
        }
    }


    var ans = ArrayList<Int>()
    val visit=Array(26){false}
    for (i in 0 until 26) {
        if (alpSet.contains(i) && nodeArr[i].inDeg == 0 && !visit[i]) {

            val queue: Queue<Int> = LinkedList()
            queue.add(i)
            while (queue.isNotEmpty()) {
                val now = queue.poll()
                visit[now]=true
                ans.add(now)
                for (next in nodeArr[now].adjList) {
                    nodeArr[next].inDeg--
                    if (nodeArr[next].inDeg == 0) queue.add(next)
                }
            }
        }
    }
    if(ans.size==alpSet.size){
        var flag=true
        for(i in 0 until ans.lastIndex){
            if(!nodeArr[ans[i]].adjList.contains(ans[i+1])){
                flag=false
                break
            }
        }
        bw.write(if(!flag)"?" else ans.joinToString("",){(it+'a'.code).toChar().toString()})
    }else bw.write("!")
    bw.close()
}