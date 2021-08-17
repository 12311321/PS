import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.*
import java.util.*
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    var str=br.readLine().split(' ')
    val N=str[0].toInt()
    val M=str[1].toInt()
    val score=Array(N){Array<Int>(M){0} }
    for(i in 0..N-1){
        str=br.readLine().split(' ')
        for(j in 0..M-1){
            score[i][j]=str[j].toInt()
        }
    }
    val INF=10000*10000+1
    var dp=Array(N){Array(M){Array<Int>(2){-INF} } }

    dp[N-1][0][0]=score[N-1][0]
    dp[N-1][0][1]=score[N-1][0]

    for(c in 0..M-1){
        for(r in N-1 downTo 0){
            if(dp[r][c][0]!=-INF){
                if(r>0) {
                    dp[r-1][c][0] = max(dp[r-1][c][0], dp[r][c][0] + score[r-1][c])
                }
                if(c<M-1) {
                    dp[r][c+1][0] = max(dp[r][c+1][0], dp[r][c][0] + score[r][c+1])
                }
                dp[r][c][1]=dp[r][c][0]+score[r][c]
            }
        }
    }
    for(c in 0..M-1){
        for( r in 0..N-1){
            if(dp[r][c][1]!=-INF){
                if(r<N-1){
                    dp[r+1][c][1]=max(dp[r+1][c][1],dp[r][c][1]+score[r+1][c])
                }
                if(c<M-1){
                    dp[r][c+1][1]=max(dp[r][c+1][1],dp[r][c][1]+score[r][c+1])
                }
            }
        }
    }
    bw.write(dp[N-1][M-1][1].toString()+"\n")
    bw.flush()
}