import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val N=br.readLine().toInt()
    val strarr=br.readLine().split(' ')
    val h=IntArray(N){it->strarr[it].toInt()}
    var ans=0
    for(i in 0..N-1){
        var num=0
        if(i>0) {
            var slope=(h[i-1]-h[i]).toDouble()
            num++
            for (j in i - 2 downTo (0)) {
                val nslope=(h[j]-h[i]).toDouble()/(i-j)
                if(nslope>slope){
                    num++

                    slope=nslope
                }
            }
        }
        if(i<N-1) {
            var slope=(h[i+1]-h[i]).toDouble()
            num++
            for (j in i + 2..N - 1) {
                val nslope=(h[j]-h[i]).toDouble()/(j-i)
                if(nslope>slope){
                    num++
                    slope=nslope
                }
            }
        }

        ans=max(ans,num)
    }
    bw.write(ans.toString()+"\n")
    bw.flush()

}