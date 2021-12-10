import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()
    val input = br.readLine().split(' ').map { it.toInt() }.toTypedArray().apply {
        sort()
    }
    val getAbs={n:Int->if(n<0)-n else n}

    var s=0
    var e=input.lastIndex
    var ans= getAbs(input[s] + input[e])
    var ansPair=Pair(input[s],input[e])
    while(true){
        if(getAbs(input[s])>getAbs(input[e])){
            s++
        }else{
            e--
        }
        if(s==e) break
        val sum=getAbs(input[s]+input[e])
        if(sum<ans){
            ans=sum
            ansPair=Pair(input[s],input[e])
        }
    }
    bw.write("${ansPair.first} ${ansPair.second}\n")
    bw.flush()
}