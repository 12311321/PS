import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
data class Data(var n:Int,var idx:Int)
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    var N=br.readLine().toInt()
    val str=br.readLine().split(' ')
    val A=Array<Data>(N){Data(-1,-1)}
    (0..N-1).forEach{ A[it]=Data(str[it].toInt(),it) }
    var S=br.readLine().toInt()

    A.sortWith{A:Data,B:Data->when{
        A.n<B.n->1
        A.n>B.n->-1
        else->0
    }}

    var next=0
    while(next<N){
        for(i in 0..N-1){
            if(next>A[i].idx) continue
            if(S>=A[i].idx-next){
                for(j in 0..N-1){
                    if(A[j].idx>=next && A[j].idx<A[i].idx) A[j].idx++
                }

                S-=A[i].idx-next
                A[i].idx=next

                break
            }
        }
        next++
    }
    A.sortWith{A:Data,B:Data->when{
        A.idx>B.idx->1
        A.idx<B.idx->-1
        else->0
    }}


    (A).forEach{
        bw.write("${it.n} ")
    }
    bw.write("\n")
    bw.flush()
}
