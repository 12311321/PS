fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val dp = Array(21){Array(21){Array(21){0L} }}

    dp[20][1][1]=1L
    for(i in 20 downTo 2) for(j in 1..20) for(k in 1..20){
        if(dp[i][j][k]==0L) continue
        if(j+1<=20) dp[i-1][j+1][k]+=dp[i][j][k]
        if(k+1<=20) dp[i-1][j][k+1]+=dp[i][j][k]
        dp[i-1][j][k]+=(20-i)*dp[i][j][k]
    }

    repeat(br.readLine().toInt()){
        val (n,l,r) = br.readLine().split(' ').map{it.toInt()}
        bw.write("${dp[20-n+1][l][r]}\n")
    }
    bw.close()
}