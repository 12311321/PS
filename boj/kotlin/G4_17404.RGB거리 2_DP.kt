fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val N=br.readLine().toInt()
    val INF=Int.MAX_VALUE/2
    val cost = Array(N){br.readLine().split(' ').map{it.toInt()} }
    val dp = Array(2){Array(3){INF} }
    var ans = INF
    repeat(3){
        dp[0][it]=cost[0][it]
        for(i in 1 until N){
            val now = i%2
            val pre = 1-now
            dp[now].fill(INF,0,3)
            for(j in 0 until 3){
                dp[now][j] = minOf(dp[now][j],minOf(dp[pre][(j+1)%3],dp[pre][(j+2)%3])+cost[i][j])
            }
        }
        for(i in 0 until 3){
            if(it == i) continue
            ans = minOf(ans,dp[(N-1)%2][i])
        }
    }
    println(ans)
}