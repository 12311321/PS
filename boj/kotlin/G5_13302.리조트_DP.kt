fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val (N,M) = br.readLine().split(' ').map{it.toInt()}
    val visit = Array(N+1){true}
    if(M!=0){ br.readLine().split(' ').map{it.toInt()}.forEach{visit[it]=false} }
    val INF = Int.MAX_VALUE/2
    val dp = Array(N+1){Array(N+1){INF} }

    dp[0][0]=0
    for(i in 0 until N) for(j in 0..N){
        if(dp[i][j] == INF) continue
        dp[i+1][j] = minOf(dp[i+1][j],dp[i][j]+if(visit[i+1]) 10000 else 0)
        if(j>=3) dp[i+1][j-3] = minOf(dp[i+1][j-3],dp[i][j])
        if(i+3<=N) dp[i+3][j+1] = minOf(dp[i+3][j+1],dp[i][j]+25000)
        if(i+5<=N) dp[i+5][j+2] = minOf(dp[i+5][j+2],dp[i][j]+37000)
    }

    println(dp[N].minOf{it})
}