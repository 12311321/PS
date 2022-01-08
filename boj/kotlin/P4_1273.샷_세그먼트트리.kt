import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    class SegTree(private val N: Int) {
        val tree: Array<Int>

        init {
            var sz = 1
            while (sz < N) sz *= 2
            tree = Array(sz * 2) { 0 }
            initData(1, N, 1)
        }

        fun initData(s: Int, e: Int, pos: Int) {
            tree[pos] = (e - s + 1)
            if (s == e) return
            val m = (s + e) / 2
            initData(s, m, pos * 2)
            initData(m + 1, e, pos * 2 + 1)
        }

        fun removeData(idx: Int) {
            var s = 1
            var e = N
            var pos = 1
            while (true) {
                tree[pos]--
                if (s == e) break
                val m = (s + e) / 2
                if (m >= idx) {
                    e = m
                    pos *= 2
                } else {
                    s = m + 1
                    pos = pos * 2 + 1
                }
            }
        }


        fun searchData(k: Int) = searchData(1, N, 1, k)
        private fun searchData(s: Int, e: Int, pos: Int, k: Int): Int {
            if (tree[pos] < k) return Int.MAX_VALUE
            if (s == e) return s
            val m = (s + e) / 2

            return if (tree[pos * 2] >= k) searchData(s, m, pos * 2, k)
            else searchData(m + 1, e, pos * 2 + 1, k - tree[pos * 2])
        }
    }

    val N = br.readLine().toInt()
    val dataArr = Array(N) { LinkedList<Int>() }

    val pq = PriorityQueue<LinkedList<Int>> { a, b ->
        when {
            a.first > b.first -> 1
            a.first < b.first -> -1
            else -> 0
        }
    }

    repeat(3) { color ->
        br.readLine().split(' ').map { it.toInt() }
            .forEachIndexed { idx, h -> dataArr[idx].run { add((if (size == 0) 0 else last) + h) } }
    }

    pq.addAll(dataArr)

    val M = br.readLine().toInt()
    var ans = Array(M) { 0 }
    var nowScore = N
    val sumSegTree = SegTree(3000000)
    val shot = br.readLine().split(' ').mapIndexed { idx, n ->
        val k = sumSegTree.searchData(n.toInt())
        sumSegTree.removeData(k)
        Pair(k, idx)
    }.toTypedArray().apply {
        sortWith { a, b ->
            when {
                a.first > b.first -> 1
                a.first < b.first -> -1
                else -> 0
            }
        }
    }


    for (i in shot.indices) {
        while (pq.isNotEmpty() && pq.peek().first < shot[i].first) {
            val data = pq.poll()
            data.removeFirst()

            when (data.size) {
                0 -> nowScore -= 5
                1 -> {
                    nowScore += 3
                    pq.add(data)
                }
                2 -> {
                    nowScore += 1
                    pq.add(data)
                }
            }
        }
        ans[shot[i].second] = nowScore
    }
    ans.forEach { bw.write("$it\n") }
    bw.close()
}