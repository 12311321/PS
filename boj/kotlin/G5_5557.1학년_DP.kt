import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val dp = Array(2) { Array(21) { 0L } }
    val clear = { idx: Int ->
        dp[idx].fill(0, 0, 21)
    }
    val n = br.readLine().toInt()
    br.readLine().split(' ').map { it.toInt() }.toTypedArray().run {
        clear(0)
        dp[0][get(0)]=1
        for(idx in 1..size-2){
            clear(idx % 2)
            for (i in 0..20) {
                if (i + get(idx) <= 20) dp[idx % 2][i + get(idx)] += dp[1 - (idx % 2)][i]
                if (i - get(idx) >= 0) dp[idx % 2][i - get(idx)] += dp[1 - (idx % 2)][i]
            }
        }
        bw.write(dp[size % 2][last()].toString() + "\n")
    }
    bw.flush()
}