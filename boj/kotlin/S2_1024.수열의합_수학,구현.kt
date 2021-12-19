import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    var (N,L) = br.readLine().split(' ').map{it.toInt()}
    val sigma={n:Int->(n*(n+1))/2}
    while(L<=100){
        val r=N-sigma(L-1)
        if(r%L==0 && r>=0){
            repeat(L){bw.write("${it+r/L} ")}
            break
        }
        L++
    }
    if(L==101) bw.write("-1\n")
    bw.close()
}