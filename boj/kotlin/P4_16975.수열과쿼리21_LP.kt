fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Node(var data: Long, var lazy: Long)
    class LazySegTree(private val N: Int) {
        private val tree: Array<Node>

        init {
            var sz = 1
            while (sz <= N) sz *= 2
            tree = Array(sz * 2) { Node(0, 0) }
        }

        fun updateData(l: Int, r: Int, k: Long) = updateData(1, N, 1, l, r, k)
        private fun updateData(s: Int, e: Int, pos: Int, l: Int, r: Int, k: Long) {
            if (l <= s && e <= r) {
                tree[pos].lazy += k
                return
            }
            tree[pos].data += k * (e.coerceAtMost(r) - s.coerceAtLeast(l) + 1)
            val m = (s + e) / 2
            if (m >= l) updateData(s, m, pos * 2, l, r, k)
            if (m < r) updateData(m + 1, e, pos * 2 + 1, l, r, k)
        }

        fun searchData(idx: Int) = searchData(1, N, 1, idx)
        private fun searchData(s: Int, e: Int, pos: Int, idx: Int): Long {
            val lazy=tree[pos].lazy
            tree[pos].lazy=0
            tree[pos].data += lazy*(e-s+1)
            if (s == e) return tree[pos].data
            tree[pos * 2].lazy += lazy
            tree[pos * 2 + 1].lazy += lazy
            val m = (s + e) / 2
            return if (idx <= m) searchData(s, m, pos * 2, idx)
            else searchData(m + 1, e, pos * 2+1, idx)
        }
    }

    val N = br.readLine().toInt()
    val lazySegTree = LazySegTree(N)
    br.readLine().split(' ').map { it.toLong() }.forEachIndexed { idx, data ->
        lazySegTree.updateData(idx + 1, idx + 1, data)
    }
    repeat(br.readLine().toInt()) {
        br.readLine().split(' ').map { it.toInt() }.run {
            if (get(0) == 1) lazySegTree.updateData(get(1), get(2), get(3).toLong())
            else bw.write("${lazySegTree.searchData(get(1))}\n")
        }
    }
    bw.close()
}