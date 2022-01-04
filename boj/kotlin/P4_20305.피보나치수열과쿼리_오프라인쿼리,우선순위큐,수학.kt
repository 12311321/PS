import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val N = br.readLine().toInt()
    val mod = 1000000007L
    val fib = Array(N + 1) { 0L }
    fib[1] = 1L
    for (i in 2..N) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod
    }
    val Q = br.readLine().toInt()
    val querys = Array(Q) { br.readLine().split(' ').map { it.toInt() - 1 }.run { Pair(get(0), get(1)) } }.apply {
        sortWith { a, b ->
            when {
                a.first > b.first -> 1
                a.first < b.first -> -1
                else -> 0
            }
        }
    }

    val pq = PriorityQueue<Pair<Int, Int>> { a, b ->
        when {
            a.second > b.second -> 1
            a.second < b.second -> -1
            else -> 0
        }
    }
    val ans = Array(N) { 0L }
    var queryIdx = 0
    for (i in 0 until N) {
        if (i + 1 < N) ans[i + 1] = (ans[i + 1] + ans[i]) % mod
        if (i + 2 < N) ans[i + 2] = (ans[i + 2] + ans[i]) % mod
        while (queryIdx < Q && querys[queryIdx].first == i) {
            ans[i] = (ans[i] + 1) % mod
            if (i + 1 < N) ans[i + 1] = (ans[i + 1] + 1) % mod
            if (i + 2 < N) ans[i + 2] = (ans[i + 2] + 1) % mod
            pq.add(querys[queryIdx++])
        }
        while (pq.isNotEmpty() && pq.peek().second == i) {
            pq.poll().run {
                if (i + 1 < N) ans[i + 1] = (mod + ans[i + 1] - fib[second - first + 2]) % mod
                if (i + 2 < N) ans[i + 2] = (mod + ans[i + 2] - fib[second - first + 3] + fib[second - first + 2]) % mod
            }
        }
    }
    bw.write(ans.joinToString(" ") + "\n")
    bw.close()
}