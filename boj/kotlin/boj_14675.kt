import java.io.*
import kotlin.math.*
import java.util.*

fun main() {
    val br=BufferedReader(InputStreamReader(System.`in`))
    val bw=BufferedWriter(OutputStreamWriter(System.out))
    val N=br.readLine().toInt()
    val adjlist=Array(N){ArrayList<Int>()}
    for(i in 1..N-1){
        val st=StringTokenizer(br.readLine())
        val a=st.nextToken().toInt()
        val b=st.nextToken().toInt()
        adjlist[a-1].add(b-1)
        adjlist[b-1].add(a-1)
    }
    val q=br.readLine().toInt()
    for(i in 0..q-1){
        val st=StringTokenizer(br.readLine())
        val t=st.nextToken().toInt()
        val k=st.nextToken().toInt()
        when(t){
            1->{
                when(adjlist[k-1].size){
                    1->bw.write("no\n")
                    else->bw.write("yes\n")
                }
            }
            2->{
                bw.write("yes\n")
            }
        }
    }
    bw.flush()
    bw.close()
}