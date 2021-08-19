package boj_2291

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br= BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))
val dp=Array(10){Array(221){Array(221){-1} } }
fun init(n:Int, a:Int, b:Int, N:Int,M:Int){//순서, 마지막 숫자, 누적합
    if(n==N-1){
        if(b==M) {
            dp[n][a][b] = 1
        }else{
            dp[n][a][b]=0
        }
        return
    }
    var r=0
    for(i in a..M-b){
        if(dp[n+1][i][b+i]==-1) init(n+1,i,b+i,N,M)
        r+=dp[n+1][i][b+i]
    }

    dp[n][a][b]=r

}

fun main(){
    var (N,M,K)= br.readLine().split(' ').map{it.toInt()}
    for(i in 1..M) {
        init(0, i, i,N,M)
    }
    var ac=0
    var last=1
    for(i in 0..N-1){
        var t=0
        for(j in last..M-ac){
            if(dp[i][j][ac+j]>0 && t+dp[i][j][ac+j]>=K){
                bw.write("${j} ")
                K-=t
                last=j
                ac+=j
                break
            }
            t+=dp[i][j][ac+j]
        }

    }
    bw.flush()
}
