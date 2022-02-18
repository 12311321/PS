fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (x1, y1, x2, y2) = br.readLine().split(' ').map { it.toLong() }
    val (x3, y3, x4, y4) = br.readLine().split(' ').map { it.toLong() }
    val p1 = x1 to y1
    val p2 = x2 to y2
    val p3 = x3 to y3
    val p4 = x4 to y4
    fun ccw(a: Pair<Long, Long>, b: Pair<Long, Long>, c: Pair<Long, Long>): Int {
        val c =
            a.first * b.second + b.first * c.second + c.first * a.second - a.second * b.first - b.second * c.first - c.second * a.first
        return if (c > 0L) 1 else if (c == 0L) 0 else -1
    }

    val c1 = ccw(p1, p2, p3)
    val c2 = ccw(p1, p2, p4)
    val c3 = ccw(p3, p4, p1)
    val c4 = ccw(p3, p4, p2)
    if (c1 * c2 <= 0 && c3 * c4 <= 0){
        if (c1 * c2 == 0 && c3 * c4 == 0) {
            if(x1==x2){
                val minY1 = y1.coerceAtMost(y2)
                val maxY1 = y1 + y2 - minY1
                val minY2 = y3.coerceAtMost(y4)
                val maxY2 = y3 + y4 - minY2
                if (minY1 <= minY2) println(if (maxY1 >= minY2) "1\n" else "0\n")
                else println(if (maxY2 >= minY1) "1\n" else "0\n")
            }else {
                val minX1 = x1.coerceAtMost(x2)
                val maxX1 = x1 + x2 - minX1
                val minX2 = x3.coerceAtMost(x4)
                val maxX2 = x3 + x4 - minX2
                if (minX1 <= minX2) println(if (maxX1 >= minX2) "1\n" else "0\n")
                else println(if (maxX2 >= minX1) "1\n" else "0\n")
            }
        }else  println("1\n")
    } else println("0\n")
}