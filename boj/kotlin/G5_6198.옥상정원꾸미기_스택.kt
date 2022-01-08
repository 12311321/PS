import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val st= Stack<Pair<Int,Int>>()
    var ans=0L
    val N=br.readLine().toInt()
    repeat(N){idx->
        br.readLine().toInt().let{h->
            while(st.isNotEmpty() && st.peek().first<=h) ans+=idx-st.pop().second-1
            st.add(Pair(h,idx))
        }
    }
    while(st.isNotEmpty()) ans+=N-st.pop().second-1
    bw.write("$ans\n")
    bw.close()
}