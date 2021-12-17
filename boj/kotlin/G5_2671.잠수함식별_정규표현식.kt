import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
/*
   status       num input 0 input 1 terminate
   ""           0   1       2       true
   "0"          1   null    0       false
   "1"          2   3       null    false
   "10"         3   4       null    false
   "100"        4   4       5       false
   "100~1"      5   1       6       true
   "100~1~1"    6   7       6       true
   "100~1~10"   7   4       0       false
 */
fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var status=0
    val statusArr=Array(8){Array(2){-1} }
    statusArr[0][0]=1
    statusArr[0][1]=2
    statusArr[1][1]=0
    statusArr[2][0]=3
    statusArr[3][0]=4
    statusArr[4][0]=4
    statusArr[4][1]=5
    statusArr[5][0]=1
    statusArr[5][1]=6
    statusArr[6][0]=7
    statusArr[6][1]=6
    statusArr[7][0]=4
    statusArr[7][1]=0
    for(c in br.readLine()){
        status=statusArr[status][if(c=='0')0 else 1]
        if(status==-1) break
    }
    bw.write((if(status==0 || status==5 || status==6)"SUBMARINE" else "NOISE")+"\n")
    bw.flush()
}