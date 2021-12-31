fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val par = Array(100000) { it }
    val d = Array(100000) { 0 }
    val clear = { n: Int ->
        repeat(n) {
            par[it] = it
            d[it] = 0
        }
    }

    fun find(a: Int): Int {
        if (par[a] != a) par[a] = find(par[a])
        return par[a]
    }

    fun union(a: Int, b: Int): Boolean {
        val pa = find(a)
        val pb = find(b)
        if (pa == pb) return false
        if (d[pa] == d[pb]) {
            par[pb] = pa
            d[pa]++
        } else if (d[pa] > d[pb]) par[pb] = pa
        else par[pa] = pb
        return true
    }
    repeat(br.readLine().toInt()) {
        val n = br.readLine().toInt()
        val m = br.readLine().toInt()
        var flag = true
        clear(n)
        repeat(m) {
            br.readLine().split(' ').map { it.toInt() - 1 }.run {
                flag = flag and union(get(0), get(1))
            }
        }
        flag = flag and (n == m + 1)
        bw.write((if (flag) "tree" else "graph") + "\n")
    }
    bw.close()
}