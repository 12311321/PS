import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Info(var a: Int, val b: Int, var c: Int)
    class SegTree(private val N: Int) {
        private val tree: Array<Int>
        init {
            var sz = 2
            while (sz <= N + 1) sz *= 2
            tree = Array(sz * 2) {0}
        }

        fun insertData(idx:Int) = insertData(0, N, 1, idx)

        private fun insertData(s: Int, e: Int, pos: Int,idx:Int) {
            tree[pos]++
            if(s==e) return
            val m=(s+e)/2
            if(m<idx) insertData(m+1,e,pos*2+1,idx)
            else insertData(s,m,pos*2,idx)
        }

        fun searchData(s: Int, e: Int) = if(s>e) 0 else searchData(0, N, 1, s, e)

        private fun searchData(s: Int, e: Int, pos: Int, fs: Int, fe: Int): Int {
            if(s>=fs && e<=fe) return tree[pos]
            val m =(s+e)/2
            var ret=0
            if(m<fe) ret+=searchData(m+1,e,pos*2+1,fs,fe)
            if(m>=fs) ret+=searchData(s,m,pos*2,fs,fe)
            return ret
        }

    }

    val N = br.readLine().toInt()
    val infos = Array(N) {
        br.readLine().split(' ').map { it.toInt() }.run {
            Info(get(0), get(1), get(2))
        }
    }.apply{sortBy{it.b}}

    val maxVal = infos.maxOf{it.b}
    val segTree = SegTree(maxVal)
    val numSet = TreeSet<Int>().apply{repeat(maxVal+1){add(it)} }

    infos.forEach{
        val need = it.c-segTree.searchData(it.a,it.b)
        if(need<=0) return@forEach
        repeat(need){_->
            val target = numSet.lower(it.b+1)!!
            numSet.remove(target)
            segTree.insertData(target)
        }
    }

    println(maxVal+1-numSet.size)
}