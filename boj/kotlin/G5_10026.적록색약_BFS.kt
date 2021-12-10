import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val input = Array(N) { br.readLine() }
    val dir = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))
    val isValidPos = { r: Int, c: Int -> r in 0 until N && c in 0 until N }

    val search = {
        val visit = Array(N) { Array(N) { false } }
        val queue = LinkedList<Pair<Int, Int>>()
        var cnt = 0
        for (r in 0 until N) for (c in 0 until N) {
            if (visit[r][c]) continue
            visit[r][c] = true
            val color = input[r][c]
            cnt++
            queue.add(Pair(r, c))
            while (queue.isNotEmpty()) {
                val now = queue.poll()
                for (d in dir) {
                    val nr = now.first + d.first
                    val nc = now.second + d.second
                    if (!isValidPos(nr, nc) || input[nr][nc] != color || visit[nr][nc]) continue
                    visit[nr][nc] = true
                    queue.add(Pair(nr, nc))
                }
            }
        }
        cnt
    }

    bw.write("${search()} ${run { repeat(N) { input[it] = input[it].replace('G', 'R') }; search() }}\n")
    bw.flush()

}