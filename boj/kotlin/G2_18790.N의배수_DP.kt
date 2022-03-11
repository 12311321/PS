fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    data class Info(var r:Int, var c:Int,var num:Int)
    val N=br.readLine().toInt()
    val dp=Array(N+1){Array(N){Info(-1,-1,-1)} } //r개의 숫자 나머지가 c
    val visit=Array(N+1){Array(N){-1} }
    dp[0][0]=Info(0,0,-1)
    val input = br.readLine().split(' ').map{it.toInt()}
    for(idx in input.indices){
        for(r in 0..N) for(c in 0 until N){
            if(dp[r][c].r==-1 || visit[r][c]==idx || r==N) continue
            val nr=r+1
            val nc=(c+input[idx])%N
            if(visit[nr][nc]==-1){
                visit[nr][nc]=idx
                dp[nr][nc]=Info(r,c,input[idx])
            }
        }
    }

    if(visit[N][0]==-1) bw.write("-1\n")
    else{
        var pos=N to 0
        while(pos.first!=0){
            bw.write("${dp[pos.first][pos.second].num} ")
            pos=dp[pos.first][pos.second].run{r to c}
        }
    }
    bw.close()
}