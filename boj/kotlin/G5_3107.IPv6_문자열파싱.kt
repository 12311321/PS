import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    br.readLine().run{
        replace("::",":".repeat(9-count{it==':'})).split(':').forEachIndexed{idx,s->
            bw.write(String.format("%4s",s).replace(' ','0'))
            if(idx!=7) bw.write(":")
        }
    }
    bw.close()
}
/*
1:1:1::1:1
0001:0001:0001:0000:0000:0000:0001:0001

123:13::
0123:0013:0000:0000:0000:0000:0000:0000

::
0000:0000:0000:0000:0000:0000:0000:0000

::a:b:
0000:0000:0000:0000:0000:000a:000b:0000
 */