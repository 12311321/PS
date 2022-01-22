import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val N = br.readLine().toInt()
    val nList = ArrayList<Int>()

    data class Data(var visit: Boolean, var lastIdx: Int, var pre: Int)

    fun isCorrect(n: Int): Boolean {
        n.toString().forEach {
            if (it != '4' && it != '7') return false
        }
        return true
    }
    for (i in 4..N) if (isCorrect(i)) nList.add(i)

    val dp = Array(N + 1) { Data(false, 0, -1) }
    val queue: Queue<Int> = LinkedList()
    dp[0] = Data(true, 0, -1)
    queue.add(0)
    while (queue.isNotEmpty()) {
        val now = queue.poll()
        if (now == N) break
        for (idx in dp[now].lastIdx until nList.size) {
            val nNum = now + nList[idx]
            if (nNum > N) break
            if (!dp[nNum].visit) {
                dp[nNum] = Data(true, idx, now)
                queue.add(nNum)
            }
        }
    }
    if (dp[N].visit) {
        val ans = ArrayList<Int>()
        var now = N
        while (now != 0) {
            ans.add(now-dp[now].pre)
            now = dp[now].pre
        }
        ans.apply {
            reverse()
            forEach { bw.write("$it ") }
        }
    } else bw.write("-1")
    bw.close()
}