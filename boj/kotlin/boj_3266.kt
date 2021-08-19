package boj_2306

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.abs
import java.lang.Math.min

val br= BufferedReader(InputStreamReader(System.`in`))
val bw= BufferedWriter(OutputStreamWriter(System.out))
fun main(){
    var A=br.readLine()
    var B=br.readLine()
    val K=br.readLine().toInt()

    val dp=Array(A.length+1){Array<Int>(B.length+1){0} }

    for(i in 0..A.length){
        dp[i][0]=K*i
        for(j in 1..B.length){
            dp[i][j]=dp[i][j-1]+K
            if(i>0) {
                dp[i][j] =min(dp[i][j], dp[i - 1][j]+K)
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(A[i-1]-B[j-1]))
            }
        }
    }


    bw.write(dp[A.length][B.length].toString())
    bw.flush()
}