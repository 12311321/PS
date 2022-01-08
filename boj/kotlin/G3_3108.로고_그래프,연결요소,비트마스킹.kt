import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val bit = Array(1001) { Array(1001) { 0 } }
    val visit = Array(1001) { Array(1001) { false } }
    val dir = arrayOf(-1 to 0, 1 to 0, 0 to 1, 0 to -1) //북 남 동 서
    repeat(br.readLine().toInt()) {
        val (r1, c1, r2, c2) = br.readLine().split(' ').map { it.toInt() + 500 }
        bit[r1][c1] = bit[r1][c1] or (1 shl 1) or (1 shl 2)
        bit[r1][c2] = bit[r1][c2] or (1 shl 1) or (1 shl 3)
        bit[r2][c1] = bit[r2][c1] or (1 shl 0) or (1 shl 2)
        bit[r2][c2] = bit[r2][c2] or (1 shl 0) or (1 shl 3)
        for (r in r1 + 1 until r2) {
            bit[r][c1] = bit[r][c1] or (1 shl 0) or (1 shl 1)
            bit[r][c2] = bit[r][c2] or (1 shl 0) or (1 shl 1)
        }
        for (c in c1 + 1 until c2) {
            bit[r1][c] = bit[r1][c] or (1 shl 2) or (1 shl 3)
            bit[r2][c] = bit[r2][c] or (1 shl 2) or (1 shl 3)
        }
    }
    val isValidPos = { r: Int, c: Int -> r in 0..1000 && c in 0..1000 }
    var ans = if (bit[500][500] == 0) 0 else -1
    val queue: Queue<Pair<Int, Int>> = LinkedList()
    for (r in 0..1000) for (c in 0..1000) {
        if (visit[r][c] || bit[r][c] == 0) continue
        ans++
        queue.add(r to c)
        visit[r][c] = true
        while (queue.isNotEmpty()) {
            val now = queue.poll()
            for (d in dir.indices) {
                if ((bit[now.first][now.second] and (1 shl d)) == 0) continue
                val nr = now.first + dir[d].first
                val nc = now.second + dir[d].second
                if (!isValidPos(nr, nc) || visit[nr][nc]) continue
                visit[nr][nc] = true
                queue.add(nr to nc)
            }
        }

    }
    bw.write("$ans\n")
    bw.close()
}