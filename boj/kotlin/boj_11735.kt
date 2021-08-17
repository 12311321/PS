





import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.*
import java.util.*


fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))

    val (n,q)=br.readLine().split(' ').map{it.toLong()}

    val checkR=Array(n.toInt()){false}
    val checkC=Array(n.toInt()){false}

    var erasedR=0L
    var erasednumR=0L
    var erasedC=0L
    var erasednumC=0L

    for(i in 0..q-1){
        val str=br.readLine().split(' ')
        val a=str[0]
        val b=str[1].toInt()
        when(a){
            "R"->{
                if(checkR[b-1]){
                    bw.write("0\n")
                }else{
                    bw.write((n*(n+1)/2+b.toLong()*(n-erasednumC)-erasedC).toString()+"\n")
                    checkR[b-1]=true
                    erasedR+=b
                    erasednumR++
                }
            }
            "C"->{
                if(checkC[b-1]){
                    bw.write("0\n")
                }else{
                    bw.write((n*(n+1)/2+b.toLong()*(n-erasednumR)-erasedR).toString()+"\n")
                    checkC[b-1]=true
                    erasedC+=b
                    erasednumC++
                }
            }
        }
    }
    bw.flush()
}

/*
TODO 반드시 제출언어 바꿔서 내기!!!!!!!!!!!!!
 */