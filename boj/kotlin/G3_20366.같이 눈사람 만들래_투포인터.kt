fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val N = br.readLine().toInt()
    var ans = Int.MAX_VALUE
    val calAbs = { a: Int -> if (a > 0) a else -a }
    br.readLine().split(' ').map { it.toInt() }.sorted().run {
        for (i in 2..lastIndex) for (j in i + 1..lastIndex) {
            val dif = get(j) - get(i)
            var s = 0
            for (e in 1 until i) {
                while (s < e - 1 && dif < (get(e) - get(s))) s++
                ans = minOf(ans, calAbs(dif - (get(e) - get(s))))
                if (s > 0) ans = minOf(ans, calAbs((get(e) - get(s - 1)) - dif))
            }
        }
    }
    println(ans)
}