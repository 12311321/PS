import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val map = HashMap<String, String>()
    br.readLine().split(' ').map { it.toInt() }.run {
        repeat(get(0)) { idx ->
            br.readLine().let { name ->
                map[name] = (idx + 1).toString()
                map[(idx + 1).toString()] = name
            }
        }
        repeat(get(1)) {
            bw.write(map[br.readLine()]!!+"\n")
        }
    }
    bw.flush()
}