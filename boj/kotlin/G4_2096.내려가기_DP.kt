fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val dp=Array(2){Array(2){Array(3){0} }}
    val N=br.readLine().toInt()
    repeat(N){idx->
        val now=idx%2
        val pre=1-now
        br.readLine().split(' ').map{it.toInt()}.run{
            dp[now][0][0]=dp[pre][0][0].coerceAtLeast(dp[pre][0][1])+get(0)
            dp[now][0][1]=dp[pre][0][0].coerceAtLeast(dp[pre][0][1].coerceAtLeast(dp[pre][0][2]))+get(1)
            dp[now][0][2]=dp[pre][0][1].coerceAtLeast(dp[pre][0][2])+get(2)
            dp[now][1][0]=dp[pre][1][0].coerceAtMost(dp[pre][1][1])+get(0)
            dp[now][1][1]=dp[pre][1][0].coerceAtMost(dp[pre][1][1].coerceAtMost(dp[pre][1][2]))+get(1)
            dp[now][1][2]=dp[pre][1][1].coerceAtMost(dp[pre][1][2])+get(2)
        }
    }
    println("${dp[(N-1)%2][0].maxOf{it}} ${dp[(N-1)%2][1].minOf{it}}")
}