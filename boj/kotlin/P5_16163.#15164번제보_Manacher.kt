import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val str=StringBuilder("")
    br.readLine().forEach{
        str.append("*$it")
    }
    str.append("*")

    var (p,r)=listOf(-1,-1)
    val length=Array(str.length){0}
    str.forEachIndexed{idx,c->
        if(r>=idx){
            length[idx]= (r - idx).coerceAtMost(length[2 * p - idx])
        }
        var now=idx+length[idx]
        while(now+1<str.length && 2*idx-now-1>=0 && str[now+1]==str[2*idx-now-1]){
            length[idx]++
            now++
        }
        if(r<now){
            r=now
            p=idx
        }
    }
    bw.write(length.sumOf{(it.toLong()+1)/2}.toString()+"\n")
    bw.flush()
}