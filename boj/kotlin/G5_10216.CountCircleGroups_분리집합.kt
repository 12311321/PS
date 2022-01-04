fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    data class Tower(val x: Int, val y: Int, val r: Int)

    val data = Array(3000) { Tower(0, 0, 0) }
    val par = Array(3000) { it }
    val d = Array(3000) { 0 }
    var ans = 0
    fun find(a: Int): Int {
        if (par[a] != a) par[a] = find(par[a])
        return par[a]
    }

    fun union(a: Int, b: Int) {
        val pa = find(a)
        val pb = find(b)
        if (pa == pb) return
        if (d[pa] == d[pb]) {
            par[pb] = pa
            d[pa]++
        } else if (d[pa] > d[pb]) par[pb] = pa
        else par[pa] = pb
        ans--
    }

    repeat(br.readLine().toInt()) {
        val N = br.readLine().toInt()
        ans = N
        for (n in 0 until N) {
            br.readLine().split(' ').map { it.toInt() }.run { data[n] = Tower(get(0), get(1), get(2)) }
            par[n] = n
            d[n] = 0
        }

        for (i in 0 until N) {
            for (j in i + 1 until N) {
                val squareDist = (data[i].x - data[j].x).let { it * it } + (data[i].y - data[j].y).let { it * it }
                if (squareDist <= (data[i].r + data[j].r).let { it * it }) union(i, j)
            }
        }
        bw.write("$ans\n")
    }
    bw.close()
}