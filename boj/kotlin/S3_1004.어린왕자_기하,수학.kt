import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val isInside={x:Int,y:Int,cx:Int,cy:Int,r:Int-> (x-cx)*(x-cx)+(y-cy)*(y-cy)<=r*r }
    repeat(br.readLine().toInt()){
        var ans=0
        val(x1,y1,x2,y2) = br.readLine().split(' ').map{it.toInt()}
        repeat(br.readLine().toInt()){
            br.readLine().split(' ').map{it.toInt()}.run{
                ans+=if(isInside(x1,y1,get(0),get(1),get(2)) xor isInside(x2,y2,get(0),get(1),get(2))) 1 else 0
            }
        }
        bw.write(ans.toString()+"\n")
        bw.flush()
    }
}