fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Node(var data: Long = 0L, var lazy: Long = 0L)
    class LazySegTree(private val N: Int) {
        val tree: Array<Node>

        init {
            var sz = 1
            while (sz < N) {
                sz *= 2
            }
            tree = Array(sz * 2 + 1) { Node() }
        }

        fun insertData(l: Int, r: Int, data: Long) = insertData(1, N, 1, l, r, data)
        private fun insertData(s: Int, e: Int, idx: Int, l: Int, r: Int, data: Long) {
            if (s >= l && e <= r) {
                tree[idx].lazy += data
                return
            }
            tree[idx].data+=(e.coerceAtMost(r) - s.coerceAtLeast(l)+1)*data
            val m = (s + e) / 2
            if (m >= l) insertData(s, m, idx * 2, l, r, data)
            if (m < r) insertData(m + 1, e, idx * 2 + 1, l, r, data)
        }

        fun searchData(l:Int, r:Int) = searchData(1,N,1,l,r)
        private fun searchData(s:Int, e:Int, idx:Int, l:Int, r:Int):Long{
            tree[idx].data+=(e-s+1)*tree[idx].lazy
            if(idx*2<tree.size) tree[idx*2].lazy+=tree[idx].lazy
            if(idx*2+1<tree.size) tree[idx*2+1].lazy+=tree[idx].lazy
            tree[idx].lazy=0

            if(s>=l && e<=r) return tree[idx].data

            val m=(s+e)/2
            var ret=0L
            if(m>=l) ret+=searchData(s,m,idx*2,l,r)
            if(m<r) ret+=searchData(m+1,e,idx*2+1,l,r)
            return ret
        }
    }
    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }
    val lazySegTree = LazySegTree(N)
    repeat(N){ lazySegTree.insertData(it+1,it+1,br.readLine().toLong()) }
    repeat(M+K){
        br.readLine().split(' ').map{it.toInt()}.run{
            if(get(0)==1) lazySegTree.insertData(get(1),get(2),get(3).toLong())
            else bw.write("${lazySegTree.searchData(get(1),get(2))}\n")
        }
    }
    bw.close()
}