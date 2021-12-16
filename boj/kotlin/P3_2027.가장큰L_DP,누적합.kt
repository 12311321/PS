import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, m) = br.readLine().split(' ').map { it.toInt() }

    val arr = Array(n) { br.readLine() }
    val dp = Array(2) { Array(n) { Array(n) { Array(2) { 0 } } } }
    val reset = { idx: Int ->
        for (i in 0 until n) for (j in i until n) {
            dp[idx][i][j][0] = 0
            dp[idx][i][j][1] = 0
        }
    }

    var ans = 0
    for (c in 0 until m) {
        var h = 0
        val now = c % 2
        val pre = 1 - now
        reset(now)
        for (r in 0 until n) {
            if (arr[r][c] == '1') {
                h++

                /*
                누적 h개  현재 인덱스 r
                r-h+1 ~ r 까지의 블록이 있음
                 */
                var maxArea = 0
                for (s in 0 until r - h + 1) {
                    maxArea = maxArea.coerceAtLeast(dp[pre][s][r][0])
                }
                for (s in r - h + 1..r) {
                    dp[now][s][r][0] = dp[pre][s][r][0] + r - s + 1

                    /*
                    dp[now][s][r][1] = if(maxArea==0) dp[pre][s][r][1] else max(dp[pre][0..s-1][r][0], dp[pre][s][r][1]) +r-s+1
                     */
                    if (maxArea != 0 || dp[pre][s][r][1] != 0) {
                        dp[now][s][r][1] = dp[pre][s][r][1].coerceAtLeast(maxArea) + r - s + 1
                        ans = ans.coerceAtLeast(dp[now][s][r][1])
                    }
                    maxArea = maxArea.coerceAtLeast(dp[pre][s][r][0])
                }
            } else {
                h = 0
            }
        }
    }
    bw.write(ans.toString() + "\n")
    bw.flush()
}