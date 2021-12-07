import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    val adjArr = Array(N) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    val queue= LinkedList<Int>()
    repeat(N) { s ->
        val visit=Array(N){false}
        queue.add(s)
        while(queue.isNotEmpty()){
            val now=queue.poll()
            for(next in 0 until N){
                if(adjArr[now][next]==0 || visit[next]) continue
                visit[next]=true
                adjArr[s][next]=1
                queue.add(next)
            }
        }
        adjArr[s].forEach{
            bw.write("$it ")
        }
        bw.write("\n")
    }
    bw.flush()


}