import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max
import java.util.*

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val str=br.readLine()
   val dp=Array(str.length){Array<Int>(str.length){0} }
    for(i in 0..str.length-2){
        when(str[i]){
            'a'-> {
              if(str[i+1]=='t') dp[i][i+1]=1
            }
            'g'->{
                if(str[i+1]=='c') dp[i][i+1]=1
            }
            else->{
                dp[i][i+1]=0
            }
        }
    }
    for(i in 1..str.length){
        for(j in 0..str.length-i){
            for(k in j..j+i-2){
                dp[j][j+i-1]=max(dp[j][j+i-1],dp[j][k]+dp[k+1][j+i-1])
            }
            if(j>0){
                dp[j-1][j+i-1]=max(dp[j-1][j+i-1],dp[j][j+i-1])
            }
            if(j+i<=str.length-1){
                dp[j][j+i]=max(dp[j][j+i],dp[j][j+i-1])
            }

            var s=j-1
            var e=j+i
            while(s>=0 && str[s]!='a'){
                s--
            }
            while(e<str.length && str[e]!='t'){
                e++
            }
            if(s>=0 && e<str.length){
                dp[s][e]=max(dp[s][e],dp[j][j+i-1]+1)
            }

            s=j-1
            e=j+i
            while(s>=0 && str[s]!='g'){
                s--
            }
            while(e<str.length && str[e]!='c'){
                e++
            }
            if(s>=0 && e<str.length){
                dp[s][e]=max(dp[s][e],dp[j][j+i-1]+1)
            }

        }


    }
    bw.write((dp[0][str.length-1]*2).toString()+"\n")
    bw.flush()

}
