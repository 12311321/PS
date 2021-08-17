import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.pow
import java.util.*

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val T=br.readLine().toInt()
    for(tc in 1..T) {
        val str = br.readLine().split(' ')
        val n = str[0].toInt()
        val m = str[1].toInt()
        val dp = Array(n) { Array<Long>(m + 1) { 0 } }

        for (i in 1..m) {
            dp[0][i] = 1
        }

        for (i in 1..n - 1) {
            val ac = Array<Long>(m + 1) { -1 }
            ac[0] = 0
            for (j in 1..m) {
                ac[j] = ac[j - 1] + dp[i - 1][j]
            }
            for (j in 1..m) {
                dp[i][j] = ac[j / 2]

            }

        }
        var ans = 0L


        for (i in 1..m) {
            ans += dp[n - 1][i]
        }
        bw.write(ans.toString()+"\n")


        bw.flush()
    }
}